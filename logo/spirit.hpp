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

#ifndef LOGO_SPIRIT_HPP
#define LOGO_SPIRIT_HPP

#include <boost/version.hpp>

#if BOOST_VERSION >= 103800
#  include <boost/spirit/home/classic/core.hpp>
#  include <boost/spirit/home/classic/utility/confix.hpp>
#  define LOGO_SPIRIT_NS BOOST_SPIRIT_CLASSIC_NS
#else
#  include <boost/spirit/core.hpp>
#  include <boost/spirit/utility/confix.hpp>
#  define BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN
#  define BOOST_SPIRIT_CLASSIC_NAMESPACE_END
#  define LOGO_SPIRIT_NS boost::spirit
#endif

#include <QChar>

/*
 * So apparently we need specializations for boost::spirit
 */
namespace boost { namespace spirit { 

BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

	namespace impl {
		template <>
		inline QChar
		tolower_(QChar x) { return x.toLower(); }

		template <>
		inline bool
		isdigit_(QChar x) { return x.isDigit(); }

		template <>
		inline bool
		isspace_(QChar x) { return x.isSpace(); }

		template <>
		inline bool
		isupper_(QChar x) { return x.isUpper(); }

		template <>
		inline bool
		isalnum_(QChar x) { return x.isLetterOrNumber(); }

		template <>
		inline bool
		isalpha_(QChar x) { return x.isLetter(); }

		template <>
		inline bool
		isgraph_(QChar x) { return x.isPrint(); }
	}

	int operator- (QChar x, const char y)
	{
		return x.toAscii() - y;
	}

BOOST_SPIRIT_CLASSIC_NAMESPACE_END

} }

#endif
