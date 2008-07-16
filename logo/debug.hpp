/*
 *	Coaxial Software
 *	Copyright (c) 2007 - Giancarlo Bellido
 *
 *	Debugging routines.
 */

#ifndef LOGO_DEBUG_HPP
#define LOGO_DEBUG_HPP

#ifdef LOGO_DEBUG
#	include <QtGui/QApplication>
#	define LOGO_LOG(msg) logo::win->log->addItem(msg)
#else
#	define LOGO_LOG(msg)
#endif

#endif // LOGO_DEBUG_HPP
