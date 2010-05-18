/*
 *	
 *	Copyright (c) 2008 - Giancarlo Bellido
 *
 *	This file is part of qsLogo.
 *
 *  Foobar is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Foobar is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *  
 */

#ifndef LOGO_TURTLE_HPP
#define LOGO_TURTLE_HPP

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "window.hpp"

#define COS45 (0.70710678)

namespace logo {

	enum pen { up, down, erase };

	class turtle
	{
		QGraphicsPixmapItem* pixmap;
		QGraphicsScene*      scene;
		QPen                 pen;

		public:

			turtle(QGraphicsScene*);
			
			// Sets Pen up(true) or down
			void setpen(logo::pen);
			// Returns current pen
			QPen& Pen();
	
			void moveBy(qreal, qreal);
			void moveTo(qreal, qreal);
			void forward(qreal count);
			void backward(qreal count);
			void rotate(qreal degree);

			QGraphicsEllipseItem* circle(qreal radius);
			QGraphicsEllipseItem* arc(qreal degree, qreal radius);

			QGraphicsPixmapItem* item();

			void reset();
			void home();

			qreal x();
			qreal y();
			const QPointF pos();

	};

}

#endif
