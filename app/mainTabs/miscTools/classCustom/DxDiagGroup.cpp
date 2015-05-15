#include "DxDiagGroup.hpp"

DxDiagGroup::DxDiagGroup()
{
    createObjects();
    createConnexions();
    createInterface();

    statutDiag();
}

void DxDiagGroup::createObjects()
{
    //GENERAL
    m_UploadLinkClp     = QApplication::clipboard();
    m_dxDiagFil         = new QFile;
    m_waitMov           = new QMovie;
    m_directxDiag       = new DirectXDiag;
    m_pasteQuery        = new QPastebinQuery;
    m_DxDiagGrd         = new QGridLayout;
    //DIAG
    m_DxDiagTim         = new QTimer;
    m_dxDiagIconLbl     = new QLabel;
    m_DiagLaunchBtn     = new QPushButton;
    m_DiagDateLbl       = new QLabel;
    //PASTEBIN
    m_PastUpTim         = new QTimer;
    m_UploadStatutLbl   = new QLabel;
    m_UploadStatutBtn   = new QPushButton;
    m_pastebinClipBtn   = new QPushButton;
    m_pastebinLineEdit  = new QLineEdit;
}
void DxDiagGroup::createConnexions()
{
    //DIAG
    connect(m_DiagLaunchBtn, SIGNAL(clicked()), this, SLOT(launchDxDiag()));
    connect(m_directxDiag, SIGNAL(finished()), this, SLOT(finishDxDiag()));
    connect(m_DxDiagTim, SIGNAL(timeout()), this, SLOT(timeoutDxDiag()));
    //PASTEBIN
    connect(m_UploadStatutBtn, SIGNAL(clicked()), this, SLOT(launchPastebin()));
    connect(m_pasteQuery, SIGNAL(linkAcquiered(QString)), this, SLOT(finishPastebin(QString)));
    connect(m_PastUpTim, SIGNAL(timeout()), this, SLOT(timeoutPastebin()));
    connect(m_pastebinClipBtn, SIGNAL(clicked()), this, SLOT(clipboardPastebin()));
}
void DxDiagGroup::createInterface()
{
    //GENERAL
    m_dxDiagFil->setFileName(QCoreApplication::applicationDirPath()+"/Storage/dxdiag.txt");
    m_dxDiagFil->open(QIODevice::Text | QIODevice::ReadOnly);

    m_waitMov->setFileName(":/icons/wait");

    m_DxDiagGrd->addWidget(new QLabel("Rapport :"),0,0,Qt::AlignRight);
    m_DxDiagGrd->addWidget(m_dxDiagIconLbl,0,1,Qt::AlignLeft);
    m_DxDiagGrd->addWidget(m_DiagLaunchBtn,0,2,Qt::AlignRight);
    m_DxDiagGrd->addWidget(new QLabel("Dernier :"),1,0,Qt::AlignRight);
    m_DxDiagGrd->addWidget(m_DiagDateLbl,1,1,1,2,Qt::AlignRight);
    m_DxDiagGrd->addWidget(new QLabel("Uploadé :"),2,0,Qt::AlignRight);
    m_DxDiagGrd->addWidget(m_UploadStatutLbl,2,1,Qt::AlignLeft);
    m_DxDiagGrd->addWidget(m_UploadStatutBtn,2,2,Qt::AlignRight);
    m_DxDiagGrd->addWidget(new QLabel("Partage :"),3,0,Qt::AlignRight);
    m_DxDiagGrd->addWidget(m_pastebinClipBtn,3,1,Qt::AlignRight);
    m_DxDiagGrd->addWidget(m_pastebinLineEdit,3,2,Qt::AlignRight);


    //DIAG
    m_DiagLaunchBtn->setObjectName("greenButton");


    //PASTEBIN
    m_UploadStatutLbl->setPixmap(QPixmap(":/icons/bad"));

    m_UploadStatutBtn->setText("Envoyer");
    m_UploadStatutBtn->setObjectName("greenButton");

    m_pastebinClipBtn->setIcon(QIcon(":/icons/clip"));
    m_pastebinClipBtn->setObjectName("noBorder");

    m_pastebinLineEdit->setObjectName("customLine");
    m_pastebinLineEdit->setReadOnly(true);


    //SETTINGS
    setTitle("Diagnotique DirectX");
    setLayout(m_DxDiagGrd);
    setFixedSize(280,150);
}

