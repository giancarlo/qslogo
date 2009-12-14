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

#include "spirit.hpp"
#include "actions.hpp"

namespace logo
{
	struct function_functor
	{
		typedef LOGO_SPIRIT_NS::nil_t result_t;

		template <typename ScannerT>
		std::ptrdiff_t
		operator() (ScannerT const& scan, result_t& result) const
		{
			if (scan.at_end()) return -1;

			logo::action::IterT start = scan.first;
			std::ptrdiff_t len = 0;

			while (!scan.at_end() && LOGO_SPIRIT_NS::impl::isalnum_(*scan))
			{
				++len;
				++scan;
			}
			
			// See if it is a function
			return logo::action::functions.contains(QString(start, len)) ? len : -1;
		}
	};

	LOGO_SPIRIT_NS::functor_parser<function_functor> function_p;
	
	struct grammar : public LOGO_SPIRIT_NS::grammar<grammar>
    {

		template <typename ScannerT>
        struct definition
        {
			typedef LOGO_SPIRIT_NS::scanner_list<
				ScannerT,
				typename LOGO_SPIRIT_NS::no_actions_scanner<ScannerT>::type
			> ScannerT2;

			LOGO_SPIRIT_NS::rule<ScannerT2>  
				expression, statement, identifier, function,
				statements,
				// Addons
				get,
				// Turtle Position
				xcor, ycor,
				// turtle stuff
				pen,
				// Algebra!
				sum, difference, negate, product, divide, sqrt, power, sqr, term,
				// Data
				make, list, thing,
				// Primitives
				forward, left, right, back,
				circle,
				cs, 
				print, exit, home,
				// Control Structures
				repeat,
				// Types
				string, number,
				// Other
				eol, invalid, end, comment,
				// Editor
				edit, save,
				// Functions
				to, other
			;

			definition(grammar const& /* self */)  
			{
				using namespace LOGO_SPIRIT_NS;

				eol			=	(*eol_p | +space_p);

				number		= real_p[&logo::action::number];
				string		= confix_p('[', (*graph_p)[&logo::action::string], ']') |
							  (ch_p('"') >> identifier[&logo::action::string])
							  ;

				identifier  = lexeme_d[+alnum_p];

				/* actions_arit.cpp */
				sum             = (str_p("sum") >> expression >> eol >> expression >> eol)[&logo::action::sum];
				difference	= (str_p("dif") >> expression >> eol >> expression >> eol)[&logo::action::dif];
				product		= (str_p("prod")>> expression >> eol >> expression >> eol)[&logo::action::product];
				divide		= (str_p("div") >> expression >> eol >> expression >> eol)[&logo::action::divide];

				negate		= (str_p("neg") >> expression >> eol)[&logo::action::negate];
				sqr             = (str_p("sqr") >> expression >> eol)[&logo::action::sqr];
				
				term		= sum | difference | product | divide | negate | sqr | number;
				expression	= string | term | function;
				
				/* Control Statements */
				repeat		= str_p("repeat") >> expression >> (statements)[&logo::action::repeat];
				make		= (str_p("make") >> string >> expression >> eol)[&logo::action::make];
				thing		= (str_p("thing") >> string >> eol)[&logo::action::thing] |
							  (str_p(":") >> identifier[&logo::action::string] >> eol)[&logo::action::thing]
							  ;

				/* TURTLE Commands */

				forward		= ((str_p("forward") | str_p("fd")) >>  expression >> eol)[&logo::action::forward];
				back		= ((str_p("back") | str_p("bk")) >> expression >> eol)[&logo::action::back];
				right		= ((str_p("right") | str_p("rt")) >> expression >> eol)[&logo::action::right];
				left		= ((str_p("left")  | str_p("lt")) >> expression >> eol)[&logo::action::left];

				get			=	str_p("get") >> +space_p >> 
								str_p("turtle") >> +space_p >> 
								(
									str_p("x")[&logo::action::xcor] |
									str_p("y")[&logo::action::ycor]
								)
								>> eol;

				pen			= str_p("pen") >>
										(str_p("up")[&logo::action::penup] |
										str_p("down")[&logo::action::pendown])
									>> eol;

				home		= (str_p("home") >> eol)[&logo::action::home];
				circle		= (str_p("circle") >> expression >> eol)[&logo::action::circle];

				/* FUNCTIONS */
				xcor		=	str_p("xcor")[&logo::action::xcor] >> eol;
				ycor		=	str_p("ycor")[&logo::action::ycor] >> eol;

				function	= xcor | ycor | thing | function_p[&logo::action::call];

				/* Screen Commands */

				cs =	(
					str_p("cs") | 
					(str_p("clear") >> str_p("screen"))
					) [ &logo::action::clear_screen ]
					>> eol;

				end = str_p("end") >> eol;
				to  = str_p("to") >> identifier[&logo::action::string]
					>> (no_actions_d[statements])[&logo::action::to]
					>> end;

				comment = ch_p(';') >> (*graph_p - eol) >> eol;

				other   = (identifier - end)[&logo::action::error];

				// Editor
				edit = (str_p("edit") >> (*string))[&logo::action::edit];
				save = (str_p("save") >> string)[&logo::action::save];

				print		= (str_p("print") >> expression)[&logo::action::print] >> eol;
				exit		= str_p("bye")[&logo::action::exit] >> eol;
				statement	=	(
								back | forward | right | left | home |
								circle |
								pen | get |
								print | cs | 
								repeat |
								make | to |
								exit | comment | function |
								edit | save |
								other
							);

				statements = *statement;
			}
           
			LOGO_SPIRIT_NS::rule<ScannerT2> const& start() const 
			{ 
				return statements; 
			}

        };
    };

}



#endif
