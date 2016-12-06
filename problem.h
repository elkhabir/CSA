#ifndef PROBLEM_H
#define PROBLEM_H
#include <iostream>
#include <fstream>

enum Direction{Maximize,Minimize};

/**
 * \file       Problem.h
 * \author     NOUWEZEM FOTSO Zach�e
 * \version    1.0	
 * \date       02 Novembre 2016
 * \brief      R�pr�sente le probl�me de l'algorithme CSA
 *
 * \details    Cette classe surcharge les accesseurs du probl�me
 */

class Problem
  {
	public:
	/**
	* \brief	Construit un probl�me avec les valeurs par defaut
	*/
		Problem();
		
	/**
	* \brief	Construit un probl�me avec sa direction, sa dimension, le LowerLimit et le UpperLimit
	*/
		Problem(Direction direction, int dimension, double LowerLimit, double UpperLimit);
		
	/**
	* \brief	D�truit un probl�me
	*/	
		~Problem();
		
	/**
     * \brief    surcharge d'op�rateurs <<
     * \details  permet d'afficher les variables � l'�cran
     *           
     * \param    os \e ostream flux de sortie
     * \param    pbm \e Problem probl�me
     */

		friend ostream& operator<< (ostream& os, const Problem& pbm);
		
	/**
     * \brief       surcharge d'op�rateurs >>
     * \details     permet d'entrer les valeurs num�riques au clavier pour cr�er un probl�me
     *                 
     * \param       is \e istream flux d'entr�e
     * \param       pbm \e Problem probl�me
     */
		friend istream& operator>> (istream& is, Problem& pbm);
		
	/**
     * \brief       surcharge d'op�rateur d'affectation
     * \param       pbm \e Problem probl�me
     * \return   	Une r�f�rence de type \e Problem
     */

		Problem& operator=  (const Problem& pbm);
		
	/**
     * \brief       surcharge d'op�rateur de comparaison == d'un probl�me
     * \param       pbm \e Problem probl�me
     * \return   	\e bool
     */
		bool operator== (const Problem& pbm) const;
		
	/**
     * \brief       surcharge d'op�rateur de comparaison != d'un probl�me
     * \param       pbm \e Problem probl�me
     * \return   	\e bool
     */
		bool operator!= (const Problem& pbm) const;
		
	/**
     * \brief       renvoie la direction d'un probl�me c'est � dire maximise ou minimise
     * \param       pbm \e Problem probl�me
     * \return   	\e bool
     */

		Direction direction () const; 
		
	/**
	* \brief	renvoie la dimension
	* \return	Un entier repr�sentant la dimension
	*/
		int dimension() const;		
	/**
	* \brief	la valeur limite minimum du param�tre d'optimisation
	*/
    int _LowerLimit;
	
	/**
    * \brief	la valeur limite maximum du param�tre d'optimisation
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