//SLOTS
void DxDiagGroup::launchDxDiag()
{
    m_dxDiagIconLbl->setMovie(m_waitMov);
    m_waitMov->start();

    m_directxDiag->start();
    m_directxDiag->setPath(m_dxDiagFil->fileName());

    m_DxDiagTim->start(m_dxDiagConf.DIAG_TIMEOUT);

    m_DiagLaunchBtn->setEnabled(false);
}
void DxDiagGroup::finishDxDiag()
{
    m_DxDiagTim->stop();

    m_DiagLaunchBtn->setEnabled(true);
    statutDiag();
}
void DxDiagGroup::timeoutDxDiag()
{
    finishDxDiag();

    m_directxDiag->terminate();
    m_directxDiag->wait();

    QToolTip::showText(m_DiagLaunchBtn->mapToGlobal(QPoint()), tr("Temps ecoulé, veuillez réessayer"));
}
void DxDiagGroup::statutDiag()
{
    if(m_dxDiagFil->exists())
    {
        m_dxDiagIconLbl->setPixmap(QPixmap(":/icons/good"));

        m_DiagLaunchBtn->setText("Refaire un Diag");

        m_DiagDateLbl->setText(QFileInfo(*m_dxDiagFil).lastModified().toString("Le dddd d MMMM yyyy à hh:mm:ss"));
    }
    else
    {
        m_dxDiagIconLbl->setPixmap(QPixmap(":/icons/bad"));

        m_DiagLaunchBtn->setText("Faire un Diag");

        m_DiagDateLbl->setText("Aucun rapport DirectX existant");
    }
}

void DxDiagGroup::launchPastebin()
{
    if(m_dxDiagFil->exists())
    {
        m_UploadStatutLbl->setMovie(m_waitMov);
        m_waitMov->start();

        m_PastUpTim->start(m_dxDiagConf.TIMEOUT);

        m_UploadStatutBtn->setEnabled(false);

        m_pasteQuery->setKey(m_dxDiagConf.PASTEBIN_API_KEY);
        m_pasteQuery->setName(m_dxDiagConf.PASTEBIN_PASTE_NAME);
        m_pasteQuery->setExpire(m_dxDiagConf.PASTEBIN_PASTE_DELAY);
        m_pasteQuery->setFormat(m_dxDiagConf.PASTEBIN_PASTE_FORMAT);
        m_pasteQuery->setPrivate(m_dxDiagConf.PASTEBIN_PASTE_PRIVACY);
        m_pasteQuery->publishPaste(m_dxDiagFil->readAll());//Envoyer le texte sur pastebin.com
    }
    else
    {
        QToolTip::showText(m_DiagLaunchBtn->mapToGlobal(QPoint()), tr("Générer d'abord votre rapport !"));
    }
}
void DxDiagGroup::finishPastebin(QString link)
{
    m_PastUpTim->stop();

    m_pastebinLineEdit->setText(link);

    m_UploadStatutLbl->setPixmap(QPixmap(":/icons/good"));
}
void DxDiagGroup::timeoutPastebin()
{
    m_PastUpTim->stop();

    QToolTip::showText(m_UploadStatutBtn->mapToGlobal(QPoint()), tr("Temps ecoulé, veuillez réessayer"));

    m_UploadStatutLbl->setPixmap(QPixmap(":/icons/bad"));

    m_UploadStatutBtn->setEnabled(true);
}
void DxDiagGroup::clipboardPastebin()
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
