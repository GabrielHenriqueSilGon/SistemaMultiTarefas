#include "leitor.hpp"

int
main ()
{
  leitor L;
  unordered_map < int, vector < string > >VT;
  unordered_map < string, vector < int >>VD;
  unordered_map < string, vector < int >>DD;
  unordered_map < string, vector < int >>DT;

  cout << "\nTentando ler arquivos...\n";
  L.LerArquivoD (&VD, &DD);
  L.LerArquivoT (&VT, &DT);

  cout << "\nArquivo D:\n";
  L.mostra (VD);
  L.mostra (DD);

  cout << "\nArquivo T:\n";
  L.mostraVT (VT);
  L.mostra (DT);

  cout << "\nPermutando arquivo:\n";
  L.Permuta (VT, VD);

  return 0;
}
