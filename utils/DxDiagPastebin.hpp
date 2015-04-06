/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef DXDIAGPASTEBIN_H
#define DXDIAGPASTEBIN_H

#include <QtWidgets>

class DxDiagPastebin : public QThread
{
    Q_OBJECT

public:
    DxDiagPastebin();

    void run();

private:
    QProcess *m_dxdiagProcess;

    QFile   *m_TXT;
};

#endif // DXDIAGPASTEBIN_H
