/*
 *	Coaxial Software
 *	Copyright (c) 2007 - Giancarlo Bellido
 *
 *	interpreter.cpp
 *  
 */

#include "main.hpp"
#include "interpreter.hpp"
#include "grammar.hpp"

// Ok now here there is our stack declared at actions.hpp as extern of course
namespace logo { namespace action {
	QVector<qreal>				stack;
	QVector<QString>			strings;
	QHash<QString, QVariant>	variables;
}}

void logo::interpreter::parse(logo::action::IterT a, logo::action::IterT b)
{
	logo::grammar g;

	boost::spirit::parse(a, b, g, boost::spirit::space_p);

	// if (!stack.isEmpty || !strings.isEmpty)
}

