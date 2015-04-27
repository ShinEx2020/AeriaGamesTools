/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef TPUSHBUTTON_HPP
#define TPUSHBUTTON_HPP

#include <QtWidgets>
#include <QApplication>

class TPushButton : public QPushButton
{

public:

    explicit TPushButton(QWidget * parent = 0);
    explicit TPushButton(const QString & text, QWidget * parent = 0);

    void mousePressEvent(QMouseEvent *evt);// Mémorise les coordonnées du clic
    void mouseMoveEvent(QMouseEvent *evt);// La fenêtre bouge si on maintient le clic

private:

    QPoint          positionPoint;

    QWidget         *m_parentWidget;
};

#endif // TPUSHBUTTON_HPP
