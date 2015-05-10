/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef SYSTEMTAB_HPP
#define SYSTEMTAB_HPP

#include <QtWidgets>
#include "app/libs/DSlider.hpp"
#include "app/mainButtons/Settings.hpp"

class SystemTab : public QWidget
{
    Q_OBJECT
public:

    SystemTab();

    void createObjects();
    void createConnections();
    void createDetailsGroup();
    void createBasicGroup();
    void createAudioGroup();
    void createAdvancedGroup();
    void createSceneGroup();
    void createTexturesGroup();
    void createOthersGroup();
    void createInterface();

    void switchStyle();

public slots:

    void hoverInfos();
    void loadSettings();
    void applySettings();
    void changeColorSwitch(int);

private:

    QList<QSlider*> m_switchSli;
    Settings        *mPathsSettings;
    QSettings       *mEdenSettings;

//GROUPS
    //DETAILS
    QPushButton     *fullLabel;
    QSlider         *fullSlider;
    QPushButton     *uiLabel;
    QSlider         *uiSlider;
    QPushButton     *oqLabel;
    QSlider         *oqSlider;
    QGridLayout     *gridDLayout;
    QGroupBox       *m_detailsGroup;
    //BASIC
    QPushButton     *resoLabel;
    QComboBox       *resoCombo;
    QPushButton     *aliaLabel;
    QComboBox       *aliaCombo;
    QGridLayout     *gridBLayout;
    QGroupBox       *baseGroup;
    //AUDIO
    QPushButton     *bgmLabel;
    DSlider         *bgmSlider;
    QPushButton     *soundLabel;
    DSlider         *soundSlider;
    QPushButton     *muteLabel;
    QSlider         *muteSlider;
    QGridLayout     *gridSLayout;
    QGroupBox       *m_audioGroup;
    //ADVANCED
    QPushButton     *charaLabel;
    QSlider         *charaSlider;
    QPushButton     *sceneLabel;
    QSlider         *sceneSlider;
    QPushButton     *effectsLabel;
    QSlider         *effectsSlider;
    QPushButton     *shadowLabel;
    QSlider         *shadowSlider;
    QPushButton     *grassLabel;
    QSlider         *grassSlider;
    QGridLayout     *m_gridALayout;
    QGroupBox       *m_avancedGroup;
    //SCENE
    QPushButton     *m_deathLabel;
    QSlider         *m_deathSlider;
    QPushButton     *photoLabel;
    QSlider         *photoSlider;
    QPushButton     *depthLabel;
    QSlider         *depthSlider;
    QPushButton     *glareLabel;
    QSlider         *glareSlider;
    QPushButton     *waterLabel;
    QSlider         *waterSlider;
    QPushButton     *ssaoLabel;
    QSlider         *ssaoSlider;
    QGridLayout     *gridLayout;
    QGroupBox       *m_sceneGroup;
    //TEXTURES
    QPushButton     *charLabel;
    QComboBox       *charCombo;
    QPushButton     *scenLabel;
    QComboBox       *scenCombo;
    QPushButton     *bloomLabel;
    QComboBox       *bloomCombo;
    QPushButton     *m_fpsFrontLbl;
    QComboBox       *m_fpsFrontCbx;
    QPushButton     *modelLabel;
    QComboBox       *modelCombo;
    QGridLayout     *gridTLayout;
    QGroupBox       *textGroup;
    //OTHERS
    QPushButton     *openMPLabel;
    QSlider         *openMPSlider;
    QPushButton     *backLightLabel;
    QSlider         *backLightSlider;
    QGridLayout     *gridWWLayout;
    QGroupBox       *m_othersGroup;
//

//LAYOUTS
    QVBoxLayout     *m_leftVbx;
    QVBoxLayout     *m_midVbx;
    QVBoxLayout     *m_rightVbx;
    QHBoxLayout     *m_systemHbx;
//
};

#endif // SYSTEMTAB_HPP
