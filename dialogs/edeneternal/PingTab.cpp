#include "PingTab.hpp"

PingTab::PingTab()
{
    QLabel *m_alarmLab = new QLabel("Alarme");
        m_alarmLab->setFixedWidth(50);
    m_alarmSli = new QSlider(Qt::Horizontal);
        m_alarmSli->setRange(0, 1);
        m_alarmSli->setFixedWidth(30);
        m_alarmSli->setObjectName("switchSlider");
    QPushButton *m_pingButton = new QPushButton("Vérifier");
        m_pingButton->setFixedSize(100, 20);
        m_pingButton->setStyleSheet("QPushButton{background: #922;}");

    QHBoxLayout *m_controlGrid = new QHBoxLayout;
        m_controlGrid->addWidget(m_alarmLab, 0,  Qt::AlignLeft);
        m_controlGrid->addWidget(m_alarmSli, 0,Qt::AlignLeft);
        m_controlGrid->addWidget(m_pingButton, 1, Qt::AlignRight);

    QGroupBox *m_control = new QGroupBox("Contrôle");
        m_control->setFixedSize(450,100);
        m_control->setLayout(m_controlGrid);

//-----------------------------------------------------------
    m_log1 = new ServerStatut("Login #1");
    m_log2 = new ServerStatut("Login #2");

    QGridLayout *loghbox3 = new QGridLayout;
        loghbox3->addWidget(m_log1, 0, 0, Qt::AlignHCenter);
        loghbox3->addWidget(m_log2, 0, 1, Qt::AlignHCenter);

    QGroupBox *login = new QGroupBox("Authentification");
        login->setFixedSize(450,90);
        login->setLayout(loghbox3);

//-----------------------------------------------------------
    chara1 = new ServerStatut("Personnage #1");
    world1 = new ServerStatut("Monde #1");

    chara2 = new ServerStatut("Personnage #2");
    world2 = new ServerStatut("Monde #2");

    chara3 = new ServerStatut("Personnage #3");
    world3 = new ServerStatut("Monde #3");

    QGridLayout *loghbox4 = new QGridLayout;
        loghbox4->addWidget(chara1, 0, 0,Qt::AlignHCenter);
        loghbox4->addWidget(world1, 0, 1,Qt::AlignHCenter);
        loghbox4->addWidget(chara2, 1, 0,Qt::AlignHCenter);
        loghbox4->addWidget(world2, 1, 1,Qt::AlignHCenter);
        loghbox4->addWidget(chara3, 2, 0,Qt::AlignHCenter);
        loghbox4->addWidget(world3, 2, 1,Qt::AlignHCenter);

    QGroupBox *celestia = new QGroupBox("Celestia");
        celestia->setLayout(loghbox4);
        celestia->setFixedWidth(450);
//-----------------------------------------------------------
    m_aChar1 = new ServerStatut("Personnage #1");
    m_aWorld1 = new ServerStatut("Monde #1");

    m_aChar2 = new ServerStatut("Personnage #2");
    m_aWorld2 = new ServerStatut("Monde #2");

    m_aChar3 = new ServerStatut("Personnage #3");
    m_aWorld3 = new ServerStatut("Monde #3");

    m_aChar4 = new ServerStatut("Personnage #4");
    m_aWorld4 = new ServerStatut("Monde #4");

    m_aChar5 = new ServerStatut("Personnage #5");
    m_aWorld5 = new ServerStatut("Monde #5");

    m_aChar6 = new ServerStatut("Personnage #6");
    m_aWorld6 = new ServerStatut("Monde #6");


    QGridLayout *m_albionGrid = new QGridLayout;
        m_albionGrid->addWidget(m_aChar1, 0, 0, Qt::AlignHCenter);
        m_albionGrid->addWidget(m_aWorld1, 0, 1, Qt::AlignHCenter);
        m_albionGrid->addWidget(m_aChar2, 1, 0, Qt::AlignHCenter);
        m_albionGrid->addWidget(m_aWorld2, 1, 1, Qt::AlignHCenter);
        m_albionGrid->addWidget(m_aChar3, 2, 0, Qt::AlignHCenter);
        m_albionGrid->addWidget(m_aWorld3, 2, 1, Qt::AlignHCenter);
        m_albionGrid->addWidget(m_aChar4, 3, 0, Qt::AlignHCenter);
        m_albionGrid->addWidget(m_aWorld4, 3, 1, Qt::AlignHCenter);
        m_albionGrid->addWidget(m_aChar5, 4, 0, Qt::AlignHCenter);
        m_albionGrid->addWidget(m_aWorld5, 4, 1, Qt::AlignHCenter);
        m_albionGrid->addWidget(m_aChar6, 5, 0, Qt::AlignHCenter);
        m_albionGrid->addWidget(m_aWorld6, 5, 1, Qt::AlignHCenter);

    QGroupBox *albion = new QGroupBox("Albion");
        albion->setLayout(m_albionGrid);
        albion->setFixedWidth(450);
//-----------------------------------------------------------
    QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(m_control);
        vbox->addWidget(login);
        vbox->addWidget(celestia);

    QHBoxLayout *hbox = new QHBoxLayout;
        hbox->addLayout(vbox);
        hbox->addWidget(albion);

    connect(m_alarmSli, SIGNAL(valueChanged(int)), this, SLOT(alarmSlid(int)));
    connect(m_pingButton, SIGNAL(clicked()), this, SLOT(launchPing()));

    alarmSlid(m_alarmSli->value());

    launchPing();

    setLayout(hbox);

    m_pingTimer = new QTimer();
    m_pingTimer->start(5000);
    connect(m_pingTimer, SIGNAL(timeout()), this, SLOT(launchPing()));
}

