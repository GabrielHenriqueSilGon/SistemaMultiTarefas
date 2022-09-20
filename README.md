# SistemaMultiTarefas
 
Esse projeto será escrito em vários passos, e com cada novo update uma nova função será habilitada no código, a fim de simular um sistema de classificação cujas características nos permitirão observar conceitos importantes como: escalonamento e gestão de memória primária. Neste sistema, vamos considerar duas bases de dados D e T, arquivos do tipo csv que contém dados para manipulação pelas funções do programa.

# Etapa I

A princípio, o programa têm uma função de leitor, uma vez que este deve ler os arquivos D e T e organizar seus dados em Tabelas Hash refentes à seus valores númericos e seus dados em texto. Sendo assim, nessa etapa são declarados 4 unordered maps no main, cada membro nessas Hash tem seus índices no arquivo como valor e uma string como chave, tal string contêm um valor númerico para Hash's V e um dado textual para Hash's D.

# Etapa II

A função Permuta é adicionada no cpp, tal função compara as Hash's V de ambos arquivos e salva os valores idénticos em uma Hash VP, e depois à imprime.

# Makefile

Como executar:

  make clean - Apaga a última compilação realizada contida na pasta build
  
  make - Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build
  
  make run - Executa o programa da pasta build após a realização da compilação
