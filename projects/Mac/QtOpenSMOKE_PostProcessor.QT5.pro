######################################################################
# Please, modify the paths reported below
######################################################################

INCLUDE_BOOST = $(HOME)/NumericalLibraries/Boost/boost_1_58_0/include
INCLUDE_RAPIDXML = $(HOME)/NumericalLibraries/RapidXML/rapidxml-1.13
INCLUDE_EIGEN = $(HOME)/NumericalLibraries/Eigen/eigen-3.2
INCLUDE_OPENSMOKEPP = ../../../OpenSMOKEpp/source
LIB_BOOST = $(HOME)/NumericalLibraries/Boost/boost_1_58_0/lib

######################################################################




################################################################################
# DO NOT CHANGE THE LINES BELOW
################################################################################

QMAKE_CXXFLAGS += -DQTVERSION=5 
QT += widgets uitools printsupport
CONFIG +=  qt release core gui printsupport
TEMPLATE = app
TARGET =  OpenSMOKE_PostProcessor.sh
DEPENDPATH +=  ../../src  ../../src/forms ../../src/QCustomPlot/qcustomplot-1.3 
INCLUDEPATH += ../../src  ../../src/forms ../../src/QCustomPlot/qcustomplot-1.3

QMAKE_LFLAGS += 

# Specifies where to find the libraries at run time
QMAKE_RPATHDIR += @executable_path/../Frameworks
QMAKE_LFLAGS_SONAME = -Wl,-install_name,@rpath/

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
           ../../src/QCustomPlot/qcustomplot-1.3/qcustomplot.h

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
           ../../src/QCustomPlot/qcustomplot-1.3/qcustomplot.cpp

#For MacOSX we perform static linking with Boost libraries
#LIBS    += -L$${LIB_BOOST} -lboost_date_time -lboost_filesystem -lboost_program_options -lboost_system -lboost_regex
LIBS     += $${LIB_BOOST}/libboost_date_time.a       $${LIB_BOOST}/libboost_filesystem.a \
            $${LIB_BOOST}/libboost_program_options.a $${LIB_BOOST}/libboost_system.a \
			$${LIB_BOOST}/libboost_regex.a           $${LIB_BOOST}/libboost_timer.a \
			$${LIB_BOOST}/libboost_chrono.a

#LIBS += /Users/acuoci/Qt5.4.1/5.4/clang_64/lib/libQt5Core.a /Users/acuoci/Qt5.4.1/5.4/clang_64/lib/libQt5Gui.a /Users/acuoci/Qt5.4.1/5.4/clang_64/lib/libQt5PrintSupport.a

##################################################
# If MKL Support is needed, add the following line
##################################################
#LIBS    += -Wl,--start-group  $${PATH_MKL}/lib/intel64/libmkl_intel_lp64.a $${PATH_MKL}/lib/intel64/libmkl_sequential.a $${PATH_MKL}/lib/intel64/libmkl_core.a -Wl,--end-group -lpthread -lm 

