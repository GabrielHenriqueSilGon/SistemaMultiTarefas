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

  while (ss >> t)
    {
      if (conti < 5)
	{
	  o = o + t + esp;
	  conti++;
	}

      else
	cla = t;

    }

  (*V)[o].push_back (cont);
  (*D)[cla].push_back (cont);


}

//Passo 2

void
leitor::DadosPString (unordered_map < string, vector<int> >*VD,
		unordered_map < string, vector<int> >*VT,
		unordered_map < int, vector<string> >*DadosString)
{

  unordered_map < string, vector<int> >::iterator it;
  unordered_map < int, vector <string> >::iterator itr;
  unordered_map < int, vector <string> >DadosStringi;

  for (it = VT->begin (); it != VT->end (); ++it)
    {
      string t;
      stringstream ss (it->first);
      
      while (ss >> t)
      {
          for (auto i = it->second.begin (); i != it->second.end (); ++i)
          DadosStringi[*i].push_back (t);
      }
      
    }
    
  for (itr = DadosStringi.begin (); itr != DadosStringi.end (); ++itr)
    {
      int cont = 0;
      for (string n:itr->second)
      {
          cont++;
          string vam;
          vam = to_string (cont);
          vam = "," + vam;
          unordered_map < string, vector < int >>::iterator itt;
          
          for (itt = VD->begin (); itt != VD->end (); ++itt)
          {
              stringstream ssi (itt->first);
              string ti;
              
              while (ssi >> ti)
              {
                  if (ti == n)
                  (*DadosString)[itr->first].push_back (n + vam);
              }
          }
      }
    }
}



void
leitor::permuta (unordered_map < int, vector <string> >*DadosString,
	     unordered_map < int, vector <vector<string>> >*DadosStringSalvos)
{

  unordered_map < int, vector < string > >::iterator it;
  vector < string >::iterator itr;
  vector < string >::iterator x, y, z;

  vector < string > vec;
  vector < vector<string> > vecvec;

  for (it = DadosString->begin (); it != DadosString->end (); ++it)
    {

      sort ((*it).second.begin (), (*it).second.end ());
     
      vecvec.clear ();
      
      for (itr = it->second.begin (); itr != it->second.end (); ++itr)
	{

	  vec.clear ();
	  vec.push_back ((*itr));
	  vecvec.push_back (vec);
	}
	
      for (itr = it->second.begin (); itr != it->second.end (); ++itr)
	{

	  x = itr;
	  ++x;
	  for (; x != it->second.end (); ++x)
	    {

	      vec.clear ();
	      vec.push_back (*itr);
	      vec.push_back (*x);
	      vecvec.push_back (vec);
	    }
	}
	
      for (itr = it->second.begin (); itr != it->second.end (); ++itr)
	{

	  x = itr;
	  ++x;

	  for (; x != it->second.end (); ++x)
	    {

	      y = x;
	      ++y;

	      for (; y != it->second.end (); ++y)
		{

		  vec.clear ();
		  vec.push_back (*itr);
		  vec.push_back (*x);
		  vec.push_back (*y);
		  vecvec.push_back (vec);

		}
	    }
	}
     
      for (itr = it->second.begin (); itr != it->second.end (); ++itr)
	{
      
     x = itr;
     ++x;
     
     for (; x != it->second.end (); ++x)
      {
         
         y = x;
         ++y;
         
         for (; y != it->second.end (); ++y)
            {
             z = y;
             ++z;
             
             for (; z != it->second.end (); ++z)
                {
                 
                 vec.clear ();
                 vec.push_back (*itr);
                 vec.push_back (*x);
                 vec.push_back (*y);
                 vec.push_back (*z);
                 vecvec.push_back (vec);
                }
            }
          
        }
	}
     
     (*DadosStringSalvos)[it->first] = vecvec;
    }
}


void
leitor::mostra (unordered_map < string, vector < int > >V)
{

  unordered_map < string, vector < int >>::iterator it;

  for (it = V.begin (); it != V.end (); ++it)
    {

      cout << it->first << " : ";

      for (auto i = it->second.begin (); i != it->second.end (); ++i)
	cout << *i << " ";

      cout << endl;
    }
}

void
leitor::mostraP (unordered_map < int, vector <vector<string>> >*DadosStringSalvos)
{
  unordered_map < int, vector < vector < string > >>::iterator it;

  for (it = DadosStringSalvos->begin (); it != DadosStringSalvos->end (); ++it)
    {
     
      cout << it->first << " : ";
       
      for (vector<string> n:it->second)
      {
          for (string a:n)
          {
              cout << a << " ";
              
          }
         cout << endl;
      }
      
     cout << endl << endl;
    }
}

