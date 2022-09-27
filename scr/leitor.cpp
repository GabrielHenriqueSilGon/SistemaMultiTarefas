#include "leitor.hpp"

void
leitor::LerArquivoD (unordered_map < string, vector < int >>*VD,
		     unordered_map < string, vector < int > >*DD)
{

  int cont = 1;
  string s;
  char del = ',';

  ifstream abreD ("./src/input/D.csv");

  if (abreD.is_open ())
    {
      while (!abreD.eof ())
	{
	  getline (abreD, s);
	  Tokenizar (s, VD, DD, cont);
	  cont++;
	}
    }
  else
    {
      cout << "Deu ruim\n";
    }

  abreD.close ();
}

void
leitor::LerArquivoT (unordered_map < string, vector < int >>*VT,
		    unordered_map < string, vector < int >>*DT)
{

  int cont = 1;
  string s;
  char del = ',';

  ifstream abreT ("./src/input/T.csv");

  if (abreT.is_open ())
    {
      while (!abreT.eof ())
	{
	  getline (abreT, s);
	  Tokenizar (s, VT, DT, cont);
	  cont++;
	}

    }
  else
    {
      cout << "Deu ruim\n";
    }

  abreT.close ();
}


void
leitor::Tokenizar (string s, unordered_map < string,
		    vector < int > >*V, unordered_map < string,
		    vector < int > >*D, int cont)
{

  string t;
  string o = "";
  string esp = " ";
  string cla;
  int conti = 1;
  stringstream ss (s);
  
  while (ss >>t)
  {
     if(conti < 5){
     o = o+t+esp;
     conti++;
     }
     
     else cla = t;
      
  }
  
  (*V)[o].push_back(cont);
  (*D)[cla].push_back(cont);
  
  
}

void
leitor::mostra (unordered_map < string, vector < int > >V)
{

  unordered_map < string, vector < int >>::iterator it;

  for (it = V.begin (); it != V.end (); ++it)
    {
      
      cout << it->first << " : ";
     
      for (auto i = it->second.begin(); i != it->second.end(); ++i)
         cout << *i << " ";
      
      cout << endl;
    }
}

void
leitor::Permuta (unordered_map < string, vector < int >> VT,
		 unordered_map < string, vector < int >>VD)
{
  int cont = 0;
  unordered_map < string, vector < int >>::iterator it;

  vector<string> VP;

  cout << "\nValores de T encontrados como chave de D:\n";
  for (it = VT.begin (); it != VT.end (); ++it)
    {
      unordered_map < string, vector < int >>::iterator itr;
     
      for (itr = VD.begin (); itr != VD.end (); ++itr)
        {
          if(itr->first == it->first){
              VP.push_back(it->first);
              cont++;
              
            }  
        }
      	 
    }
  
  
  cout << "Total de chaves encontradas: " << cont << endl;

  for (auto vv = VP.begin(); vv != VP.end(); ++vv)
        cout << *vv << " ";

}