void PingTab::alarmSlid(int val)
{
    QFile *qssSliderOn = new QFile(":/qss/slider_on");
        qssSliderOn->open(QIODevice::ReadOnly | QIODevice::Text);
    QString strSliderOn = qssSliderOn->readAll();

    QFile *qssSliderOff = new QFile(":/qss/slider_off");
        qssSliderOff->open(QIODevice::ReadOnly | QIODevice::Text);
    QString strSliderOff = qssSliderOff->readAll();

    if(val == 1)
    {
        m_alarmSli->setStyleSheet(strSliderOn);
        qDebug()<<"1";
    }
    else if(val == 0)
    {
        m_alarmSli->setStyleSheet(strSliderOff);
        qDebug()<<"0";
    }
}

void PingTab::launchPing()
{
    m_pingLoginTrd = new ServerPing("213.203.212.100");
    m_pingLoginTrd->start();
    connect(m_pingLoginTrd, SIGNAL(endPing(int)), this, SLOT(readPing(int)));


    m_pingCelestia_13Trd = new ServerPing("213.203.212.101");
    m_pingCelestia_13Trd->start();
    connect(m_pingCelestia_13Trd, SIGNAL(endPing(int)), this, SLOT(readPing(int)));

    m_pingCelestia_2Trd = new ServerPing("213.203.212.102");
    m_pingCelestia_2Trd->start();
    connect(m_pingCelestia_2Trd, SIGNAL(endPing(int)), this, SLOT(readPing(int)));


    m_pingAlbion_135Trd = new ServerPing("213.203.212.103");
    m_pingAlbion_135Trd->start();
    connect(m_pingAlbion_135Trd, SIGNAL(endPing(int)), this, SLOT(readPing(int)));

    m_pingAlbion_246Trd = new ServerPing("213.203.212.104");
    m_pingAlbion_246Trd->start();
    connect(m_pingAlbion_246Trd, SIGNAL(endPing(int)), this, SLOT(readPing(int)));
}

void PingTab::readPing(int ping)
{
    if(sender() == m_pingLoginTrd)
    {
        m_log1->setPing(ping);
        m_log2->setPing(ping);
    }
    if(sender() == m_pingCelestia_13Trd)
    {
            chara1->setPing(ping);
            world1->setPing(ping);
            chara3->setPing(ping);
            world3->setPing(ping);
    }
    if(sender() == m_pingCelestia_2Trd)
    {
        chara2->setPing(ping);
        world2->setPing(ping);
    }
    if(sender() == m_pingAlbion_135Trd)
    {
        m_aChar1->setPing(ping);
        m_aWorld1->setPing(ping);

        m_aChar3->setPing(ping);
        m_aWorld3->setPing(ping);

        m_aChar5->setPing(ping);
        m_aWorld5->setPing(ping);
    }
    if(sender() == m_pingAlbion_246Trd)
    {
        m_aChar2->setPing(ping);
        m_aWorld2->setPing(ping);

        m_aChar4->setPing(ping);
        m_aWorld4->setPing(ping);

        m_aChar6->setPing(ping);
        m_aWorld6->setPing(ping);
    }
}
