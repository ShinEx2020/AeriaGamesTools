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
    m_name = new QPushButton(tr("Name"));
    m_sname = new QSlider(Qt::Horizontal);

    m_guild = new QPushButton(tr("Guild"));
    m_sguild = new QSlider(Qt::Horizontal);

    m_title = new QPushButton(tr("Title"));
    m_stitle = new QSlider(Qt::Horizontal);

    m_vital = new QPushButton(tr("Vital m_stats"));
    m_svital = new QSlider(Qt::Horizontal);

    m_health = new QPushButton(tr("Health Bar"));
    m_shealth = new QSlider(Qt::Horizontal);

    m_dammages = new QPushButton(tr("Dammages"));
    m_sdammages = new QSlider(Qt::Horizontal);

    m_cast = new QPushButton(tr("Self Cast"));
    m_scast = new QSlider(Qt::Horizontal);

    m_npc = new QPushButton(tr("NPC Name"));
    m_snpc = new QSlider(Qt::Horizontal);

    m_critical = new QPushButton(tr("Critical Hit"));
    m_scritical = new QSlider(Qt::Horizontal);

    m_tandem = new QPushButton(tr("Decline Tandem"));
    m_standem = new QSlider(Qt::Horizontal);

    m_clickm = new QPushButton(tr("Click to move"));
    m_sclickm = new QSlider(Qt::Horizontal);

    m_reverse = new QPushButton(tr("Reverse Camera"));
    m_sreverse = new QSlider(Qt::Horizontal);

    m_guildin = new QPushButton(tr("Guild Insigne"));
    m_sguildin = new QSlider(Qt::Horizontal);

//-----------------------------------------

    m_dectrade = new QPushButton(tr("Decline Trade"));
    m_sdectrade = new QSlider(Qt::Horizontal);

    m_decduel = new QPushButton(tr("Decline Duel"));
    m_sdecduel = new QSlider(Qt::Horizontal);

    m_decgroup = new QPushButton(tr("Decline Group"));
    m_sdecgroup = new QSlider(Qt::Horizontal);

    m_denysearch = new QPushButton(tr("Deny m_search"));
    m_sdenysearch = new QSlider(Qt::Horizontal);

    m_gellyeffect = new QPushButton(tr("Gelly Effect"));
    m_sgellyeffect = new QSlider(Qt::Horizontal);

    m_folcamera = new QPushButton(tr("Follow Camera"));
    m_srotcamera = new QSlider(Qt::Horizontal);

    m_recbattle = new QPushButton(tr("Record Battle"));
    m_srecbattle = new QSlider(Qt::Horizontal);

    m_groupevent = new QPushButton(tr("Group Event"));
    m_sgroupevent = new QSlider(Qt::Horizontal);

    m_leftclic = new QPushButton(tr("Left Clic"));
    m_sleftclic = new QSlider(Qt::Horizontal);

//--
    QGridLayout *socialLayout = new QGridLayout();
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

    QGroupBox *socialGroup = new QGroupBox("Social");
        socialGroup->setLayout(socialLayout);
//--
    QGridLayout *uiLayout = new QGridLayout();
        uiLayout->addWidget(m_name, 0, 0);
        uiLayout->addWidget(m_sname, 0, 1);
        uiLayout->addWidget(m_guild, 1, 0);
        uiLayout->addWidget(m_sguild, 1, 1);
        uiLayout->addWidget(m_title, 2, 0);
        uiLayout->addWidget(m_stitle, 2, 1);
        uiLayout->addWidget(m_vital, 3, 0);
        uiLayout->addWidget(m_svital, 3, 1);
        uiLayout->addWidget(m_guildin, 4, 0);
        uiLayout->addWidget(m_sguildin, 4, 1);
        uiLayout->addWidget(m_npc, 0, 2);
        uiLayout->addWidget(m_snpc, 0, 3);
        uiLayout->addWidget(m_health, 1, 2);
        uiLayout->addWidget(m_shealth, 1, 3);
        uiLayout->addWidget(m_dammages, 2, 2);
        uiLayout->addWidget(m_sdammages, 2, 3);
        uiLayout->addWidget(m_recbattle, 3, 2);
        uiLayout->addWidget(m_srecbattle, 3, 3);
        uiLayout->addWidget(m_gellyeffect, 4, 2);
        uiLayout->addWidget(m_sgellyeffect, 4, 3);

    QGroupBox *uiGroup = new QGroupBox("Interface");
        uiGroup->setLayout(uiLayout);
