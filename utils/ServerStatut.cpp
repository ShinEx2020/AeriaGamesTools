#include "ServerStatut.hpp"

ServerStatut::ServerStatut(QString name, QWidget *parent) : QWidget(parent)
{
    m_servname = name;

    m_ledLab = new QLabel;
    m_ledLab->setPixmap(QPixmap(":/icons/tabs/yellow"));
    m_nameLab = new QLabel(m_servname);
    m_pingLab = new QLabel("Wait...");

    QHBoxLayout *loghbox = new QHBoxLayout;
        loghbox->addWidget(m_ledLab,0);
        loghbox->addWidget(m_nameLab,0);
        loghbox->addWidget(m_pingLab,1);

    setLayout(loghbox);
    setFixedHeight(36);
}

void ServerStatut::setStatut(bool statut)
{
    if(statut)
        m_ledLab->setPixmap(QPixmap(":/icons/tabs/green"));
    else
        m_ledLab->setPixmap(QPixmap(":/icons/tabs/red"));
}

void ServerStatut::setName(QString name)
{
    m_servname = name;

    m_nameLab->setText(m_servname);
}

void ServerStatut::setPing(int ping)
{
    m_servping = ping;

    if(ping == -1)
    {
        setStatut(false);
        m_pingLab->setText("Offline");
    }
    else
    {
        setStatut(true);
        m_pingLab->setText(QString::number(m_servping)+" ms");
    }
}
