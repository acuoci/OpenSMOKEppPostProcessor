/*----------------------------------------------------------------------*\
|    ___                   ____  __  __  ___  _  _______                  |
|   / _ \ _ __   ___ _ __ / ___||  \/  |/ _ \| |/ / ____| _     _         |
|  | | | | '_ \ / _ \ '_ \\___ \| |\/| | | | | ' /|  _| _| |_ _| |_       |
|  | |_| | |_) |  __/ | | |___) | |  | | |_| | . \| |__|_   _|_   _|      |
|   \___/| .__/ \___|_| |_|____/|_|  |_|\___/|_|\_\_____||_|   |_|        |
|        |_|                                                              |
|                                                                         |
|   Author: Alberto Cuoci <alberto.cuoci@polimi.it>                       |
|   CRECK Modeling Group <http://creckmodeling.chem.polimi.it>            |
|   Department of Chemistry, Materials and Chemical Engineering           |
|   Politecnico di Milano                                                 |
|   P.zza Leonardo da Vinci 32, 20133 Milano                              |
|                                                                         |
|-------------------------------------------------------------------------|
|                                                                         |
|   This file is part of OpenSMOKE++PostProcessor.                        |
|                                                                         |
|	License                                                           |
|                                                                         |
|   Copyright(C) 2014, 2013  Alberto Cuoci                                |
|   OpenSMOKE++PostProcessor is free software: you can redistribute it    |
|   and/or modify it under the terms of the GNU General Public            |
|   License as published by the Free Software Foundation, either          |
|   version 3 of the License, or (at your option) any later version.      |
|                                                                         |
|   OpenSMOKE++PostProcessor is distributed in the hope that it will be   |
|   useful, but WITHOUT ANY WARRANTY; without even the implied warranty   |
|   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the      |
|   GNU General Public License for more details.                          |
|                                                                         |
|   You should have received a copy of the GNU General Public License     |
|   along with OpenSMOKE++. If not, see <http://www.gnu.org/licenses/>.   |
|                                                                         |
\*-----------------------------------------------------------------------*/

#include "qtopensmoke_postprocessor.h"
#include <boost/filesystem.hpp>
#if QTVERSION == 4
#include <QtGui/QApplication>
#elif QTVERSION == 5
#include <QtWidgets/QApplication>
#endif

int main(int argc, char *argv[])
{ 
    #ifdef __linux__ 
        boost::filesystem::path executable_file = boost::filesystem::system_complete(argv[0]);
        boost::filesystem::path executable_folder = executable_file.parent_path();
	#elif __APPLE__ 
		boost::filesystem::path executable_file = boost::filesystem::system_complete(argv[0]);
		boost::filesystem::path executable_folder = executable_file.parent_path();
    #elif defined _WIN32 || defined _WIN64
        boost::filesystem::path executable_file = boost::filesystem::system_complete(argv[0]);
        boost::filesystem::path executable_folder = executable_file.parent_path();
    #endif

	//unsigned int max_number_allowed_species;
	//OpenSMOKE::OpenSMOKE_CheckLicense(executable_folder, "PostProcessor", max_number_allowed_species);

	QApplication a(argc, argv);
	QtOpenSMOKE_PostProcessor w;
	w.SetExeFolder(executable_folder);
	w.show();
	return a.exec();
}
