/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "SPushButton.hpp"

SPushButton::SPushButton(QWidget * parent) : QPushButton(parent)
{

}
SPushButton::SPushButton(const QString & text, QWidget * parent) : QPushButton(text, parent)
{

}

void SPushButton::mousePressEvent(QMouseEvent *event)
{
    positionPoint = event->globalPos() - parentWidget()->pos();
}

void SPushButton::mouseMoveEvent(QMouseEvent *event)
{
    const QPoint movePoint = event->globalPos() - positionPoint - pos();
    parentWidget()->move(x() + movePoint.x(), y() + movePoint.y());
    positionPoint = event->globalPos() - parentWidget()->pos();
}
