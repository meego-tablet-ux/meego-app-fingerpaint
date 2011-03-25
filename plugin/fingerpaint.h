/*
 * Copyright 2011 Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at 
 * http://www.apache.org/licenses/LICENSE-2.0
 */

#ifndef FINGERPAINT_H
#define FINGERPAINT_H

#include <QGraphicsWidget>
#include <QImage>

class Fingerpaint : public QGraphicsWidget
{
    Q_OBJECT

public:
    Fingerpaint(QGraphicsItem *parent = 0);
    ~Fingerpaint();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void resizeEvent(QGraphicsSceneResizeEvent *event);
    bool sceneEvent(QEvent *event);

public slots:
    void clear();

private:
    QImage image;
    QList<QColor> colors;
    Q_DISABLE_COPY(Fingerpaint)
};

#endif // FINGERPAINT_H
