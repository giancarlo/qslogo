#
#	Qmake PRO file. 
#

#
#	Custom Paths
#
BOOST = y:/projects/boost/build/include/boost-1_36

CONFIG	+= qt
HEADERS += logo/*.hpp
SOURCES += logo/*.cpp
RESOURCES += logo/resources.qrc
RC_FILE = logo/Logo.rc

# Check for Boost Spirit Headers
!exists( $$BOOST/boost/spirit/core.hpp ) {
	error ( "No Boost Spirit Headers founds. Please fix immediately" )
}

INCLUDEPATH += $$BOOST

CONFIG(release): DESTDIR = bin/release
CONFIG(debug):   DESTDIR = bin/debug