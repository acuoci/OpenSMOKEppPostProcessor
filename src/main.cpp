/*----------------------------------------------------------------------*\
|     ____                    ______ __  __  ____  _  ________            |
|    / __ \                  /  ___ |  \/  |/ __ \| |/ /  ____|           |
|   | |  | |_ __   ___ _ __ |  (___ | \  / | |  | | ' /| |__              |
|   | |  | | '_ \ / _ \ '_ \ \___  \| |\/| | |  | |  < |  __|             |
|   | |__| | |_) |  __/ | | |____)  | |  | | |__| | . \| |____            |
|    \____/| .__/ \___|_| |_|______/|_|  |_|\____/|_|\_\______|           |
|          | |                                                            |
|          |_|                                                            |
|                                                                         |
|   CRECK Modeling Group <http://creckmodeling.chem.polimi.it>            |
|   Department of Chemistry, Materials and Chemical Engineering           |
|   Politecnico di Milano                                                 |
|   Author: Alberto Cuoci <alberto.cuoci@polimi.it>                       |
|	Date: 07 Mar 2013                                                     |
|-------------------------------------------------------------------------|
|	License                                                               |
|                                                                         |
|   This file is part of OpenSMOKE.                                       |
|                                                                         |
|   OpenSMOKE is free software: you can redistribute it and/or modify     |
|   it under the terms of the GNU General Public License as published by  |
|   the Free Software Foundation, either version 3 of the License, or     |
|   (at your option) any later version.                                   |
|                                                                         |
|   OpenSMOKE is distributed in the hope that it will be useful,          |
|   but WITHOUT ANY WARRANTY; without even the implied warranty of        |
|   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         |
|   GNU General Public License for more details.                          |
|                                                                         |
|   You should have received a copy of the GNU General Public License     |
|   along with OpenSMOKE. If not, see <http://www.gnu.org/licenses/>.     |
|                                                                         |
\*-----------------------------------------------------------------------*/

#include "qtopensmoke_postprocessor.h"
#include <boost/filesystem.hpp>
//#include <QtGui/QApplication>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{ 
    #ifdef __linux__
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
