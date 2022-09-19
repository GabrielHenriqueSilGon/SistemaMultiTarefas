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
	  TokenizarInColumn (s, VD, DD, cont);
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
leitor::LerArquivoT (unordered_map < int, vector < string > >*VT,
		     unordered_map < string, vector < int > >*DT)
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
	  TokenizarInLine (s, VT, DT, cont);
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
leitor::TokenizarInColumn (string s, unordered_map < string,
			   vector < int > >*V, unordered_map < string,
			   vector < int > >*D, int cont)
{

  char vir = ',';
  string t;
  int conti = 1;
  stringstream ss (s);

  while (getline (ss, t, vir))
    {

      if (conti < 5)
	{
	  t.append (",").append (to_string (conti));
	  (*V)[t].push_back (conti);
	}
      else
	{
	  (*D)[t].push_back (cont);
	}
      conti++;
    }
}

void
leitor::TokenizarInLine (string s, unordered_map < int,
			 vector < string > >*V, unordered_map < string,
			 vector < int > >*D, int cont)
{
  char vir = ',';
  string t;
  int conti = 1;
  stringstream ss (s);

  while (getline (ss, t, vir))
    {
      if (conti < 5)
	{
	  t.append (",").append (to_string (conti));
	  (*V)[cont].push_back (t);
	}
      conti++;
    }
}



void
leitor::mostra (unordered_map < string, vector < int > >V)
{

  unordered_map < string, vector < int >>::iterator it;

  for (it = V.begin (); it != V.end (); ++it)
    {

      cout << it->first << " :: ";

    for (int n:it->second)
	{

	  cout << n << " ";
	}

      cout << endl;
    }
}

void
leitor::mostraVT (unordered_map < int, vector < string > >VT)
{

  unordered_map < int, vector < string > >::iterator it;


  for (it = VT.begin (); it != VT.end (); ++it)
    {

      cout << it->first << " :: ";

    for (string n:it->second)
	{

	  cout << n << " ";
	}

      cout << endl;
    }
}


void
leitor::Permuta (unordered_map < int, vector < string >> VT,
		 unordered_map < string, vector < int >>VD)
{
  int cont = 0;
  unordered_map < int, vector < string > >::iterator it;

  unordered_map < int, vector < string > >VP;

  cout << "\nValores de T encontrados como chave de D:\n";
  for (it = VT.begin (); it != VT.end (); ++it)
    {

    for (string n:it->second)
	{

	  if (VD.find (n) == VD.end ())
	    {

	      cout << n << endl;
	      VP[it->first].push_back (n);
	      cont++;
	    }
	}
    }

  cout << "Total de chaves encontradas: " << cont << endl;

  mostraVT (VP);

}
