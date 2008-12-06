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

namespace logo {

	enum pen { up, down, erase };

	class turtle
	{
		QGraphicsPixmapItem* pixmap;
		QGraphicsScene*      scene;
		QPen								 pen;

		public:

			turtle(QGraphicsScene*);
			
			// Sets Pen up(true) or down
			void setpen(logo::pen);
	
			void moveBy(qreal, qreal);
			void forward(qreal count);
			void backward(qreal count);
			void rotate(qreal degree);

			QGraphicsPixmapItem* item();

			void reset();

			qreal x();
			qreal y();
			const QPointF pos();

	};

}

#endif
