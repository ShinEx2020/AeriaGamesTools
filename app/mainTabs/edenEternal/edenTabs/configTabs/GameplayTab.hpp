/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef GAMEPLAYTAB_HPP
#define GAMEPLAYTAB_HPP

#include <QtWidgets>
#include "app/mainButtons/Settings.hpp"

class GameplayTab : public QWidget
{
    Q_OBJECT
public:

    GameplayTab();

    void createObjects();
    void createConnexions();
    void createInterfaceGroup();
    void createSocialGroup();
    void createMiscGroup();
    void createInterface();

    void switchStyle();

public slots:

    void hoverInfos();
    void loadSettings();
    void applySettings();
    void changeColorSwitch(int val);

private:

    QList<QSlider*> slider;
    Settings        *mPathsSettings;
    QSettings       *mEdenSettings;

//GROUPS
    //INTERFACE
    QPushButton     *m_name;
    QSlider         *m_sname;
    QPushButton     *m_npc;
    QSlider         *m_snpc;
    QPushButton     *m_guild;
    QSlider         *m_sguild;
    QPushButton     *m_health;
    QSlider         *m_shealth;
    QPushButton     *m_title;
    QSlider         *m_stitle;
    QPushButton     *m_dammages;
    QSlider         *m_sdammages;
    QPushButton     *m_vital;
    QSlider         *m_svital;
    QPushButton     *m_recbattle;
    QSlider         *m_srecbattle;
    QPushButton     *m_guildin;
    QSlider         *m_sguildin;
    QPushButton     *m_gellyeffect;
    QSlider         *m_sgellyeffect;
    QGridLayout     *uiLayout;
    QGroupBox       *uiGroup;
    //SOCIAL
    QPushButton     *m_dectrade;
    QSlider         *m_sdectrade;
    QPushButton     *m_decduel;
    QSlider         *m_sdecduel;
    QPushButton     *m_decgroup;
    QSlider         *m_sdecgroup;
    QPushButton     *m_denysearch;
    QSlider         *m_sdenysearch;
    QPushButton     *m_tandem;
    QSlider         *m_standem;
    QPushButton     *m_groupevent;
    QSlider         *m_sgroupevent;
    QGridLayout     *socialLayout;
    QGroupBox       *socialGroup;
    //MISC
    QPushButton     *m_cast;
    QSlider         *m_scast;
    QPushButton     *m_reverse;
    QSlider         *m_sreverse;
    QPushButton     *m_critical;
    QSlider         *m_scritical;
    QPushButton     *m_folcamera;
    QSlider         *m_sfolcamera;
    QPushButton     *m_clickm;
    QSlider         *m_sclickm;
    QPushButton     *m_leftclic;
    QSlider         *m_sleftclic;
    QGridLayout     *miscLayout;
    QGroupBox       *miscGroup;
//

//LAYOUTS
    QVBoxLayout     *m_rightVbx;
    QHBoxLayout     *m_gameplayHbx;
//
};

#endif // GAMEPLAYTAB_HPP
