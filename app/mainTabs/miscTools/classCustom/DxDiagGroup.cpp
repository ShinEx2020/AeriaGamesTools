#include "DxDiagGroup.hpp"

DxDiagGroup::DxDiagGroup()
{
    createObjects();
    createConnexions();

    m_DxDiagFil->setFileName(QCoreApplication::applicationDirPath()+"/Storage/dxdiag.txt");

    dxDiagExist();
    dxDiagDate();

    dxDiagGroup();

    m_UploadStatutBtn->setText("Envoyer");
    m_UploadClipBtn->setStyleSheet("QPushButton{border: none; outline :none;}"
                                   "QPushButton:hover{margin-left: 8px}");

    m_UploadStatutLbl->setPixmap(QPixmap(":/icons/bad"));
    m_WaitAnim->setFileName(":/icons/wait");

    m_pastebinLineEdit->setStyleSheet("QLineEdit{ border: 1px solid white; width: 200px;}");
    m_pastebinLineEdit->setReadOnly(true);


    setLayout(m_DxDiagVbx);
}

DxDiagGroup::createObjects()
{
    m_UploadLinkClp     = QApplication::clipboard();

    m_DxDiagTim         = new QTimer;
    m_PastUpTim         = new QTimer;
    m_directxDiag       = new DirectXDiag;
    m_DiagStatutBtn     = new QPushButton;

    m_UploadStatutBtn   = new QPushButton;
    m_UploadStatutLbl   = new QLabel;
    m_WaitAnim          = new QMovie;
    m_UploadClipBtn     = new QPushButton;

    m_pastebinLineEdit  = new QLineEdit;

    m_pasteQuery        = new QPastebinQuery;
    m_DiagStatutLbl     = new QLabel;
    m_DiagDateLbl       = new QLabel;
    m_DxDiagVbx         = new QVBoxLayout;
    m_DxDiagGrp         = new QGroupBox;
    m_DxDiagGrd         = new QGridLayout;
    m_DxDiagFil         = new QFile;
}

DxDiagGroup::createConnexions()
{
    connect(m_DiagStatutBtn, SIGNAL(clicked()), this, SLOT(makeDxDiag()));
    connect(m_directxDiag, SIGNAL(finished()), this, SLOT(refreshDiagStat()));
    connect(m_DxDiagTim, SIGNAL(timeout()), this, SLOT(timeOutDxDiag()));
    connect(m_PastUpTim, SIGNAL(timeout()), this, SLOT(timeOutUpPast()));
    connect(m_UploadStatutBtn, SIGNAL(clicked()), this, SLOT(pastebinLink()));
    connect(m_pasteQuery, SIGNAL(linkAcquiered(QString)), this, SLOT(uploadSuccessful(QString)));
    connect(m_UploadClipBtn, SIGNAL(clicked()), this, SLOT(linkToClip()));
}

void DxDiagGroup::makeDxDiag()
{
    m_DiagStatutLbl->setMovie(m_WaitAnim);
    m_WaitAnim->start();

    m_directxDiag->start();
    m_DxDiagTim->start(m_settingsHdr.TIMEOUT);

    m_DiagStatutBtn->setEnabled(false);
}
void DxDiagGroup::timeOutDxDiag()
{
    m_DxDiagTim->stop();

    QToolTip::showText(m_DiagStatutBtn->mapToGlobal(QPoint()), tr("Temps ecoulé, veuillez réessayer"));

    m_UploadStatutLbl->setPixmap(QPixmap(":/icons/bad"));
    m_DiagDateLbl->setEnabled(true);

    m_directxDiag->terminate();
    m_directxDiag->wait();
}
void DxDiagGroup::timeOutUpPast()
{
    QToolTip::showText(m_UploadStatutBtn->mapToGlobal(QPoint()), tr("Temps ecoulé, veuillez réessayer"));
    m_UploadStatutLbl->setPixmap(QPixmap(":/icons/bad"));
    m_UploadStatutBtn->setEnabled(true);
}

void DxDiagGroup::uploadSuccessful(QString link)
{
    m_PastUpTim->stop();
    m_pastebinLineEdit->setText(link);
    m_UploadStatutLbl->setPixmap(QPixmap(":/icons/good"));
}