//--
    QGridLayout *miscLayout =new QGridLayout;
        miscLayout->addWidget(m_cast, 0, 0);
        miscLayout->addWidget(m_scast, 0, 1);
        miscLayout->addWidget(m_critical, 1, 0);
        miscLayout->addWidget(m_scritical, 1, 1);
        miscLayout->addWidget(m_clickm, 2, 0);
        miscLayout->addWidget(m_sclickm, 2, 1);
        miscLayout->addWidget(m_reverse, 0, 2);
        miscLayout->addWidget(m_sreverse, 0, 3);
        miscLayout->addWidget(m_folcamera, 1, 2);
        miscLayout->addWidget(m_srotcamera, 1, 3);
        miscLayout->addWidget(m_leftclic, 2, 2);
        miscLayout->addWidget(m_sleftclic, 2, 3);

    QGroupBox *miscGroup = new QGroupBox("Misc");
        miscGroup->setLayout(miscLayout);
//--

    QVBoxLayout *socialVBOX = new QVBoxLayout;
        socialVBOX->addWidget(socialGroup);
        socialVBOX->addWidget(miscGroup);

        //============================
    m_infosEdit = new QTextEdit;
        m_infosEdit->setText("Cliquer sur un libelé pour plus d'infos");

    QVBoxLayout *infosVBOX = new QVBoxLayout;
        infosVBOX->addWidget(m_infosEdit);

    QGroupBox *infosGroup = new QGroupBox("Informations");
        infosGroup->setLayout(infosVBOX);

        //============================

    QHBoxLayout *socialHBOX = new QHBoxLayout;
        socialHBOX->addWidget(uiGroup);
        socialHBOX->addLayout(socialVBOX);
        //socialHBOX->addWidget(infosGroup);

    QFile *qssSliderOn = new QFile(":/qss/slider_on");
        qssSliderOn->open(QIODevice::ReadOnly | QIODevice::Text);
            strSliderOn = qssSliderOn->readAll();

    QFile *qssSliderOff = new QFile(":/qss/slider_off");
        qssSliderOff->open(QIODevice::ReadOnly | QIODevice::Text);
            strSliderOff = qssSliderOff->readAll();


    QFile *m_pathsFile = new QFile(QCoreApplication::applicationDirPath()+"/logs/paths.lst");
            m_pathsFile->open(QIODevice::ReadOnly | QIODevice::Text);
    QSettings *m_pathsSets = new QSettings(m_pathsFile->fileName(), QSettings::IniFormat);
        m_pathsString = m_pathsSets->value("Paths/EdenEternal").toString();



    createConnexions();
    initSettings();

    setLayout(socialHBOX);
}

