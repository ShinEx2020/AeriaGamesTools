/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef DirectXDiag_HPP
#define DirectXDiag_HPP

#include <QtWidgets>

class DirectXDiag : public QThread
{
    Q_OBJECT

public:
    DirectXDiag();

    void setPath(QString path);

    void run();

private:

    QProcess    *m_DxDiagPro;   // Processus du thread
    QString     m_CommandStr;       // Commande du thread
};

#endif // DirectXDiag_HPP
