#
#	Qmake PRO file. 
#

#
#	Custom Paths
#
# BOOST = ../boost/

CONFIG	+= qt
HEADERS += logo/*.hpp
SOURCES += logo/*.cpp
RESOURCES += logo/resources.qrc
RC_FILE = logo/Logo.rc
BOOST = lib

# Check for Boost Spirit Headers
!exists( $$BOOST/spirit/core.hpp ) {
	error ( "No Boost Spirit Headers found." )
}

INCLUDEPATH += $$BOOST

CONFIG(release): DESTDIR = bin/release
CONFIG(debug):   DESTDIR = bin/debug
CONFIG(debug):   DEFINES = LOGO_DEBUG_ENABLE
