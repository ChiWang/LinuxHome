#=============================================================================
#       FileName :          Makefile
#       Version  :          0.0.1
#       Author   :          Chi    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-04-18   20:58:07
#------------------------------------------------------------------------------
#       Description  :
#
#		Check:
#			1;	directories in $pwd are like below?	(search Dir.)
#			2;	planeform and compilers are the same as ARCH	(search ARCH)
#					if not, find right one in $(ROOTSYS)/etc/Makefile.arch, and replace modle setup compilers
#
#       User can do:	(search Set)
#       	1;	change PROGRAMS name (default is main)
#       	2;	change Srcsuf (source file type, default is C)
#       	3;	use yourself software path (path of header file and shared library)
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-04-18   21:33:43
#=============================================================================


# Set exicutable file name or src file type
#------------------------------------------------------------------
PROGRAMS      = main
SrcSuf        = cc
#------------------------------------------------------------------


# Dir. in current $pwd	?? if not this, arragement like this
#------------------------------------------------------------------
TOP     := $(shell pwd)
OBJ     := $(TOP)/obj
BIN     := $(TOP)/bin
SRC     := $(TOP)/src
INCLUDE  := $(TOP)/include
#------------------------------------------------------------------


# setup compilers
#------------------------------------------------------------------
RC           := root-config
#ARCH         := $(shell $(RC) --arch)	#plantform and compiler information from root-comfig
ifneq ($(findstring debug, $(strip $(shell $(RC) --config))),)
OPT           = -g
else
OPT           = -O2
#OPT           = -O
endif
#ifeq ($(ARCH),linuxx8664gcc)
	# AMD Opteron and Intel EM64T (64 bit mode) Linux with gcc 3.x
CXX           = g++
CXXFLAGS      = $(OPT) -Wall -fPIC -I $(INCLUDE)	# default use user header file
LD            = g++
LDFLAGS       = $(OPT)
SOFLAGS       = -shared
#endif
LIBS          = $(SYSLIBS)
#------------------------------------------------------------------


# Use root
#------------------------------------------------------------------
ROOTCFLAGS   := $(shell $(RC) --cflags)
ROOTLDFLAGS  := $(shell $(RC) --ldflags)
#ROOTLIBS     := $(shell $(RC) --libs)
ROOTGLIBS    := $(shell $(RC) --glibs)	# add lGui than ROOTLIBS
#HASTHREAD    := $(shell $(RC) --has-thread)
#ROOTDICTTYPE := $(shell $(RC) --dicttype)
ROOTCINT     := rootcint

#add root
CXXFLAGS     +=	$(ROOTCFLAGS) 
#CXXFLAGS = -Wall -ansi -pedantic -Wno-long-long -I$(INCLUDE) -I$(ROOTCFLAGS) -I. $(LCIOINCLUDES) -D_REENTRANT
LIBS          += $(ROOTGLIBS)
#------------------------------------------------------------------


# Set path to use myself software:	put all my header file and shared library in some where
#------------------------------------------------------------------
#Path=$(TOP)
#LIBS         += $(Path)/lib/*.so
#CXXFLAGS     +=	-I$(Path)/include
#------------------------------------------------------------------


############## Make Executables ####################################
all: $(PROGRAMS)

$(PROGRAMS): $(patsubst $(SRC)/%.$(SrcSuf),$(OBJ)/%.o,$(wildcard $(SRC)/*.$(SrcSuf)))
	$(LD) $^ $(LIBS) -o $(BIN)/$(notdir $@)
	@echo

######################################################
$(OBJ)/%.o : 	$(SRC)/%.$(SrcSuf)
	$(CXX)  $(CXXFLAGS) -c $(SRC)/$(notdir $<) -o $(OBJ)/$(notdir $@)
	@echo	

######################################################



#	phony meathods
#------------------------------------------------------------------
.PHONY:  clean    distclean

clean:
	@rm -f $(OBJ)/*.o core *Dict.*
#	@rm -f $(BIN)*

distclean:   clean
		@rm -f $(BIN)/$(PROGRAMS)
#*Dict.* *.def *.exp \
		   *.root *.ps *.so *.lib *.dll *.d *.log .def so_locations \
		   files/*
#------------------------------------------------------------------



