
#+
export G4INSTALL=$HOME/Tools/geant4_v$GEANT4_VERSION
export G4INCLUDE=$G4INSTALL/include/Geant4
export G4WORKDIR=$HOME/g4work
#	echo "geant4 work directory = $G4WORKDIR, you can reset it in your .bashrc"
export G4LIB=$G4INSTALL/lib64		#64 system need to set G4LIB manually, default is $G4INSTALL/lib
export G4SYSTEM=Linux-g++
export PATH=$G4INSTALL/bin:$G4WORKDIR/bin/$G4SYSTEM:$PATH
export LD_LIBRARY_PATH=$G4LIB/$G4SYSTEM:$LD_LIBRARY_PATH
#+

#+	Data base
DataPath=$G4INSTALL/share/Geant4-9.6.1/data
export G4LEVELGAMMADATA=$DataPath/PhotonEvaporation2.3
export G4NEUTRONXSDATA=$DataPath/G4NEUTRONXS1.2
export G4LEDATA=$DataPath/G4EMLOW6.32
export G4NEUTRONHPDATA=$DataPath/G4NDL4.2
export G4RADIOACTIVEDATA=$DataPath/RadioactiveDecay3.6
export G4PIIDATA=$DataPath/G4PII1.3
export G4SAIDXSDATA=$DataPath/G4SAIDDATA1.1
export G4REALSURFACEDATA=$DataPath/RealSurface1.0
unset DataPath
#+

#+
unset G4LIB_BUILD_SHARED	# if use, cannot load shared lib. of developer codes 
#export G4LIB_BUILD_STATIC=1	#default used 
export XERCESCROOT=/usr		#GDML use it
export G4LIB_USE_GDML=1
export G4LIB_USE_ZLIB=1
export G4LIB_USE_SHARED=1
export G4LIB_USE_STATIC=1
#unset G4LIB_USE_GRANULAR	#default: unset it, if set it, will not use Prefix/lib/Linux-g++
#+

#+
export G4UI_USE_QT=1
#export G4UI_USE_TCSH=1
#+

#+
export G4VIS_BUILD_RAYTRACERX_DRIVER=1
export G4VIS_USE_RAYTRACERX=1
export G4VIS_BUILD_OPENGLQT_DRIVER=1
export G4VIS_USE_OPENGLQT=1
#export G4VIS_BUILD_OPENGLX_DRIVER=1
#export G4VIS_USE_OPENGLX=1
#	echo "G4VIS_USE_OPENGLQT = 1"
#+


#+
#export G4ANALYSIS_USE=1
unset G4ANALYSIS_USE
#+

