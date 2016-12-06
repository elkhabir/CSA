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
 * \author     Nouwezem Fotso Zach�e
 * \version    1.2
 * \date       20 Novembre 2016
 * \brief      Classe repr�sentant le noyau de l'algorithme                
 */

class CuckooSearch
  {
	private:
		/**
    	* \brief	le tableau des solutions
    	*/ 
		vector<Solution*> _solutions;   
		/**
    	* \brief	le param�tre de l'algorithme
    	*/   
		const SetUpParams& _setup;
		/**
    	* \brief	le co�t le plus �lev�
    	*/
		unsigned int _upper_cost;
		/**
    	* \brief	le co�t le plus �lev�
    	*/
		unsigned int  _lower_cost; 
		/**
    	* \brief	le tableau contenant le degr� d'adaptation des solutions
    	*/
    	vector<double> _fitness_values;
 
	public:
		
		/**
		* \brief	Construit un MyAlgorithm
		* \details	Initialise les valeurs par d�faut : _setup(setup), _upper_cost(0), _lower_cost(0)
    	* \param    pbm \e Problem probl�me
    	* \param    setup \e SetUpParams param�tre
		*/
		CuckooSearch(const Problem& pbm,const SetUpParams& setup);  
		
		/**
		* \brief	d�truit l'algorithme CSA
		*/
		~CuckooSearch();
		
		/**
     	* \brief    surcharge d'op�rateurs <<
     	* \details  permet d'afficher les variables � l'�cran
     	*           
     	* \param    os \e ostream flux de sortie
     	* \param    myAlgo \e CuckooSearch algorithme
     	*/

		friend ostream& operator<< (ostream& os, const CuckooSearch& myAlgo);
		
		
		friend istream& operator>> (istream& is, CuckooSearch& myAlgo); // est ce qu'il faut saisir les param ...??
		CuckooSearch& operator= (const CuckooSearch& myAlgo); // est ce qu'il faut ???
		
		/**
		* \brief	renvoie une r�f�rence vers le param�tre de l'algorithme
		* \return   Un \e SetUpParams repr�sentant une r�f�rence vers le param�tre de l'algorithme
		*/
		
		const SetUpParams& setup() const;
		
		/**
     	* \brief    initialise l'algorithme CuckooSearch
     	* \param    pbm \e Problem probl�me
     	*/
     	
	  	void initialize(const Problem& pbm); 
	  	
	  	
		/**
     	* \brief    �value les solutions
    	*/
        void evaluate();
        
        /**
		* \brief	renvoie des r�f�rences vers le tableau des solutions
		* \return   Un \e std::vector<Solution*>& repr�sentant le tableau des solutions
		*/
	 
	 	const vector<Solution*>& solutions() const;
	 	
	 	/**
		* \brief	renvoie l'indice de la solution contenant le co�t le plus �lev�
		* \return   Un \e unsigned int repr�sentant l'indice de la solution contenant le co�t le plus �lev�
		*/
		
		unsigned int upper_cost() const;
		
		/**
		* \brief	renvoie l'indice de la solution contenant le co�t le moins �lev�
		* \return   Un \e unsigned int repr�sentant l'indice de la solution contenant le co�t le moins �lev�
		*/
		
		unsigned int lower_cost() const;
		
		/**
		* \brief	renvoie une solution � l'indice index
		* \return   une reference vers une solution
		*/
		
		Solution& solution(const unsigned int index) const;// 
		
		/**
		* \brief	renvoie la fitness � l'indice index
		* \return   Un r�el representant la fiteness � l'indice index
		*/
		double fitness(const unsigned int index) const;//
         
		/**
		* \brief	renvoie le meilleur co�t
		* \return   Un \e double repr�sentant le meilleur co�t
		*/
		
		double best_cost() const;
		
		/**
		* \brief	renvoie le mauvais co�t
		* \return   Un \e double repr�sentant le mauvais co�t
		*/
		double worst_cost() const;
		
		/**
		* \brief	renvoie une r�f�rence vers la meilleure solution
		* \return   Un \e Solution repr�sentant la meilleure solution
		*/
		
		Solution& best_solution() const;
		
		/**
		* \brief	renvoie une r�f�rence vers la pire solution
		* \return   Un \e Solution repr�sentant la pire solution
		*/
		
		Solution& worst_solution() const;
		
		/**
		* \brief	etapes de l'�volution de l'algorithme CSA
		
		*/
		 
		void evolution(int iter); 

  };
  
#endif

#endif