void GameplayTab::createConnexions()
{
    connect(m_sname, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sguild, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_stitle, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_svital, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_shealth, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sdammages, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_scast, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_snpc, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_scritical, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_standem, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sclickm, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sreverse, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sguildin, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    //---------------------------------------------------------------------------------
    connect(m_sdectrade, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sdecduel, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sdecgroup, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sdenysearch, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sgellyeffect, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_srotcamera, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_srecbattle, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sgroupevent, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(m_sleftclic, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    //---------------------------------------------------------------------------------
    connect(m_name, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_guild, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_title, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_vital, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_health, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_dammages, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_cast, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_npc, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_critical, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_tandem, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_clickm, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_reverse, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_guildin, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //---------------------------------------------------------------------------------
    connect(m_dectrade, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_decduel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_decgroup, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_denysearch, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_gellyeffect, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_folcamera, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_recbattle, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_groupevent, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_leftclic, SIGNAL(clicked()), this, SLOT(hoverInfos()));
}

void GameplayTab::initSettings()
{
    QFile *m_configSet = new QFile(m_pathsString+"/client.ini");
            m_configSet->open(QIODevice::ReadOnly | QIODevice::Text);

    mEdenSettings = new QSettings(m_configSet->fileName(), QSettings::IniFormat);

    m_sname->setValue(mEdenSettings->value("Option/PlayerAppellationb").toInt());
    m_sguild->setValue(mEdenSettings->value("Option/PlayerFamilyb").toInt());
    m_stitle->setValue(mEdenSettings->value("Option/PlayerNameb").toInt());
    m_svital->setValue(mEdenSettings->value("Option/PlayerLifeb").toInt());
    m_shealth->setValue(mEdenSettings->value("Option/PlayerBloodb").toInt());
    m_sdammages->setValue(mEdenSettings->value("Option/OthersDamageb").toInt());
    m_scast->setValue(mEdenSettings->value("Option/SelfConjurationb").toInt());
    m_snpc->setValue(mEdenSettings->value("Option/NpcNameb").toInt());
    m_scritical->setValue(mEdenSettings->value("Option/CriticalShakeb").toInt());
    m_standem->setValue(mEdenSettings->value("Option/RejectCoRide").toInt());
    m_sclickm->setValue(mEdenSettings->value("Option/ClickToMove").toInt());
    m_sreverse->setValue(mEdenSettings->value("Option/MouseReverseb").toInt());
    m_sguildin->setValue(mEdenSettings->value("Option/ShowEmblem").toInt());
    m_sdectrade->setValue(mEdenSettings->value("Option/RejectTradeb").toInt());
    m_sdecduel->setValue(mEdenSettings->value("Option/RejectDuelb").toInt());
    m_sdecgroup->setValue(mEdenSettings->value("Option/RejectTeamb").toInt());
    m_sdenysearch->setValue(mEdenSettings->value("Option/RejectSearchb").toInt());
    m_sgellyeffect->setValue(mEdenSettings->value("Channel/UIEffect").toInt());
    m_srotcamera->setValue(mEdenSettings->value("Option/CamaraRotationb").toInt());
    m_srecbattle->setValue(mEdenSettings->value("MapOption/BattleReport").toInt());
    m_sgroupevent->setValue(mEdenSettings->value("Option/EventBossMode").toInt());
    m_sleftclic->setValue(mEdenSettings->value("Option/MouseLeftBtnTraceb").toInt());

    QList<QSlider*> slider;
        slider.append(m_sname);
        slider.append(m_sguild);
        slider.append(m_stitle);
        slider.append(m_svital);
        slider.append(m_shealth);
        slider.append(m_sdammages);
        slider.append(m_scast);
        slider.append(m_snpc);
        slider.append(m_scritical);
        slider.append(m_standem);
        slider.append(m_sclickm);
        slider.append(m_sreverse);
        slider.append(m_sguildin);
        slider.append(m_sdectrade);
        slider.append(m_sdecduel);
        slider.append(m_sdecgroup);
        slider.append(m_sdenysearch);
        slider.append(m_sgellyeffect);
        slider.append(m_srotcamera);
        slider.append(m_srecbattle);
        slider.append(m_sgroupevent);
        slider.append(m_sleftclic);

    foreach (QSlider* s, slider)
    {
        s->setObjectName("switchSlider");
        s->setRange(0, 1);
        s->setFixedWidth(30);

        if(s->value() == 1)
        {
            s->setStyleSheet(strSliderOn);
        }
        else if(s->value() == 0)
        {
            s->setStyleSheet(strSliderOff);
        }
    }
}

void GameplayTab::applySettings()
{
    mEdenSettings->setValue("Option/PlayerAppellationb", m_sname->value());
    mEdenSettings->setValue("Option/PlayerFamilyb", m_sguild->value());
    mEdenSettings->setValue("Option/PlayerNameb", m_stitle->value());
    mEdenSettings->setValue("Option/PlayerLifeb", m_svital->value());
    mEdenSettings->setValue("Option/PlayerBloodb", m_shealth->value());
    mEdenSettings->setValue("Option/OthersDamageb", m_sdammages->value());
    mEdenSettings->setValue("Option/SelfConjurationb", m_scast->value());
    mEdenSettings->setValue("Option/NpcNameb", m_snpc->value());
    mEdenSettings->setValue("Option/CriticalShakeb", m_scritical->value());
    mEdenSettings->setValue("Option/RejectCoRide", m_standem->value());
    mEdenSettings->setValue("Option/ClickToMove", m_sclickm->value());
    mEdenSettings->setValue("Option/MouseReverseb", m_sreverse->value());
    mEdenSettings->setValue("Option/ShowEmblem", m_sguildin->value());
    mEdenSettings->setValue("Option/RejectTradeb", m_sdectrade->value());
    mEdenSettings->setValue("Option/RejectDuelb", m_sdecduel->value());
    mEdenSettings->setValue("Option/RejectTeamb", m_sdecgroup->value());
    mEdenSettings->setValue("Option/RejectSearchb", m_sdenysearch->value());
    mEdenSettings->setValue("Channel/UIEffect", m_sgellyeffect->value());
    mEdenSettings->setValue("Option/CamaraRotationb", m_srotcamera->value());
    mEdenSettings->setValue("MapOption/BattleReport", m_srecbattle->value());
    mEdenSettings->setValue("Option/EventBossMode", m_sgroupevent->value());
    mEdenSettings->setValue("Option/MouseLeftBtnTraceb", m_sleftclic->value());
}

void GameplayTab::changeColorSwitch(int val)
{
    if(val == 1)
    {
        qobject_cast<QSlider*>(sender())->setStyleSheet(strSliderOn);
    }
    else if(val == 0)
    {
        qobject_cast<QSlider*>(sender())->setStyleSheet(strSliderOff);
    }
}

void GameplayTab::hoverInfos()
{
    if(sender() == m_name)
        m_infosEdit->setText("Active/Desactive l'affichage du nom du personnage");
    else if(sender() == m_guild)
        m_infosEdit->setText("Active/Desactive l'affichage du nom de guilde");
    else if(sender() == m_title)
        m_infosEdit->setText("Active/Desactive l'affichage du titre du personnage");
    else if(sender() == m_vital)
        m_infosEdit->setText("Active/Desactive l'affichage des valeurs de vie et de mana");
    else if(sender() == m_health)
        m_infosEdit->setText("Active/Desactive l'affichage des barres de vie");
    else if(sender() == m_dammages)
        m_infosEdit->setText("Active/Desactive l'affichage des degats des autres joueurs");
    else if(sender() == m_cast)
        m_infosEdit->setText("Active/Desactive le ciblage des sort sur soit même si aucun cible n'a été sélectionner");
    else if(sender() == m_npc)
        m_infosEdit->setText("Active/Desactive les noms des pnj");
    else if(sender() == m_critical)
        m_infosEdit->setText("Active/Desactive l'effet de choc lors des critiques");
    else if(sender() == m_tandem)
        m_infosEdit->setText("Active/Desactive le bloquage des tandems");
    else if(sender() == m_clickm)
        m_infosEdit->setText("Active/Desactive le déplacement au clic gauche");
    else if(sender() == m_reverse)
        m_infosEdit->setText("Active/Desactive l'inversion de rotation dela camera");
    else if(sender() == m_guildin)
        m_infosEdit->setText("Active/Desactive l'affichage de l'insigne de guilde");


    else if(sender() == m_dectrade)
        m_infosEdit->setText("Active/Desactive le bloquage des echanges");
    else if(sender() == m_decduel)
        m_infosEdit->setText("Active/Desactive le bloquage des duels");
    else if(sender() == m_decgroup)
        m_infosEdit->setText("Active/Desactive le bloquage des groupes");
    else if(sender() == m_denysearch)
        m_infosEdit->setText("Active/Desactive le bloquage de la recharche public");
    else if(sender() == m_gellyeffect)
        m_infosEdit->setText("Active/Desactive l'effet flasque sur l'interface");
    else if(sender() == m_folcamera)
        m_infosEdit->setText("Active/Desactive l'affichage du nom du personnage");
    else if(sender() == m_recbattle)
        m_infosEdit->setText("Active/Desactive le compteur de combat\n\n"
                             "Permet de faire des statistique sur:\n"
                             "- Les dégats infligés au unités enemies\n"
                             "- Les soins prodigués au unités amies\n"
                             "- Les recus par les unités enemies\n");
    else if(sender() == m_groupevent)
        m_infosEdit->setText("Active/Desactive le masquage des joueurs lors des event");
    else if(sender() == m_leftclic)
        m_infosEdit->setText("Active/Desactive le déplacement au clic gauche");
}
