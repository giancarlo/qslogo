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

#ifndef LOGO_ACTIONS_HPP
#define LOGO_ACTIONS_HPP

#include <QtCore/QStack>
#include <QtCore/QHash>
#include <QtCore/QVariant>

namespace logo
{
	namespace action {

		/**
		 *	qreal Stack. I could use QStack but it is the same thing, so i refuse to.
		 */
		extern QStack<QVariant>							stack;
		extern QVector<QString>						strings;
		extern QHash<QString, QVariant>		variables;

		///	Print will print text on screen. 
		void print(IterT, IterT);
		/// Clear screen.
		void clear_screen(IterT, IterT);
		/// Exits application.
		void exit(IterT, IterT);
		/// Define a variable
		void make(IterT, IterT);

		void repeat(IterT, IterT);

		/*
		 *	Turtle Actions and Queries
		 *	logo/actions_turtle.cpp
		 */
		void xcor(IterT, IterT);
		void ycor(IterT, IterT);
		void penup(IterT, IterT);
		void pendown(IterT, IterT);
		void home(IterT, IterT);

		void string(IterT, IterT);
		void number(float);

		// Arithmetic (actions_arit.cpp)
		void sqr(IterT, IterT);
		void sum(IterT, IterT);
		void dif(IterT, IterT);
		void product(IterT, IterT);
		void divide(IterT, IterT);
		void negate(IterT, IterT);
		
		void forward(IterT, IterT);
		void back(IterT, IterT);
		void right(IterT, IterT);
		void left(IterT, IterT);

		void to(IterT, IterT);
		void call(IterT, IterT);
	
	}

}

#endif
