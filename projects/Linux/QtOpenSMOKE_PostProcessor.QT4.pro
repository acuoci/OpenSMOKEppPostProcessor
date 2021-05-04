######################################################################
# Please, modify the paths reported below
######################################################################

INCLUDE_BOOST = /software/chimica2/libraries/boost/boost-1.72.0-gcc-9.2.0/include
INCLUDE_EIGEN = /software/chimica2/libraries/eigen/eigen-3.4.r1
INCLUDE_OPENSMOKEPP = ../../../OpenSMOKEpp/source
LIB_BOOST = /software/chimica2/libraries/boost/boost-1.72.0-gcc-9.2.0/lib

######################################################################




################################################################################
# DO NOT CHANGE THE LINES BELOW
################################################################################

QMAKE_CXXFLAGS += -DQTVERSION=4 -std=c++11 
QT += widgets uitools printsupport
CONFIG += qt release core gui printsupport
TEMPLATE = app
TARGET =  OpenSMOKEpp_PostProcessor_QT4.sh
DEPENDPATH +=  ../../src  ../../src/forms ../../src/QCustomPlot/qcustomplot-2.0.1
INCLUDEPATH += ../../src  ../../src/forms ../../src/QCustomPlot/qcustomplot-2.0.1

QMAKE_LFLAGS += 

DESTDIR = ../../exe/linux
MOC_DIR = moc
OBJECTS_DIR = obj
UI_DIR = ui

INCLUDEPATH +=  $${INCLUDE_BOOST} \
		$${INCLUDE_RAPIDXML} \ 
		$${INCLUDE_EIGEN} \
		$${INCLUDE_OPENSMOKEPP} 

# Header files (.h)
HEADERS += ../../src/Profiles_Database.h \
           ../../src/qtopensmoke_postprocessor.h \
           ../../src/Sensitivities_Database.h \
           ../../src/Utilities.h \
           ../../src/widget_horizontal_bars.h \
           ../../src/window_profiles.h \
           ../../src/window_ropa.h \
           ../../src/window_sensitivities.h \
           ../../src/window_zoom_2dplot.h \
           ../../src/xyplot.h \
           ../../src/QCustomPlot/qcustomplot-2.0.1/qcustomplot.h

#Forms (.ui)
FORMS += ../../src/forms/qtopensmoke_postprocessor.ui \
         ../../src/forms/widget_horizontal_bars.ui \
         ../../src/forms/Widget_PlotXYProfiles.ui \
         ../../src/forms/window_profiles.ui \
         ../../src/forms/window_ropa.ui \
         ../../src/forms/window_sensitivities.ui \
         ../../src/forms/window_zoom_2dplot.ui

#Source files (.cpp)
SOURCES += ../../src/main.cpp \
           ../../src/CollectionOfClasses.cpp \
           ../../src/qtopensmoke_postprocessor.cpp \
           ../../src/widget_horizontal_bars.cpp \
           ../../src/window_sensitivities.cpp \
           ../../src/window_zoom_2dplot.cpp \
           ../../src/xyplot.cpp \
           ../../src/QCustomPlot/qcustomplot-2.0.1/qcustomplot.cpp

LIBS    += -L$${LIB_BOOST} -lboost_date_time -lboost_filesystem -lboost_program_options -lboost_system -lboost_regex

##################################################
# If MKL Support is needed, add the following line
##################################################
#LIBS    += -Wl,--start-group  $${PATH_MKL}/lib/intel64/libmkl_intel_lp64.a $${PATH_MKL}/lib/intel64/libmkl_sequential.a $${PATH_MKL}/lib/intel64/libmkl_core.a -Wl,--end-group -lpthread -lm 

