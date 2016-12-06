#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "problem.h"
#include <fstream>

/**
 * \file       Problem.cpp
 * \author     NOUWEZEM FOTSO Zachée
 * \version    1.0	
 * \date       02 Novembre 2016
 * \brief      définition des méthodes de la classe problem de l'algorithme CSA
 *
 * \details    Cette classe surcharge les accesseurs du problème
 */

/**
* \brief    Construit un problème
* \details  Initialise les valeurs par défaut : _direction (Minimize), _dimension(30), _LowerLimit(-4), _UpperLimit(4)
*/
Problem::Problem() : _direction(Minimize), _dimension(30), _LowerLimit(-4), _UpperLimit(4)
{

}

/**
* \brief    Construit un problème
* \param    dimension         \e double la dimension
* \param    LowerLimit        \e double la limite minimum du paramètre d'optimisation
* \param    UpperLimit        \e double la limite maximum du paramètre d'optimisation
*/
Problem::Problem(Direction direction, int dimension, int LowerLimit, int UpperLimit) : _direction(direction), _dimension(dimension), _LowerLimit(LowerLimit), _UpperLimit(UpperLimit)
{

}

/**
 * \brief    surcharge d'opérateurs <<
 * \details  permet d'afficher les variables à l'écran
 *           
 * \param    os \e ostream flux de sortie
 * \param    pbm \e Problem problème
 */
std::ostream& operator<< (std::ostream& os, const Problem& pbm)
{
    os << "========================Problem : Paramètres==========================" << std::endl;
    os << " Dimension : " << pbm._dimension << std::endl;
    os << " Direction : " << pbm._direction << std::endl;
    os << " LowerLimit : " << pbm._LowerLimit << std::endl;
    os << " UpperLimit : " << pbm._UpperLimit << std::endl;
    os << "======================================================================" << std::endl;
    
    return os;
}

/**
 * \brief       Lit avec le format: target_value_to_reach,n,x_min,x_max
 * \details     permet d'entrer les valeurs numériques au clavier pour créer un problème
 *                 
 * \param       is \e istream flux d'entrée
 * \param       pbm \e Problem problème
 */
std::istream& operator>> (std::istream& is, Problem& pbm)
{
    char c;
    int dimension, dir, LowerLimit, UpperLimit;
    Direction direction;

    is >> c;
    if(c==',')
    {
        is >> dimension;
        is >> c;
        if(c==',')
        {
        	cout << "Direction : (0 = Minimiser - 1 = Maximiser)" << std::endl;
        	is >> dir
        	is >> c;
        	if (c==  )
        	{
        		is >> LowerLimit;
            	is >> c;
            	if(c==',')
           		 {
                	is >> UpperLimit;
                	pbm._dimension = dimension;
                	switch(dir)
                	{
                		case 0 : pbm._direction = Minimize;
                		break;
                		case 1 : pbm._direction = Maximize;
                		break;
                		default : cout << "Valeur inconnue";
                		break;
					}
                	
                	pbm._LowerLimit = LowerLimit;
                	pbm._UpperLimit = UpperLimit;
           		 }
			}
            
        }
    }
}

/**
 * \brief       surcharge de l'opérateur d'affectation d'un problème
 * \param       pbm \e Problem problème
 * \return      Une référence de type \e Problem
 */
Problem& Problem::operator=  (const Problem& pbm)
{
    return *this;
}

/**
 * \brief       surcharge d'opérateur de comparaison == d'un problème
 * \param       pbm \e Problem problème
 * \return      \e bool
 */
bool Problem::operator== (const Problem& pbm) const
{
    return _dimension == pbm._dimension && _LowerLimit == pbm._LowerLimit && _UpperLimit == pbm._UpperLimit;
}

/**
 * \brief       surcharge d'opérateur de comparaison != d'un problème
 * \param       pbm \e Problem problème
 * \return      \e bool
 */
bool Problem::operator!= (const Problem& pbm) const
{
    return !(*this==pbm);
}

/**
* \brief    renvoie la direction
* \return   Une Direction représentant la diection
*/

Direction Problem::direction() const{ return _direction;}

/**
* \brief    renvoie la dimension
* \return   Un entier représentant la dimension
*/
const int Problem::dimension() const
{
	return _dimension;
}

/**
* \brief    renvoie la valeur limite minimum du paramètre d'optimisation
* \return   Un \e double représentant la valeur limite minimum de la valeur à atteindre
*/
const int Problem::LowerLimit() const
{
	return _LowerLimit;
}

/**
* \brief    renvoie la valeur limite maximum du paramètre d'optimisation
* \return   Un \e double représentant la valeur limite maximum de la valeur à atteindre
*/
const int Problem::UpperLimit() const
{
	return _UpperLimit;
}


/**
* \brief    modifie la dimension
* \param    val \e double la dimension
*/
/*void Problem::dimension(const double val)
{
	_dimension = val;
}

/**
* \brief    modifie la limite minimum du paramètre d'optimisation
* \param    val \e double la dimension
*/
/*void Problem::LowerLimit(const double val)
{
	_LowerLimit = val;
}*/

/**
* \brief    modifie la limite maximum du paramètre d'optimisation
* \param    val \e double la limite maximum du paramètre d'optimisation
*/
/*void Problem::UpperLimit(const double val)
{
	_UpperLimit = val;
}

/**
* \brief    Le destructeur du problème
*/
Problem::~Problem()
{

}


