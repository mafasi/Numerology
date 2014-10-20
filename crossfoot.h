#ifndef CROSSFOOT_H
#define CROSSFOOT_H

#include <string>
#include <map>

#include <QObject>

class CrossFoot : public QObject
{
    Q_OBJECT

public:
    CrossFoot();
signals:
    void result(QString sum);
    void addToList(QString lastValue);
    void updateStatus(QString);

public slots:
    void calculate(QString in);
    void setName(QString name) { _lastName = name; }
    void clearHistory(QString name) { _history = name + "-"; }
    void saveLastValue();

protected:
    void initTable();

private:
    std::map<QChar, unsigned> _table;
    QString _lastValue;
    QString _lastName;
    QString _history;
};

#endif // CROSSFOOT_H
