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
	struct function {
		QString code;
		QVector<QString> args;
	};

	struct fn_return {
		QVariant value;
	};

	namespace action {
	
		struct call_struct
		{
			int id;
			QString function_name;

			void get_id()
			{
				static int i = 0;
				id = ++i;
			}

			call_struct()
			{
				get_id();
			}

			call_struct(const QString& fn_name)
			{		
				get_id();
				function_name = fn_name;
			}
		};

		extern QStack<QVariant>         stack;
		extern QHash<QString, QVariant> variables;
		extern QHash<QString, logo::function>  functions;
		extern QStack<call_struct> call_stack;
		extern QString scope;

		///	Print will print text on screen. 
		void print(IterT, IterT);
		/// Clear screen.
		void clear_screen(IterT, IterT);
		/// Exits application.
		void exit(IterT, IterT);
		/// Define a variable
		void make(IterT, IterT);
		/// GETS a variable
		void thing(IterT, IterT);

		void repeat(IterT, IterT);
		void repcount(IterT, IterT);
		void sqrt(IterT, IterT);

		/*
		 *	Turtle Actions and Queries
		 *	logo/actions_turtle.cpp
		 */
		void xcor(IterT, IterT);
		void ycor(IterT, IterT);
		void penup(IterT, IterT);
		void pendown(IterT, IterT);
		void penwidth(IterT, IterT);
		void home(IterT, IterT);
		void setx(IterT, IterT);
		void sety(IterT, IterT);
		void setxy(IterT, IterT);
		void setcolor(IterT, IterT);

		void circle(IterT, IterT);
		void arc(IterT, IterT);

		void string(IterT, IterT);
		void number(float);

		// Arithmetic (actions_arit.cpp)
		void sqr(IterT, IterT);
		void sum(IterT, IterT);
		void dif(IterT, IterT);
		void product(IterT, IterT);
		void divide(IterT, IterT);
		void negate(IterT, IterT);
		void gt(IterT, IterT);
		void gte(IterT, IterT);
		void lt(IterT, IterT);
		void lte(IterT, IterT);
		void eq(IterT, IterT);
		void mod(IterT, IterT);
		void random(IterT, IterT);
		void cos(IterT, IterT);
		
		void forward(IterT, IterT);
		void back(IterT, IterT);
		void right(IterT, IterT);
		void left(IterT, IterT);

		void to(IterT, IterT);
		void call(IterT, IterT);
		void error(IterT, IterT);
		void var(IterT, IterT);
		void arg(IterT, IterT);
		void method_name(IterT, IterT);
		void do_call(IterT, IterT);
		void stop(IterT, IterT);

		void _if(IterT, IterT);
		void ifelse(IterT, IterT);

		void edit(IterT, IterT);
		void save(IterT, IterT);
	
	}

}

#endif
