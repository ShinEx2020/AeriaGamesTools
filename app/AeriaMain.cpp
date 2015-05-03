/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "AeriaMain.hpp"

AeriaMain::AeriaMain(QWidget *parent) : QWidget(parent)
{
    createObjects();
    createConnections();
    createTitleBar();
    createInfosBar();
    createHeaderWid();
    createTabWidget();
    createSettings();
}

void AeriaMain::createObjects()
{
    m_titleBtn          = new TPushButton(this);
    m_minimizeBtn       = new QPushButton;
    m_closeBtn          = new QPushButton;
    m_titleBarHbx       = new QHBoxLayout;

    m_updatesDlg        = new Updates;
    m_settingsDlg       = new Settings;
    m_aboutDlg          = new About;
    m_infosBarHbx       = new QHBoxLayout;

    m_headerVbx         = new QVBoxLayout;
    m_headerWid         = new QWidget;

    m_MiscGeneralWid    = new MiscGeneralTool;
    m_EdenEternalWid    = new EdenEternalTool;
    m_AuraKingdomWid    = new AuraKingdomTool;
    m_S4LeagueWid       = new S4LeagueTool;
    m_GrandFantasiaWid  = new GrandFantasiaTool;
    m_WolfTeamWid       = new WolfTeamTool;
    m_ShaiyaWid         = new ShaiyaTool;
    m_AvaWid            = new AvaTool;
    m_TribesAscendWid   = new TribesAscendTool;
    m_MaestiaWid        = new MaestiaTool;
    m_EchoOfSoulWid     = new EchoOfSoulTool;
    m_mainTabWid        = new QTabWidget;

    mPathsFile          = new QFile;
    mPathsSettings      = new QSettings(mPathsFile->fileName(), QSettings::IniFormat);
    bar                 = new QProgressBar;
    qss                 = new QFile;

    m_mainLayout        = new QVBoxLayout;

    m_settingsBtn       = new QPushButton;
    m_updatesBtn        = new QPushButton;
    m_aboutBtn          = new QPushButton;
}

void AeriaMain::initSettings()
{
    m_EdenPath = mPathsSettings->value("Paths/EdenEternal").toString();
}

void AeriaMain::createSettings()
{
    m_mainLayout->addWidget(m_headerWid);
    m_mainLayout->addWidget(m_mainTabWid);
    m_mainLayout->setSpacing(0);

    mPathsFile->setFileName(QCoreApplication::applicationDirPath()+"/logs/paths.lst");
    mPathsFile->open(QIODevice::ReadOnly | QIODevice::Text);


    qss->setFileName(":/qss/style");
    qss->open(QIODevice::ReadOnly | QIODevice::Text);

    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(800, 595);
    setWindowTitle(m_titleBtn->text());
    setContentsMargins(-11, -12, -11, -11);
    setLayout(m_mainLayout);
    qApp->setStyleSheet(qss->readAll());
}

void AeriaMain::createTitleBar()
{
    m_titleBtn->setText("AERIA GAMES TOOLS");
    m_titleBtn->setFixedHeight(25);
    m_titleBtn->setObjectName("titleButton");
    m_titleBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    m_minimizeBtn->setText("-");
    m_minimizeBtn->setFixedSize(40, 25);
    m_minimizeBtn->setObjectName("minimizeButton");
    m_minimizeBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_closeBtn->setText("X");
    m_closeBtn->setFixedSize(40, 25);
    m_closeBtn->setObjectName("closeButton");
    m_closeBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_titleBarHbx->addWidget(m_titleBtn, 0);
    m_titleBarHbx->addWidget(m_minimizeBtn, 0, Qt::AlignRight);
    m_titleBarHbx->addWidget(m_closeBtn, 0, Qt::AlignRight);
    m_titleBarHbx->setSpacing(0);
}

void AeriaMain::createInfosBar()
{
    m_settingsBtn->setIcon(QIcon(":/icons/settings"));
    m_settingsBtn->setFixedSize(40, 25);
    m_settingsBtn->setObjectName("settingsButton");

    m_updatesBtn->setIcon(QIcon(":/icons/update"));
    m_updatesBtn->setFixedSize(40, 25);
    m_updatesBtn->setObjectName("updatesButton");

    m_aboutBtn->setIcon(QIcon(":/icons/info"));
    m_aboutBtn->setFixedSize(40, 25);
    m_aboutBtn->setObjectName("aboutButton");

    m_infosBarHbx->addWidget(m_updatesBtn, 1, Qt::AlignRight);
    m_infosBarHbx->addWidget(m_settingsBtn, 0, Qt::AlignRight);
    m_infosBarHbx->addWidget(m_aboutBtn, 0, Qt::AlignRight);
    m_infosBarHbx->setContentsMargins(0, 2, 10, 0);
    m_infosBarHbx->setSpacing(1);
}

void AeriaMain::createHeaderWid()
{
    m_headerVbx->addLayout(m_titleBarHbx);
    m_headerVbx->addLayout(m_infosBarHbx);
    m_headerVbx->setContentsMargins(0, 0, 0, -10);

    m_headerWid->setObjectName("headerWidget");
    m_headerWid->setLayout(m_headerVbx);
}

void AeriaMain::createTabWidget()
{
    m_mainTabWid->setTabPosition(QTabWidget::West);
    m_mainTabWid->addTab(m_MiscGeneralWid, QIcon(":/logos/misc"), "");
    m_mainTabWid->addTab(m_EdenEternalWid, QIcon(":/logos/eden"), "");
    m_mainTabWid->addTab(m_AuraKingdomWid, QIcon(":/logos/aura"), "");
    m_mainTabWid->addTab(m_S4LeagueWid, QIcon(":/logos/s4"), "");
    m_mainTabWid->addTab(m_GrandFantasiaWid, QIcon(":/logos/fanta"), "");
    m_mainTabWid->addTab(m_WolfTeamWid, QIcon(":/logos/wolf"), "");
    m_mainTabWid->addTab(m_ShaiyaWid, QIcon(":/logos/shaiya"), "");
    m_mainTabWid->addTab(m_AvaWid, QIcon(":/logos/ava"), "");
    m_mainTabWid->addTab(m_TribesAscendWid, QIcon(":/logos/tribes"), "");
    m_mainTabWid->addTab(m_MaestiaWid, QIcon(":/logos/maes"), "");
    m_mainTabWid->addTab(m_EchoOfSoulWid, QIcon(":/logos/eos"), "");
    m_mainTabWid->tabBar()->setObjectName("mTabBar");
    m_mainTabWid->tabBar()->setIconSize(QSize(60,60));
    m_mainTabWid->setObjectName("mTabMain");
}

void AeriaMain::createConnections()
{
    connect(m_minimizeBtn, SIGNAL(clicked()), this, SLOT(minimizeTool()));
    connect(m_closeBtn, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(m_settingsBtn, SIGNAL(clicked()), m_settingsDlg, SLOT(show()));
    connect(m_updatesBtn, SIGNAL(clicked()), m_updatesDlg, SLOT(show()));
    connect(m_aboutBtn, SIGNAL(clicked()), m_aboutDlg, SLOT(show()));
}

//SLOTS
void AeriaMain::minimizeTool()
{
    setWindowState(Qt::WindowMinimized);
}

//EVENTS
void AeriaMain::moveEvent(QMoveEvent *event)
{
    if(m_MiscGeneralWid->isVisible())
    {
        m_MiscGeneralWid->move(event->pos().x() - m_MiscGeneralWid->width(), event->pos().y());
    }
}
