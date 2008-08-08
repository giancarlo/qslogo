/**
 *
 * Turtle.cpp
 *
 */

#include "turtle.hpp"

// TODO setOffset code sets the turtle offset in its center. 
// This code might be better at another place.
logo::turtle::turtle(QGraphicsScene* scene)
{
	// NOTE I believe this is deleted automatically? 
	pixmap = scene->addPixmap(QPixmap(":/resources/turtle.png"));
	pixmap->setOffset(-pixmap->pixmap().width()/2,-pixmap->pixmap().height()/2);
}

qreal logo::turtle::x()
{
	return pixmap->x();
}

qreal logo::turtle::y()
{
	return pixmap->y();
}

void logo::turtle::forward(qreal count)
{
	pixmap->translate(0, -count);
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
	pixmap->moveBy(dx, dy);
}