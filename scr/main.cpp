#include "leitor.hpp"

int
main ()
{
  leitor L;
  unordered_map < string, vector < int >>VT;
  unordered_map < string, vector < int >>VD;
  unordered_map < string, vector < int >>DD;
  unordered_map < string, vector < int >>DT;

  //cout << "\nTentando ler arquivos...\n";
  //L.LerArquivoD (&VD, &DD);
  //L.LerArquivoT (&VT, &DT);
  
  //para teste
  string strinD[] = { "5.4 3.4 1.5 0.4 Iris-setosa",
    "6.3 2.9 5.6 1.8 Iris-virginica",
    "5.8 2.6 4.0 1.2 Iris-versicolor",
    "5.5 2.5 4.0 1.3 Iris-versicolor",
    "6.3 2.7 4.9 1.8 Iris-virginica",
    "5.0 3.2 1.2 0.2 Iris-setosa",
    "6.3 2.7 4.9 1.8 Iris-virginica",
    "4.9 3.1 1.5 0.1 Iris-setosa",
    "5.7 3.8 1.7 0.3 Iris-setosa"
  };

  string strinT[] = { "6.7 3.3 5.7 2.1 Iris-virginica",
    "6.7 3.0 5.2 2.3 Iris-virginica",
    "6.3 2.7 4.9 1.8 Iris-virginica",
    "5.0 3.5 1.6 0.6 Iris-setosa",
    "5.8 2.7 3.9 1.2 Iris-versicolor",
    "4.4 3.0 1.3 0.2 Iris-setosa",
    "6.8 3.2 5.9 2.3 Iris-virginica",
    "6.0 3.4 4.5 1.6 Iris-versicolor",
    "7.4 2.8 6.1 1.9 Iris-virginica"
  };
  
  
  //para teste
  for (int i = 0; i < 9; i++) {
      L.Tokenizar(strinD[i],&VD,&DD,i);
      L.Tokenizar(strinT[i],&VT,&DT,i);
  }

  cout << "\nArquivo D:\n";
  cout << "Valores em D:\n";
  L.mostra (VD);
  cout << "\nClasses em D:\n";
  L.mostra (DD);

  cout << "\nArquivo T:\n";
  cout << "Valores em T:\n";
  L.mostra (VT);
  cout << "\nClasses em T:\n";
  L.mostra (DT);

  cout << "\nPermutando arquivo:\n";
  L.Permuta (VT, VD);

  return 0;
}
