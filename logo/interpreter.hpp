/**
 *	Logo Interpreter
 *	This file contains the interpreter which encapsulates the spirit grammar or w/e grammar
 *	we decide to use. 
 */

#ifndef LOGO_INTERPRETER_HPP
#define LOGO_INTERPRETER_HPP

#include "stack.hpp"
//#include "symboltable.hpp"

#include <QtCore/QStack>
#include <QtCore/QVector>

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
		void parse(const char* first, const char* last);
	};
}

#endif