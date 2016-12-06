#ifndef PROBLEM_H
#define PROBLEM_H
#include <iostream>
#include <fstream>

enum Direction{Maximize,Minimize};

/**
 * \file       Problem.h
 * \author     NOUWEZEM FOTSO Zachée
 * \version    1.0	
 * \date       02 Novembre 2016
 * \brief      Réprésente le problème de l'algorithme CSA
 *
 * \details    Cette classe surcharge les accesseurs du problème
 */

class Problem
  {
	public:
	/**
	* \brief	Construit un problème avec les valeurs par defaut
	*/
		Problem();
		
	/**
	* \brief	Construit un problème avec sa direction, sa dimension, le LowerLimit et le UpperLimit
	*/
		Problem(Direction direction, int dimension, double LowerLimit, double UpperLimit);
		
	/**
	* \brief	Détruit un problème
	*/	
		~Problem();
		
	/**
     * \brief    surcharge d'opérateurs <<
     * \details  permet d'afficher les variables à l'écran
     *           
     * \param    os \e ostream flux de sortie
     * \param    pbm \e Problem problème
     */

		friend ostream& operator<< (ostream& os, const Problem& pbm);
		
	/**
     * \brief       surcharge d'opérateurs >>
     * \details     permet d'entrer les valeurs numériques au clavier pour créer un problème
     *                 
     * \param       is \e istream flux d'entrée
     * \param       pbm \e Problem problème
     */
		friend istream& operator>> (istream& is, Problem& pbm);
		
	/**
     * \brief       surcharge d'opérateur d'affectation
     * \param       pbm \e Problem problème
     * \return   	Une référence de type \e Problem
     */

		Problem& operator=  (const Problem& pbm);
		
	/**
     * \brief       surcharge d'opérateur de comparaison == d'un problème
     * \param       pbm \e Problem problème
     * \return   	\e bool
     */
		bool operator== (const Problem& pbm) const;
		
	/**
     * \brief       surcharge d'opérateur de comparaison != d'un problème
     * \param       pbm \e Problem problème
     * \return   	\e bool
     */
		bool operator!= (const Problem& pbm) const;
		
	/**
     * \brief       renvoie la direction d'un problème c'est à dire maximise ou minimise
     * \param       pbm \e Problem problème
     * \return   	\e bool
     */

		Direction direction () const; 
		
	/**
	* \brief	renvoie la dimension
	* \return	Un entier représentant la dimension
	*/
		int dimension() const;		
	/**
	* \brief	la valeur limite minimum du paramètre d'optimisation
	*/
    int _LowerLimit;
	
	/**
    * \brief	la valeur limite maximum du paramètre d'optimisation
    */    
    int _UpperLimit;

	private:

	/**
    * \brief	la dimension
    */ 
    int _dimension;
    
    /**
    * \brief	la direction
    */
    Direction _direction; // on n'en a pas besoin
  };

#endif
