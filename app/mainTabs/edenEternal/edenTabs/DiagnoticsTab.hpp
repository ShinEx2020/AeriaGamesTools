/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef DIAGNOTICSTAB_HPP
#define DIAGNOTICSTAB_HPP

#include <QtWidgets>

#include "app/libs/FreeUpload.hpp"
#include "app/mainTabs/edenEternal/classCustom/NlsStatut.hpp"
#include "app/mainTabs/edenEternal/classCustom/LogShare.hpp"

class DiagnoticsTab : public QWidget
{
    Q_OBJECT

public:
    DiagnoticsTab(QWidget *parent = 0);

public slots:

    bool nlsExist(QString);

    void logsGroup();
    void nlsGroup();

private:

    LogShare    *m_logsSha;
    NlsStatut   *m_nlsGrp;


    FreeUpload  *m_uplo;
    QLineEdit   *m_line;
    QPushButton *m_push;

};

#endif // DIAGNOTICSTAB_HPP
