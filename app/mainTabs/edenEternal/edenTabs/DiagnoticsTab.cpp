/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "DiagnoticsTab.hpp"

DiagnoticsTab::DiagnoticsTab(QWidget *parent) : QWidget(parent)
{
    logsGroup();
    nlsGroup();

    QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(m_logsSha);
        vbox->addWidget(m_nlsGrp);

    setLayout(vbox);
}

bool DiagnoticsTab::nlsExist(QString filename)
{
    QFile *file = new QFile("C:/Windows/System32/"+filename);

    if(file->exists())
        return true;
    else
        return false;
}

void DiagnoticsTab::logsGroup()
{
    m_logsSha = new LogShare;
}

void DiagnoticsTab::nlsGroup()
{
    m_nlsGrp = new NlsStatut;
}
