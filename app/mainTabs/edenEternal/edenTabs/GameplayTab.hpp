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

class GameplayTab : public QWidget
{
    Q_OBJECT
public:

    GameplayTab();
    void createConnexions();

signals:

public slots:
    void changeColorSwitch(int val);
    void initSettings();
    void applySettings();

    void settingsInfos();

private:

    QString     m_pathsString;

    QSettings   *mEdenSettings;

    QString     strSliderOn;
    QString     strSliderOff;

    QPushButton *m_name;
    QPushButton *m_guild;
    QPushButton *m_title;
    QPushButton *m_vital;
    QPushButton *m_health;
    QPushButton *m_dammages;
    QPushButton *m_cast;
    QPushButton *m_npc;
    QPushButton *m_critical;
    QPushButton *m_tandem;
    QPushButton *m_clickm;
    QPushButton *m_reverse;
    QPushButton *m_guildin;
    //----------------
    QPushButton *m_dectrade;
    QPushButton *m_decduel;
    QPushButton *m_decgroup;
    QPushButton *m_denysearch;
    QPushButton *m_gellyeffect;
    QPushButton *m_folcamera;
    QPushButton *m_recbattle;
    QPushButton *m_groupevent;
    QPushButton *m_leftclic;


    QSlider *m_sname;
    QSlider *m_sguild;
    QSlider *m_stitle;
    QSlider *m_svital;
    QSlider *m_shealth;
    QSlider *m_sdammages;
    QSlider *m_scast;
    QSlider *m_snpc;
    QSlider *m_scritical;
    QSlider *m_standem;
    QSlider *m_sclickm;
    QSlider *m_sreverse;
    QSlider *m_sguildin;
    //----------------
    QSlider *m_sdectrade;
    QSlider *m_sdecduel;
    QSlider *m_sdecgroup;
    QSlider *m_sdenysearch;
    QSlider *m_sgellyeffect;
    QSlider *m_srotcamera;
    QSlider *m_srecbattle;
    QSlider *m_sgroupevent;
    QSlider *m_sleftclic;
};

#endif // GAMEPLAYTAB_HPP
