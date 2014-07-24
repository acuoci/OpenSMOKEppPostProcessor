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

#include "Utilities.h"

void MergePositiveAndNegativeBars
			(	const std::vector<unsigned int>& positive_indices, 
				const std::vector<unsigned int>& negative_indices,
				const std::vector<double>& positive_coefficients, 
				const std::vector<double>& negative_coefficients, 
				std::vector<int>& indices,
				std::vector<double>& coefficients)
{
	unsigned int n = positive_indices.size() +
					 negative_indices.size();

	indices.resize(n);
	coefficients.resize(n);
	for(unsigned int i=0;i<positive_coefficients.size();i++)
	{
		indices[i] = positive_indices[i];
		coefficients[i] = positive_coefficients[i];
	}
	for(unsigned int i=0;i<negative_coefficients.size();i++)
	{
		indices[i+positive_indices.size()] = -negative_indices[i];
		coefficients[i+positive_indices.size()] = -negative_coefficients[i];
	}
	
	OpenSMOKE_Utilities::ReorderPairsOfVectors(coefficients, indices);
	std::reverse(indices.begin(), indices.end());
	std::reverse(coefficients.begin(), coefficients.end());
	for(unsigned int i=0;i<n;i++)
		if (indices[i]<0)	
		{
			indices[i] *= -1;
			coefficients[i] *= -1.;
		}
		
}


void MergeBars( const std::vector<unsigned int>& total_indices, 
				const std::vector<double>& total_coefficients, 
				std::vector<int>& indices,
				std::vector<double>& coefficients)
{
	unsigned int n = total_indices.size();

	indices.resize(n);
	coefficients.resize(n);
	for(unsigned int i=0;i<total_indices.size();i++)
		if (total_coefficients[i] < 0.)
		{
			coefficients[i] = -total_coefficients[i];
			indices[i] = -total_indices[i];
		}
		else
		{
			coefficients[i] = total_coefficients[i];
			indices[i] = total_indices[i];
		}

	OpenSMOKE_Utilities::ReorderPairsOfVectors(coefficients, indices);
	std::reverse(indices.begin(), indices.end());
	std::reverse(coefficients.begin(), coefficients.end());
	for(unsigned int i=0;i<n;i++)
		if (indices[i]<0)	
		{
			indices[i] *= -1;
			coefficients[i] *= -1.;
		}
}

void MergeBars( const std::vector<unsigned int>& total_indices, 
				const std::vector<double>& total_coefficients, 
				const std::vector<double>& total_peaks,
				std::vector<int>& indices,
				std::vector<double>& coefficients, 
				std::vector<double>& peaks)
{
	unsigned int n = total_indices.size();

	indices.resize(n);
	coefficients.resize(n);
	peaks.resize(n);
	for(unsigned int i=0;i<total_indices.size();i++)
		if (total_coefficients[i] < 0.)
		{
			coefficients[i] = -total_coefficients[i];
			indices[i] = -total_indices[i];
			peaks[i] = total_peaks[i];
		}
		else
		{
			coefficients[i] = total_coefficients[i];
			indices[i] = total_indices[i];
			peaks[i] = total_peaks[i];
		}

	std::vector<double> tmp = coefficients;
	OpenSMOKE_Utilities::ReorderPairsOfVectors(coefficients, indices);
	std::reverse(indices.begin(), indices.end());
	std::reverse(coefficients.begin(), coefficients.end());
	for(unsigned int i=0;i<n;i++)
		if (indices[i]<0)	
		{
			indices[i] *= -1;
			coefficients[i] *= -1.;
		}

	OpenSMOKE_Utilities::ReorderPairsOfVectors(tmp, peaks);
	std::reverse(peaks.begin(), peaks.end());
}

