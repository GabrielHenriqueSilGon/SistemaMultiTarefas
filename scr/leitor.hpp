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

  void LerArquivoT (unordered_map < string, vector < int >>*VT,
		    unordered_map < string, vector < int >>*DT);

  void Tokenizar (string s, unordered_map < string,
		   vector < int >>*V, unordered_map < string,
		   vector < int >>*D, int cont);

  void mostra (unordered_map < string, vector < int >>V);

  void Permuta (unordered_map < string, vector < int >>VT,
		unordered_map < string, vector < int >>VD);

};

#endif
