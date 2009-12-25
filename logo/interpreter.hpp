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

#ifndef LOGO_INTERPRETER_HPP
#define LOGO_INTERPRETER_HPP

//#include "stack.hpp"
//#include "symboltable.hpp"

#include <QtCore/QStack>
#include <QtCore/QVector>
#include <Qthread>

#include "main.hpp"

namespace logo
{
	/**
	 *	Interpreter Class
	 *
	 *	This class parses and 
	 */
	class interpreter
	{
	protected:

		//QStack 
		
	public:


		/**
		 *	Parses the data contained in the pointers (first to last).
		 *	Throws an exception only if an error occurs.
		 */
		void parse(QString code);
		void parse(logo::action::IterT s, logo::action::IterT e);
	};
}

#endif

