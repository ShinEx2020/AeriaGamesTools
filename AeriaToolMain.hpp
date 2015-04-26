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

#include "utils/Settings.hpp"

class AeriaToolMain : public QWidget
{
    Q_OBJECT

public:
    AeriaToolMain(QWidget *parent = 0);

    void initSettings();
    void createObjects();
    void createButtons();
    void createConnections();
    void createSettings();

    void moveEvent(QMoveEvent *event);

public slots:
    void minimizeTool();

    //Bottom
    void openTools();
    void openUpdates();
    void closeUpdates();

    void openAbout();
    void getCurrentVersion(QNetworkReply*); // EN COURS D'ESSAI
    void downStatut(qint64, qint64);// ESSAI SUITE
    void getCurrentApplication();
    void updateApplication(QNetworkReply*);


private:

    QWidget         *m_headerWidget;

    QSettings       *mPathsSettings;

    QVBoxLayout     *m_mainLayout;

    QList<QWidget*> m_widgetList;

    Settings        *m_settingsS;


    QHBoxLayout     *barLayout;

    QProgressBar    *bar;

    bool            m_updateIsOpen;

    Config          m_settings;

    QTextStream     *streamS;

    QPushButton     *colapseButton;
    QPushButton     *localButton;
    QPushButton     *onlineButton;
    QPushButton     *vcheckButton;

    TPushButton     *titleButton;
    QPushButton     *minimizeButton;
    QPushButton     *closeButton;

    QPushButton     *settingsButton;
    QPushButton     *updateButton;
    QPushButton     *infoButton;

    EdenEternalTool *mEdenEternalTool;

    QFile           *qss;

    QPushButton     *mGrandFantasiaButton;
    QPushButton     *mEdenEternalButton;
    QPushButton     *mAuraKingdomButton;
    QPushButton     *mWolfTeamButton;
    QPushButton     *mShaiyaButton;
    QPushButton     *mS4LeagueButton;
    QPushButton     *mAVAButton;

    QPushButton     *m_toolButton;
    QHBoxLayout     *m_tilesHBox;

    ToolDialog      *m_toolDialog;

    QFile           *mPathsFile;

    QString         m_EdenPath;
};

#endif // AERIATOOLMAIN_HPP
