/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef THEMETAB_HPP
#define THEMETAB_HPP

#include <QtWidgets>
#include <QtNetwork>

#include "app/threads/ThemeExtract.hpp"
#include "app/Config.hpp"
#include "app/mainButtons/Settings.hpp"

class ThemeTab : public QWidget
{
    Q_OBJECT
public:

    enum class VType{Local, Online};

    ThemeTab();

    void checkDir();
    void createObjects();
    void createConnexions();
    void createInfoTheme();
    void createThemesList();
    void createInterface();
    void createSettings();

public slots:

    //--AJOUT
    void addTheme();
    void installTheme(QString nameTheme);
    void extractTheme(QNetworkReply* sevenTheme);
    //--SUPPRESSION
    void delTheme();
    void removeTheme(QString nameTheme);
    //--MISE A JOUR
    void updateListThemes();
    void repListThemes(QNetworkReply *listThemesfile);
    void updateInfosThemes();
    void repInfosThemes(QNetworkReply *listInfosfile);
    //--DIVERS
    QString version(VType type);
    void listThemes();
    void infosThemes(QListWidgetItem* item);
    bool isUpdated(QString string);


private:

    QDir            cacheDir;
    QDir            storeDir;
    QDir            edenThemes;
    QString         m_themeName;
    QString         m_onlineRln;
    QString         m_edenPath;
    QStringList     defaultThemes;
    int             m_localVersion;
    int             m_onlineVersion;

    //--
    Config          m_settingsHdr;
    Settings        *m_settingsCfg;
    ThemeExtract    *m_themeExtract;
    QTextStream     *m_onlineStm;

    //FICHIERS
    QFile           *m_themeLoc;
    QFile           *zipThemeFil;
    QFile           *m_themeOnlineFile;
    QFile           *m_themeOnlineInfosFile;

    //BOUTTONS
    QPushButton     *m_addButton;
    QPushButton     *m_delButton;
    QPushButton     *m_majButton;

    //DIALOGUE CONFIRMATION
    QPushButton     *m_yesRoleBtn;
    QPushButton     *m_noRoleBtn;
    QPushButton     *m_okRoleBtn;
    QMessageBox     *m_themesConfirmBox;

    //INFOS DU THEMES
    QLabel          *m_authorLabel;
    QLabel          *m_versionLabel;
    QTextEdit       *m_infosLabel;
    QGridLayout     *m_themesInfosGrd;
    QGroupBox       *m_infoTheme;

    //PRINCIPALE
    QListWidget     *m_localList;
    QListWidget     *m_onlineList;
    QVBoxLayout     *m_centerVbx;
    QVBoxLayout     *m_themesVbx;
    QHBoxLayout     *m_themesHbx;
};

#endif // THEMETAB_HPP
