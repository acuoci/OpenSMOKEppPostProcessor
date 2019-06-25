/*-----------------------------------------------------------------------*\
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
|	License                                                               |
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

	std::vector<int> signum(n);

	indices.resize(n);
	coefficients.resize(n);
	for(unsigned int i=0;i<positive_coefficients.size();i++)
	{
		indices[i] = positive_indices[i];
		coefficients[i] = positive_coefficients[i];
		signum[i] = 1;
	}
	for(unsigned int i=0;i<negative_coefficients.size();i++)
	{
		indices[i+positive_indices.size()] = -negative_indices[i];
		coefficients[i+positive_indices.size()] = -negative_coefficients[i];
		signum[i + positive_indices.size()] = -1;
	}
	
	std::vector<double> tmp = coefficients;

	OpenSMOKE_Utilities::ReorderPairsOfVectors(coefficients, indices);
	std::reverse(indices.begin(), indices.end());
	std::reverse(coefficients.begin(), coefficients.end());

	OpenSMOKE_Utilities::ReorderPairsOfVectors(tmp, signum);
	std::reverse(signum.begin(), signum.end());


	for(unsigned int i=0;i<n;i++)
		if (signum[i] == -1)	
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

	std::vector<int> signum(n);

	indices.resize(n);
	coefficients.resize(n);
	for(unsigned int i=0;i<total_indices.size();i++)
		if (total_coefficients[i] < 0.)
		{
			coefficients[i] = -total_coefficients[i];
			indices[i] = -total_indices[i];
			signum[i] = -1;
		}
		else
		{
			coefficients[i] = total_coefficients[i];
			indices[i] = total_indices[i];
			signum[i] = 1;
		}

	std::vector<double> tmp = coefficients;

	OpenSMOKE_Utilities::ReorderPairsOfVectors(coefficients, indices);
	std::reverse(indices.begin(), indices.end());
	std::reverse(coefficients.begin(), coefficients.end());

	OpenSMOKE_Utilities::ReorderPairsOfVectors(tmp, signum);
	std::reverse(signum.begin(), signum.end());

	for(unsigned int i=0;i<n;i++)
		if (signum[i] == -1)	
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

	std::vector<int> signum(n);

	indices.resize(n);
	coefficients.resize(n);
	peaks.resize(n);
	for(unsigned int i=0;i<total_indices.size();i++)
		if (total_coefficients[i] < 0.)
		{
			coefficients[i] = -total_coefficients[i];
			indices[i] = -total_indices[i];
			peaks[i] = total_peaks[i];
			signum[i] = -1;
		}
		else
		{
			coefficients[i] = total_coefficients[i];
			indices[i] = total_indices[i];
			peaks[i] = total_peaks[i];
			signum[i] = 1;
		}

	std::vector<double> tmp = coefficients;
	std::vector<double> tmp1 = coefficients;

	OpenSMOKE_Utilities::ReorderPairsOfVectors(coefficients, indices);
	std::reverse(indices.begin(), indices.end());
	std::reverse(coefficients.begin(), coefficients.end());

	OpenSMOKE_Utilities::ReorderPairsOfVectors(tmp, signum);
	std::reverse(signum.begin(), signum.end());

	for(unsigned int i=0;i<n;i++)
		if (signum[i] == -1)	
		{
			indices[i] *= -1;
			coefficients[i] *= -1.;
		}

	OpenSMOKE_Utilities::ReorderPairsOfVectors(tmp1, peaks);
	std::reverse(peaks.begin(), peaks.end());
}

