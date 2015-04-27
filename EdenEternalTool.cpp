/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "EdenEternalTool.hpp"

EdenEternalTool::EdenEternalTool(QWidget *parent) : QWidget(parent)
{
    createObjects();
    createAdvancedGroup();
    createAudioGroup();
    createDetailsGroup();
    createSceneGroup();
    createResolutionGroup();
    createHiddenGroup();
    createComboDetails();

    createSystemTab();

    createConfigTab();

    createMainLyt();

    createConnections();

    initSettings();

    setLayout(m_layoutEdenEternal);
}

void EdenEternalTool::createObjects()
{
    m_gameWidget        = new GameplayTab;
    m_ConfigsTabWidget  = new QTabWidget;

    mPathsSettings      = new Settings;
    m_themeWidget       = new ThemeTab(mPathsSettings->gamePath(0).toString());
    m_configWidget      = new QWidget;
    m_repairWidget      = new RescueTab;
    m_ApplyButton       = new QPushButton;
    m_CancelButton      = new QPushButton;
    charaLabel          = new QPushButton;
    charaSlider         = new QSlider;
    sceneLabel          = new QPushButton;
    sceneSlider         = new QSlider;
    effectsLabel        = new QPushButton;
    effectsSlider       = new QSlider;
    shadowLabel         = new QPushButton;
    shadowSlider        = new QSlider;
    grassLabel          = new QPushButton;
    grassSlider         = new QSlider;

    m_gridALayout       = new QGridLayout;
    m_avancedGroup      = new QGroupBox;
    m_sceneGroup        = new QGroupBox;
}

void EdenEternalTool::createAdvancedGroup()
{
    charaLabel->setText("Character");
    charaSlider->setOrientation(Qt::Horizontal);
    charaSlider->setRange(1, 40);

    sceneLabel->setText("Scene");
    sceneSlider->setOrientation(Qt::Horizontal);
    sceneSlider->setRange(1, 5);

    effectsLabel->setText("Effects");
    effectsSlider->setOrientation(Qt::Horizontal);
    effectsSlider->setRange(1, 25);

    shadowLabel->setText("Shadow");
    shadowSlider->setOrientation(Qt::Horizontal);
    shadowSlider->setRange(1, 7);

    grassLabel->setText("Grass");
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

    m_avancedGroup->setTitle("Avanced");
    m_avancedGroup->setLayout(m_gridALayout);
    m_avancedGroup->setFont(font);
}

void EdenEternalTool::createSceneGroup()
{
    waterLabel = new QPushButton("Water");
    waterSlider = new QSlider(Qt::Horizontal);
        waterSlider->setFixedWidth(30);
        waterSlider->setRange(0, 1);

    glareLabel = new QPushButton("Glare");
    glareSlider = new QSlider(Qt::Horizontal);
        glareSlider->setFixedWidth(30);
        glareSlider->setRange(0, 1);

    photoLabel = new QPushButton("Photo");
    photoSlider = new QSlider(Qt::Horizontal);
        photoSlider->setFixedWidth(30);
        photoSlider->setRange(0, 1);

    depthLabel = new QPushButton("Depth");
    depthSlider = new QSlider(Qt::Horizontal);
        depthSlider->setFixedWidth(30);
        depthSlider->setRange(0, 1);

    bwLabel = new QPushButton("BW");
    bwSlider = new QSlider(Qt::Horizontal);
        bwSlider->setFixedWidth(30);
        bwSlider->setRange(0, 1);

    ssaoLabel = new QPushButton("SSAO");
    ssaoSlider = new QSlider(Qt::Horizontal);
        ssaoSlider->setFixedWidth(30);
        ssaoSlider->setRange(0, 1);

    QGridLayout *gridLayout = new QGridLayout;
        gridLayout->addWidget(bwLabel, 0, 0);
        gridLayout->addWidget(bwSlider, 0, 1, Qt::AlignLeft);
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

    m_sceneGroup->setTitle("Scene");
    m_sceneGroup->setLayout(gridLayout);
    m_sceneGroup->setFixedWidth(220);
    m_sceneGroup->setFont(font);
}

