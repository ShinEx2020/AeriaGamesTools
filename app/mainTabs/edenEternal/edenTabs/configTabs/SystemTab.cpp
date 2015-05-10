/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "SystemTab.hpp"

SystemTab::SystemTab()
{
    createObjects();
    createConnections();
    createDetailsGroup();
    createBasicGroup();
    createAudioGroup();
    createAdvancedGroup();
    createSceneGroup();
    createTexturesGroup();
    createOthersGroup();
    createInterface();

    switchStyle();
    loadSettings();
}

void SystemTab::createObjects()
{
    mPathsSettings  = new Settings;
    mEdenSettings   = new QSettings(mPathsSettings->gamePath(Settings::GamePath::Eden).toString()+"/client.ini", QSettings::IniFormat);

//GROUPS
    //DETAILS
    fullLabel       = new QPushButton;
    fullSlider      = new QSlider;
    uiLabel         = new QPushButton;
    uiSlider        = new QSlider;
    oqLabel         = new QPushButton;
    oqSlider        = new QSlider;
    gridDLayout     = new QGridLayout;
    m_detailsGroup  = new QGroupBox;
    //BASIC
    resoLabel       = new QPushButton;
    resoCombo       = new QComboBox;
    aliaLabel       = new QPushButton;
    aliaCombo       = new QComboBox;
    gridBLayout     = new QGridLayout;
    baseGroup       = new QGroupBox;
    //AUDIO
    bgmLabel        = new QPushButton;
    bgmSlider       = new DSlider;
    soundLabel      = new QPushButton;
    soundSlider     = new DSlider;
    muteLabel       = new QPushButton;
    muteSlider      = new QSlider;
    gridSLayout     = new QGridLayout;
    m_audioGroup    = new QGroupBox;
    //ADVANCED
    charaLabel      = new QPushButton;
    charaSlider     = new QSlider;
    sceneLabel      = new QPushButton;
    sceneSlider     = new QSlider;
    effectsLabel    = new QPushButton;
    effectsSlider   = new QSlider;
    shadowLabel     = new QPushButton;
    shadowSlider    = new QSlider;
    grassLabel      = new QPushButton;
    grassSlider     = new QSlider;
    m_gridALayout   = new QGridLayout;
    m_avancedGroup  = new QGroupBox;
    //SCENE
    m_deathLabel    = new QPushButton;
    m_deathSlider   = new QSlider;
    photoLabel      = new QPushButton;
    photoSlider     = new QSlider;
    depthLabel      = new QPushButton;
    depthSlider     = new QSlider;
    glareLabel      = new QPushButton;
    glareSlider     = new QSlider;
    waterLabel      = new QPushButton;
    waterSlider     = new QSlider;
    ssaoLabel       = new QPushButton;
    ssaoSlider      = new QSlider;
    gridLayout      = new QGridLayout;
    m_sceneGroup    = new QGroupBox;
    //TEXTURES
    charLabel       = new QPushButton;
    charCombo       = new QComboBox;
    scenLabel       = new QPushButton;
    scenCombo       = new QComboBox;
    bloomLabel      = new QPushButton;
    bloomCombo      = new QComboBox;
    m_fpsFrontLbl   = new QPushButton;
    m_fpsFrontCbx   = new QComboBox;
    modelLabel      = new QPushButton;
    modelCombo      = new QComboBox;
    gridTLayout     = new QGridLayout;
    textGroup       = new QGroupBox;
    //OTHERS
    openMPLabel     = new QPushButton;
    openMPSlider    = new QSlider;
    backLightLabel  = new QPushButton;
    backLightSlider = new QSlider;
    gridWWLayout    = new QGridLayout;
    m_othersGroup   = new QGroupBox;
//

//LAYOUTS
    m_leftVbx       = new QVBoxLayout;
    m_midVbx        = new QVBoxLayout;
    m_rightVbx      = new QVBoxLayout;
    m_systemHbx     = new QHBoxLayout;
//
}
void SystemTab::createConnections()
{
    //DETAILS
    connect(fullSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(uiSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(oqSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    //AUDIO
    connect(muteSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    //SCENE
    connect(m_deathSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(photoSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(depthSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(glareSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(waterSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(ssaoSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    //OTHERS
    connect(openMPSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(backLightSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));

//----------------------------------- BULLES D'INFOS -----------------------------------------

    //DETAILS
    connect(fullLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(uiLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(oqLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //BASIQUE
    connect(resoLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(aliaLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //AUDIO
    connect(bgmLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(soundLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(muteLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //ADVANCED
    connect(charaLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(sceneLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(effectsLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(shadowLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(grassLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //SCENE
    connect(m_deathLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(photoLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(depthLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(glareLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(waterLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(ssaoLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //TEXTURES
    connect(charLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(scenLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(bloomLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(m_fpsFrontLbl, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(modelLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //OTHERS
    connect(openMPLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(backLightLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
}
void SystemTab::createDetailsGroup()
{
    fullLabel->setText("Plein écran");
    fullSlider->setOrientation(Qt::Horizontal);
    fullSlider->setRange(0, 1);
    fullSlider->setFixedWidth(30);

    uiLabel->setText("Cache UI");
    uiSlider->setOrientation(Qt::Horizontal);
    uiSlider->setRange(0, 1);
    uiSlider->setFixedWidth(30);

    oqLabel->setText("Occlu. Query");
    oqSlider->setOrientation(Qt::Horizontal);
    oqSlider->setRange(0, 1);
    oqSlider->setFixedWidth(30);

    gridDLayout->addWidget(fullLabel, 0, 0);
    gridDLayout->addWidget(fullSlider, 0, 1, Qt::AlignLeft);
    gridDLayout->addWidget(uiLabel, 0, 2);
    gridDLayout->addWidget(uiSlider, 0, 3, Qt::AlignLeft);
    gridDLayout->addWidget(oqLabel, 1, 0);
    gridDLayout->addWidget(oqSlider, 1, 1, Qt::AlignLeft);

    m_detailsGroup->setTitle("Détails");
    m_detailsGroup->setLayout(gridDLayout);
}
void SystemTab::createBasicGroup()
{
    resoLabel->setText("Résolution");

    resoCombo->addItem("800 x 600", QSize(800, 600));
    resoCombo->addItem("1024 x 768", QSize(1024, 768));
    resoCombo->addItem("1152 x 864", QSize(1152, 864));
    resoCombo->addItem("1280 x 720", QSize(1280, 720));
    resoCombo->addItem("1280 x 768", QSize(1280, 768));
    resoCombo->addItem("1280 x 800", QSize(1280, 800));
    resoCombo->addItem("1280 x 960", QSize(1280, 960));
    resoCombo->addItem("1280 x 1024", QSize(1280, 1024));
    resoCombo->addItem("1360 x 768", QSize(1360, 768));
    resoCombo->addItem("1366 x 768", QSize(1366, 768));
    resoCombo->addItem("1600 x 900", QSize(1600, 900));
    resoCombo->addItem("1600 x 1024", QSize(1600, 1024));
    resoCombo->addItem("1600 x 1200", QSize(1600, 1200));
    resoCombo->addItem("1680 x 1050", QSize(1680, 1050));
    resoCombo->addItem("1920 x 1080", QSize(1920, 1080));

    aliaLabel->setText("Anti-Aliasing");

    aliaCombo->addItem("Aucun", 0);
    aliaCombo->addItem("2x", 1);
    aliaCombo->addItem("4x", 2);

    gridBLayout->addWidget(resoLabel, 0, 0);
    gridBLayout->addWidget(resoCombo, 0, 1, Qt::AlignLeft);
    gridBLayout->addWidget(aliaLabel, 1, 0);
    gridBLayout->addWidget(aliaCombo, 1, 1, Qt::AlignLeft);

    baseGroup->setTitle("Basique");
    baseGroup->setLayout(gridBLayout);
}
void SystemTab::createAudioGroup()
{
    bgmLabel->setText("Musique");
    bgmSlider->setOrientation(Qt::Horizontal);
    bgmSlider->setRange(0, 10);
    bgmSlider->setFixedWidth(90);

    soundLabel->setText("Effets Sons");
    soundSlider->setOrientation(Qt::Horizontal);
    soundSlider->setRange(0, 10);
    soundSlider->setFixedWidth(90);

    muteLabel->setText("Muet");
    muteSlider->setOrientation(Qt::Horizontal);
    muteSlider->setRange(0, 1);
    muteSlider->setFixedWidth(30);

    gridSLayout->addWidget(bgmLabel, 0, 0);
    gridSLayout->addWidget(bgmSlider, 0, 1, Qt::AlignLeft);
    gridSLayout->addWidget(soundLabel, 1, 0);
    gridSLayout->addWidget(soundSlider, 1, 1, Qt::AlignLeft);
    gridSLayout->addWidget(muteLabel, 2, 0);
    gridSLayout->addWidget(muteSlider, 2, 1, Qt::AlignLeft);

    m_audioGroup->setTitle("Audio");
    m_audioGroup->setLayout(gridSLayout);
}
void SystemTab::createAdvancedGroup()
{
    charaLabel->setText("Perso");
    charaSlider->setOrientation(Qt::Horizontal);
    charaSlider->setRange(1, 40);

    sceneLabel->setText("Décors");
    sceneSlider->setOrientation(Qt::Horizontal);
    sceneSlider->setRange(1, 5);

    effectsLabel->setText("Effets");
    effectsSlider->setOrientation(Qt::Horizontal);
    effectsSlider->setRange(1, 25);

    shadowLabel->setText("Ombres");
    shadowSlider->setOrientation(Qt::Horizontal);
    shadowSlider->setRange(1, 7);

    grassLabel->setText("Herbe");
    grassSlider->setOrientation(Qt::Horizontal);
    grassSlider->setRange(0, 4);

    m_gridALayout->addWidget(charaLabel, 0, 0);
    m_gridALayout->addWidget(charaSlider, 0, 1, Qt::AlignLeft);
    m_gridALayout->addWidget(sceneLabel, 1, 0);
    m_gridALayout->addWidget(sceneSlider, 1, 1, Qt::AlignLeft);
    m_gridALayout->addWidget(effectsLabel, 2, 0);
    m_gridALayout->addWidget(effectsSlider, 2, 1, Qt::AlignLeft);
    m_gridALayout->addWidget(shadowLabel, 3, 0);
    m_gridALayout->addWidget(shadowSlider, 3, 1, Qt::AlignLeft);
    m_gridALayout->addWidget(grassLabel, 4, 0);
    m_gridALayout->addWidget(grassSlider, 4, 1, Qt::AlignLeft);

    m_avancedGroup->setTitle("Avancé");
    m_avancedGroup->setLayout(m_gridALayout);
}
void SystemTab::createSceneGroup()
{
    m_deathLabel->setText("Mort");
    m_deathSlider->setOrientation(Qt::Horizontal);
    m_deathSlider->setFixedWidth(30);
    m_deathSlider->setRange(0, 1);

    photoLabel->setText("Sépia");
    photoSlider->setOrientation(Qt::Horizontal);
    photoSlider->setFixedWidth(30);
    photoSlider->setRange(0, 1);

    depthLabel->setText("Prof.");
    depthSlider->setOrientation(Qt::Horizontal);
    depthSlider->setFixedWidth(30);
    depthSlider->setRange(0, 1);

    glareLabel->setText("Soleil");
    glareSlider->setOrientation(Qt::Horizontal);
    glareSlider->setFixedWidth(30);
    glareSlider->setRange(0, 1);

    waterLabel->setText("Eau");
    waterSlider->setOrientation(Qt::Horizontal);
    waterSlider->setFixedWidth(30);
    waterSlider->setRange(0, 1);

    ssaoLabel->setText("SSAO");
    ssaoSlider->setOrientation(Qt::Horizontal);
    ssaoSlider->setFixedWidth(30);
    ssaoSlider->setRange(0, 1);

    gridLayout->addWidget(m_deathLabel, 0, 0);
    gridLayout->addWidget(m_deathSlider, 0, 1, Qt::AlignLeft);
    gridLayout->addWidget(photoLabel, 0, 2);
    gridLayout->addWidget(photoSlider, 0, 3, Qt::AlignLeft);
    gridLayout->addWidget(depthLabel, 1, 0);
    gridLayout->addWidget(depthSlider, 1, 1, Qt::AlignLeft);
    gridLayout->addWidget(glareLabel, 1, 2);
    gridLayout->addWidget(glareSlider, 1, 3, Qt::AlignLeft);
    gridLayout->addWidget(waterLabel, 2, 0);
    gridLayout->addWidget(waterSlider, 2, 1, Qt::AlignLeft);
    gridLayout->addWidget(ssaoLabel, 2, 2);
    gridLayout->addWidget(ssaoSlider, 2, 3, Qt::AlignLeft);

    m_sceneGroup->setTitle("Scène");
    m_sceneGroup->setLayout(gridLayout);
}
void SystemTab::createTexturesGroup()
{
    charLabel->setText("Personnage");
    charCombo->addItem("Faible", 0);
    charCombo->addItem("Elevé", 1);

    scenLabel->setText("Terrain");
    scenCombo->addItem("Faible", 0);
    scenCombo->addItem("Moyen", 1);
    scenCombo->addItem("Elevé", 2);

    bloomLabel->setText("Bloom");
    bloomCombo->addItem("Aucun", 0);
    bloomCombo->addItem("Faible", 1);
    bloomCombo->addItem("Elevé", 2);

    m_fpsFrontLbl->setText("FPS Active");
    m_fpsFrontCbx->addItem("30", 30);
    m_fpsFrontCbx->addItem("60", 60);
    m_fpsFrontCbx->addItem("120", 120);

    modelLabel->setText("Contour");
    modelCombo->addItem("Aucun", 0);
    modelCombo->addItem("Pers", 1);
    modelCombo->addItem("Tout", 2);

    gridTLayout->addWidget(charLabel, 0, 0);
    gridTLayout->addWidget(charCombo, 0, 1, Qt::AlignLeft);
    gridTLayout->addWidget(scenLabel, 1, 0);
    gridTLayout->addWidget(scenCombo, 1, 1, Qt::AlignLeft);
    gridTLayout->addWidget(bloomLabel, 2, 0);
    gridTLayout->addWidget(bloomCombo, 2, 1, Qt::AlignLeft);
    gridTLayout->addWidget(m_fpsFrontLbl, 3, 0);
    gridTLayout->addWidget(m_fpsFrontCbx, 3, 1, Qt::AlignLeft);
    gridTLayout->addWidget(modelLabel, 4, 0);
    gridTLayout->addWidget(modelCombo, 4, 1, Qt::AlignLeft);

    textGroup->setTitle("Textures");
    textGroup->setLayout(gridTLayout);
}
void SystemTab::createOthersGroup()
{
    openMPLabel->setText("Open MP");
    openMPSlider->setOrientation(Qt::Horizontal);
    openMPSlider->setRange(0, 1);
    openMPSlider->setFixedWidth(30);

    backLightLabel->setText("Lum. de fond");
    backLightSlider->setOrientation(Qt::Horizontal);
    backLightSlider->setRange(0, 1);
    backLightSlider->setFixedWidth(30);

    gridWWLayout->addWidget(openMPLabel, 0, 0);
    gridWWLayout->addWidget(openMPSlider, 0, 1, Qt::AlignLeft);
    gridWWLayout->addWidget(backLightLabel, 1, 0);
    gridWWLayout->addWidget(backLightSlider, 1, 1, Qt::AlignLeft);

    m_othersGroup->setTitle("Autres");
    m_othersGroup->setLayout(gridWWLayout);
}
void SystemTab::createInterface()
{
    m_leftVbx->addWidget(m_detailsGroup);
    m_leftVbx->addWidget(baseGroup);
    m_leftVbx->addWidget(m_audioGroup);

    m_midVbx->addWidget(m_avancedGroup);
    m_midVbx->addWidget(m_sceneGroup);

    m_rightVbx->addWidget(textGroup);
    m_rightVbx->addWidget(m_othersGroup);

    m_systemHbx->addLayout(m_leftVbx);
    m_systemHbx->addLayout(m_midVbx);
    m_systemHbx->addLayout(m_rightVbx);

    setLayout(m_systemHbx);
}

void SystemTab::switchStyle()
{
    //DETAILS
    m_switchSli.append(fullSlider);
    m_switchSli.append(uiSlider);
    m_switchSli.append(oqSlider);
    //AUDIO
    m_switchSli.append(muteSlider);
    //SCENE
    m_switchSli.append(m_deathSlider);
    m_switchSli.append(photoSlider);
    m_switchSli.append(depthSlider);
    m_switchSli.append(glareSlider);
    m_switchSli.append(waterSlider);
    m_switchSli.append(ssaoSlider);
    //OTHERS
    m_switchSli.append(openMPSlider);
    m_switchSli.append(backLightSlider);

    foreach (QSlider* i_slid, m_switchSli)
    {
        if(i_slid->value() == 1)
            i_slid->setObjectName("switchSlider1");
        else
            i_slid->setObjectName("switchSlider0");
    }
}

//SLOTS
void SystemTab::hoverInfos()
{
    //DETAILS
    if(sender() == fullLabel)
        QToolTip::showText(fullLabel->mapToGlobal(QPoint()), "Active/Desactive le mode plein-écran.\n\n"
                             "Préferez la résolution native de votre écran\n"
                             "lorsque vous utilisez ce mode d'affichage");
    else if(sender() == uiLabel)
        QToolTip::showText(uiLabel->mapToGlobal(QPoint()), "Active/Desactive le cache des interfaces.\n\n"
                             "Peut parfois résoudre certains problèmes.");
    else if(sender() == oqLabel)
        QToolTip::showText(oqLabel->mapToGlobal(QPoint()), "Active/Desactive l'occlusion query\n\n"
                             "Il permet de faire un rendu uniquemetn des choses"
                             "qui sonts visible a l'ecran, ce qui demande moins de"
                             "ressources à votre ordinateur.");
    //BASIC
    else if(sender() == resoLabel)
        QToolTip::showText(resoLabel->mapToGlobal(QPoint()), "Defini la résolution du jeu\n"
                             "Lorsque que le mode plein écran est activer\n"
                             "il est conseillé de définir la résolution de votre écran");
    else if(sender() == aliaLabel)
        QToolTip::showText(aliaLabel->mapToGlobal(QPoint()), "Defini la valeur de l'anti alisasing");
    //AUDIO
    else if(sender() == bgmLabel)
        QToolTip::showText(bgmLabel->mapToGlobal(QPoint()), "Defini le volume de la musique de fond");
    else if(sender() == soundLabel)
        QToolTip::showText(soundLabel->mapToGlobal(QPoint()), "Defini le volume des effets sonore");
    else if(sender() == muteLabel)
        QToolTip::showText(muteLabel->mapToGlobal(QPoint()), "Active/Desactive l'arrêt de tous les sons");
    //ADVANCED
    else if(sender() == charaLabel)
        QToolTip::showText(charaLabel->mapToGlobal(QPoint()), "Defini la distance d'affichage des personages");
    else if(sender() == sceneLabel)
        QToolTip::showText(sceneLabel->mapToGlobal(QPoint()), "Defini la distance d'affichage des evironement");
    else if(sender() == effectsLabel)
        QToolTip::showText(effectsLabel->mapToGlobal(QPoint()), "Defini le detail des effets");
    else if(sender() == shadowLabel)
        QToolTip::showText(shadowLabel->mapToGlobal(QPoint()), "Defini le detail des ombres");
    else if(sender() == grassLabel)
        QToolTip::showText(grassLabel->mapToGlobal(QPoint()), "Defini la distance d'affichage de la végetation");
    //SCENE
    else if(sender() == m_deathLabel)
        QToolTip::showText(m_deathLabel->mapToGlobal(QPoint()), "Active/Desactive l'effet de noir et blanc lorsque vous êtes mort");
    else if(sender() == photoLabel)
        QToolTip::showText(photoLabel->mapToGlobal(QPoint()), "Active/Desactive l'effet sépia lorsque vous gagnez un nouveau titre");
    else if(sender() == depthLabel)
        QToolTip::showText(depthLabel->mapToGlobal(QPoint()), "Active/Desactive la profondeur de champ");
    else if(sender() == glareLabel)
        QToolTip::showText(glareLabel->mapToGlobal(QPoint()), "Active/Desactive l'effet du soleil lorsque vous regarder le ciel");
    else if(sender() == waterLabel)
        QToolTip::showText(waterLabel->mapToGlobal(QPoint()), "Active/Desactive les effets de vagues de l'eau");
    else if(sender() == ssaoLabel)
        QToolTip::showText(ssaoLabel->mapToGlobal(QPoint()), "Active/Desactive l'occlusion ambiante\n\n"
                                                                "Permet un meilleur réalisme de l'éclairage"
                                                                "comme les ombres projetées ou les endroits sombre");
    //TEXTURES
    else if(sender() == charLabel)
        QToolTip::showText(charLabel->mapToGlobal(QPoint()), "Defini la qualité des textures des personnages");
    else if(sender() == scenLabel)
        QToolTip::showText(scenLabel->mapToGlobal(QPoint()), "Defini la qualité des textures de l'environement");
    else if(sender() == bloomLabel)
        QToolTip::showText(bloomLabel->mapToGlobal(QPoint()), "Defini la quantité de flou lumineux");
    else if(sender() == m_fpsFrontLbl)
        QToolTip::showText(m_fpsFrontLbl->mapToGlobal(QPoint()), "Defini la limite de FPS du jeu.");
    else if(sender() == modelLabel)
        QToolTip::showText(modelLabel->mapToGlobal(QPoint()), "Defini ou les contour style BD vonts s'appliquer");
    //OTHERS
    else if(sender() == openMPLabel)
        QToolTip::showText(openMPLabel->mapToGlobal(QPoint()), "Active/Desactive OpenMP (Expert)");
    else if(sender() == backLightLabel)
        QToolTip::showText(backLightLabel->mapToGlobal(QPoint()), "Active/Desactive l'éclairage de fond");
}
void SystemTab::loadSettings()
{
    //DETAILS
    fullSlider->setValue(mEdenSettings->value("Option/FullScreenMode").toInt());
    uiSlider->setValue(mEdenSettings->value("Option/UITextureCache").toInt());
    oqSlider->setValue(mEdenSettings->value("Option/OcclusionQuery").toInt());
    //BASIC
    resoCombo->setCurrentIndex(resoCombo->findData(QSize(mEdenSettings->value("Option/ScreenWidth").toInt(), mEdenSettings->value("Option/ScreenHeight").toInt())));
    aliaCombo->setCurrentIndex(aliaCombo->findData(mEdenSettings->value("Option/FXAA")));
    //AUDIO
    bgmSlider->setValueDouble(mEdenSettings->value("Option/BGMValoume").toDouble());
    soundSlider->setValueDouble(mEdenSettings->value("Option/SoundValoume").toDouble());
    muteSlider->setValue(mEdenSettings->value("Option/SoundMute").toInt());
    //ADVANCED
    charaSlider->setValue(mEdenSettings->value("Option/ViewCharacterRange").toInt());
    sceneSlider->setValue(mEdenSettings->value("Option/ViewRange").toInt());
    effectsSlider->setValue(mEdenSettings->value("Option/CharacterEffectNum").toInt());
    shadowSlider->setValue(mEdenSettings->value("Option/ShadowType").toInt());
    grassSlider->setValue(mEdenSettings->value("Option/WeedRange").toInt());
    //SCENE
    m_deathSlider->setValue(mEdenSettings->value("Option/PPMonochrome").toInt());
    photoSlider->setValue(mEdenSettings->value("Option/PPSepia").toInt());
    depthSlider->setValue(mEdenSettings->value("Option/PPDepthOfField").toInt());
    glareSlider->setValue(mEdenSettings->value("Option/PPGodRay").toInt());
    waterSlider->setValue(mEdenSettings->value("Option/WaterEffect").toInt());
    ssaoSlider->setValue(mEdenSettings->value("Option/PPSSAO").toInt());
    //TEXTURES
    charCombo->setCurrentIndex(charCombo->findData(mEdenSettings->value("Option/CharacterTexture")));
    scenCombo->setCurrentIndex(scenCombo->findData(mEdenSettings->value("Option/SceneTexture")));
    bloomCombo->setCurrentIndex(bloomCombo->findData(mEdenSettings->value("Option/BloomShader")));
    m_fpsFrontCbx->setCurrentIndex(m_fpsFrontCbx->findData(mEdenSettings->value("Option/ForegroundFpsValue")));
    modelCombo->setCurrentIndex(modelCombo->findData(mEdenSettings->value("Option/OutlineShader")));
    //OTHERS
    openMPSlider->setValue(mEdenSettings->value("Option/OpenMP").toInt());
    backLightSlider->setValue(mEdenSettings->value("Option/BackLightEffect").toInt());
}
void SystemTab::applySettings()
{
    //DETAILS
    mEdenSettings->setValue("Option/FullScreenMode", fullSlider->value());
    mEdenSettings->setValue("Option/UITextureCache", uiSlider->value());
    mEdenSettings->setValue("Option/OcclusionQuery", oqSlider->value());
    //BASIC
    mEdenSettings->setValue("Option/ScreenWidth", resoCombo->itemData(resoCombo->currentIndex()).toSize().width());
    mEdenSettings->setValue("Option/ScreenHeight", resoCombo->itemData(resoCombo->currentIndex()).toSize().height());
    mEdenSettings->setValue("Option/FXAA", aliaCombo->itemData(aliaCombo->currentIndex()).toInt());
    //AUDIO
    mEdenSettings->setValue("Option/BGMValoume", bgmSlider->valueDouble());
    mEdenSettings->setValue("Option/SoundValoume", soundSlider->valueDouble());
    mEdenSettings->setValue("Option/SoundMute", muteSlider->value());
    //ADVANCED
    mEdenSettings->setValue("Option/ViewCharacterRange", charaSlider->value());
    mEdenSettings->setValue("Option/ViewRange", sceneSlider->value());
    mEdenSettings->setValue("Option/CharacterEffectNum", effectsSlider->value());
    mEdenSettings->setValue("Option/ShadowType", shadowSlider->value());
    mEdenSettings->setValue("Option/WeedRange", grassSlider->value());
    //SCENE
    mEdenSettings->setValue("Option/PPMonochrome", m_deathSlider->value());
    mEdenSettings->setValue("Option/PPSepia", photoSlider->value());
    mEdenSettings->setValue("Option/PPDepthOfField", depthSlider->value());
    mEdenSettings->setValue("Option/PPGodRay", glareSlider->value());
    mEdenSettings->setValue("Option/WaterEffect", waterSlider->value());
    mEdenSettings->setValue("Option/PPSSAO", ssaoSlider->value());
    //TEXTURES
    mEdenSettings->setValue("Option/CharacterTexture", charCombo->itemData(charCombo->currentIndex()).toInt());
    mEdenSettings->setValue("Option/SceneTexture", scenCombo->itemData(scenCombo->currentIndex()).toInt());
    mEdenSettings->setValue("Option/BloomShader", bloomCombo->itemData(bloomCombo->currentIndex()).toInt());
    mEdenSettings->setValue("Option/ForegroundFpsValue", m_fpsFrontCbx->itemData(m_fpsFrontCbx->currentIndex()).toInt());
    mEdenSettings->setValue("Option/OutlineShader", modelCombo->itemData(modelCombo->currentIndex()).toInt());
    //OTHERS
    mEdenSettings->setValue("Option/OpenMP", openMPSlider->value());
    if(backLightSlider->value() == 1)
    {
        mEdenSettings->setValue("Option/BackLightEffect", backLightSlider->value());
        mEdenSettings->setValue("BackLight/CharBackLightType", 2);
        mEdenSettings->setValue("BackLight/SceneBackLightType", 2);
    }
    else
    {
        mEdenSettings->setValue("Option/BackLightEffect", backLightSlider->value());
        mEdenSettings->setValue("BackLight/CharBackLightType", 0);
        mEdenSettings->setValue("BackLight/SceneBackLightType", 0);
    }
}
void SystemTab::changeColorSwitch(int val)
{
    if(val == 1)
        qobject_cast<QSlider*>(sender())->setObjectName("switchSlider1");
    else if(val == 0)
        qobject_cast<QSlider*>(sender())->setObjectName("switchSlider0");

    setStyleSheet(mPathsSettings->loadStylesheet());
}
