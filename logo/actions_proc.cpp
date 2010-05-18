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

#include <cstdio>

namespace logo {

	namespace action {

		QString scope;
		QStack<logo::action::call_struct> call_stack;

		double _repcount=-1; // Stores repcount value

		inline QVariant& getVariable(QString name)
		{
			QString id = QString::number(call_stack.last().id) + name;
			return variables[id];
		}

		inline void setVariable(QString name, QVariant value)
		{
			getVariable(name) = value;
		}	

		void method_name(IterT start, IterT end)
		{
			scope = QString(start, end-start);
			functions[scope].args.clear();
		}

		void arg(IterT s, IterT e)
		{
			functions[scope].args.push_front(QString(s, e-s));
		}

		void to(IterT start, IterT end)
		{
			functions[scope].code = QString(start, end-start);
			LOGO_DEBUG("Function added: \"" + scope + '(' + QString::number(functions[scope].args.count()) + ")\"");
			LOGO_DEBUG(functions[scope].code);
		}

		void make(IterT, IterT)
		{
			QVariant value = stack.pop();
			QString  name  = ":" + stack.pop().toString();
			setVariable(name, value);
		}

		void thing(IterT, IterT)
		{
			QString name = stack.pop().toString();
			stack.push(getVariable(name));
		}

		void var(IterT a, IterT b)
		{
			QString name(a, b-a);
			stack.push(getVariable(name).toDouble());
		}

		void _if(IterT, IterT)
		{
			QString code = stack.pop().toString();
			bool condition = stack.pop().toBool();
			if (condition)
			{
				win->interpreter->parse(code);
			}
		}

		void ifelse(IterT, IterT)
		{
			QString else_code = stack.pop().toString();
			QString code = stack.pop().toString();
			bool condition = stack.pop().toBool();

			win->interpreter->parse(condition ? code : else_code);
		}

		void repeat(IterT, IterT)
		{
			QString block = stack.pop().toString();
			int start = stack.pop().toInt();

			for (int i = start; i > 0; --i)
			{
				_repcount = start - i + 1; // To implement repcount command. This is not thread safe.
				win->interpreter->parse(block);
			}
			_repcount = -1;
		}

		/**
		 * Outputs the repetition count of the innermost current REPEAT or FOREVER, starting from 1.
		 */
		void repcount(IterT, IterT)
		{
			stack.push(_repcount);
		}

		/** NOTE: Check if the function exists is done in the parser. No Need to do it here */
		void call(IterT first, IterT last)
		{
			scope = QString(first, last-first); // + QString::number(++i));
		}

		void do_call(IterT, IterT)
		{
			logo::function& f = functions[scope];
			call_stack.push(call_struct(scope));

			for (QVector<QString>::const_iterator i = f.args.begin();
				i != f.args.end(); ++i)
			{
				QVariant value = stack.pop();
				setVariable(*i, value); //stack.pop();
			}

			//logo::win->scene->up;
			
			try {
				win->interpreter->parse(functions[scope].code);
			} catch(QVariant& ret)
			{
				LOGO_DEBUG("Function returned: " + ret.toString());// push ret?
			} 

			scope = call_stack.pop().function_name;
		}

		void stop(IterT, IterT)
		{
			throw QVariant(0); //fn_return();
		}

		void error(IterT first, IterT last)
		{
			QString x(first, last-first);
			x.prepend("I don't know how to ");
#ifdef LOGO_DEBUG_ENABLE
			LOGO_DEBUG(x);
#endif
			throw x;
		}

	}
}

