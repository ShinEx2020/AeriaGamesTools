/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef AERIAMAIN_HPP
#define AERIAMAIN_HPP

#include <QtWidgets>
#include <QtNetwork>
#include <QSslConfiguration>
#include <QNetworkRequest>

#include "app/Config.hpp"
#include "app/libs/TPushButton.hpp"
#include "app/mainButtons/Updates.hpp"
#include "app/mainButtons/Settings.hpp"
#include "app/mainButtons/About.hpp"
#include "app/mainTabs/miscTools/MiscGeneralTool.hpp"
#include "app/mainTabs/edenEternal/EdenEternalTool.hpp"
#include "app/mainTabs/auraKingdom/AuraKingdomTool.hpp"
#include "app/mainTabs/s4League/S4LeagueTool.hpp"
#include "app/mainTabs/grandFantasia/GrandFantasiaTool.hpp"
#include "app/mainTabs/wolfTeam/WolfTeamTool.hpp"
#include "app/mainTabs/shaiya/ShaiyaTool.hpp"
#include "app/mainTabs/ava/AvaTool.hpp"
#include "app/mainTabs/tribesAscend/TribesAscendTool.hpp"
#include "app/mainTabs/maestia/MaestiaTool.hpp"
#include "app/mainTabs/echoOfSoul/EchoOfSoulTool.hpp"

class AeriaMain : public QWidget
{
    Q_OBJECT

public:
    AeriaMain(QWidget *parent = 0);

    void createObjects();
    void createTitleBar();
    void createInfosBar();
    void createHeaderWid();
    void createTabWidget();
    void createInterface();
    void createConnections();
    void createSettings();

public slots:
    void minimizeTool();

private:

    Config              m_settingsHdr;  //Constantes prédefini

    QFile               *m_StyleQss;    //Fichier CSS

//-- En-tête du logiciel

    //-- Les contrôles de la fenêtre
    TPushButton         *m_titleBtn;
    QPushButton         *m_minimizeBtn;
    QPushButton         *m_closeBtn;

    QHBoxLayout         *m_titleBarHbx;
    //--

    //-- Les boutons de commandes
    QPushButton         *m_updatesBtn;
    Updates             *m_updatesDlg;
    QPushButton         *m_settingsBtn;
    Settings            *m_settingsDlg;
    QPushButton         *m_aboutBtn;
    About               *m_aboutDlg;

    QHBoxLayout         *m_infosBarHbx;
    //--

    //-- Disposition de l'en-tête
    QVBoxLayout         *m_headerVbx;
    QWidget             *m_headerWid;
    //--

//--

//-- Corps du logiciel

    //-- Les Classes outils
    MiscGeneralTool     *m_MiscGeneralWid;
    EdenEternalTool     *m_EdenEternalWid;
    AuraKingdomTool     *m_AuraKingdomWid;
    S4LeagueTool        *m_S4LeagueWid;
    GrandFantasiaTool   *m_GrandFantasiaWid;
    WolfTeamTool        *m_WolfTeamWid;
    ShaiyaTool          *m_ShaiyaWid;
    AvaTool             *m_AvaWid;
    TribesAscendTool    *m_TribesAscendWid;
    MaestiaTool         *m_MaestiaWid;
    EchoOfSoulTool      *m_EchoOfSoulWid;

    QTabWidget          *m_mainTabWid;
    //--

    QVBoxLayout         *m_mainVbx;// Layout principal

//--
};

#endif // AERIAMAIN_HPP