//Passo 3

void
leitor::intercede (unordered_map<int,vector<vector<string>>>*DadosStringSalvos,
			       unordered_map < string, vector < int > >*VD,
			       unordered_map < string, vector < int > >*DD,
			       unordered_map < string, vector < int >>*cache,
			       unordered_map < string, int >*DI)
  {
    unordered_map < int, vector < vector < string > >>::iterator it;
    unordered_map < string, vector < int >>::iterator itr;
    unordered_map < string, int >DA;

    interAux (DD, DI);

    for (it = DadosStringSalvos->begin(); it!=DadosStringSalvos->end(); ++it)
      {
         interAux (DD, &DA);
         
         for (vector < string > vec:it->second)
            {
                //cout << " teste ";
             vector < int > r;
             unordered_map < string, vector < int >>::iterator ita;
             if (vec.size () == 1)
                {
                    string vecn = vec[0];
                    vecn.pop_back();
                    vecn.pop_back();
                    
                    unordered_map < string, vector < int >>::iterator itVD;
                   
                    for (itVD = VD->begin (); itVD != VD->end (); ++itVD)
                    {
                      string t;
                      stringstream ss (itVD->first);
                      while (ss >> t)
                       {
                          if(t == vecn){
                              itr = itVD;
                              r = itr->second;
                              cache->insert({vec[0], r});
                            }
                        }
                    }
                }
  else
   {
     string s1, s2;
     vector <int> v1, v2;
     bool b = false;
     string sa = "";
      
     for (string str:vec){
         
         
         if (b){
             sa.append (s1).append (" ");
             s2.assign (str);
             
             string vecn = s2;
    vecn.pop_back();
    vecn.pop_back();
    
    unordered_map < string, vector < int >>::iterator itVD;
    for (itVD = VD->begin (); itVD != VD->end (); ++itVD)
    {
      string t;
      stringstream ss (itVD->first);
      while (ss >> t)
       {
          if(t == vecn){
              v2 = itVD->second;
           }
        }
    }
             
             r.clear ();
             s1.clear ();
             sa.append (s2);
             ita = cache->find (sa);
             
     if (ita != cache->end ())
        {
          r = (*cache)[sa];
        }
        
     else
        {
  set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(r));
  cache->insert({sa, r}); 
        }
        
      s1.assign (sa);
      v1 = r;
    }
     
     else
        { 
         
         b = true;
         s1.assign (str);
         string vecn = s1;
         vecn.pop_back();
         vecn.pop_back();
         
         unordered_map < string, vector < int >>::iterator itVD;
         for (itVD = VD->begin (); itVD != VD->end (); ++itVD){
             string t;
             stringstream ss (itVD->first);
             while (ss >> t){
                 if(t == vecn){
                     v1 = itVD->second;
                 }
             }
         }
        }
       }
      }
     
      InterseD (DD, &DA, r);
      
     }
     
     cout << "Intersecao:" << it->first << endl;
     mostraI (&DA);
     MaiorClasse (&DA, DI);
     cout << endl;
    }
     
}

void
leitor::interAux(unordered_map<string,vector<int>>*DD,
			                  unordered_map < string, int > *DI)
  {
      
     unordered_map < string, vector < int >>::iterator it;
     
     for (it = DD->begin (); it != DD->end (); ++it)
     {
         (*DI)[it->first] = 0;
     }
  }

void
leitor::InterseD (unordered_map < string, vector<int> > *DD,
			                 unordered_map < string, int > *DA,
			                 vector<int> r)
  {
      unordered_map < string, vector < int >>::iterator itr;
      
      for (itr = DD->begin (); itr != DD->end (); ++itr)
      {
          vector<int> aux;
          
          set_intersection(r.begin(), r.end(),
          (*DD)[itr->first].begin(), (*DD)[itr->first].end(),
          back_inserter (aux));
          
          (*DA)[itr->first] += aux.size ();
      }
  }

void
leitor::MaiorClasse(unordered_map<string,int>*DA,unordered_map<string,int>*DI)
  {
      
     unordered_map < string, int >::iterator it;
     string s;
     int i = -1;
     for (it = DA->begin (); it != DA->end (); ++it)
     {
         if (it->second > i)
            {
             i = it->second;
             s.assign (it->first);
            }
      }
     cout << "  Classe com mais inter: " << s << endl;
     (*DI)[s]++;
  }

void
leitor::mostraI (unordered_map < string, int > *DI)
  {
      unordered_map < string, int >::iterator it;
      
      for(it = DI->begin (); it != DI->end (); ++it)
          cout << it->first << " : " << it->second << endl;
  }
