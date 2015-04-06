#include "ServerPing.hpp"

ServerPing::ServerPing(QString ip, QString count)
{
    m_adress = ip;
    m_count = count;
}

void ServerPing::run()
{
    m_pingPro = new QProcess;
        m_pingPro->start("ping -n "+m_count+" "+m_adress);
        m_pingPro->waitForFinished();

    m_output = m_pingPro->readAll();

    if(m_output.contains("Moyenne"))
    {
        QString ff = m_output.section("Moyenne = ", 1, 1);
        m_ping = ff.section("ms", 0, 0).toInt();
    }
    else
    {
        m_ping = -1;
    }

    emit endPing(m_ping);
}
