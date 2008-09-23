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

#ifndef LOGO_GRAMMAR_HPP
#define LOGO_GRAMMAR_HPP

#include <boost/spirit/core.hpp>
#include <boost/spirit/utility/confix.hpp>
//#include <QGraphicsScene>

#include "actions.hpp"

namespace logo
{

	struct grammar : public boost::spirit::grammar<grammar>
    {

		/*
		 *	Initialize the stupid scene
		 */		 
		template <typename ScannerT>
        struct definition
        {

			boost::spirit::rule<ScannerT>  
				expression, statement, identifier, statements,
				// Addons
				get,
				// Turtle Position
				xcor, ycor,
				// turtle stuff
				pen,
				// Algebra!
				sum, difference, negate, product, divide, sqrt, power, sqr,
				// Data
				make, list,
				// Primitives
				forward, left, right, back,
				cs,
				print, exit,
				// Control Structures
				repeat,
				// Types
				string, number,
				// Other
				eol, invalid, end, comment,
				// Functions
				to, other
			;

			definition(grammar const& self)  
			{
				using namespace boost::spirit;

				eol			=	(*eol_p | +space_p);

				number		= real_p[&logo::action::number];
				string		= confix_p('[', (*graph_p)[&logo::action::string], ']');

				expression	= string | number;
				identifier  = lexeme_d[+alnum_p];

				/*sum			= (lexeme_d[str_p("sum")] >> number >> eol)[&logo::action::sum];
				difference	= (lexeme_d[str_p("dif")] >> number >> eol)[&logo::action::dif];
				product		= (lexeme_d[str_p("prod")]>> number >> eol)[&logo::action::product];
				divide		= (lexeme_d[str_p("div")] >> number >> eol)[&logo::action::divide];
				negate		= (lexeme_d[str_p("neg")] >> number >> eol)
				*/
				repeat	= (str_p("repeat") >> number
										>> confix_p('[', *statement, ']')
									>> end)[&logo::action::repeat];

				sqr			= (str_p("sqr") >> number >> eol)[&logo::action::sqr];
				make		= (str_p("make") >> identifier >> expression >> eol)[&logo::action::make];

				forward		= (str_p("forward") | str_p("fd") >>  number >> eol)[&logo::action::forward];
				back		= (str_p("back") | str_p("bk") >> number >> eol)[&logo::action::back];
				right		= (str_p("right") | str_p("rt") >> number >> eol)[&logo::action::right];
				left		= (str_p("left")  | str_p("lt") >> number >> eol)[&logo::action::left];


				xcor		=	str_p("xcor")[&logo::action::xcor] >> eol;
				ycor		=	str_p("ycor")[&logo::action::ycor] >> eol;
				
				get			=	str_p("get") >> +space_p >> 
									str_p("turtle") >> +space_p >> 
										(
										str_p("x")[&logo::action::xcor] |
										str_p("y")[&logo::action::ycor]
										)
								>> eol;

				cs			=	(
									str_p("cs") | 
									(str_p("clear") >> str_p("screen"))
								) [ &logo::action::clear_screen ]
								>> eol;

				end			= str_p("end") >> eol;
				to			= (str_p("to") >> identifier[&logo::action::to]) 
									>> *statement 
									>> end;

				pen			= str_p("pen") >>
										(str_p("up")[&logo::action::penup] |
										str_p("down")[&logo::action::pendown])
									>> eol;

				comment = ch_p(';') >> (*graph_p - eol) >> eol;

				other   = identifier[&logo::action::call];

				print		= (str_p("print") >> expression)[&logo::action::print] >> eol;
				exit		= str_p("exit")[&logo::action::exit] >> eol;
				//invalid		= (*graph_p);
				statement	=	(
								back | forward | right | left |
								xcor | ycor | pen |
								print | cs | get | 
								exit | other | comment
								);

				statements = *statement;
			}
           
			boost::spirit::rule<ScannerT> const& start() const 
			{ 
				return statements; 
			}

        };
    };

}



#endif
