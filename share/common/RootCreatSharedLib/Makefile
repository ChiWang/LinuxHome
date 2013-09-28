# Makefile for the ROOT test programs.
# This Makefile shows nicely how to compile and link applications
# using the ROOT libraries on all supported platforms.
#
# Copyright (c) 2000 Rene Brun and Fons Rademakers
#
# Author: Fons Rademakers, 29/2/2000

include $(ROOTSYS)/etc/Makefile.arch	#important!
-include ../MyConfig.mk

#------------------------------------------------------------------------------
#SrcSuf = C
#------------------------------------------------------------------------------

EVENTO        = Event.$(ObjSuf) EventDict.$(ObjSuf)
EVENTS        = Event.$(SrcSuf) EventDict.$(SrcSuf)
EVENTSO       = libEvent.$(DllSuf)
EVENT         = Event$(ExeSuf)
EVENTLIB      = $(shell pwd)/$(EVENTSO)


PROGRAMS      = $(EVENT)


#------------------------------------------------------------------------------

.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf)

all:            $(EVENTSO)
#all:            $(PROGRAMS)
	@echo "all"
	@echo "arch $(ARCH)"
	@echo "$(OPT)		sss	$(OPT2)"
	@echo "$(SYSLIBS)"


$(EVENTSO):     $(EVENTO)
		$(LD) $(SOFLAGS) $(LDFLAGS) $^ -o $@ $(EXPLLINKLIBS)
		@echo $(EXPLLINKLIBS)
		@echo "$@ done	b1"

.SUFFIXES: .$(SrcSuf)

###
 
Event.$(ObjSuf): Event.h

EventDict.$(SrcSuf): Event.h EventLinkDef.h
	@echo "Generating dictionary $@..."
	@echo $(ROOTCINT)
	$(ROOTCINT) -f $@ -c $^

.$(SrcSuf).$(ObjSuf):
	$(CXX)  $(CXXFLAGS) -c $<
	@echo "me"
#	@exit 1



#-------------------------------------------------------------------------
.PHONY:  clean cleanall
clean:
		@rm -f *.o $(TRACKMATHSRC) core *Dict.*

cleanall:      clean
		@rm -f $(PROGRAMS) $(EVENTSO) $(EVENTLIB) *Dict.* *.def *.exp \
		   *.root *.ps *.so *.lib *.dll *.d *.log .def so_locations \
		   files/*
		@rm -rf cxx_repository

