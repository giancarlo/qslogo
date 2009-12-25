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
#include "interpreter.hpp"
#include "grammar.hpp"
#include "window.hpp"

// Ok now here there is our stack declared at actions.hpp as extern of course
namespace logo { namespace action {
	QStack<QVariant>		stack;
	QHash<QString, QVariant>	variables;
	QHash<QString, logo::function>	functions;
}}

void logo::interpreter::parse(QString code)
{
	parse(code.constBegin(), code.constEnd());
}

void logo::interpreter::parse(logo::action::IterT s, logo::action::IterT e)
{
	logo::grammar g;

	try {
		LOGO_SPIRIT_NS::parse(s, e, g, LOGO_SPIRIT_NS::space_p);
	} catch(QString& e)
	{
		win->statusBar()->showMessage(e);
	}

	//LOGO_DEBUG("Stack Size: " + logo::action::stack.size());
	logo::action::stack.clear();
}

