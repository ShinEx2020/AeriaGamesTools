/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "EdenEternalTool.hpp"

EdenEternalTool::EdenEternalTool(QWidget *parent) : QWidget(parent)
{
    createObjects();
    createConnexions();
    createConfigTab();
    createInterface();
}

void EdenEternalTool::createObjects()
{
    mPathsSettings      = new Settings;

    //CONFIGS
    m_systemWid         = new SystemTab;
    m_gameWid           = new GameplayTab;
    m_configsTbw        = new QTabWidget;
    m_applyBtn          = new QPushButton;
    m_cancelBtn         = new QPushButton;
    m_buttonsHbx        = new QHBoxLayout;
    m_configsVbx        = new QVBoxLayout;
    //PRIMARY
    m_themeWidget       = new ThemeTab(mPathsSettings->gamePath(Settings::GamePath::Eden).toString());
    m_configsWid        = new QWidget;
    m_repairWidget      = new DiagnoticsTab;
    m_edenPrimaryTbw    = new QTabWidget;
    m_primaryVbx        = new QVBoxLayout;
}
void EdenEternalTool::createConnexions()
{
    connect(m_applyBtn, SIGNAL(clicked()), this, SLOT(applyAllSettings()));
    connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(loadAllSettings()));
}
void EdenEternalTool::createConfigTab()
{
    m_configsTbw->addTab(m_systemWid, QIcon(":/icons/tabs/sys"), "Système");
    m_configsTbw->addTab(m_gameWid, QIcon(":/icons/tabs/game"), "Gameplay");
    m_configsTbw->setObjectName("mTab");

    m_applyBtn->setText("Appliquer");
    m_applyBtn->setObjectName("greenButton");
    m_applyBtn->setFixedSize(140, 25);

    m_cancelBtn->setText("Annuler");
    m_cancelBtn->setObjectName("redButton");
    m_cancelBtn->setFixedSize(140, 25);

    m_buttonsHbx->addWidget(m_applyBtn);
    m_buttonsHbx->addWidget(m_cancelBtn);

    m_configsVbx->addWidget(m_configsTbw);
    m_configsVbx->addLayout(m_buttonsHbx);

    m_configsWid->setLayout(m_configsVbx);
}
void EdenEternalTool::createInterface()
{
    m_edenPrimaryTbw->addTab(m_themeWidget, "Themes");
    m_edenPrimaryTbw->addTab(m_configsWid, "Configs");
    m_edenPrimaryTbw->addTab(m_repairWidget, "Diagnostics");
    m_edenPrimaryTbw->setObjectName("mTab");

    m_primaryVbx->addWidget(m_edenPrimaryTbw);

    setLayout(m_primaryVbx);
    setContentsMargins(-9, 0, -9, -9);
}

//SLOTS

void EdenEternalTool::loadAllSettings()
{
    m_systemWid->loadSettings();
    m_gameWid->loadSettings();
}
void EdenEternalTool::applyAllSettings()
{
    m_systemWid->applySettings();
    m_gameWid->applySettings();
}
