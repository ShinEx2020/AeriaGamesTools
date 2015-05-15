/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "NlsStatut.hpp"

NlsStatut::NlsStatut() : QGroupBox()
{
    createObjects();
    createInterface();

    checkFile();
    checkReg();
}

void NlsStatut::createObjects()
{
    m_nlsReg        = new QSettings("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Nls\\CodePage", QSettings::NativeFormat);

    m_fileIconBtn   = new QPushButton;
    m_regIconBtn    = new QPushButton;
    m_936FileBtn    = new QPushButton;
    m_936RegBtn     = new QPushButton;
    m_950FileBtn    = new QPushButton;
    m_950RegBtn     = new QPushButton;
    m_10002FileBtn  = new QPushButton;
    m_10002RegBtn   = new QPushButton;
    m_10008FileBtn  = new QPushButton;
    m_10008RegBtn   = new QPushButton;

    m_nlsGrd        = new QGridLayout;
}
void NlsStatut::createConnexions()
{

}
void NlsStatut::createInterface()
{
    m_fileIconBtn->setIcon(QIcon(":/icons/file"));
    m_fileIconBtn->setObjectName("noBorder");

    m_regIconBtn->setIcon(QIcon(":/icons/reg"));
    m_regIconBtn->setObjectName("noBorder");

    m_936FileBtn->setObjectName("noBorder");
    m_936RegBtn->setObjectName("noBorder");

    m_950FileBtn->setObjectName("noBorder");
    m_950RegBtn->setObjectName("noBorder");

    m_10002FileBtn->setObjectName("noBorder");
    m_10002RegBtn->setObjectName("noBorder");

    m_10008FileBtn->setObjectName("noBorder");
    m_10008RegBtn->setObjectName("noBorder");

    m_nlsGrd->addWidget(m_fileIconBtn,0,1);
    m_nlsGrd->addWidget(m_regIconBtn,0,2);
    m_nlsGrd->addWidget(new QLabel("936"),1,0, Qt::AlignHCenter);
    m_nlsGrd->addWidget(m_936FileBtn,1,1);
    m_nlsGrd->addWidget(m_936RegBtn,1,2);
    m_nlsGrd->addWidget(new QLabel("950"),2,0, Qt::AlignHCenter);
    m_nlsGrd->addWidget(m_950FileBtn,2,1);
    m_nlsGrd->addWidget(m_950RegBtn,2,2);
    m_nlsGrd->addWidget(new QLabel("10002"),3,0, Qt::AlignHCenter);
    m_nlsGrd->addWidget(m_10002FileBtn,3,1);
    m_nlsGrd->addWidget(m_10002RegBtn,3,2);
    m_nlsGrd->addWidget(new QLabel("10008"),4,0, Qt::AlignHCenter);
    m_nlsGrd->addWidget(m_10008FileBtn,4,1);
    m_nlsGrd->addWidget(m_10008RegBtn,4,2);

    setTitle("NLS Checker");
    setLayout(m_nlsGrd);
    setFixedSize(280, 200);
}

void NlsStatut::checkFile()
{
    for(int i=1; i<=4; i++)
    {
        if(QFile("C:/Windows/System32/c_"+qobject_cast<QLabel *>(m_nlsGrd->itemAtPosition(i,0)->widget())->text()+".nls").exists())
            qobject_cast<QPushButton*>(m_nlsGrd->itemAtPosition(i,1)->widget())->setIcon(QIcon(":icons/good"));
        else
            qobject_cast<QPushButton*>(m_nlsGrd->itemAtPosition(i,1)->widget())->setIcon(QIcon(":icons/bad"));
    }
}
void NlsStatut::checkReg()
{
    for(int i=1; i<=4; i++)
    {
        if(m_nlsReg->contains(qobject_cast<QLabel *>(m_nlsGrd->itemAtPosition(i,0)->widget())->text()))
            qobject_cast<QPushButton*>(m_nlsGrd->itemAtPosition(i,2)->widget())->setIcon(QIcon(":icons/good"));
        else
            qobject_cast<QPushButton*>(m_nlsGrd->itemAtPosition(i,2)->widget())->setIcon(QIcon(":icons/bad"));
    }
}
