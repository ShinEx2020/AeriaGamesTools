/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "NlsStatut.hpp"

NlsStatut::NlsStatut(QString filename, QWidget *parent) : QWidget(parent)
{
    m_nameLabel = new QLabel(filename);
        m_nameLabel->setFixedSize(80,30);
        m_nameLabel->setObjectName("nameLab");
        m_nameLabel->setAlignment(Qt::AlignCenter);
    m_filPush = new QPushButton;
        m_filPush->setFixedSize(50,30);
        m_filPush->setObjectName("filPush");
    m_regPush = new QPushButton;
        m_regPush->setFixedSize(50,30);
        m_regPush->setObjectName("regPush");
    m_checkLabel = new QLabel(filename);
        m_checkLabel->setFixedSize(80,30);
        m_checkLabel->setObjectName("checkLab");
        m_checkLabel->setAlignment(Qt::AlignCenter);

    QFile *file = new QFile("C:/Windows/System32/c_"+filename+".nls");

    if(file->exists())
    {
        m_filPush->setIcon(QIcon(":icons/tabs/green"));
        m_exFile = true;
    }
    else
    {
        m_filPush->setIcon(QIcon(":icons/tabs/red"));
        m_exFile = false;
    }

    QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Nls\\CodePage", QSettings::NativeFormat);

    if(settings->contains(filename))
    {
        m_regPush->setIcon(QIcon(":icons/tabs/green"));
        m_exReg = true;
    }
    else
    {
        m_regPush->setIcon(QIcon(":icons/tabs/red"));
        m_exReg = false;
    }

    if(m_exFile && m_exReg)
    {
        m_checkLabel->setText("GOOD");
        m_checkLabel->setStyleSheet("#checkLab{background: #282;}");
    }
    else
    {
        m_checkLabel->setText("BAD");
        m_checkLabel->setStyleSheet("#checkLab{background: #822;}");
    }


    QHBoxLayout *hbox = new QHBoxLayout;
        hbox->setSpacing(0);
        hbox->addWidget(m_nameLabel);
        hbox->addWidget(m_filPush);
        hbox->addWidget(m_regPush);
        hbox->addWidget(m_checkLabel);

    setLayout(hbox);
    setFixedWidth(sizeHint().width());

    setStyleSheet("#nameLab{font-weight: bold; color: white; background: #333; border: 1px solid white; border-top-left-radius: 13px; border-bottom-left-radius: 13px;}"
                    "#filPush{background: #666; border-radius: none; border: 1px solid white; margin-bottom: 2px;}"
                    "#regPush{background: #666; border-radius: none; border: 1px solid white; margin-bottom: 2px;}"
                    "#checkLab{font-weight: bold; background: white; border: 1px solid white; border-top-right-radius: 13px; border-bottom-right-radius: 13px;}");
}
