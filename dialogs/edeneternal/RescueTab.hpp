/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef RESCUETAB_HPP
#define RESCUETAB_HPP

#include <QtWidgets>

#include "utils/FreeUpload.hpp"
#include "utils/widgets/NlsStatut.hpp"
#include "utils/widgets/LogShare.hpp"

class RescueTab : public QWidget
{
    Q_OBJECT

public:
    RescueTab(QWidget *parent = 0);

public slots:

    bool nlsExist(QString);

    void logsGroup();
    void nlsGroup();

private:

    LogShare    *m_logsSha;

    NlsStatut   *m_nlsWid;
    NlsStatut   *m_nlsWid2;
    NlsStatut   *m_nlsWid3;
    NlsStatut   *m_nlsWid4;

    QGroupBox   *m_logsGrp;
    QGroupBox   *m_nlsGrp;

    FreeUpload  *m_uplo;
    QLineEdit   *m_line;
    QPushButton *m_push;

};

#endif // RESCUETAB_HPP
