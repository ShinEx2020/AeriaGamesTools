/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "TPushButton.hpp"

TPushButton::TPushButton(QWidget * parent) : QPushButton(parent)
{
    m_parentWidget = parent;
}
TPushButton::TPushButton(const QString & text, QWidget * parent) : QPushButton(text, parent)
{
    m_parentWidget = parent;
}

void TPushButton::mousePressEvent(QMouseEvent *event)
{
    positionPoint = event->globalPos() - m_parentWidget->pos();
}
void TPushButton::mouseMoveEvent(QMouseEvent *event)
{
    const QPoint movePoint = event->globalPos() - positionPoint - pos();
    m_parentWidget->move(x() + movePoint.x(), y() + movePoint.y());
}
