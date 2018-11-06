/* -*- c-basic-offset: 4 indent-tabs-mode: nil -*-  vi:set ts=8 sts=4 sw=4: */

/*
    Sonic Visualiser
    An audio file viewer and annotation editor.
    Centre for Digital Music, Queen Mary, University of London.
    This file copyright 2006-2007 Chris Cannam and QMUL.
   
    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.  See the file
    COPYING included with this distribution for more information.
*/

#ifndef SV_PAINT_ASSISTANT_H
#define SV_PAINT_ASSISTANT_H

#include <QRect>
#include <QPen>
#include <vector>

class QPainter;
class Layer;
class LayerGeometryProvider;

class PaintAssistant
{
public:
    enum Scale { LinearScale, MeterScale, dBScale };

    static void paintVerticalLevelScale(QPainter &p, QRect rect,
                                        double minVal, double maxVal,
                                        Scale scale, int &multRtn,
                                        std::vector<int> *markCoordRtns = 0);

    static int getYForValue(Scale scale, double value,
                            double minVal, double maxVal,
                            int minY, int height);

    enum TextStyle {
        BoxedText,
        OutlinedText,
        OutlinedItalicText
    };

    static void drawVisibleText(const LayerGeometryProvider *,
                                QPainter &p, int x, int y,
                                QString text, TextStyle style);

    /**
     * Scale up a size in pixels for a hi-dpi display without pixel
     * doubling. This is like ViewManager::scalePixelSize, but taking
     * and returning floating-point values rather than integer
     * pixels. It is also a little more conservative - it never
     * shrinks the size, it can only increase or leave it unchanged.
     */
    static double scaleSize(double size);

    /**
     * Scale up pen width for a hi-dpi display without pixel doubling.
     * This is like scaleSize except that it also scales the
     * zero-width case.
     */
    static double scalePenWidth(double width);

    /**
     * Apply scalePenWidth to a pen.
     */
    static QPen scalePen(QPen pen);
};

#endif
