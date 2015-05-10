/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "GameplayTab.hpp"

GameplayTab::GameplayTab()
{
    createObjects();
    createConnexions();
    createSocialGroup();
    createInterfaceGroup();
    createMiscGroup();
    createInterface();

    switchStyle();
    loadSettings();
}

void GameplayTab::createObjects()
{
    mPathsSettings  = new Settings;
    mEdenSettings   = new QSettings(mPathsSettings->gamePath(Settings::GamePath::Eden).toString()+"/client.ini", QSettings::IniFormat);

//GROUPS
    //INTERFACE
    m_name          = new QPushButton;
    m_sname         = new QSlider;
    m_npc           = new QPushButton;
    m_snpc          = new QSlider;
    m_guild         = new QPushButton;
    m_sguild        = new QSlider;
    m_health        = new QPushButton;
    m_shealth       = new QSlider;
    m_title         = new QPushButton;
    m_stitle        = new QSlider;
    m_dammages      = new QPushButton;
    m_sdammages     = new QSlider;
    m_vital         = new QPushButton;
    m_svital        = new QSlider;
    m_recbattle     = new QPushButton;
    m_srecbattle    = new QSlider;
    m_guildin       = new QPushButton;
    m_sguildin      = new QSlider;
    m_gellyeffect   = new QPushButton;
    m_sgellyeffect  = new QSlider;
    uiLayout        = new QGridLayout;
    uiGroup         = new QGroupBox;
    //SOCIAL
    m_dectrade      = new QPushButton;
    m_sdectrade     = new QSlider;
    m_decduel       = new QPushButton;
    m_sdecduel      = new QSlider;
    m_decgroup      = new QPushButton;
    m_sdecgroup     = new QSlider;
    m_denysearch    = new QPushButton;
    m_sdenysearch   = new QSlider;
    m_tandem        = new QPushButton;
    m_standem       = new QSlider;
    m_groupevent    = new QPushButton;
    m_sgroupevent   = new QSlider;
    socialLayout    = new QGridLayout;
    socialGroup     = new QGroupBox;
    //MISC
    m_cast          = new QPushButton;
    m_scast         = new QSlider;
    m_reverse       = new QPushButton;
    m_sreverse      = new QSlider;
    m_critical      = new QPushButton;
    m_scritical     = new QSlider;
    m_folcamera     = new QPushButton;
    m_sfolcamera    = new QSlider;
    m_clickm        = new QPushButton;
    m_sclickm       = new QSlider;
    m_leftclic      = new QPushButton;
    m_sleftclic     = new QSlider;
    miscLayout      = new QGridLayout;
    miscGroup       = new QGroupBox;
//

//LAYOUTS
    m_rightVbx      = new QVBoxLayout;
    m_gameplayHbx   = new QHBoxLayout;
//
}
void GameplayTab::createConnexions()
{
    //INTERFACE
    connect(m_sname, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_snpc, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sguild, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_shealth, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_stitle, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sdammages, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_svital, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_srecbattle, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sguildin, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sgellyeffect, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    //SOCIAL
    connect(m_sdectrade, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sdecduel, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sdecgroup, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sdenysearch, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_standem, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sgroupevent, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    //MISC
    connect(m_scast, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sreverse, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_scritical, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sfolcamera, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sclickm, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sleftclic, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));

//----------------------------------- BULLES D'INFOS -----------------------------------------

    //INTERFACE
    connect(m_name, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_npc, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_guild, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_health, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_title, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_dammages, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_vital, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_recbattle, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_guildin, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_gellyeffect, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //SOCIAL
    connect(m_dectrade, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_decduel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_decgroup, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_denysearch, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_tandem, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_groupevent, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //MISC
    connect(m_cast, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_reverse, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_critical, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_folcamera, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_clickm, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_leftclic, SIGNAL(clicked()), this, SLOT(hoverInfos()));
}
void GameplayTab::createInterfaceGroup()
{
    m_name->setText(tr("Nom du Pers."));
    m_sname->setOrientation(Qt::Horizontal);
    m_npc->setText(tr("Noms des PNJs"));
    m_snpc->setOrientation(Qt::Horizontal);
    m_guild->setText(tr("Noms de Guildes"));
    m_sguild->setOrientation(Qt::Horizontal);
    m_health->setText(tr("Barre de vie"));
    m_shealth->setOrientation(Qt::Horizontal);
    m_title->setText(tr("Titre"));
    m_stitle->setOrientation(Qt::Horizontal);
    m_dammages->setText(tr("Dégats"));
    m_sdammages->setOrientation(Qt::Horizontal);
    m_vital->setText(tr("Vital"));
    m_svital->setOrientation(Qt::Horizontal);
    m_recbattle->setText(tr("Log de combat"));
    m_srecbattle->setOrientation(Qt::Horizontal);
    m_guildin->setText(tr("Ins de guilde"));
    m_sguildin->setOrientation(Qt::Horizontal);
    m_gellyeffect->setText(tr("Effet gellé"));
    m_sgellyeffect->setOrientation(Qt::Horizontal);

    uiLayout->addWidget(m_name, 0, 0);
    uiLayout->addWidget(m_sname, 0, 1);
    uiLayout->addWidget(m_npc, 0, 2);
    uiLayout->addWidget(m_snpc, 0, 3);
    uiLayout->addWidget(m_guild, 1, 0);
    uiLayout->addWidget(m_sguild, 1, 1);
    uiLayout->addWidget(m_health, 1, 2);
    uiLayout->addWidget(m_shealth, 1, 3);
    uiLayout->addWidget(m_title, 2, 0);
    uiLayout->addWidget(m_stitle, 2, 1);
    uiLayout->addWidget(m_dammages, 2, 2);
    uiLayout->addWidget(m_sdammages, 2, 3);
    uiLayout->addWidget(m_vital, 3, 0);
    uiLayout->addWidget(m_svital, 3, 1);
    uiLayout->addWidget(m_recbattle, 3, 2);
    uiLayout->addWidget(m_srecbattle, 3, 3);
    uiLayout->addWidget(m_guildin, 4, 0);
    uiLayout->addWidget(m_sguildin, 4, 1);
    uiLayout->addWidget(m_gellyeffect, 4, 2);
    uiLayout->addWidget(m_sgellyeffect, 4, 3);

    uiGroup->setTitle("Interface");
    uiGroup->setLayout(uiLayout);
}
void GameplayTab::createSocialGroup()
{
    m_dectrade->setText(tr("Bloquer échanges"));
    m_sdectrade->setOrientation(Qt::Horizontal);
    m_decduel->setText(tr("Bloquer duels"));
    m_sdecduel->setOrientation(Qt::Horizontal);
    m_decgroup->setText(tr("Bloquer groupes"));
    m_sdecgroup->setOrientation(Qt::Horizontal);
    m_denysearch->setText(tr("Bloquer dispo."));
    m_sdenysearch->setOrientation(Qt::Horizontal);
    m_tandem->setText(tr("Bloquer tandems"));
    m_standem->setOrientation(Qt::Horizontal);
    m_groupevent->setText(tr("Groupes éven."));
    m_sgroupevent->setOrientation(Qt::Horizontal);

    socialLayout->addWidget(m_dectrade, 0, 0);
    socialLayout->addWidget(m_sdectrade, 0, 1);
    socialLayout->addWidget(m_decduel, 0, 2);
    socialLayout->addWidget(m_sdecduel, 0, 3);
    socialLayout->addWidget(m_decgroup, 1, 0);
    socialLayout->addWidget(m_sdecgroup, 1, 1);
    socialLayout->addWidget(m_denysearch, 1, 2);
    socialLayout->addWidget(m_sdenysearch, 1, 3);
    socialLayout->addWidget(m_tandem, 2, 0);
    socialLayout->addWidget(m_standem, 2, 1);
    socialLayout->addWidget(m_groupevent, 2, 2);
    socialLayout->addWidget(m_sgroupevent, 2, 3);

    socialGroup->setTitle("Social");
    socialGroup->setLayout(socialLayout);
}
void GameplayTab::createMiscGroup()
{
    m_cast->setText(tr("Invo. sur soi"));
    m_scast->setOrientation(Qt::Horizontal);
    m_reverse->setText(tr("Inv. caméra"));
    m_sreverse->setOrientation(Qt::Horizontal);
    m_critical->setText(tr("Coup crit;"));
    m_scritical->setOrientation(Qt::Horizontal);
    m_folcamera->setText(tr("Suiv. camera"));
    m_sfolcamera->setOrientation(Qt::Horizontal);
    m_clickm->setText(tr("Dépl. par clic"));
    m_sclickm->setOrientation(Qt::Horizontal);
    m_leftclic->setText(tr("Clic gauche"));
    m_sleftclic->setOrientation(Qt::Horizontal);

    miscLayout->addWidget(m_cast, 0, 0);
    miscLayout->addWidget(m_scast, 0, 1);
    miscLayout->addWidget(m_reverse, 0, 2);
    miscLayout->addWidget(m_sreverse, 0, 3);
    miscLayout->addWidget(m_critical, 1, 0);
    miscLayout->addWidget(m_scritical, 1, 1);
    miscLayout->addWidget(m_folcamera, 1, 2);
    miscLayout->addWidget(m_sfolcamera, 1, 3);
    miscLayout->addWidget(m_clickm, 2, 0);
    miscLayout->addWidget(m_sclickm, 2, 1);
    miscLayout->addWidget(m_leftclic, 2, 2);
    miscLayout->addWidget(m_sleftclic, 2, 3);

    miscGroup->setTitle("Autres");
    miscGroup->setLayout(miscLayout);
}
void GameplayTab::createInterface()
{
    m_rightVbx->addWidget(socialGroup);
    m_rightVbx->addWidget(miscGroup);

    m_gameplayHbx->addWidget(uiGroup);
    m_gameplayHbx->addLayout(m_rightVbx);

    setLayout(m_gameplayHbx);
}

void GameplayTab::switchStyle()
{
    //INTERFACE
    slider.append(m_sname);
    slider.append(m_snpc);
    slider.append(m_sguild);
    slider.append(m_shealth);
    slider.append(m_stitle);
    slider.append(m_sdammages);
    slider.append(m_svital);
    slider.append(m_srecbattle);
    slider.append(m_sguildin);
    slider.append(m_sgellyeffect);
    //SOCIAL
    slider.append(m_sdectrade);
    slider.append(m_sdecduel);
    slider.append(m_sdecgroup);
    slider.append(m_sdenysearch);
    slider.append(m_standem);
    slider.append(m_sgroupevent);
    //MISC
    slider.append(m_scast);
    slider.append(m_sreverse);
    slider.append(m_scritical);
    slider.append(m_sfolcamera);
    slider.append(m_sclickm);
    slider.append(m_sleftclic);

    foreach (QSlider* i_slid, slider)
    {
        i_slid->setRange(0, 1);
        i_slid->setFixedWidth(30);

        if(i_slid->value() == 1)
            i_slid->setObjectName("switchSlider1");
        else
            i_slid->setObjectName("switchSlider0");
    }
}

//SLOTS
void GameplayTab::hoverInfos()
{
    //INTERFACE
    if(sender() == m_name)
        QToolTip::showText(m_name->mapToGlobal(QPoint()), "Active/Desactive l'affichage du nom du personnage");
    else if(sender() == m_npc)
        QToolTip::showText(m_npc->mapToGlobal(QPoint()), "Active/Desactive les noms des pnj");
    else if(sender() == m_guild)
        QToolTip::showText(m_guild->mapToGlobal(QPoint()), "Active/Desactive l'affichage du nom de guilde");
    else if(sender() == m_health)
        QToolTip::showText(m_health->mapToGlobal(QPoint()), "Active/Desactive l'affichage des barres de vie");
    else if(sender() == m_title)
        QToolTip::showText(m_title->mapToGlobal(QPoint()), "Active/Desactive l'affichage du titre du personnage");
    else if(sender() == m_dammages)
        QToolTip::showText(m_dammages->mapToGlobal(QPoint()), "Active/Desactive l'affichage des degats des autres joueurs");
    else if(sender() == m_vital)
        QToolTip::showText(m_vital->mapToGlobal(QPoint()), "Active/Desactive l'affichage des valeurs de vie et de mana");
    else if(sender() == m_recbattle)
        QToolTip::showText(m_recbattle->mapToGlobal(QPoint()), "Active/Desactive le compteur de combat\n\n"
                             "Permet de faire des statistique sur:\n"
                             "- Les dégats infligés au unités enemies\n"
                             "- Les soins prodigués au unités amies\n"
                             "- Les recus par les unités enemies\n");
    else if(sender() == m_guildin)
        QToolTip::showText(m_guildin->mapToGlobal(QPoint()), "Active/Desactive l'affichage de l'insigne de guilde");
    else if(sender() == m_gellyeffect)
        QToolTip::showText(m_gellyeffect->mapToGlobal(QPoint()), "Active/Desactive l'effet flasque sur l'interface");
    //SOCIAL
    else if(sender() == m_dectrade)
        QToolTip::showText(m_dectrade->mapToGlobal(QPoint()), "Active/Desactive le bloquage des echanges");
    else if(sender() == m_decduel)
        QToolTip::showText(m_decduel->mapToGlobal(QPoint()), "Active/Desactive le bloquage des duels");
    else if(sender() == m_decgroup)
        QToolTip::showText(m_decgroup->mapToGlobal(QPoint()), "Active/Desactive le bloquage des groupes");
    else if(sender() == m_denysearch)
        QToolTip::showText(m_denysearch->mapToGlobal(QPoint()), "Active/Desactive le bloquage de la recharche public");
    else if(sender() == m_tandem)
        QToolTip::showText(m_tandem->mapToGlobal(QPoint()), "Active/Desactive le bloquage des tandems");
    else if(sender() == m_groupevent)
        QToolTip::showText(m_groupevent->mapToGlobal(QPoint()), "Active/Desactive le masquage des joueurs lors des event");
    //MISC
    else if(sender() == m_cast)
        QToolTip::showText(m_cast->mapToGlobal(QPoint()), "Active/Desactive le ciblage des sort sur soi-même si aucun cible n'a été séléctionné");
    else if(sender() == m_reverse)
        QToolTip::showText(m_reverse->mapToGlobal(QPoint()), "Active/Desactive la rotation de la camera lors du\n"
                                                             "déplacement du personnage avec les 2 clics appuyé");
    else if(sender() == m_critical)
        QToolTip::showText(m_critical->mapToGlobal(QPoint()), "Active/Desactive l'effet de choc lors des critiques");
    else if(sender() == m_folcamera)
        QToolTip::showText(m_folcamera->mapToGlobal(QPoint()), "Active/Desactive l'affichage du nom du personnage");
    else if(sender() == m_clickm)
        QToolTip::showText(m_clickm->mapToGlobal(QPoint()), "Active/Desactive le déplacement au clic gauche");
    else if(sender() == m_leftclic)
        QToolTip::showText(m_leftclic->mapToGlobal(QPoint()), "Active/Desactive (pas trouvé effet correspondant)");
}
void GameplayTab::loadSettings()
{
    //INTERFACE
    m_sname->setValue(mEdenSettings->value("Option/PlayerAppellationb").toInt());
    m_snpc->setValue(mEdenSettings->value("Option/NpcNameb").toInt());
    m_sguild->setValue(mEdenSettings->value("Option/PlayerFamilyb").toInt());
    m_shealth->setValue(mEdenSettings->value("Option/PlayerBloodb").toInt());
    m_stitle->setValue(mEdenSettings->value("Option/PlayerNameb").toInt());
    m_sdammages->setValue(mEdenSettings->value("Option/OthersDamageb").toInt());
    m_svital->setValue(mEdenSettings->value("Option/PlayerLifeb").toInt());
    m_srecbattle->setValue(mEdenSettings->value("MapOption/BattleReport").toInt());
    m_sguildin->setValue(mEdenSettings->value("Option/ShowEmblem").toInt());
    m_sgellyeffect->setValue(mEdenSettings->value("Channel/UIEffect").toInt());
    //SOCIAL
    m_sdectrade->setValue(mEdenSettings->value("Option/RejectTradeb").toInt());
    m_sdecduel->setValue(mEdenSettings->value("Option/RejectDuelb").toInt());
    m_sdecgroup->setValue(mEdenSettings->value("Option/RejectTeamb").toInt());
    m_sdenysearch->setValue(mEdenSettings->value("Option/RejectSearchb").toInt());
    m_standem->setValue(mEdenSettings->value("Option/RejectCoRide").toInt());
    m_sgroupevent->setValue(mEdenSettings->value("Option/EventBossMode").toInt());
    //MISC
    m_scast->setValue(mEdenSettings->value("Option/SelfConjurationb").toInt());
    m_sreverse->setValue(mEdenSettings->value("Option/MouseReverseb").toInt());
    m_scritical->setValue(mEdenSettings->value("Option/CriticalShakeb").toInt());
    m_sfolcamera->setValue(mEdenSettings->value("Option/CamaraRotationb").toInt());
    m_sclickm->setValue(mEdenSettings->value("Option/ClickToMove").toInt());
    m_sleftclic->setValue(mEdenSettings->value("Option/MouseLeftBtnTraceb").toInt());
}
void GameplayTab::applySettings()
{
    //INTERFACE
    mEdenSettings->setValue("Option/PlayerAppellationb", m_sname->value());
    mEdenSettings->setValue("Option/NpcNameb", m_snpc->value());
    mEdenSettings->setValue("Option/PlayerFamilyb", m_sguild->value());
    mEdenSettings->setValue("Option/PlayerBloodb", m_shealth->value());
    mEdenSettings->setValue("Option/PlayerNameb", m_stitle->value());
    mEdenSettings->setValue("Option/OthersDamageb", m_sdammages->value());
    mEdenSettings->setValue("Option/PlayerLifeb", m_svital->value());
    mEdenSettings->setValue("MapOption/BattleReport", m_srecbattle->value());
    mEdenSettings->setValue("Option/ShowEmblem", m_sguildin->value());
    mEdenSettings->setValue("Channel/UIEffect", m_sgellyeffect->value());
    //SOCIAL
    mEdenSettings->setValue("Option/RejectTradeb", m_sdectrade->value());
    mEdenSettings->setValue("Option/RejectDuelb", m_sdecduel->value());
    mEdenSettings->setValue("Option/RejectTeamb", m_sdecgroup->value());
    mEdenSettings->setValue("Option/RejectSearchb", m_sdenysearch->value());
    mEdenSettings->setValue("Option/RejectCoRide", m_standem->value());
    mEdenSettings->setValue("Option/EventBossMode", m_sgroupevent->value());
    //MISC
    mEdenSettings->setValue("Option/SelfConjurationb", m_scast->value());
    mEdenSettings->setValue("Option/MouseReverseb", m_sreverse->value());
    mEdenSettings->setValue("Option/CriticalShakeb", m_scritical->value());
    mEdenSettings->setValue("Option/CamaraRotationb", m_sfolcamera->value());
    mEdenSettings->setValue("Option/ClickToMove", m_sclickm->value());
    mEdenSettings->setValue("Option/MouseLeftBtnTraceb", m_sleftclic->value());
}
void GameplayTab::changeColorSwitch(int val)
{
    if(val == 1)
        qobject_cast<QSlider*>(sender())->setObjectName("switchSlider1");
    else if(val == 0)
        qobject_cast<QSlider*>(sender())->setObjectName("switchSlider0");

    setStyleSheet(mPathsSettings->loadStylesheet());
}
