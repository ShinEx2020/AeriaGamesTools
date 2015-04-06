/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "TPushButton.hpp"

TPushButton::TPushButton(QWidget * parent) : QPushButton(parent)
{

}
TPushButton::TPushButton(const QString & text, QWidget * parent) : QPushButton(text, parent)
{

}

void TPushButton::mousePressEvent(QMouseEvent *event)
{
    positionPoint = event->globalPos() - parentWidget()->parentWidget()->pos();
}

void TPushButton::mouseMoveEvent(QMouseEvent *event)
{
    const QPoint movePoint = event->globalPos() - positionPoint - pos();
    parentWidget()->parentWidget()->move(x() + movePoint.x(), y() + movePoint.y());
    positionPoint = event->globalPos() - parentWidget()->parentWidget()->pos();
}
