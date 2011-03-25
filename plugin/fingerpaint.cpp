/*
 * Copyright 2011 Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at 
 * http://www.apache.org/licenses/LICENSE-2.0
 */

#include <QDebug>
#include <QtDeclarative/qdeclarative.h>
#include <QPainter>

#include "fingerpaint.h"

Fingerpaint::Fingerpaint(QGraphicsItem *parent):
        QGraphicsWidget(parent)
{
    colors << QColor("red")
            << QColor("green")
            << QColor("blue")
            << QColor("yellow")
            << QColor("orange")
            << QColor("gray")
            << QColor("lightsteelblue")
            << QColor("darkred")
            << QColor("black")
            << QColor("magenta");
    setAcceptTouchEvents(true);
}

Fingerpaint::~Fingerpaint()
{
}

void Fingerpaint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawImage(QPoint(0,0), image);
}

void Fingerpaint::resizeEvent(QGraphicsSceneResizeEvent *event)
{
    QImage i(QSize(boundingRect().width(), boundingRect().height()), QImage::Format_RGB32);
    i.fill(qRgb(255, 255, 255));
    QPainter painter(&i);
    painter.drawImage(QPoint(0, 0), image);
    image = i;

    QGraphicsWidget::resizeEvent(event);
}

bool Fingerpaint::sceneEvent(QEvent *event)
{
    if (event->type() == QEvent::TouchBegin ||
        event->type() == QEvent::TouchEnd ||
        event->type() == QEvent::TouchUpdate)
    {
        QList<QTouchEvent::TouchPoint> touchPoints =
                static_cast<QTouchEvent *>(event)->touchPoints();
        foreach (const QTouchEvent::TouchPoint &touchPoint, touchPoints)
        {
            if (touchPoint.state() == Qt::TouchPointStationary)
                continue;

            QRectF rect = touchPoint.rect();
            if (rect.isEmpty())
            {
                qreal diameter = qreal(50) * touchPoint.pressure();
                rect.setSize(QSizeF(diameter, diameter));
            }

            QPainter painter(&image);
            painter.setPen(Qt::NoPen);
            painter.setBrush(colors.at(touchPoint.id() % colors.count()));
            painter.drawEllipse(rect);
            painter.end();

            update(rect.toRect().adjusted(-2,-2, +2, +2));
        }

        return true;
    }

    return QGraphicsWidget::event(event);
}

void Fingerpaint::clear()
{
    image.fill(qRgb(255, 255, 255));
    update();
}

QML_DECLARE_TYPE(Fingerpaint);
