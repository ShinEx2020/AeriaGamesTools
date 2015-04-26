#include "LogShare.hpp"

LogShare::LogShare()
{
    m_settings = new Settings;

    m_compress = new FilesCompress(m_settings->gamePath(0).toString());

    QFile *m_logsArchive = new QFile(QCoreApplication::applicationDirPath()+"/logs/edenlogs.7z");

    m_uplo = new FreeUpload(m_logsArchive);

    m_line = new QLineEdit("Cliquez pour obtenir un lien");
        m_line->setReadOnly(true);
        m_line->setStyleSheet("QLineEdit{border: 2px solid white; border-top-left-radius: 12px; border-bottom-left-radius: 12px;}");
        m_line->setFixedSize(200, 25);

    m_push = new QPushButton("PARTAGER");
        m_push->setFixedSize(100, 25);
        m_push->setStyleSheet("QPushButton{border-bottom-left-radius: 0px; border-top-left-radius: 0px; background: white; color: black;}");

    QHBoxLayout *hbox = new QHBoxLayout;
        hbox->addWidget(m_line, 0,Qt::AlignRight);
        hbox->addWidget(m_push, 0);
        hbox->setSpacing(0);



    connect(m_push, SIGNAL(clicked()), this, SLOT(logCompress()));
    connect(m_compress, SIGNAL(finished()), this, SLOT(logUpload()));
    connect(m_uplo, SIGNAL(replyLink(QString)), this, SLOT(logUrl(QString)));

    setLayout(hbox);
}

void LogShare::logCompress()
{
    m_compress->start();

    m_line->setText("Veuillez patientez");
    m_push->setText("COMPRESS...");
}

void LogShare::logUpload()
{
    m_line->setText("Veuillez patientez");
    m_push->setText("UPLOAD...");
    m_uplo->upload();
}

void LogShare::logUrl(QString url)
{
    m_url = url;
    m_line->setText("Recuperez le lien");
    m_push->setText("COPIEZ...");
    connect(m_push, SIGNAL(clicked()), this, SLOT(logClip()));
}

void LogShare::logClip()
{
    QClipboard  *m_clip = QApplication::clipboard();
    m_clip->setText(m_url);

    m_line->setText("Lien dans le presse-papier");
    m_push->setText("FINI !");
    m_push->setEnabled(false);
}
