#include "Settings.hpp"

Settings::Settings()
{
    createObjects();

    //QDialog *mSettingsDialog = new QDialog();

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
    mclose->setMask(QBitmap(":/mask/mask"));

    QHBoxLayout *mhset = new QHBoxLayout;
        mhset->addWidget(titleSettingsButton);
        mhset->addWidget(mclose);

    QGroupBox *mSettingsGroup = new QGroupBox("Emplacements");
        mSettingsGroup->setLayout(mSettingsGrid);

    mSettingsBox->addLayout(mhset);
    mSettingsBox->addWidget(mSettingsGroup);

    //------------------------

    mPathsFile->open(QIODevice::ReadOnly | QIODevice::Text);

    //mPathsSettings.beginGroup("Paths");

    //-------------------------

    createConnexions();
    createSettings();
    createParams();

    loadSettings();
}

void Settings::createObjects()
{
    m_styleFile = new QFile();

    mPathsFile = new QFile(QCoreApplication::applicationDirPath()+"/logs/paths.list");
    mPathsSettings = new QSettings(mPathsFile->fileName(), QSettings::IniFormat);

    mSettingsBox = new QVBoxLayout;

    mclose = new QPushButton("X");

    mSettingsGrid = new QGridLayout;

    titleSettingsButton = new SPushButton("SETTINGS");

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
    setWindowFlags(Qt::FramelessWindowHint);
    setLayout(mSettingsBox);
    setFixedSize(500, 300);
}
void Settings::createParams()
{
    m_styleFile->setFileName(":/qss/style");
    m_styleFile->open(QIODevice::ReadOnly);

    m_styleString = m_styleFile->readAll();
}

void Settings::loadSettings()
{
    if(mPathsSettings->contains("Paths/EdenEternal"))
    {
        m_EdenPath = mPathsSettings->value("Paths/EdenEternal").toString();

        mEdenEternalEdit->setText(m_EdenPath);
        mEdenEternalEdit->setStyleSheet("QLineEdit{background-color: #5a5}");
    }
}
QString Settings::loadStylesheet()
{
    return m_styleString;
}

//METHODES
void Settings::setEEDir()
{
    QPushButton *button = qobject_cast<QPushButton*>(QObject::sender());

    QPoint testS = QPoint(690, 105);

    QFile *qssDialog = new QFile(":/qss/file_dialog");
        qssDialog->open(QIODevice::ReadOnly | QIODevice::Text);

    QFileDialog *dialog = new QFileDialog;
        dialog->setContentsMargins(10,10,140,10);
        dialog->setStyleSheet(qssDialog->readAll());
        dialog->setWindowFlags(Qt::FramelessWindowHint);
        dialog->setFileMode(QFileDialog::Directory);
        dialog->setOptions(QFileDialog::ShowDirsOnly | QFileDialog::DontUseNativeDialog);
        dialog->setFixedSize(700, 400);
        dialog->move(button->parentWidget()->parentWidget()->geometry().topLeft() + button->geometry().topLeft() - testS);
        dialog->setMask(QBitmap(":/mask/maskset"));
        dialog->setSizeGripEnabled(false);
        dialog->setLabelText(QFileDialog::Reject, "Annuler");


    QDialogButtonBox *box = dialog->findChild<QDialogButtonBox*>();

    QPushButton *openButton = box->button(QDialogButtonBox::Open);
        openButton->setStyleSheet("QPushButton{background-color: #484;} QPushButton:hover{background-color: #4b4;}");

    QPushButton *cancelButton = box->button(QDialogButtonBox::Cancel);
        cancelButton->setStyleSheet("QPushButton{background-color: #844;} QPushButton:hover{background-color: #d44;}");


    if(dialog->exec() == 1)//On vérifie le repertoire uniquement si on clique sur "Choisir"
    {
        setGamePath(dialog->directory().absolutePath());
    }
}

void Settings::setGamePath(QString path)
{
//    QSettings mPathsSettings(mPathsFile->fileName(), QSettings::IniFormat);
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

    mPathsFile->close();
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

QVariant Settings::gamePath(int type)
{
    switch(type)
    {
        case EdenPath:
            return m_EdenPath;
                break;
    }

    return 0;
}
