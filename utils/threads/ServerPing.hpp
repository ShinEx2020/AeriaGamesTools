#ifndef SERVERPING_H
#define SERVERPING_H

#include <QtWidgets>

class ServerPing : public QThread
{
    Q_OBJECT
public:
    ServerPing(QString ip, QString count = "1");

    void run();

signals:
    void endPing(int);

private:
    QProcess    *m_pingPro;

    QString     m_count;
    QString     m_output;
    QString     m_adress;

    int         m_ping;
};

#endif // SERVERPING_H
