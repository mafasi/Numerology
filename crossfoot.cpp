#include "crossfoot.h"

#include <iostream>
#include <stdexcept>

CrossFoot::CrossFoot()
{
    initTable();
}

void CrossFoot::calculate(QString in)
{
    in = in.toLower();
    unsigned sum = 0;
    for (QString::const_iterator it = in.begin(); it != in.end(); ++it)
    {
        QChar ch (*it);
        try {
            sum += _table.at(ch);
        } catch (std::out_of_range) {
            std::cout << "Unsupported character: \"" << ch.toLatin1() << "\"";
        }

    }
    QString res = QString::number(sum);
    _history.append("->" + res);
    emit updateStatus("Magic numbers: " + _history);
    if (res.length() == 1)
    {
        emit result(_lastValue = QString::number(sum));
        return;
    }
    calculate(res);
}

void CrossFoot::saveLastValue()
{
    emit addToList(_lastName + "=" + _lastValue);
}

void CrossFoot::initTable()
{
    _table['1'] = _table['a'] = _table['j'] = _table['s'] = 1;
    _table['2'] = _table['b'] = _table['k'] = _table['t'] = _table[246] = _table[63] = 2; //ö, ß
    _table['3'] = _table['c'] = _table['l'] = _table['u'] = 3; //
    _table['4'] = _table['d'] = _table['m'] = _table['v'] = 4;
    _table['5'] = _table['e'] = _table['n'] = _table['w'] = 5;
    _table['6'] = _table['f'] = _table['o'] = _table['x'] = _table[228] = 6; // ä 228
    _table['7'] = _table['g'] = _table['p'] = _table['y'] = 7;
    _table['8'] = _table['h'] = _table['q'] = _table['z'] = _table[252] = 8;// ü 252
    _table['9'] = _table['i'] = _table['r'] = 9;
}

