/**
 *
 * Turtle.cpp
 *
 */

#include "turtle.hpp"
#include <cmath>

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

void logo::turtle::home()
{
	pixmap->resetTransform();
}

void logo::turtle::reset()
{
	home();
	setpen(logo::down);
	pen.setColor(QColor(0,0,0));
	pen.setWidth(1);
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
	moveBy(0, -count);
}

void logo::turtle::backward(qreal count)
{
	forward(-count);
}

void logo::turtle::rotate(qreal degree)
{
	pixmap->rotate(degree);
}

/**
 * Moves and Draws turtle by dx, dy
 */
void logo::turtle::moveBy(qreal dx, qreal dy)
{
	QPointF last(pixmap->scenePos());
	pixmap->translate(dx, dy);
	scene->addLine(QLineF(last, pixmap->scenePos()), pen);
}

void logo::turtle::moveTo(qreal x, qreal y)
{
	// TODO Assuming no scaling or shearing, this will work.
	qreal ix = this->x();
	qreal iy = this->y();
	qreal r = ::acos(pixmap->transform().m11());

	scene->addLine(ix, iy, x, y, pen);

	QTransform t;
	t.translate(x, y);
	t.rotateRadians(r);
	pixmap->setTransform(t);
}

QGraphicsEllipseItem* logo::turtle::circle(qreal radius)
{
	// Calculate Rect
	qreal t = radius * COS45;
	QGraphicsEllipseItem* i = scene->addEllipse(-t, -t, t+t, t+t, pen);
	i->setPos(x(), y());
	return i;
}

QGraphicsEllipseItem* logo::turtle::arc(qreal degree, qreal radius)
{
	QGraphicsEllipseItem* i = circle(radius);
	i->setSpanAngle(degree * 16);
	return i;
}

