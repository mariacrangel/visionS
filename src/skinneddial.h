/*

Copyright (c) 2012 Dynamic Perception

  This software is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This software is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this software.  If not, see <http://www.gnu.org/licenses/>.

  */

#ifndef SKINNEDDIAL_H
#define SKINNEDDIAL_H

#include <QDial>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QTransform>

class SkinnedDial : public QDial
{
    Q_OBJECT
        /** Background Image Property

          Sets the background image for the dial (the dial its self, and any surrounding decoration).
          */
    Q_PROPERTY(QPixmap backgroundImage READ backgroundImage WRITE setBackgroundImage DESIGNABLE true)
        /** Needle Image Property

          Sets the needle (pointer) image, to be drawn over the dial. Must be the same width and height
          as the background image, and transparent everywhere the needle isn't.
          */
    Q_PROPERTY(QPixmap needleImage READ needleImage WRITE setNeedleImage DESIGNABLE true)
        /** Maximum Rotation Angle Property

          Sets the maximum angle at which the needle may be rotated on either side of the dial
          */
    Q_PROPERTY(float maxAngle READ maxAngle WRITE setMaxAngle DESIGNABLE true)

public:
    explicit SkinnedDial(QWidget *parent = 0);
    SkinnedDial(QPixmap* c_back, QPixmap* c_needle, float c_angle, QWidget *parent = 0);

    ~SkinnedDial();

    QPixmap backgroundImage();
    void setBackgroundImage(QPixmap p_img);

    QPixmap needleImage();
    void setNeedleImage(QPixmap p_img);

    float maxAngle();
    void setMaxAngle(float p_angle);

protected:

    void paintEvent(QPaintEvent *pe);

signals:

public slots:

private:

    QPixmap* m_background;
    QPixmap* m_needle;
    QPainter::RenderHint m_paintFlags;
    float m_maxDeg;

    QPixmap* m_cacheBackground;
    QPixmap* m_cacheNeedle;

    int m_cacheVal;
    int m_cacheWidth;
    int m_cacheHeight;

    QPixmap _rotatePix(QPixmap* p_pix, float p_deg, bool p_dir);

};

#endif // SKINNEDDIAL_H
