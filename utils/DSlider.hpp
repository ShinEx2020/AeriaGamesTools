/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef DSLIDER_HPP
#define DSLIDER_HPP

#include <QtWidgets>

class DSlider : public QSlider
{
    Q_OBJECT

public:

    explicit DSlider(QWidget *parent = 0);
    explicit DSlider(Qt::Orientation orientation, QWidget *parent = 0);

    double valueDouble();
    void setValueDouble(double value);

signals:

    void doubleValueChanged(double value);

public slots:

    void DValueChanged(int value);
};

#endif // DSLIDER_HPP
