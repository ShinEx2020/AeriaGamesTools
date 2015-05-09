/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "Settings.hpp"

Settings::Settings()
{
    createObjects();

    mGrandFantasiaLabel->setObjectName("gamenameLabel");
    mGrandFantasiaEdit->setObjectName("gamenameEdit");
    sGrandFantasiaButton->setObjectName("gamenameButton");

    mEdenEternalLabel->setObjectName("gamenameLabel");
    mEdenEternalEdit->setObjectName("gamenameEdit");
    sEdenEternalButton->setObjectName("gamenameButtonE");

    mAuraKingdomLabel->setObjectName("gamenameLabel");
    mAuraKingdomEdit->setObjectName("gamenameEdit");
    sAuraKingdomButton->setObjectName("gamenameButton");

    mS4LeagueLabel->setObjectName("gamenameLabel");
    mS4LeagueEdit->setObjectName("gamenameEdit");
    sS4LeagueButton->setObjectName("gamenameButton");

    mWolfTeamLabel->setObjectName("gamenameLabel");
    mWolfTeamEdit->setObjectName("gamenameEdit");
    sWolfTeamButton->setObjectName("gamenameButton");

    mShaiyaLabel->setObjectName("gamenameLabel");
    mShaiyaEdit->setObjectName("gamenameEdit");
    sShaiyaButton->setObjectName("gamenameButton");


    mSettingsGrid->setSpacing(0);

    mSettingsGrid->addWidget(mGrandFantasiaLabel, 0, 0);
    mSettingsGrid->addWidget(mGrandFantasiaEdit, 0, 1);
    mSettingsGrid->addWidget(sGrandFantasiaButton, 0, 2);

    mSettingsGrid->addWidget(mEdenEternalLabel, 1, 0);
    mSettingsGrid->addWidget(mEdenEternalEdit, 1, 1);
    mSettingsGrid->addWidget(sEdenEternalButton, 1, 2);

    mSettingsGrid->addWidget(mAuraKingdomLabel, 2, 0);
    mSettingsGrid->addWidget(mAuraKingdomEdit, 2, 1);
    mSettingsGrid->addWidget(sAuraKingdomButton, 2, 2);

    mSettingsGrid->addWidget(mS4LeagueLabel, 3, 0);
    mSettingsGrid->addWidget(mS4LeagueEdit, 3, 1);
    mSettingsGrid->addWidget(sS4LeagueButton, 3, 2);

    mSettingsGrid->addWidget(mWolfTeamLabel, 4, 0);
    mSettingsGrid->addWidget(mWolfTeamEdit, 4, 1);
    mSettingsGrid->addWidget(sWolfTeamButton, 4, 2);

    mSettingsGrid->addWidget(mShaiyaLabel, 5, 0);
    mSettingsGrid->addWidget(mShaiyaEdit, 5, 1);
    mSettingsGrid->addWidget(sShaiyaButton, 5, 2);


    titleSettingsButton->setFixedHeight(25);
    titleSettingsButton->setObjectName("titleButton");

    mclose->setFixedSize(40, 25);
    mclose->setObjectName("closeButton");

    QHBoxLayout *mhset = new QHBoxLayout;
        mhset->addWidget(titleSettingsButton);
        mhset->addWidget(mclose);
        mhset->setSpacing(0);

    QGroupBox *mSettingsGroup = new QGroupBox("Emplacements");
        mSettingsGroup->setLayout(mSettingsGrid);

    mSettingsBox->addLayout(mhset);
    mSettingsBox->addWidget(mSettingsGroup);

    m_ConfigCfg->open(QIODevice::ReadOnly | QIODevice::Text);

    createConnexions();
    createSettings();

    loadSettings();
}

