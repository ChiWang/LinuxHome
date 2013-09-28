

Structure
--------------
    include         // header files
    src             // source files
    mac             // macro files
    result          // simulation results will save into this directory
    analysis        // analysis codes, input is result/*
    Scons           // to store temprary files created by using SCons, if Scons is exist


Usage
--------------
    1)  Makefile    // MyX.cc file must at ./
        make            // will creat executable file MyX at $G4WORK, temporary files in ./src/
        make clean      // clean all created files

    2)  SCons       // MyX.cc file must at ./src/
        scons           // will creat executable file MyX at ./, temporary files in Scons
        scons -c        // clean up


