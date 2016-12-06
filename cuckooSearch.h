#ifndef CUCKOOSEARCH_H
#define CUCKOOSEARCH_H
#include <iostream>
#include <fstream>
#include <vector>

class Solution;
class SetUpParams;
class Problem;

//=======================================================================
/**
 * \file       cuckooSearch.h
 * \author     Nouwezem Fotso Zachée
 * \version    1.2
 * \date       20 Novembre 2016
 * \brief      Classe représentant le noyau de l'algorithme                
 */

class CuckooSearch
  {
	private:
		/**
    	* \brief	le tableau des solutions
    	*/ 
		vector<Solution*> _solutions;   
		/**
    	* \brief	le paramètre de l'algorithme
    	*/   
		const SetUpParams& _setup;
		/**
    	* \brief	le coût le plus élevé
    	*/
		unsigned int _upper_cost;
		/**
    	* \brief	le coût le plus élevé
    	*/
		unsigned int  _lower_cost; 
		/**
    	* \brief	le tableau contenant le degré d'adaptation des solutions
    	*/
    	vector<double> _fitness_values;
 
	public:
		
		/**
		* \brief	Construit un MyAlgorithm
		* \details	Initialise les valeurs par défaut : _setup(setup), _upper_cost(0), _lower_cost(0)
    	* \param    pbm \e Problem problème
    	* \param    setup \e SetUpParams paramètre
		*/
		CuckooSearch(const Problem& pbm,const SetUpParams& setup);  
		
		/**
		* \brief	détruit l'algorithme CSA
		*/
		~CuckooSearch();
		
		/**
     	* \brief    surcharge d'opérateurs <<
     	* \details  permet d'afficher les variables à l'écran
     	*           
     	* \param    os \e ostream flux de sortie
     	* \param    myAlgo \e CuckooSearch algorithme
     	*/

		friend ostream& operator<< (ostream& os, const CuckooSearch& myAlgo);
		
		
		friend istream& operator>> (istream& is, CuckooSearch& myAlgo); // est ce qu'il faut saisir les param ...??
		CuckooSearch& operator= (const CuckooSearch& myAlgo); // est ce qu'il faut ???
		
		/**
		* \brief	renvoie une référence vers le paramètre de l'algorithme
		* \return   Un \e SetUpParams représentant une référence vers le paramètre de l'algorithme
		*/
		
		const SetUpParams& setup() const;
		
		/**
     	* \brief    initialise l'algorithme CuckooSearch
     	* \param    pbm \e Problem problème
     	*/
     	
	  	void initialize(const Problem& pbm); 
	  	
	  	
		/**
     	* \brief    évalue les solutions
    	*/
        void evaluate();
        
        /**
		* \brief	renvoie des références vers le tableau des solutions
		* \return   Un \e std::vector<Solution*>& représentant le tableau des solutions
		*/
	 
	 	const vector<Solution*>& solutions() const;
	 	
	 	/**
		* \brief	renvoie l'indice de la solution contenant le coût le plus élevé
		* \return   Un \e unsigned int représentant l'indice de la solution contenant le coût le plus élevé
		*/
		
		unsigned int upper_cost() const;
		
		/**
		* \brief	renvoie l'indice de la solution contenant le coût le moins élevé
		* \return   Un \e unsigned int représentant l'indice de la solution contenant le coût le moins élevé
		*/
		
		unsigned int lower_cost() const;
		
		/**
		* \brief	renvoie une solution à l'indice index
		* \return   une reference vers une solution
		*/
		
		Solution& solution(const unsigned int index) const;// 
		
		/**
		* \brief	renvoie la fitness à l'indice index
		* \return   Un réel representant la fiteness à l'indice index
		*/
		double fitness(const unsigned int index) const;//
         
		/**
		* \brief	renvoie le meilleur coût
		* \return   Un \e double représentant le meilleur coût
		*/
		
		double best_cost() const;
		
		/**
		* \brief	renvoie le mauvais coût
		* \return   Un \e double représentant le mauvais coût
		*/
		double worst_cost() const;
		
		/**
		* \brief	renvoie une référence vers la meilleure solution
		* \return   Un \e Solution représentant la meilleure solution
		*/
		
		Solution& best_solution() const;
		
		/**
		* \brief	renvoie une référence vers la pire solution
		* \return   Un \e Solution représentant la pire solution
		*/
		
		Solution& worst_solution() const;
		
		/**
		* \brief	etapes de l'évolution de l'algorithme CSA
		
		*/
		 
		void evolution(int iter); 

  };
  
#endif

#endif
