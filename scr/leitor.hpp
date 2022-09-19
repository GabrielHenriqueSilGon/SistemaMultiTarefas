#ifndef LEITOR_HPP
#define LEITOR_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class leitor
{

public:

  void LerArquivoD (unordered_map < string, vector < int >>*VD,
		    unordered_map < string, vector < int >>*DD);

  void LerArquivoT (unordered_map < int, vector < string >> *VT,
		    unordered_map < string, vector < int >>*DT);

  void TokenizarInColumn (string s, unordered_map < string,
			  vector < int >>*V, unordered_map < string,
			  vector < int >>*D, int cont);

  void TokenizarInLine (string s, unordered_map < int,
			vector < string >> *V, unordered_map < string,
			vector < int >>*D, int cont);

  void mostra (unordered_map < string, vector < int >>V);

  void mostraVT (unordered_map < int, vector < string >> VT);

  void Permuta (unordered_map < int, vector < string >> VT,
		unordered_map < string, vector < int >>VD);

};

#endif