/*
 *	Coaxial Software
 *	Copyright (c) 2007 - Giancarlo Bellido
 *
 *	actions.hpp
 *		Define the actions called by the grammar. To speed up compilation only 
 *		function definitions will be allowed here. 
 */

#ifndef LOGO_ACTIONS_HPP
#define LOGO_ACTIONS_HPP

#include <QtCore/QVector>
#include <QtCore/QHash>
#include <QtCore/QVariant>

namespace logo
{
	namespace action {

		/**
		 *	qreal Stack. I could use QStack but it is the same thing, so i refuse to.
		 */
		extern QVector<qreal>				stack;
		extern QVector<QString>				strings;
		extern QHash<QString, QVariant>		variables;

		///	Print will print text on screen. 
		void print(IterT, IterT);
		/// Clear screen.
		void clear_screen(IterT, IterT);
		/// Exits application.
		void exit(IterT, IterT);
		/// Define a variable
		void make(IterT, IterT);

		/*
		 *	Turtle Actions and Queries
		 */
		/// Returns X Coordinate
		void xcor(IterT, IterT);
		/// Returns Y Coordinate
		void ycor(IterT, IterT);

		void string(IterT, IterT);
		void number(float);

		// Arithmetic
		void sqr(IterT, IterT);
		
		void forward(IterT, IterT);
		void back(IterT, IterT);
		void right(IterT, IterT);
		void left(IterT, IterT);
	
	}

}

#endif