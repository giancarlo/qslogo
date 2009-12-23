/**
 *
 * Turtle.cpp
 *
 */

#include "turtle.hpp"

// TODO setOffset code sets the turtle offset in its center. 
// This code might be better at another place.
logo::turtle::turtle(QGraphicsScene* scenes)
{
	// NOTE I believe this is deleted automatically? 
	pixmap = scenes->addPixmap(QPixmap(":/resources/turtle.png"));
	pixmap->setOffset(-pixmap->pixmap().width()/2,-pixmap->pixmap().height()/2);
	scene  = scenes;
	pen.setWidth(1);
}

QGraphicsPixmapItem* logo::turtle::item()
{
	return pixmap;
}

void logo::turtle::setpen(logo::pen what)
{
	switch (what) {
	case logo::up   : pen.setStyle(Qt::NoPen); break;
	case logo::down : pen.setStyle(Qt::SolidLine); break;
	/* TODO Implement */
	case logo::erase : break;
	default:
		;
	};	
}

QPen& logo::turtle::Pen()
{
	return pen;
}

void logo::turtle::reset()
{
	pixmap->resetTransform();
}

qreal logo::turtle::x()
{
	return pixmap->transform().dx();
}

qreal logo::turtle::y()
{
	return pixmap->transform().dy();
}

const QPointF logo::turtle::pos()
{
	return QPointF(x(), y());
}

void logo::turtle::forward(qreal count)
{
	QPointF last(pixmap->scenePos());
	pixmap->translate(0, -count);
	scene->addLine(QLineF(last, pixmap->scenePos()), pen);
}

void logo::turtle::backward(qreal count)
{
	forward(-count);
}

void logo::turtle::rotate(qreal degree)
{
	pixmap->rotate(degree);
}

void logo::turtle::moveBy(qreal dx, qreal dy)
{
	pixmap->translate(dx, dy);
}

void logo::turtle::circle(qreal radius)
{
	// Calculate Rect
	qreal t = radius * COS45;
	QGraphicsEllipseItem* i = scene->addEllipse(-t, -t, t+t, t+t, pen);
	i->setPos(x(), y());
}