void DxDiagGroup::linkToClip()
{
    if(!m_pastebinLineEdit->text().isEmpty())
    {
        m_UploadLinkClp->setText(m_pastebinLineEdit->text());

        if(m_UploadLinkClp->text() == m_pastebinLineEdit->text())
            QToolTip::showText(m_pastebinLineEdit->mapToGlobal(QPoint()), tr("Lien dans le presse papier"));
        else
            QToolTip::showText(m_pastebinLineEdit->mapToGlobal(QPoint()), tr("Erreur de presse papier"));
    }
    else
        QToolTip::showText(m_pastebinLineEdit->mapToGlobal(QPoint()), "Rien à copier");
}

void DxDiagGroup::refreshDiagStat()
{
    m_DxDiagTim->stop();

    m_DiagStatutBtn->setEnabled(true);

    dxDiagExist();
    dxDiagDate();
}

bool DxDiagGroup::dxDiagExist()
{
    m_DxDiagFil->open(QIODevice::ReadOnly | QIODevice::Text);

    m_directxDiag->setPath(m_DxDiagFil->fileName());

    if(m_DxDiagFil->exists())
    {
        m_DiagStatutLbl->setPixmap(QPixmap(":/icons/good"));

        m_DiagStatutBtn->setText("Refaire un Diag");

        m_DxExist = true;
    }
    else
    {
        m_DiagStatutLbl->setPixmap(QPixmap(":/icons/bad"));

        m_DiagStatutBtn->setText("Faire un Diag");

        m_DxExist = false;
    }

    return m_DxExist;
}

void DxDiagGroup::dxDiagDate()
{
    if(m_DxExist)
    {
        m_DiagDateLbl->setText(QFileInfo(*m_DxDiagFil).lastModified().toString("Le dddd d MMMM yyyy à hh:mm:ss"));
    }
    else
    {
        m_DiagDateLbl->setText("Aucun DxDiag rapport existant");
    }
}

void DxDiagGroup::dxDiagGroup()
{

    m_UploadClipBtn->setIcon(QIcon(":/icons/clip"));

    m_DxDiagGrd->addWidget(new QLabel("Rapport :"),0,0,Qt::AlignRight);
    m_DxDiagGrd->addWidget(m_DiagStatutLbl,0,1,Qt::AlignLeft);
    m_DxDiagGrd->addWidget(m_DiagStatutBtn,0,2,Qt::AlignRight);
    m_DxDiagGrd->addWidget(new QLabel("Dernier :"),1,0,Qt::AlignRight);
    m_DxDiagGrd->addWidget(m_DiagDateLbl,1,1,1,2,Qt::AlignRight);

    m_DxDiagGrd->addWidget(new QLabel("Uploadé :"),2,0,Qt::AlignRight);
    m_DxDiagGrd->addWidget(m_UploadStatutLbl,2,1,Qt::AlignLeft);
    m_DxDiagGrd->addWidget(m_UploadStatutBtn,2,2,Qt::AlignRight);
    m_DxDiagGrd->addWidget(new QLabel("Partage :"),3,0,Qt::AlignRight);
    m_DxDiagGrd->addWidget(m_UploadClipBtn,3,1,Qt::AlignRight);
    m_DxDiagGrd->addWidget(m_pastebinLineEdit,3,2,Qt::AlignRight);

    m_DxDiagGrp->setTitle("Diagnotique DirectX");
    m_DxDiagGrp->setLayout(m_DxDiagGrd);
    m_DxDiagGrp->setFixedSize(280,150);

    m_DxDiagVbx->addWidget(m_DxDiagGrp);
}

void DxDiagGroup::pastebinLink()
{
    if(m_DxDiagFil->exists())
    {
        m_UploadStatutLbl->setMovie(m_WaitAnim);
        m_WaitAnim->start();

        m_PastUpTim->start(m_settingsHdr.TIMEOUT);

        m_UploadStatutBtn->setEnabled(false);

        m_pasteQuery->setKey(m_settingsHdr.PASTEBIN_API_KEY);
        m_pasteQuery->setName(m_settingsHdr.PASTEBIN_PASTE_NAME);
        m_pasteQuery->setExpire(m_settingsHdr.PASTEBIN_PASTE_DELAY);
        m_pasteQuery->setFormat(m_settingsHdr.PASTEBIN_PASTE_FORMAT);
        m_pasteQuery->setPrivate(m_settingsHdr.PASTEBIN_PASTE_PRIVACY);

        m_pasteQuery->publishPaste(m_DxDiagFil->readAll());
    }
    else
    {
        QToolTip::showText(m_DiagStatutBtn->mapToGlobal(QPoint()), tr("Générer d'abord votre rapport !"));
    }
}
