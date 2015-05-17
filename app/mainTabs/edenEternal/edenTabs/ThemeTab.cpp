/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "ThemeTab.hpp"

ThemeTab::ThemeTab()
{
    checkDir();//Vérifier si les dossiers existe

    createObjects();
    createConnexions();
    createThemesList();
    createInfoTheme();
    createInterface();
    createSettings();

    listThemes();//Affiche la liste des thèmes
}

//METHODS
void ThemeTab::checkDir()
{
    storeDir.mkpath(QCoreApplication::applicationDirPath()+"/Storage/EdenEternal");
    cacheDir.mkpath(QCoreApplication::applicationDirPath()+"/CacheThemes/EdenEternal");
}
void ThemeTab::createObjects()
{
    m_settingsCfg           = new Settings;
    m_themeExtract          = new ThemeExtract;
    m_onlineStm             = new QTextStream;

    //FICHIERS
    m_themeLoc              = new QFile;
    zipThemeFil             = new QFile;
    m_themeOnlineFile       = new QFile;
    m_themeOnlineInfosFile  = new QFile;

    //BOUTTONS
    m_addButton             = new QPushButton;
    m_delButton             = new QPushButton;
    m_majButton             = new QPushButton;

    //DIALOGUE CONFIRMATION
    m_yesRoleBtn            = new QPushButton;
    m_noRoleBtn             = new QPushButton;
    m_okRoleBtn             = new QPushButton;
    m_themesConfirmBox      = new QMessageBox;

    //INFOS DU THEMES
    m_authorLabel           = new QLabel;
    m_versionLabel          = new QLabel;
    m_infosLabel            = new QTextEdit;
    m_themesInfosGrd        = new QGridLayout;
    m_infoTheme             = new QGroupBox;

    //PRINCIPALE
    m_localList             = new QListWidget;
    m_onlineList            = new QListWidget;
    m_centerVbx             = new QVBoxLayout;
    m_themesVbx             = new QVBoxLayout;
    m_themesHbx             = new QHBoxLayout;
}
void ThemeTab::createConnexions()
{
    connect(m_addButton, SIGNAL(clicked()), this, SLOT(addTheme()));
    connect(m_delButton, SIGNAL(clicked()), this, SLOT(delTheme()));
    connect(m_majButton, SIGNAL(clicked()), this, SLOT(updateListThemes()));

    connect(m_localList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(infosThemes(QListWidgetItem*)));
    connect(m_onlineList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(infosThemes(QListWidgetItem*)));
}
void ThemeTab::createThemesList()
{
    m_localList->setFixedWidth(200);

    m_onlineList->setFixedWidth(200);

    m_addButton->setText("< AJOUTER");
    m_addButton->setFixedSize(100,30);
    m_addButton->setObjectName("greenButton");

    m_delButton->setText(" SUPPRIMER >");
    m_delButton->setFixedSize(100,30);
    m_delButton->setObjectName("redButton");

    m_majButton->setText("Update");
    m_majButton->setFixedSize(100,30);
    m_majButton->setObjectName("greenButton");
}
void ThemeTab::createInfoTheme()
{
    m_infosLabel->setReadOnly(true);

    m_themesInfosGrd->addWidget(new QLabel("Auteur :"), 0, 0, Qt::AlignTop);
    m_themesInfosGrd->addWidget(m_authorLabel, 0, 1);
    m_themesInfosGrd->addWidget(new QLabel ("Version :"), 1, 0, Qt::AlignTop);
    m_themesInfosGrd->addWidget(m_versionLabel, 1, 1);
    m_themesInfosGrd->addWidget(new QLabel ("Details :"), 2, 0, Qt::AlignTop);
    m_themesInfosGrd->addWidget(m_infosLabel, 2, 1);

    m_infoTheme->setTitle("  Info du theme  ");
    m_infoTheme->setLayout(m_themesInfosGrd);
    m_infoTheme->setAlignment(Qt::AlignHCenter);
    m_infoTheme->setFixedSize(200, 150);
}
void ThemeTab::createInterface()
{
    //BOUTONS
    m_yesRoleBtn->setObjectName("yesRole");
    m_yesRoleBtn->setText("Oui");

    m_noRoleBtn->setObjectName("noRole");
    m_noRoleBtn->setText("Non");

    m_okRoleBtn->setObjectName("yesRole");
    m_okRoleBtn->setText("OK");

    //LISTES
    m_localList->setObjectName("themesList");
    m_onlineList->setObjectName("themesList");

    //LAYOUTS
    m_centerVbx->setContentsMargins(0, 90, 0, 0);
    m_centerVbx->addWidget(m_addButton, 0, Qt::AlignCenter);
    m_centerVbx->addWidget(m_delButton, 0, Qt::AlignCenter);
    m_centerVbx->addWidget(m_infoTheme, 1, Qt::AlignBottom);

    m_themesHbx->setContentsMargins(0, 20, 0, 5);
    m_themesHbx->addWidget(m_localList);
    m_themesHbx->addLayout(m_centerVbx);
    m_themesHbx->addWidget(m_onlineList);

    m_themesVbx->addLayout(m_themesHbx);
    m_themesVbx->addWidget(m_majButton, 1, Qt::AlignHCenter);

    setLayout(m_themesVbx);
}
void ThemeTab::createSettings()
{
    m_themeOnlineFile->setFileName(QCoreApplication::applicationDirPath()+"/Storage/EdenEternal/themes.list");
    m_themeOnlineInfosFile->setFileName(QCoreApplication::applicationDirPath()+"/Storage/EdenEternal/themes.info");
    m_edenPath = m_settingsCfg->gamePath(Settings::GamePath::Eden).toString();
    setStyleSheet(m_settingsCfg->loadStylesheet());
}