void EdenEternalTool::createHiddenGroup()
{
    openMPLabel = new QPushButton("Open MP");
    openMPSlider = new QSlider(Qt::Horizontal);
        openMPSlider->setRange(0, 1);
        openMPSlider->setFixedWidth(30);

    backLightLabel = new QPushButton("Back Light");
    backLightSlider = new QSlider(Qt::Horizontal);
        backLightSlider->setRange(0, 1);
        backLightSlider->setFixedWidth(30);

    QGridLayout *gridWWLayout = new QGridLayout;
        gridWWLayout->addWidget(openMPLabel, 0, 0);
        gridWWLayout->addWidget(openMPSlider, 0, 1, Qt::AlignLeft);
        gridWWLayout->addWidget(backLightLabel, 1, 0);
        gridWWLayout->addWidget(backLightSlider, 1, 1, Qt::AlignLeft);

    m_hiddenGroup = new QGroupBox("Hidden");
        m_hiddenGroup->setLayout(gridWWLayout);
        m_hiddenGroup->setFont(font);
}

void EdenEternalTool::createDetailsGroup()
{
    fullLabel = new QPushButton("Plein écran");
    fullSlider = new QSlider(Qt::Horizontal);
        fullSlider->setRange(0, 1);
        fullSlider->setFixedWidth(30);

    uiLabel = new QPushButton("Cache UI");
    uiSlider = new QSlider(Qt::Horizontal);
        uiSlider->setRange(0, 1);
        uiSlider->setFixedWidth(30);

    oqLabel = new QPushButton("OcclusionQuery");
    oqSlider = new QSlider(Qt::Horizontal);
        oqSlider->setRange(0, 1);
        oqSlider->setFixedWidth(30);

    QGridLayout *gridDLayout = new QGridLayout;
        gridDLayout->addWidget(fullLabel, 0, 0);
        gridDLayout->addWidget(fullSlider, 0, 1, Qt::AlignLeft);
        gridDLayout->addWidget(uiLabel, 0, 2);
        gridDLayout->addWidget(uiSlider, 0, 3, Qt::AlignLeft);
        gridDLayout->addWidget(oqLabel, 1, 0);
        gridDLayout->addWidget(oqSlider, 1, 1, Qt::AlignLeft);

    m_detailsGroup = new QGroupBox("Details");
        m_detailsGroup->setLayout(gridDLayout);
        m_detailsGroup->setFont(font);
}

void EdenEternalTool::createAudioGroup()
{
    bgmLabel = new QPushButton("BGM");
    bgmSlider = new DSlider(Qt::Horizontal);
        bgmSlider->setRange(0, 10);
        bgmSlider->setFixedWidth(90);

    soundLabel = new QPushButton("Sounds");
    soundSlider = new DSlider(Qt::Horizontal);
        soundSlider->setRange(0, 10);
        soundSlider->setFixedWidth(90);

    muteLabel = new QPushButton("Mute");
    muteSlider = new QSlider(Qt::Horizontal);
        muteSlider->setRange(0, 1);
        muteSlider->setFixedWidth(30);

    QGridLayout *gridSLayout = new QGridLayout;
        gridSLayout->addWidget(bgmLabel, 0, 0);
        gridSLayout->addWidget(bgmSlider, 0, 1, Qt::AlignLeft);
        gridSLayout->addWidget(soundLabel, 1, 0);
        gridSLayout->addWidget(soundSlider, 1, 1, Qt::AlignLeft);
        gridSLayout->addWidget(muteLabel, 2, 0);
        gridSLayout->addWidget(muteSlider, 2, 1, Qt::AlignLeft);

    m_audioGroup = new QGroupBox("Audio");
        m_audioGroup->setLayout(gridSLayout);
        m_audioGroup->setFont(font);
}

