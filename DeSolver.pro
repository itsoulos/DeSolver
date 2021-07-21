TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT+= core
QT-= gui

SOURCES += main.cpp \
    gpopulation.cc \
    gprogram.cc \
    grule.cc \
    gsymbol.cc \
    isinf.cc \
    gdoublestack.cc \
    fparser.cc \
    gsodeprogram.cc \
    gpdeprogram.cc \
    godeprogram.cc \
    pde_grammar.cc \
    ode_grammar.cc \
    get_options.cc

HEADERS += \
    gpopulation.h \
    gprogram.h \
    grule.h \
    gsymbol.h \
    isinf.h \
    gdoublestack.h \
    fparser.hh \
    gsodeprogram.h \
    gpdeprogram.h \
    godeprogram.h \
    pde_grammar.h \
    ode_grammar.h \
    get_options.h
LIBS+=  -lm -fopenmp

QMAKE_CXXFLAGS_RELEASE += -O3 -march=native -fopenmp -unroll-loops -omit-frame-pointer -Winline -unsafe-math-optimizations -mtune=native -mno-vzeroupper -pthread -fopt-info-optimized-vec-loop-omp
QMAKE_CFLAGS_RELEASE += -O3 -march=native -fopenmp -unroll-loops -omit-frame-pointer -Winline -unsafe-math-optimizations -mtune=native -mno-vzeroupper -pthread -fopt-info-optimized-vec-loop-omp

QMAKE_CXXFLAGS += -O3 -march=native -fopenmp -unroll-loops -omit-frame-pointer -Winline -unsafe-math-optimizations -mtune=native -mno-vzeroupper -pthread -fopt-info-optimized-vec-loop-omp
QMAKE_CFLAGS += -O3 -march=native -fopenmp -unroll-loops -omit-frame-pointer -Winline -unsafe-math-optimizations -mtune=native -mno-vzeroupper -pthread -fopt-info-optimized-vec-loop-omp

QMAKE_LFLAGS += -O3
