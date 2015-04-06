/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef SPUSHBUTTON_HPP
#define SPUSHBUTTON_HPP

#include <QtWidgets>
#include <QApplication>

class SPushButton : public QPushButton
{

public:

    explicit SPushButton(QWidget * parent = 0);
    explicit SPushButton(const QString & text, QWidget * parent = 0);

    void mousePressEvent(QMouseEvent *evt);// Mémorise les coordonnées du clic
    void mouseMoveEvent(QMouseEvent *evt);// La fenêtre bouge si on maintient le clic

private:

    QPoint          positionPoint;
};

#endif // SPUSHBUTTON_HPP