void Settings::createObjects()
{
    m_styleFile = new QFile();

    m_ConfigCfg = new QFile(QCoreApplication::applicationDirPath()+"/Storage/config.cfg");
    mPathsSettings = new QSettings(m_ConfigCfg->fileName(), QSettings::IniFormat);

    mSettingsBox = new QVBoxLayout;

    mclose = new QPushButton("X");

    mSettingsGrid = new QGridLayout;

    titleSettingsButton = new TPushButton("SETTINGS", this);

    mGrandFantasiaLabel = new QLabel("Grand Fantasia");
    mGrandFantasiaEdit = new QLineEdit;
    sGrandFantasiaButton = new QPushButton("...");

    mEdenEternalLabel = new QLabel("Eden Eternal");
    mEdenEternalEdit = new QLineEdit;
    sEdenEternalButton = new QPushButton("...");

    mAuraKingdomLabel = new QLabel("Aura Kingdom");
    mAuraKingdomEdit = new QLineEdit;
    sAuraKingdomButton = new QPushButton("...");

    mS4LeagueLabel = new QLabel("S4 League");
    mS4LeagueEdit = new QLineEdit;
    sS4LeagueButton = new QPushButton("...");

    mWolfTeamLabel = new QLabel("Wolf Team");
    mWolfTeamEdit = new QLineEdit;
    sWolfTeamButton = new QPushButton("...");

    mShaiyaLabel = new QLabel("Shaiya");
    mShaiyaEdit = new QLineEdit;
    sShaiyaButton = new QPushButton("...");
}
void Settings::createConnexions()
{
    connect(mEdenEternalEdit, SIGNAL(textChanged(QString)), this, SLOT(setGamePath(QString)));

    connect(sEdenEternalButton, SIGNAL(clicked()), this, SLOT(setEEDir()));
    connect(mclose, SIGNAL(clicked()), this, SLOT(close()));
    connect(sGrandFantasiaButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));
    connect(sAuraKingdomButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));
    connect(sWolfTeamButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));
    connect(sShaiyaButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));
    connect(sS4LeagueButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));
}
void Settings::createSettings()
{
    m_styleFile->setFileName(":/style/style");
    m_styleFile->open(QIODevice::ReadOnly);

    m_styleString = m_styleFile->readAll();

    setStyleSheet(loadStylesheet());
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowModality(Qt::ApplicationModal);
    setLayout(mSettingsBox);
    setFixedSize(500, 300);
    setContentsMargins(-11, -11, -11, -11);
}

void Settings::loadSettings()
{
    if(mPathsSettings->contains("Paths/EdenEternal"))
    {
        m_EdenPath = mPathsSettings->value("Paths/EdenEternal").toString();

        mEdenEternalEdit->setText(m_EdenPath);
    }
}
QString Settings::loadStylesheet()
{
    return m_styleString;
}

//METHODES
void Settings::setEEDir()
{
    QFileDialog *dialog = new QFileDialog;
        dialog->setWindowFlags(Qt::FramelessWindowHint);
        dialog->setFileMode(QFileDialog::Directory);
        dialog->setOptions(QFileDialog::ShowDirsOnly | QFileDialog::DontUseNativeDialog);
        dialog->setFixedSize(600, 400);
        dialog->setSizeGripEnabled(false);
        dialog->setLabelText(QFileDialog::Reject, "Annuler");


    QDialogButtonBox *box = dialog->findChild<QDialogButtonBox*>();

    QPushButton *openButton = box->button(QDialogButtonBox::Open);
        openButton->setStyleSheet("QPushButton{background-color: #484; border: none;} QPushButton:hover{background-color: #4b4;}");

    QPushButton *cancelButton = box->button(QDialogButtonBox::Cancel);
        cancelButton->setStyleSheet("QPushButton{background-color: #844; border: none;} QPushButton:hover{background-color: #d44;}");

    if(dialog->exec() == 1)//On vérifie le repertoire uniquement si on clique sur "Choisir"
    {
        setGamePath(dialog->directory().absolutePath());
    }
}

void Settings::setGamePath(QString path)
{
//    QSettings mPathsSettings(m_ConfigCfg->fileName(), QSettings::IniFormat);
//        mPathsSettings.beginGroup("Paths");

    if(sender() == sEdenEternalButton || sender() == mEdenEternalEdit)
    {
        QFile *cltax = new QFile(QDir(path).absolutePath() + "/cltax.xmf");
        QFile *ftrace = new QFile(QDir(path).absolutePath() + "/ftrace.dos");

        if(cltax->exists() && ftrace->exists())
        {
            cltax->close();
            ftrace->close();

            m_EdenPath = path;

            mEdenEternalEdit->setText(path);
            mEdenEternalEdit->setStyleSheet("QLineEdit{background-color: #5a5}");

            mPathsSettings->setValue("Paths/EdenEternal", path);
        }
        else
        {
            mEdenEternalEdit->setStyleSheet("QLineEdit{background-color: #a55}");
        }
    }

    m_ConfigCfg->close();
}

void Settings::openWorkInProgress()
{
    QSpacerItem* horizontalSpacer = new QSpacerItem(350, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    QPushButton *butab = new QPushButton("OK");
        butab->setFixedSize(40, 25);
        butab->setObjectName("wipButton");

    QMessageBox wip;
        wip.setIcon(QMessageBox::Warning);
        wip.setWindowTitle("Work In Progress");
        wip.setText("Cette fonction n'est pas ma priorité en ce momment");
        wip.setInformativeText("Contactez FoxiesCuties pour toutes sugestions");
        wip.addButton(butab, QMessageBox::AcceptRole);
        wip.setObjectName("wipBox");
        wip.setWindowFlags(Qt::FramelessWindowHint);

        QGridLayout* layout = (QGridLayout*)wip.layout();
        layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());

        wip.exec();
}

QVariant Settings::gamePath(GamePath type)
{
    switch(type)
    {
        case GamePath::Eden:
            return m_EdenPath;
                break;
    }

    return 0;
}
