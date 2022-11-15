#ifndef LEITOR_HPP
#define LEITOR_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class leitor
{

public:

  void LerArquivoD (unordered_map < string, vector < int >>*VD,
		    unordered_map < string, vector < int >>*DD);
      
  void LerArquivoT (unordered_map < string, vector < int >>*VT,
		    unordered_map < string, vector < int >>*DT);
     
  void Tokenizar (string s, unordered_map < string,
		   vector < int >>*V, unordered_map < string,
		   vector < int >>*D, int cont);
       
  void mostra (unordered_map < string, vector < int >>V);
  
  //Passo 2
  void mostraP (unordered_map <int,vector<vector<string>>>*DadosStringSalvos);
		
  void DadosPString (unordered_map < string, vector < int > >*VD,
		unordered_map < string, vector < int > >*VT,
		unordered_map < int, vector < string > >*DadosString);
		
  void permuta(unordered_map<int, vector<string> > *DadosString, 
        unordered_map<int, vector<vector<string> > > *DadosStringSalvos);
        
        
  //Passo 3 e 4
  void intercede (unordered_map<int,vector<vector<string>>>*DadosStringSalvos,
			       unordered_map < string, vector < int > >*VD,
			       unordered_map < string, vector < int > >*DD,
			       unordered_map < string, vector < int >>*cache,
			       unordered_map < string, int >*DI);
			 
  void interAux (unordered_map<string,vector<int>>*DD,
			     unordered_map < string, int > *DI);
			 
  void InterseD (unordered_map < string, vector<int> > *DD,
			                 unordered_map < string, int > *DA,
			                 vector<int> r);
			                 
  void MaiorClasse(unordered_map<string,int>*DA,unordered_map<string,int>*DI);
  
  void mostraI (unordered_map < string, int > *DI);
     
};

#endif
