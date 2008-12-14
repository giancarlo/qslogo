/*
 *	
 *	Copyright (c) 2008 - Giancarlo Bellido
 *
 *	This file is part of qsLogo.
 *
 *  qsLogo is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  qsLogo is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with qsLogo.  If not, see <http://www.gnu.org/licenses/>.
 *  
 */

#include "main.hpp"
#include "actions.hpp"
#include "window.hpp"
#include "interpreter.hpp"

namespace logo {

	namespace action {

		void to(IterT start, IterT end)
		{
			LOGO_DEBUG(QString(start, end-start)); 
			QString name = stack.pop().toString();
			functions[name] = QString(start, end-start);
		}

		void make(IterT, IterT)
		{
			QVariant value = stack.pop();
			QString  name  = stack.pop().toString();
			variables[name] = value;
		}

		void thing(IterT, IterT)
		{
			QString name = stack.pop().toString();
			stack.push(variables[name]);
		}

		/*
		 *  Ok So the trick here is to reevaluate the string inside IterT and IterT.
		 *  It is always executed once.
		 *
		 *  Problems: This assumes the stack contains the repeat value. Which might not be right.
		 *  TODO Needs to be fixed. 
		 */
		void repeat(IterT start, IterT end)
		{
			for (int i = stack.pop().toInt(); i > 1; --i)
			{
				win->interpreter->parse(start, end);
			}
		}

		void call(IterT first, IterT last)
		{
			QString& hello = functions[QString(first, last-first)];
			win->interpreter->parse(hello.constBegin(), hello.constEnd());
		}

		void error(IterT first, IterT last)
		{
			QString x(first, last-first);
			x.prepend("I don't know how to ");
			win->statusBar()->showMessage(x);
		}

	}
}

