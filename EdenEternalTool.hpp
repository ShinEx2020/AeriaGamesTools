/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef EDENETERNALTOOL_HPP
#define EDENETERNALTOOL_HPP

#include <QtWidgets>
#include "utils/DSlider.hpp" // <============ WORK IN PROGRESS ============>
#include "dialogs/edeneternal/RescueTab.hpp"
#include "dialogs/edeneternal/ThemeTab.hpp"
#include "dialogs/edeneternal/GameplayTab.hpp"
#include "utils/SPushButton.hpp"
#include "utils/Settings.hpp"

class EdenEternalTool : public QWidget
{
    Q_OBJECT

public:
    EdenEternalTool(QWidget *parent = 0);

    void createObjects();

    void createResolutionGroup();
    void createConnections();
    void createComboDetails();
    void createAudioGroup();
    void createDetailsGroup();
    void createHiddenGroup();
    void createSceneGroup();
    void createAdvancedGroup();

    void createSystemTab();

    void createConfigTab();

    void createMainLyt();

signals:

public slots:

    void initSettings();

    void closeEdenEternalTool();
    void applySettings();
    void changeColorSwitch(int val);
    void changeColorSlider(int val);

    void hoverInfos();

private:

    QGridLayout     *m_gridALayout;

    Settings        *mPathsSettings;

    QTabWidget      *m_ConfigsTabWidget;

    QTextEdit       *m_infosEdit;

//--------TAB----------
    GameplayTab         *m_gameWidget;
    ThemeTab        *m_themeWidget;
    RescueTab       *m_repairWidget;
//-------------Widget--------------
    QWidget         *m_systemWidget;

    QWidget         *m_configWidget;

    //--------
    QVBoxLayout *m_layoutEdenEternal;
//---------------------------------
    QFont font;

//--------------WIP DXDIAG---------
    QGroupBox *m_hiddenGroup;
    QGroupBox *m_detailsGroup;
    QGroupBox *m_audioGroup;
    QGroupBox *m_avancedGroup;
    QGroupBox *m_sceneGroup;
    //------

    QPushButton *charLabel;
    QComboBox   *charCombo;

    QPushButton *scenLabel;
    QComboBox   *scenCombo;

    QPushButton *bloomLabel;
    QComboBox   *bloomCombo;

    QPushButton *fpsLabel;
    QComboBox   *fpsCombo;

    QPushButton *modelLabel;
    QComboBox   *modelCombo;


    QGroupBox   *textGroup;

    //-------

    QPushButton *m_closeButton;

    //--------------------------------
    QPushButton  *bgmLabel;
    DSlider *bgmSlider;

    QPushButton  *soundLabel;
    DSlider *soundSlider;

    QPushButton  *muteLabel;
    QSlider *muteSlider;

    //------

    QPushButton *resoLabel;
    QComboBox   *resoCombo;

    QPushButton *aliaLabel;
    QComboBox   *aliaCombo;

    //-------

    QPushButton  *charaLabel;
    QSlider *charaSlider;

    QPushButton  *sceneLabel;
    QSlider *sceneSlider;

    QPushButton  *effectsLabel;
    QSlider *effectsSlider;

    QPushButton  *shadowLabel;
    QSlider *shadowSlider;

    QPushButton  *grassLabel;
    QSlider *grassSlider;

    //-------

    QPushButton  *waterLabel;
    QSlider *waterSlider;

    QPushButton  *glareLabel;
    QSlider *glareSlider;

    QPushButton  *photoLabel;
    QSlider *photoSlider;

    QPushButton  *depthLabel;
    QSlider *depthSlider;

    QPushButton  *bwLabel;
    QSlider *bwSlider;

    QPushButton  *ssaoLabel;
    QSlider *ssaoSlider;

    //-------

    QPushButton  *uiLabel;
    QSlider *uiSlider;

    QPushButton  *oqLabel;
    QSlider *oqSlider;

    QPushButton  *fullLabel;
    QSlider *fullSlider;

    QPushButton  *openMPLabel;
    QSlider *openMPSlider;

    QPushButton  *backLightLabel;
    QSlider *backLightSlider;

//-----------------------------------------

    QGroupBox   *baseGroup;

    QComboBox   *combobox;

    QWidget     *mParent;

    QSettings   *mEdenSettings;

    QSlider     *slid1;

    QLCDNumber *charLine;

    QPushButton *m_ApplyButton;
    QPushButton *m_CancelButton;

    QFile       *qssEden;
    QFile       *qssSliderOn;
    QFile       *qssSliderOff;
    QString     strSliderOn;
    QString     strSliderOff;
};

#endif // EDENETERNALTOOL_HPP
