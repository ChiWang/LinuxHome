# $Id: GNUmakefile,v 1.1 1999/01/07 16:05:40 gunter Exp $
# --------------------------------------------------------------
# GNUmakefile for examples module.  Gabriele Cosmo, 06/04/98.
# --------------------------------------------------------------

name := MyPro
G4TARGET := $(name)
G4EXLIB := true

ifndef G4INSTALL
  G4INSTALL = ../../..
endif

ROOTCFLAGS = $(shell root-config --cflags)
ROOTLIBS = $(shell root-config --libs)
ROOTGLIBS = $(shell root-config --glibs)
CPPFLAGS += $(ROOTCFLAGS)
EXTRALIBS += $(ROOTLIBS) $(ROOTGLIBS)

#EXTRALIBS += -L$(ROOTSYS)/lib

.PHONY: all distclean
all: lib bin

include $(G4INSTALL)/config/binmake.gmk

distclean:  clean
	@rm -f current* G4Hist*