void EdenEternalTool::createResolutionGroup()
{
    resoLabel = new QPushButton("Résolution");

    resoCombo = new QComboBox;
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

    aliaLabel = new QPushButton("Anti-Aliasing");

    aliaCombo = new QComboBox;
        aliaCombo->addItem("Aucun", 1);
        aliaCombo->addItem("2x", 65536);
        aliaCombo->addItem("4x", 196608);

    QGridLayout *gridBLayout = new QGridLayout;
        gridBLayout->addWidget(resoLabel, 0, 0);
        gridBLayout->addWidget(resoCombo, 0, 1, Qt::AlignLeft);
        gridBLayout->addWidget(aliaLabel, 1, 0);
        gridBLayout->addWidget(aliaCombo, 1, 1, Qt::AlignLeft);

    baseGroup = new QGroupBox("Basique");
        baseGroup->setLayout(gridBLayout);
        baseGroup->setFont(font);
}

void EdenEternalTool::createComboDetails()
{
    charLabel = new QPushButton("Personnage");

    charCombo = new QComboBox; // CharacterTexture=X
        charCombo->addItem("Faible", 0);
        charCombo->addItem("Elevé", 1);

    scenLabel = new QPushButton("Terrain");

    scenCombo = new QComboBox; // SceneTexture=X
        scenCombo->addItem("Faible", 0);
        scenCombo->addItem("Moyen", 1);
        scenCombo->addItem("Elevé", 2);

    bloomLabel = new QPushButton("Bloom");

    bloomCombo = new QComboBox; // BloomShader=X
        bloomCombo->addItem("Aucun", 0);
        bloomCombo->addItem("Faible", 1);
        bloomCombo->addItem("Elevé", 2);

    fpsLabel = new QPushButton("FPS");

    fpsCombo = new QComboBox; // FpsLockValue=X
        fpsCombo->addItem("30", 30);
        fpsCombo->addItem("60", 60);
        fpsCombo->addItem("120", 120);

    modelLabel = new QPushButton("Contour");

    modelCombo = new QComboBox; // OutlineShader=X
        modelCombo->addItem("Aucun", 0);
        modelCombo->addItem("Pers", 1);
        modelCombo->addItem("Tout", 2);

    QGridLayout *gridTLayout = new QGridLayout;
        gridTLayout->addWidget(charLabel, 0, 0);
        gridTLayout->addWidget(charCombo, 0, 1, Qt::AlignLeft);
        gridTLayout->addWidget(scenLabel, 1, 0);
        gridTLayout->addWidget(scenCombo, 1, 1, Qt::AlignLeft);
        gridTLayout->addWidget(bloomLabel, 2, 0);
        gridTLayout->addWidget(bloomCombo, 2, 1, Qt::AlignLeft);
        gridTLayout->addWidget(fpsLabel, 3, 0);
        gridTLayout->addWidget(fpsCombo, 3, 1, Qt::AlignLeft);
        gridTLayout->addWidget(modelLabel, 4, 0);
        gridTLayout->addWidget(modelCombo, 4, 1, Qt::AlignLeft);

    textGroup = new QGroupBox("Textures");
        textGroup->setLayout(gridTLayout);
        textGroup->setFont(font);
}

void EdenEternalTool::createSystemTab()
{
    QVBoxLayout *slid = new QVBoxLayout;
        slid->addWidget(m_detailsGroup);
        slid->addWidget(baseGroup);
        slid->addWidget(m_audioGroup);

    QVBoxLayout *slidmid = new QVBoxLayout;
        slidmid->addWidget(m_avancedGroup);
        slidmid->addWidget(m_sceneGroup);

    QVBoxLayout *slidright = new QVBoxLayout;
        slidright->addWidget(textGroup);
        slidright->addWidget(m_hiddenGroup);

//--------------------TEST----------------------------
     m_infosEdit = new QTextEdit;
        m_infosEdit->setText("Cliquer sur un libelé pour plus d'infos");

     QHBoxLayout *hboxx = new QHBoxLayout;
        hboxx->addWidget(m_infosEdit);

    QGroupBox *groupb = new QGroupBox("Informations");
        groupb->setFixedWidth(250);
        groupb->setLayout(hboxx);
//----------------------------------------------------

    QHBoxLayout *groupsHBox = new QHBoxLayout;
        groupsHBox->addLayout(slid);
        groupsHBox->addLayout(slidmid);
        groupsHBox->addLayout(slidright);

    m_systemWidget = new QWidget;
        m_systemWidget->setLayout(groupsHBox);
}

