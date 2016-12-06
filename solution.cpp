#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "solution.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <time.h>
#include "solution.h"
#include "problem.h"


Solution::Solution (const Problem& pbm) : _pbm(pbm)
{
	initialize();
}

Solution::Solution (const Solution& sol)
{
	
}

Solution::~Solution()
{
	
}

Solution& Solution::operator=  (const Problem& pbm)
{
    return *this;
}

bool Solution::operator== (const Solution& sol) const
{
    return _current_fitness == sol._current_fitness && _pbm == sol._pbm && _solution == sol._solution;
}

bool Solution::operator!= (const Solution& sol) const
{
    return !(*this==sol);
}

void Solution::initialize()
{
	int min = _pbm.LowerLimit();
    int max = _pbm.UpperLimit();
    double nombreAleatoire;
    double rdm;

    for(int i=1;i<=_pbm.dimension();i++)
    {
        rdm = (double)rand() / (RAND_MAX+1);
        nombreAleatoire = Xmin + f * (max - min);
        _solution.push_back(nombreAleatoire);
    }
}

const Problem& Solution::pbm() const
{
	return _pbm;
}

double Solution::fitness()
{
	
}

double Solution::get_fitness()
{
	
}
