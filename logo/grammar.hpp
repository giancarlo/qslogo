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
				expression, statement, identifier,
				// Addons
				get,
				// Turtle Position
				xcor, ycor,
				// Algebra!
				sum, difference, negate, product, divide, sqrt, power, sqr,
				// Data
				make,
				// Primitives
				forward, left, right, back,
				cs,
				print, exit,
				// Types
				string, number,
				// Other
				eol, invalid;
			
			definition(grammar const& self)  
			{
				using namespace boost::spirit;

				eol			=	(*eol_p | +space_p);

				number		= real_p[&logo::action::number];
				string		= confix_p('"', (*graph_p)[&logo::action::string], '"');
				expression	= string | number;
				identifier  = lexeme_d[+alnum_p];

				//sum			= (lexeme_d[str_p("sum")] >> number >> eol)[&logo::action::sum];
				//difference	= (lexeme_d[str_p("dif")] >> number >> eol)[&logo::action::dif];
				//product		= (lexeme_d[str_p("prod")]>> number >> eol)[&logo::action::product];
				//divide		= (lexeme_d[str_p("div")] >> number >> eol)[&logo::action::divide];
				//negate		= (lexeme_d[str_p("neg")] >> number >> eol)
				sqr			= (lexeme_d[str_p("sqr")] >> number >> eol)[&logo::action::sqr];
				make		= (lexeme_d[str_p("make")] >> identifier >> expression >> eol)[&logo::action::make];

				forward		= (lexeme_d[str_p("forward") | str_p("fd")] >>  number >> eol)[&logo::action::forward];
				back		= (lexeme_d[str_p("back") | str_p("bk")] >> number >> eol)[&logo::action::back];
				right		= (lexeme_d[str_p("right") | str_p("rt")] >> number >> eol)[&logo::action::right];
				left		= (lexeme_d[str_p("left")  | str_p("lt")] >> number >> eol)[&logo::action::left];


				xcor		=	lexeme_d[str_p("xcor")][&logo::action::xcor] >> eol;
				ycor		=	lexeme_d[str_p("ycor")][&logo::action::ycor] >> eol;
				
				get			=	lexeme_d[str_p("get")] >> +space_p >> 
									lexeme_d[str_p("turtle")] >> +space_p >> 
										(
										str_p("x")[&logo::action::xcor] |
										str_p("y")[&logo::action::ycor]
										)
								>> eol;

				cs			=	(
									lexeme_d[str_p("cs")] | 
									(lexeme_d[str_p("clear")] >> lexeme_d[str_p("screen")])
								) [ &logo::action::clear_screen ]
								>> eol;

				print		= (lexeme_d[str_p("print")] >> expression)[&logo::action::print] >> eol;
				exit		= lexeme_d[str_p("exit")][&logo::action::exit] >> eol;
				//invalid		= (*graph_p);
				statement	=	(
								back | forward | right | left |
								xcor | ycor |
								print | cs | get | 
								exit
								) >> (*statement);
			}
           
			boost::spirit::rule<ScannerT> const& start() const 
			{ 
				return statement; 
			}

        };
    };

}



#endif