void EdenEternalTool::createConfigTab()
{
    m_ApplyButton->setText("Appliquer");
    m_ApplyButton->setObjectName("applyButton");
    m_ApplyButton->setFixedSize(140, 25);

    m_CancelButton->setText("Fermer");
    m_CancelButton->setObjectName("cancelButton");
    m_CancelButton->setFixedSize(140, 25);


    m_ConfigsTabWidget->addTab(m_systemWidget, QIcon(":/icons/tabs/sys"), "Système");
    m_ConfigsTabWidget->addTab(m_gameWidget, QIcon(":/icons/tabs/game"), "Gameplay");
    m_ConfigsTabWidget->setObjectName("mTab");

    QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(m_ApplyButton);
        buttonLayout->addWidget(m_CancelButton);

    QVBoxLayout *vboxconfig = new QVBoxLayout;
        vboxconfig->addWidget(m_ConfigsTabWidget);
        vboxconfig->addLayout(buttonLayout);


    m_configWidget->setLayout(vboxconfig);
}


void EdenEternalTool::createMainLyt()
{
    QTabWidget *mTab = new QTabWidget;
        mTab->addTab(m_themeWidget, "Themes");
        mTab->addTab(m_configWidget, "Configs");
        mTab->addTab(m_repairWidget, "Diagnostics");
        mTab->setObjectName("mTab");

    m_layoutEdenEternal = new QVBoxLayout();
        m_layoutEdenEternal->addWidget(mTab);
}

void EdenEternalTool::createConnections()
{
    connect(fullSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(uiSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(oqSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));

//----------------------------------------------------------------------------------

    connect(waterSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(glareSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(photoSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(depthSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(bwSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));
    connect(ssaoSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));

//----------------------------------------------------------------------------------

    connect(bgmSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSlider(int)));
    connect(soundSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSlider(int)));
    connect(muteSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));

//----------------------------------------------------------------------------------

    connect(charaSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSlider(int)));
    connect(sceneSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSlider(int)));
    connect(effectsSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSlider(int)));
    connect(shadowSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSlider(int)));
    connect(grassSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSlider(int)));

//----------------------------------------------------------------------------------

    connect(m_ApplyButton, SIGNAL(clicked()), this, SLOT(applySettings()));
    connect(m_CancelButton, SIGNAL(clicked()), this, SLOT(closeEdenEternalTool()));

//----------------------------------------------------------------------------------

    connect(openMPSlider, SIGNAL(valueChanged(int)), this, SLOT(changeColorSwitch(int)));


