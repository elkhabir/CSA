#ifndef SOLUTION_H
#define SOLUTION_H
#include <cmath>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>

class Problem;

/**
 * \file       Solution.h
 * \author     NOUWEZEM FOTSO Zachée
 * \version    1.0	
 * \date       08 Novembre 2016
 * \brief      Réprésente la solution de l'algorithme CSA
 *
 */

class Solution
  {

	public:
		
	/**
	* \brief	Construit une Solution
    * \param    pbm \e Problem probl?me
	*/
		
		Solution (const Problem& pbm);
		
	/**
	* \brief	Constructeur de recopie d'une Solution
    * \param    sol \e Solution solution
	*/
		Solution (const Solution& sol);
		
	/**
	* \brief	d?truit un solution
	*/
		~Solution();
		
	/**
     * \brief    surcharge d'op?rateurs <<
     * \details  permet d'afficher les variables ? l'?cran
     *           
     * \param    os \e ostream flux de sortie
     * \param    sol \e Solution solution
     */

 		friend ostream& operator<< (ostream& os, const Solution& sol);
 		
 	/**
     * \brief    surcharge d'op?rateurs >>
     * \details  permet d'entrer les valeurs au clavier 
     *           
     * \param    is \e istream flux d'entrée
     * \param    sol \e Solution solution
     */
		friend istream& operator>> (istream& is, Solution& sol);
		
	/**
     * \brief	renvoie le probl?me
     * \return	Un \e Problem le probl?me pour lequel on g?n?re une solution
     */

		const Problem& pbm() const;
		
	/**
     * \brief    copie une solution
     * \param    sol \e Solution solution
     */

		Solution& operator=  (const Solution& sol);
		
	/**
     * \brief    surcharge d'op?rateurs ==
     * \param    sol \e Solution solution
     * \return	 Un \e bool
     */
		bool operator== (const Solution& sol) const;
		
	/**
     * \brief    surcharge d'op?rateurs !=
     * \param    sol \e Solution solution
     * \return	 Un \e bool
     */
		bool operator!= (const Solution& sol) const;
		
	/**
     * \brief    initialise la solution
     */
		
		void initialize();
		
	/**
    * \brief  -   Methode qui calcule puis renvoit la fitness d'une solution
    * \param  -   Aucun
    * \return -   reel correspondant a la fitness de la solution
	**/
		double fitness();
		
	/**
    * \brief  -    Methode qui renvoit uniquement la fitness d'une solution
    * \param  -   Aucun
    * \return -   reel correspondant a la fitness de la solution
    **/
		double get_fitness();
		
	/**
    * \brief  -    Methode qui renvoit la taille d'une solution 
    * \param  -   Aucun
    * \return -   entier correspondant a la taille de la solution
    **/
		
		unsigned int size() const;
		
	/**
    * \brief  -    Methode qui renvoit une reference vers un vecteur de nombres reels 
    * \param  -   Aucun
    * \return -   Reference vers un vecteur de nombres reels
    **/

		vector<double>& solution();
		
	/**
    * \brief  -    Methode qui retourne une solution à une position index 
    * \param  -   Aucun
    * \return -   Reference vers un vecteur de nombres reels (tableau _solution)
    **/
		
		double& position(const int index); 
		
	/**
    * \brief  -    Methode qui fixe la valeur a un index donne
    * \param  -   index   -   entier correspondant a l'index de la position dans le vecteur Solution
    * \param  -   value   -   nombre reel
    * \return -   Rien
    **/
        void  position(const int index, const double value);
	

	private:
        vector<double> _solution;
        double _current_fitness;                  
		const Problem& _pbm;
  };

#endif
