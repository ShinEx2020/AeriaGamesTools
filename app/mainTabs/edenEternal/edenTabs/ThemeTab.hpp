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

    ThemeTab(QString edenpath);

    void createObjects();

    void createInfoTheme();

public slots:

    void checkDir();

    void updateListThemes();
    void updateInfosThemes();
    void repListThemes(QNetworkReply*);
    void repInfosThemes(QNetworkReply*);

    void addTheme();
    void installTheme(QString nameTheme);
    void extractTheme(QNetworkReply*);

    void delTheme();
    void removeTheme(QString nameTheme);

    QString version(VType type);

    //REWORK
    void listThemes();
    bool isUpdated(QString string);
    void infosThemes(QListWidgetItem* item);

private:

    Settings        *m_settingsCfg;

    QString m_themeName;

//-----------------------------------

    QList<QString> strrep;

    QGroupBox *m_infoTheme;

    ThemeExtract    *m_themeExtract;

    QListWidgetItem *ee;

    QListWidget     *localList;
    QListWidget     *onlineList;

    QPushButton     *addButton;
    QPushButton     *delButton;
    QPushButton     *majButton;

    //REWORK

    QFile           *m_pathsFile;
    QSettings       *m_pathsSets;
    QString         m_pathsString;

    Config          m_settingsHdr;

    int             m_localVersion;
    int             m_onlineVersion;

    QString         m_edenPath;

    QFile           *m_infoFile;
    QFile           *m_themeOnlineFile;
    QFile           *m_themeOnlineInfosFile;

    QLabel          *m_authorLabel;
    QLabel          *m_versionLabel;

    QTextEdit       *m_infosLabel;
};

#endif // THEMETAB_HPP
