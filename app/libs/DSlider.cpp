/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "DSlider.hpp"

DSlider::DSlider(QWidget *parent) : QSlider(parent)
{
    connect(this, SIGNAL(valueChanged(int)), this, SLOT(DValueChanged(int)));
}
DSlider::DSlider(Qt::Orientation orientation, QWidget *parent) : QSlider(orientation, parent)
{
    connect(this, SIGNAL(valueChanged(int)), this, SLOT(DValueChanged(int)));
}

double DSlider::valueDouble()
{
    double deci = value();

    return deci / 10.0;
}

void DSlider::setValueDouble(double value)
{
    setValue(value*10);
}

void DSlider::DValueChanged(int value)
{
    double doubleValue = value / 10.0;
    emit doubleValueChanged(doubleValue);
}
