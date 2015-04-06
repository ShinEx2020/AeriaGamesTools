/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef AERIATOOLMAIN_HPP
#define AERIATOOLMAIN_HPP

#include <QtWidgets>
#include <QtNetwork>
#include <QSslConfiguration>
#include <QNetworkRequest>

#include "utils/TPushButton.hpp"
#include "utils/SPushButton.hpp"
#include "dialogs/ToolDialog.hpp"

#include "EdenEternalTool.hpp"
#include "Config.hpp"

class AeriaToolMain : public QMainWindow
{
    Q_OBJECT

public:
    AeriaToolMain(QWidget *parent = 0);

    void createButtons();
    void createConnections();

    void moveEvent(QMoveEvent *event);

public slots:
    void minimizeTool();
    void openEdenEternalTool();
    void openWorkInProgress();

    //Bottom
    void openTools();
    void openSettings();
    void openUpdates();
    void closeUpdates();

    void setGamePath(QString path);
    QString gamePath(int nb);

    void openAbout();
    void setDir();
    void getCurrentVersion(QNetworkReply*); // EN COURS D'ESSAI
    void downStatut(qint64, qint64);// ESSAI SUITE
    void getCurrentApplication();
    void updateApplication(QNetworkReply*);


private:

    QProgressBar    *bar;


    bool            m_updateIsOpen;

    Config          m_settings;

    QTextStream     *streamS;

    QPushButton     *colapseButton;
    QPushButton     *localButton;
    QPushButton     *onlineButton;
    QPushButton     *vcheckButton;

//----------------------------------------------
    TPushButton     *titleButton;
    SPushButton     *titleSettingsButton;
    QPushButton     *minimizeButton;
    QPushButton     *closeButton;

    QPushButton     *mGrandFantasiaButton;
    QPushButton     *mEdenEternalButton;
    QPushButton     *mAuraKingdomButton;
    QPushButton     *mWolfTeamButton;
    QPushButton     *mShaiyaButton;
    QPushButton     *mS4LeagueButton;
    QPushButton     *mAVAButton;

    QPushButton     *sGrandFantasiaButton;
    QPushButton     *sEdenEternalButton;
    QPushButton     *sAuraKingdomButton;
    QPushButton     *sWolfTeamButton;
    QPushButton     *sShaiyaButton;
    QPushButton     *sS4LeagueButton;
    QPushButton     *sAVAButton;

    QPushButton     *settingsButton;
    QPushButton     *updateButton;
    QPushButton     *infoButton;

    EdenEternalTool *mEdenEternalTool;

    QFile           *qss;

//-------------------------------------------
    QLineEdit       *mEdenEternalEdit;

//-------------------------------------------

    QPushButton *m_toolButton;
    QHBoxLayout *m_tilesHBox;


    ToolDialog  *m_toolDialog;

//---------------------------------

    QFile           *mPathsFile;
    //QSettings       mPathsSettings;

    QString         m_EdenPath;
};

#endif // AERIATOOLMAIN_HPP
