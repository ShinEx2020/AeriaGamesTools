/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "RescueTab.hpp"

RescueTab::RescueTab(QWidget *parent) : QWidget(parent)
{
    logsGroup();
    nlsGroup();

    QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(m_logsGrp);
        vbox->addWidget(m_nlsGrp);

    setLayout(vbox);
}

bool RescueTab::nlsExist(QString filename)
{
    QFile *file = new QFile("C:/Windows/System32/"+filename);

    if(file->exists())
        return true;
    else
        return false;
}

void RescueTab::logsGroup()
{
    m_logsSha = new LogShare;

    QHBoxLayout *hbbox = new QHBoxLayout;
        hbbox->addWidget(m_logsSha);

    m_logsGrp = new QGroupBox("Logs du jeu");
    m_logsGrp->setLayout(hbbox);
    m_logsGrp->setFixedWidth(300);
}

void RescueTab::nlsGroup()
{
    m_nlsWid = new NlsStatut("936");
    m_nlsWid2 = new NlsStatut("950");
    m_nlsWid3 = new NlsStatut("10002");
    m_nlsWid4 = new NlsStatut("10008");

    QVBoxLayout *vbox = new QVBoxLayout;
        vbox->setAlignment(Qt::AlignHCenter);
        vbox->addWidget(m_nlsWid);
        vbox->addWidget(m_nlsWid2);
        vbox->addWidget(m_nlsWid3);
        vbox->addWidget(m_nlsWid4);

    m_nlsGrp = new QGroupBox("Error Load DB");
        m_nlsGrp->setLayout(vbox);
        m_nlsGrp->setFixedSize(300, 220);
}
