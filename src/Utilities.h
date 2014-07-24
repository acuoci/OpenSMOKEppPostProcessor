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

#ifndef QTOPENSMOKE_Utilities_H
#define QTOPENSMOKE_Utilities_H

#include <vector>
#include <string>

void MergePositiveAndNegativeBars
			(	const std::vector<unsigned int>& positive_indices, 
				const std::vector<unsigned int>& negative_indices,
				const std::vector<double>& positive_coefficients, 
				const std::vector<double>& negative_coefficients, 
				std::vector<int>& indices,
				std::vector<double>& coefficients);

void MergeBars( const std::vector<unsigned int>& total_indices, 
				const std::vector<double>& total_coefficients, 
				std::vector<int>& indices,
				std::vector<double>& coefficients);

void MergeBars( const std::vector<unsigned int>& total_indices, 
				const std::vector<double>& total_coefficients, 
				const std::vector<double>& total_peaks,
				std::vector<int>& indices,
				std::vector<double>& coefficients, 
				std::vector<double>& peaks);

#endif