//-----------------------------------------TEST-------------------------------------

    connect(fullLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(uiLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(oqLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //--
    connect(resoLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(aliaLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //--
    connect(bgmLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(soundLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(muteLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //--
    connect(charaLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(sceneLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(effectsLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(shadowLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(grassLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //--
    connect(bwLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(depthLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(waterLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(photoLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(glareLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(ssaoLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //--
    connect(charLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(scenLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(bloomLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(fpsLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    connect(modelLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
    //--
    connect(openMPLabel, SIGNAL(clicked()), this, SLOT(hoverInfos()));
}

void EdenEternalTool::closeEdenEternalTool()
{
    close();

    //mParent->show();//affiche AeriaToolMain
}

void EdenEternalTool::initSettings()
{
    font.setBold(true);

    qssEden = new QFile(":/qss/style_eden");
        qssEden->open(QIODevice::ReadOnly | QIODevice::Text);

    setStyleSheet(qssEden->readAll());
    //setFixedSize(1000,540);
    setContentsMargins(-9, 0, -9, -9);
    setWindowTitle("Eden");
    setWindowFlags(Qt::FramelessWindowHint);

    //---------------------------------------------------------------------------------

//    QFile *pathsEden = new QFile(QCoreApplication::applicationDirPath()+"/logs/paths.lst");
//        pathsEden->open(QIODevice::ReadOnly | QIODevice::Text);



//    pathsEden->close();

    mEdenSettings = new QSettings(mPathsSettings->gamePath(0).toString()+"/client.ini", QSettings::IniFormat);

    //---------------------------------------------------------------------------------

    qssSliderOn = new QFile(":/qss/slider_on");
        qssSliderOn->open(QIODevice::ReadOnly | QIODevice::Text);
            strSliderOn = qssSliderOn->readAll();

    qssSliderOff = new QFile(":/qss/slider_off");
        qssSliderOff->open(QIODevice::ReadOnly | QIODevice::Text);
            strSliderOff = qssSliderOff->readAll();


    bgmSlider->setValueDouble(mEdenSettings->value("Option/BGMValoume").toDouble());
    soundSlider->setValueDouble(mEdenSettings->value("Option/SoundValoume").toDouble());
    muteSlider->setValue(mEdenSettings->value("Option/SoundMute").toInt());

    fullSlider->setValue(mEdenSettings->value("Option/FullScreenMode").toInt());
    uiSlider->setValue(mEdenSettings->value("Option/UITextureCache").toInt());
    oqSlider->setValue(mEdenSettings->value("Option/OcclusionQuery").toInt());

    aliaCombo->setCurrentIndex(aliaCombo->findData(mEdenSettings->value("Option/AntiAliasing")));
    resoCombo->setCurrentIndex(resoCombo->findData(QSize(mEdenSettings->value("Option/ScreenWidth").toInt(),
                                                       mEdenSettings->value("Option/ScreenHeight").toInt())));

    glareSlider->setValue(mEdenSettings->value("Option/PPGodRay").toInt());
    photoSlider->setValue(mEdenSettings->value("Option/PPSepia").toInt());
    bwSlider->setValue(mEdenSettings->value("Option/PPMonochrome").toInt());
    depthSlider->setValue(mEdenSettings->value("Option/PPDepthOfField").toInt());
    waterSlider->setValue(mEdenSettings->value("Option/WaterEffect").toInt());
    ssaoSlider->setValue(mEdenSettings->value("Option/PPSSAO").toInt());
//------------------------------------
    charaSlider->setValue(mEdenSettings->value("Option/ViewCharacterRange").toInt());
    sceneSlider->setValue(mEdenSettings->value("Option/ViewRange").toInt());
    effectsSlider->setValue(mEdenSettings->value("Option/CharacterEffectNum").toInt());
    shadowSlider->setValue(mEdenSettings->value("Option/ShadowType").toInt());
    grassSlider->setValue(mEdenSettings->value("Option/WeedRange").toInt());
//------------------------------------

    charCombo->setCurrentIndex(charCombo->findData(mEdenSettings->value("Option/CharacterTexture")));
    scenCombo->setCurrentIndex(scenCombo->findData(mEdenSettings->value("Option/SceneTexture")));
    bloomCombo->setCurrentIndex(bloomCombo->findData(mEdenSettings->value("Option/BloomShader")));
    fpsCombo->setCurrentIndex(fpsCombo->findData(mEdenSettings->value("Option/FpsLockValue")));
    modelCombo->setCurrentIndex(modelCombo->findData(mEdenSettings->value("Option/OutlineShader")));


    openMPSlider->setValue(mEdenSettings->value("Option/OpenMP").toInt());
    backLightSlider->setValue(mEdenSettings->value("Option/BackLightEffect").toInt());

    QList<QSlider*> slider;
        slider.append(fullSlider);
        slider.append(uiSlider);
        slider.append(glareSlider);
        slider.append(photoSlider);
        slider.append(bwSlider);
        slider.append(depthSlider);
        slider.append(waterSlider);
        slider.append(ssaoSlider);
        slider.append(muteSlider);
        slider.append(oqSlider);
        slider.append(openMPSlider);
        slider.append(backLightSlider);

    foreach (QSlider* s, slider)
    {
        s->setObjectName("switchSlider");

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

void EdenEternalTool::applySettings()
{
    mEdenSettings->setValue("Option/BGMValoume", bgmSlider->valueDouble());
    mEdenSettings->setValue("Option/SoundValoume", soundSlider->valueDouble());
    mEdenSettings->setValue("Option/SoundMute", muteSlider->value());

    mEdenSettings->setValue("Option/FullScreenMode", fullSlider->value());
    mEdenSettings->setValue("Option/UITextureCache", uiSlider->value());
    mEdenSettings->setValue("Option/OcclusionQuery", oqSlider->value());

    mEdenSettings->setValue("Option/AntiAliasing", aliaCombo->itemData(aliaCombo->currentIndex()).toInt());
    mEdenSettings->setValue("Option/ScreenWidth", resoCombo->itemData(resoCombo->currentIndex()).toSize().width());
    mEdenSettings->setValue("Option/ScreenHeight", resoCombo->itemData(resoCombo->currentIndex()).toSize().height());

    mEdenSettings->setValue("Option/PPGodRay", glareSlider->value());
    mEdenSettings->setValue("Option/PPSepia", photoSlider->value());
    mEdenSettings->setValue("Option/PPMonochrome", bwSlider->value());
    mEdenSettings->setValue("Option/PPDepthOfField", depthSlider->value());
    mEdenSettings->setValue("Option/WaterEffect", waterSlider->value());
    mEdenSettings->setValue("Option/PPSSAO", ssaoSlider->value());

    mEdenSettings->setValue("Option/ViewCharacterRange", charaSlider->value());
    mEdenSettings->setValue("Option/ViewRange", sceneSlider->value());
    mEdenSettings->setValue("Option/CharacterEffectNum", effectsSlider->value());
    mEdenSettings->setValue("Option/ShadowType", shadowSlider->value());
    mEdenSettings->setValue("Option/WeedRange", grassSlider->value());

    mEdenSettings->setValue("Option/CharacterTexture", charCombo->itemData(charCombo->currentIndex()).toInt());
    mEdenSettings->setValue("Option/SceneTexture", scenCombo->itemData(scenCombo->currentIndex()).toInt());
    mEdenSettings->setValue("Option/BloomShader", bloomCombo->itemData(bloomCombo->currentIndex()).toInt());
    mEdenSettings->setValue("Option/FpsLockValue", fpsCombo->itemData(fpsCombo->currentIndex()).toInt());
    mEdenSettings->setValue("Option/OutlineShader", modelCombo->itemData(modelCombo->currentIndex()).toInt());

    mEdenSettings->setValue("Option/OpenMP", openMPSlider->value());
    //BackLight
    if(openMPSlider->value() == 1)
    {
        mEdenSettings->setValue("Option/BackLightEffect", openMPSlider->value());
        mEdenSettings->setValue("BackLight/CharBackLightType", 2);
        mEdenSettings->setValue("BackLight/SceneBackLightType", 2);
    }


    m_gameWidget->applySettings();//Call GameTab apply Settings
}

void EdenEternalTool::changeColorSwitch(int val)
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

void EdenEternalTool::changeColorSlider(int val)
{
    QSlider *d = qobject_cast<QSlider*>(sender());

    double val2 = val * 100 / d->maximum();

    QString beg, end;

    end = QString::number(val2*1.5);
    beg = QString::number(val2*2);

    QString css = "QSlider::handle:horizontal{background:qlineargradient(x1:0,y1:0,x2:1,y2:1,stop:0 rgb(34, " + beg + ", 34), stop:1 rgb(134, " + end + ", 134))}";

    d->setStyleSheet(css);
}

void EdenEternalTool::hoverInfos()
{
    if(sender() == fullLabel)
        m_infosEdit->setText("Active/Desactive le mode plein-écran.\n\n"
                             "Préferez la résolution native de votre écran\n"
                             "lorsque vous utilisez ce mode d'affichage");
    else if(sender() == uiLabel)
        m_infosEdit->setText("Active/Desactive le cache des interfaces.\n\n"
                             "Peut parfois résoudre certains problèmes.");
    else if(sender() == oqLabel)
        m_infosEdit->setText("Active/Desactive l'occlusion query\n\n"
                             "Il permet de faire un rendu uniquemetn des choses"
                             "qui sonts visible a l'ecran, ce qui demande moins de"
                             "ressources à votre ordinateur.");


    else if(sender() == resoLabel)
        m_infosEdit->setText("Defini la résolution du jeu\n"
                             "Lorsque que le mode plein écran est activer\n"
                             "il est conseillé de définir la résolution de votre écran");
    else if(sender() == aliaLabel)
        m_infosEdit->setText("Defini la valeur de l'anti alisasing");


    else if(sender() == bgmLabel)
        m_infosEdit->setText("Defini le volume de la musique de fond");
    else if(sender() == soundLabel)
        m_infosEdit->setText("Defini le volume des effets sonore");
    else if(sender() == muteLabel)
        m_infosEdit->setText("Active/Desactive l'arrêt de tous les sons");


    else if(sender() == charaLabel)
        m_infosEdit->setText("Defini la distance d'affichage des personages");
    else if(sender() == sceneLabel)
        m_infosEdit->setText("Defini la distance d'affichage des evironement");
    else if(sender() == effectsLabel)
        m_infosEdit->setText("Defini le detail des effets");
    else if(sender() == shadowLabel)
        m_infosEdit->setText("Defini le detail des ombres");
    else if(sender() == grassLabel)
        m_infosEdit->setText("Defini la distance d'affichage de la végetation");


    else if(sender() == bwLabel)
        m_infosEdit->setText("bw");
    else if(sender() == depthLabel)
        m_infosEdit->setText("Active/Desactive la profondeur de champ\n\n");
    else if(sender() == waterLabel)
        m_infosEdit->setText("Active/Desactive les effets de l'eau\n\n");
    else if(sender() == photoLabel)
        m_infosEdit->setText("Active/Desactive l'effet sépia\n\n");
    else if(sender() == glareLabel)
        m_infosEdit->setText("Active/Desactive la reflection lumineuse");
    else if(sender() == ssaoLabel)
        m_infosEdit->setText("Active/Desactive l'occlusion ambiante\n\n"
                             "Permet un meilleur réalisme de l'éclairage"
                             "comme les ombres projeter ou les endroits sombre");


    else if(sender() == charLabel)
        m_infosEdit->setText("Defini la qualité des textures des personnages");
    else if(sender() == scenLabel)
        m_infosEdit->setText("Defini la qualité des textures de l'environement");
    else if(sender() == bloomLabel)
        m_infosEdit->setText("Defini la quantité de flou lumineux");
    else if(sender() == fpsLabel)
        m_infosEdit->setText("Defini la limite de FPS du jeu."
                             "Pour un jeu comme Edent Eternal 30 FPS peuvent suffir.");
    else if(sender() == modelLabel)
        m_infosEdit->setText("Defini ou les contour style BD vonts s'appliquer");


    else if(sender() == openMPLabel)
        m_infosEdit->setText("Active/Desactive OpenMP (Expert)\n\n"
                             "Lié au paralelisme je n'est pas encore fait\n"
                             "des test approfondi de cette fonction\n\n"
                             "Aucun changement de performence constater chez moi\n"
                             "Je vous conseille de ne pas toucher pour le momment\n\n"
                             "on ne sait jamais ce qui pourrait ce passer");
}
