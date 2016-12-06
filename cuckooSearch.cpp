#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "cuckooSearch.h"
#include "solution.h"
#include "setUpParams.h"
using std::cout;
using std::endl;

//=======================================================================
/**
 * \file       cuckooSearch.cpp
 * \author     Nouwezem Fotso Zachée
 * \version    1.2
 * \date       03 Decembre 2016
 * \brief      Classe représentant le noyau de l'algorithme                
 */


/**
* \brief    Construit un MyAlgorithm
* \details  Initialise les valeurs par d?faut : _setup(setup), _upper_cost(0), _lower_cost(0)
* \param    pbm \e Problem probl?me
* \param    setup \e SetUpParams param?tre
*/
cuckooSearch::cuckooSearch(const Problem& pbm,const SetUpParams& setup) : _setup(setup), _upper_cost(0), _lower_cost(0)
{
    initialize(pbm);
}

/**
* \brief    d?truit cuckooSearch
*/
cuckooSearch::~cuckooSearch()
{
    for(int i=0;i<_solutions.size();i++)
    {
        delete _solutions[i];
    }
    _solutions.clear();
}


/**
* \brief    surcharge d'op?rateurs <<
* \details  permet d'afficher les variables ? l'?cran
*           
* \param    os \e ostream flux de sortie
* \param    myAlgo \e cuckooSerach algorithme
*/
std::ostream& operator<< (std::ostream& os, const CuckooSearch& myAlgo)
{
    os << "***==============================MyAlgorithm=======================***" << std::endl;
    os << myAlgo.setup();
    os << "***================================================================***" << std::endl;
}

/**
* \brief    renvoie une r?f?rence vers le param?tre de l'algorithme
* \return   Un \e SetUpParams repr?sentant une r?f?rence vers le param?tre de l'algorithme
*/
const SetUpParams& cuckooSearch::setup() const
{
    return _setup;
}

/**
* \brief    renvoie des r?f?rences vers le tableau des solutions
* \return   Un \e std::vector<Solution*>& repr?sentant le tableau des solutions
*/
const std::vector<Solution*>& cuckooSearch::solutions() const
{
    return _solutions;
}

/**
* \brief    renvoie l'indice de la solution contenant le co?t le plus ?lev?
* \return   Un \e unsigned int repr?sentant l'indice de la solution contenant le co?t le plus ?lev?
*/
unsigned int cuckooSearch::upper_cost() const
{
    return _upper_cost;
}

/**
* \brief    renvoie l'indice de la solution contenant le co?t le moins ?lev?
* \return   Un \e unsigned int repr?sentant l'indice de la solution contenant le co?t le moins ?lev?
*/
unsigned int cuckooSearch::lower_cost() const
{
    return _lower_cost;
}

/**
* \brief    renvoie le meilleur co?t
* \return   Un \e double repr?sentant le meilleur co?t
*/
double cuckooSearch::best_cost() const
{
	_solutions[_lower_cost]->get_fitness();
}

/**
* \brief    renvoie le pire co?t
* \return   Un \e double repr?sentant le pire co?t
*/
double cuckooSearch::worst_cost() const
{
    _solutions[_upper_cost]->get_fitness();
}

Solution& cuckooSearch::best_solution() const
{
    return *_solutions[_lower_cost];
}

/**
* \brief    renvoie une r?f?rence vers la pire solution
* \return   Un \e Solution repr?sentant la pire solution
*/
Solution& cuckooSearch::worst_solution() const
{
    return *_solutions[_upper_cost];
}

/**
* \brief    initialise cuckooSearch ainsi que le meilleur co?t, pire co?t,etc.
* \param    pbm \e Problem probl?me
*/
void cuckooSearch::initialize(const Problem& pbm)
{
    _solutions.clear();

    for(int i=0;i<_setup.league_size();i++)
    {
        Solution* s = new Solution(pbm);
        _solutions.push_back(s);
    }

    for(int i=0;i<_solutions.size();i++)
    {
        double fitness=_solutions[i]->get_fitness();
        if(fitness<_lower_cost)
        {
            _lower_cost = fitness;
        }

        if(fitness>_upper_cost)
        {
            _upper_cost = fitness;
        }
    }
}


