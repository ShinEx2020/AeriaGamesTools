/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "About.hpp"

About::About()
{
    QFile *mTodoListFile = new QFile(":/texts/todolist");
        mTodoListFile->open(QIODevice::ReadOnly | QIODevice::Text);

    TPushButton *mPushInfo = new TPushButton("A PROPOS DE AERIAGAMES-TOOLS", this);
        mPushInfo->setFixedHeight(25);
        mPushInfo->setObjectName("titleButton");

    QPushButton *mPushClose = new QPushButton("X");
        mPushClose->setFixedSize(40, 25);
        mPushClose->setObjectName("closeButton");

    QHBoxLayout *mHboxTitle = new QHBoxLayout;
        mHboxTitle->addWidget(mPushInfo);
        mHboxTitle->addWidget(mPushClose);
        mHboxTitle->setSpacing(0);

    QPushButton *mLabel = new QPushButton();
        mLabel->setIcon(QIcon(":/misc/avatar"));
        mLabel->setIconSize(QSize(80,80));
        mLabel->setObjectName("avatarButton");
    QLabel *mLabelpseudo = new QLabel("FoxiesCuties");
        mLabelpseudo->setObjectName("pseudoLabel");

    QLabel *mLabelInfo2 = new QLabel("Outil dédié aux problèmes AeriaGames");
    QLabel *mLabelInfo3 = new QLabel("Compiler sous Qt "+QString(qVersion()));
    QLabel *mLabelInfo4 = new QLabel("Logiciel sous licence GPLv3");

    QGridLayout *mGridInfo = new QGridLayout;
        mGridInfo->addWidget(mLabel, 2, 0, 3, 0, Qt::AlignLeft);
        mGridInfo->addWidget(mLabelpseudo, 5, 0);
        mGridInfo->addWidget(mLabelInfo2, 2, 1, Qt::AlignLeft);
        mGridInfo->addWidget(mLabelInfo3, 3, 1, Qt::AlignLeft);
        mGridInfo->addWidget(mLabelInfo4, 4, 1, Qt::AlignLeft);

    QTextEdit *mTextEdit = new QTextEdit;
        mTextEdit->setReadOnly(true);
        mTextEdit->setHtml(mTodoListFile->readAll());

    QVBoxLayout *vBox = new QVBoxLayout;
        vBox->addLayout(mHboxTitle);
        vBox->addLayout(mGridInfo);
        vBox->addWidget(mTextEdit);

    connect(mPushClose, SIGNAL(clicked()), this, SLOT(close()));

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowModality(Qt::ApplicationModal);
    setFixedSize(550, 430);
    setLayout(vBox);
    setContentsMargins(-11, -11, -11, -11);
}
