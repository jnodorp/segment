## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS =\
	 -Wall\
	 -g

lib_LTLIBRARIES = libsegment.la


libsegment_la_SOURCES = \
	segment.cpp \
	convolve.hpp \
	disjoint-set.hpp \
	filter.hpp \
	image.hpp \
	imconv.hpp \
	imutil.hpp \
	misc.hpp \
	pnmfile.hpp \
	segment-graph.hpp \
	segment-image.hpp

libsegment_la_LDFLAGS = 

libsegment_la_LIBADD = 


if PLATFORM_WIN32
libsegment_la_LDFLAGS += -no-undefined
endif

if NATIVE_WIN32
libsegment_la_LDFLAGS += -export-dynamic
endif

include_HEADERS = \
	segment.hpp

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = segment-1.0.pc \
	segment-1.0.pc.in

EXTRA_DIST = \
	segment-1.0.pc.in
