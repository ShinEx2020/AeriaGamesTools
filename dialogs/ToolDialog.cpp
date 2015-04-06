/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "ToolDialog.hpp"

ToolDialog::ToolDialog(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400, 280);
    setWindowFlags(Qt::FramelessWindowHint);
    setMask(QBitmap(":/mask/uimaskw"));

    directx();

    QPushButton *lab = new QPushButton(QIcon(":/icons/directx"), "DXDIAG");
        lab->setFixedHeight(30);
        lab->setObjectName("directxLabButton");
        lab->setStyleSheet("#directxLabButton{background-color: #aaa;"
                            "padding: 10px;"
                            "font-weight: bold;"
                            "border-radius: 0px;"
                            "border-top-left-radius: 15px;"
                            "border-bottom-left-radius: 15px;"
                            "color: black;}");

    m_pastebinLineEdit = new QLineEdit;
        m_pastebinLineEdit->setFixedHeight(30);
        m_pastebinLineEdit->setReadOnly(true);
        m_pastebinLineEdit->setStyleSheet("QLineEdit{border: 4px solid #aaa;"
                           "background-color: #eee;"
                           "color: black;}");

    QPushButton *push = new QPushButton(QIcon(":/icons/link"), "PARTAGEZ");
        push->setFixedHeight(30);
        push->setStyleSheet("QPushButton{background-color: #aaa;"
                            "padding: 10px;"
                            "border-radius: 0px;"
                            "border-top-right-radius: 15px;"
                            "border-bottom-right-radius: 15px;"
                            "color: black;}"
                            "QPushButton:hover{background-color: #fff;}");


    QHBoxLayout *hbox = new QHBoxLayout;
        hbox->setSpacing(0);
        hbox->addWidget(lab);
        hbox->addWidget(m_pastebinLineEdit);
        hbox->addWidget(push);

    connect(push, SIGNAL(clicked()), this, SLOT(pastebinLink()));

    setLayout(hbox);
}

void ToolDialog::directx()
{
    diagTXT = new QFile(QCoreApplication::applicationDirPath()+"/logs/dxdiag.txt");
        diagTXT->open(QIODevice::ReadOnly | QIODevice::Text);

    if(!diagTXT->exists())
    {
        m_directxDiag = new DxDiagPastebin;
        m_directxDiag->start();
    }
}

void ToolDialog::pastebinLink()
{
    m_pasteQuery = new QPastebinQuery(m_settings.PASTEBIN_API_KEY);
        m_pasteQuery->setName(m_settings.PASTEBIN_PASTE_NAME);
        m_pasteQuery->setExpire(m_settings.PASTEBIN_PASTE_DELAY);
        m_pasteQuery->setFormat(m_settings.PASTEBIN_PASTE_FORMAT);
        m_pasteQuery->setPrivate(m_settings.PASTEBIN_PASTE_PRIVACY);

    connect(m_pasteQuery, SIGNAL(linkAcquiered(QString)), m_pastebinLineEdit, SLOT(setText(QString)));

    m_pasteQuery->publishPaste(diagTXT->readAll());
}