//SLOTS
//--AJOUT
void ThemeTab::addTheme()
{
    //On nettoie les bouttons assigné à la boîte de dialogue
    while(m_themesConfirmBox->buttons().size()!=0)
        m_themesConfirmBox->removeButton(m_themesConfirmBox->buttons().last());

    m_themesConfirmBox->setInformativeText("");
    m_themesConfirmBox->setObjectName("themeBox");
    m_themesConfirmBox->setWindowFlags(Qt::FramelessWindowHint);

    if(m_onlineList->currentIndex().row() != -1)
    {
        m_themesConfirmBox->setIcon(QMessageBox::Information);
        m_themesConfirmBox->addButton(m_yesRoleBtn, QMessageBox::YesRole);
        m_themesConfirmBox->addButton(m_noRoleBtn, QMessageBox::NoRole);

        //On vérifie si il y a une mise à jour du thèmes
        if(!isUpdated(m_onlineList->currentItem()->text()) && QDir(m_edenPath+"/themes/"+m_onlineList->currentItem()->text()).exists())
        {
            m_themesConfirmBox->setText("Voulez vous mettre à jour le thème " + m_onlineList->currentItem()->text());
            m_themesConfirmBox->setInformativeText("de la version " + version(VType::Local) + " vers la version " + version(VType::Online) + " ?");

            qDebug()<<m_themesConfirmBox->exec();

            if(m_themesConfirmBox->exec() == QMessageBox::AcceptRole)
            {
                installTheme(m_onlineList->currentItem()->text());
                m_onlineList->takeItem(m_onlineList->currentRow());
            }
        }
        else
        {
            m_themesConfirmBox->setText("Le thème " + m_onlineList->currentItem()->text() + " sera ajouté au jeu ?");
            m_themesConfirmBox->setInformativeText("Il sera dans la liste des thèmes");

            if(m_themesConfirmBox->exec() == QMessageBox::AcceptRole)
            {
                installTheme(m_onlineList->currentItem()->text());
                m_localList->addItem(m_onlineList->takeItem(m_onlineList->currentRow()));
            }
        }
    }
    else
    {
        m_themesConfirmBox->setIcon(QMessageBox::Warning);
        m_themesConfirmBox->addButton(m_okRoleBtn, QMessageBox::AcceptRole);
        m_themesConfirmBox->setText("Veuillez sélectionner un thème en premier");
        m_themesConfirmBox->exec();
    }
}
void ThemeTab::installTheme(QString nameTheme)
{
    m_themeName = nameTheme;

    if(m_themeOnlineInfosFile->exists())
    {
        QSettings onlineInfosSettings(m_themeOnlineInfosFile->fileName(), QSettings::IniFormat);

        QSslConfiguration sslconfig = QSslConfiguration::defaultConfiguration();

        if(!sslconfig.isNull())
        {
            sslconfig.setProtocol(QSsl::TlsV1_2);

            QNetworkRequest netReq(QUrl(onlineInfosSettings.value(nameTheme+"/Link").toString(), QUrl::StrictMode));
                netReq.setSslConfiguration(sslconfig);

            QNetworkAccessManager *manager = new QNetworkAccessManager;
                manager->get(netReq);

            connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(extractTheme(QNetworkReply*)));
        }
    }
}
void ThemeTab::extractTheme(QNetworkReply* sevenTheme)
{
    //CREATE ARCHIVE
    zipThemeFil->setFileName(QCoreApplication::applicationDirPath()+"/CacheThemes/EdenEternal/"+m_themeName+".7z");
    zipThemeFil->open(QIODevice::WriteOnly);
    zipThemeFil->write(sevenTheme->readAll());
    zipThemeFil->close();
    //EXTRACT ARCHIVE
    m_themeExtract->setPath(m_edenPath);
    m_themeExtract->setArchive(zipThemeFil->fileName());
    m_themeExtract->start();
}
//--SUPPRESSION
void ThemeTab::delTheme()
{
    //On nettoie les bouttons assigné à la boîte de dialogue
    while(m_themesConfirmBox->buttons().size()!=0)
        m_themesConfirmBox->removeButton(m_themesConfirmBox->buttons().last());

    m_themesConfirmBox->setInformativeText("");
    m_themesConfirmBox->setObjectName("themeBox");
    m_themesConfirmBox->setWindowFlags(Qt::FramelessWindowHint);

    if(m_localList->currentIndex().row() != -1)
    {
        m_themesConfirmBox->setIcon(QMessageBox::Information);
        m_themesConfirmBox->addButton(m_yesRoleBtn, QMessageBox::YesRole);
        m_themesConfirmBox->addButton(m_noRoleBtn, QMessageBox::NoRole);
        m_themesConfirmBox->setText("Le thème " + m_localList->currentItem()->text() + " sera retiré du jeu ?");

        if(m_themesConfirmBox->exec() == QMessageBox::AcceptRole)
        {
            removeTheme(m_localList->currentItem()->text());

            //On vérifie si une mise à jour du thème existe
            if (m_onlineList->findItems(m_localList->currentItem()->text(), Qt::MatchExactly).size() > 0)
                m_localList->takeItem(m_localList->currentRow());
            else
                m_onlineList->addItem(m_localList->takeItem(m_localList->currentRow()));
        }
    }
    else
    {
        m_themesConfirmBox->setIcon(QMessageBox::Warning);
        m_themesConfirmBox->addButton(m_okRoleBtn, QMessageBox::AcceptRole);
        m_themesConfirmBox->setText("Veuillez sélectionner un thème en premier");
        m_themesConfirmBox->exec();
    }
}
void ThemeTab::removeTheme(QString nameTheme)
{
    QDir directoryTodelete(m_edenPath+"/themes/"+nameTheme);
    directoryTodelete.removeRecursively();
}
//--MISE A JOUR
void ThemeTab::updateListThemes()
{
    if(m_majButton->isEnabled())
    {
        m_majButton->setEnabled(false);
        m_majButton->setText("Connexion...");
        m_majButton->setObjectName("redButton");
        m_majButton->setStyleSheet(m_settingsCfg->loadStylesheet());
    }

    QSslConfiguration sslconfig = QSslConfiguration::defaultConfiguration();

    if(!sslconfig.isNull())
    {
        sslconfig.setProtocol(QSsl::TlsV1_2);

        QNetworkRequest netReq(QUrl(m_settingsHdr.THEME_LIST_URL, QUrl::StrictMode));
            netReq.setSslConfiguration(sslconfig);

        QNetworkAccessManager *manager = new QNetworkAccessManager;
            manager->get(netReq);

        connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(repListThemes(QNetworkReply*)));
    }
}
void ThemeTab::repListThemes(QNetworkReply *listThemesfile)
{
    m_themeOnlineFile->open(QIODevice::WriteOnly);
    m_themeOnlineFile->write(listThemesfile->readAll());
    m_themeOnlineFile->close();

    updateInfosThemes();
}
void ThemeTab::updateInfosThemes()
{
    QSslConfiguration sslconfig = QSslConfiguration::defaultConfiguration();

    if(!sslconfig.isNull())
    {
        sslconfig.setProtocol(QSsl::TlsV1_2);

        QNetworkRequest netReq(QUrl(m_settingsHdr.THEME_INFO_URL, QUrl::StrictMode));
            netReq.setSslConfiguration(sslconfig);

        QNetworkAccessManager *manager = new QNetworkAccessManager;
            manager->get(netReq);

        connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(repInfosThemes(QNetworkReply*)));
    }
}
void ThemeTab::repInfosThemes(QNetworkReply *listInfosfile)
{
    m_themeOnlineInfosFile->open(QIODevice::WriteOnly);
    m_themeOnlineInfosFile->write(listInfosfile->readAll());
    m_themeOnlineInfosFile->close();

    listThemes();
}
//--DIVERS
QString ThemeTab::version(VType type)
{
    QSettings localInfosSettings(m_edenPath+"/themes/"+m_onlineList->currentItem()->text()+"/theme.info", QSettings::IniFormat);
    QSettings onlineInfosSettings(QCoreApplication::applicationDirPath()+"/Storage/EdenEternal/themes.info", QSettings::IniFormat);

    if(type == VType::Local)
    {
        if(localInfosSettings.contains("Version"))
            return localInfosSettings.value("Version").toString();
    }
    else if(type == VType::Online)
    {
        if(onlineInfosSettings.contains(m_onlineList->currentItem()->text()+"/Version"))
            return onlineInfosSettings.value(m_onlineList->currentItem()->text()+"/Version").toString();
    }
    return 0;
}
void ThemeTab::listThemes()
{
    if(!m_majButton->isEnabled())
    {
        m_majButton->setEnabled(true);
        m_majButton->setText("Update");
        m_majButton->setObjectName("greenButton");
        m_majButton->setStyleSheet(m_settingsCfg->loadStylesheet());
    }

    //LOCAL
    edenThemes.setPath(m_edenPath+"/themes");
    edenThemes.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);

    defaultThemes << "Coffee" << "Blue" << "Green" << "Purple" << "Red";

    m_localList->clear();

    for (int i=0; i<edenThemes.entryList().size(); i++)
    {
        if(!defaultThemes.contains(edenThemes.entryList().at(i)))
            m_localList->addItem(edenThemes.entryList().at(i));
    }

    //ONLINE
    m_themeOnlineFile->open(QIODevice::ReadOnly | QIODevice::Text);
    m_onlineStm->setString(new QString(m_themeOnlineFile->readAll()), QIODevice::ReadOnly);
    m_themeOnlineFile->close();

    m_onlineList->clear();

    while(!m_onlineStm->atEnd())
    {
        m_onlineRln = m_onlineStm->readLine();

        if(!edenThemes.entryList().contains(m_onlineRln))
        {
            m_onlineList->addItem(m_onlineRln);
        }
        else
        {
            if(!isUpdated(m_onlineRln))
                m_onlineList->addItem(new QListWidgetItem(QIcon(":/icons/tabs/upd"), m_onlineRln));
        }
    }
}
void ThemeTab::infosThemes(QListWidgetItem* item)
{
    m_themeLoc->setFileName(m_edenPath+"/themes/"+item->text()+"/theme.info");

    //LOCAL
    if(item->listWidget() == m_localList)
    {
        if(m_themeLoc->exists())
        {
            QSettings localInfosSettings(m_themeLoc->fileName(), QSettings::IniFormat);

            m_authorLabel->setText(localInfosSettings.value("Author").toString());
            m_versionLabel->setText(localInfosSettings.value("Version").toString());
            m_infosLabel->setText(localInfosSettings.value("Info").toString());
        }
    }
    //ONLINE
    else if(item->listWidget() == m_onlineList)
    {
        if(m_themeOnlineInfosFile->exists())
        {
            QSettings onlineInfosSettings(m_themeOnlineInfosFile->fileName(), QSettings::IniFormat);

            m_authorLabel->setText(onlineInfosSettings.value(item->text()+"/Author").toString());
            m_versionLabel->setText(onlineInfosSettings.value(item->text()+"/Version").toString());
            m_infosLabel->setText(onlineInfosSettings.value(item->text()+"/Info").toString());
        }
    }
}
bool ThemeTab::isUpdated(QString string)
{
    m_themeLoc->setFileName(m_edenPath+"/themes/"+string+"/theme.info");

    //LOCAL
    if(m_themeLoc->exists())
    {
        QSettings localInfosSettings(m_themeLoc->fileName(), QSettings::IniFormat);
        m_localVersion = localInfosSettings.value("Version").toInt();
    }
    //ONLINE
    if(m_themeOnlineInfosFile->exists())
    {
        QSettings onlineInfosSettings(m_themeOnlineInfosFile->fileName(), QSettings::IniFormat);
        m_onlineVersion = onlineInfosSettings.value(string+"/Version").toInt();
    }

    //CONDITION
    if(m_localVersion == m_onlineVersion)
        return true;
    else if(m_localVersion < m_onlineVersion)
        return false;
}
