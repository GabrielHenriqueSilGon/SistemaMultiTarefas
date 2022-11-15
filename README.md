# SistemaMultiTarefas
 
Esse projeto será escrito em vários passos, e com cada novo update uma nova função será habilitada no código, a fim de simular um sistema de classificação cujas características nos permitirão observar conceitos importantes como: escalonamento e gestão de memória primária. Neste sistema, vamos considerar duas bases de dados D e T, arquivos do tipo csv que contém dados para manipulação pelas funções do programa.

# Etapa I

A princípio, o programa têm uma função de leitor, uma vez que este deve ler os arquivos D e T e organizar seus dados em Tabelas Hash refentes à seus valores númericos e seus dados em texto. Sendo assim, nessa etapa são declarados 4 unordered maps no main, cada membro nessas Hash tem seus índices no arquivo como valor e uma string como chave, tal string contêm um valor númerico para Hash's V e um dado textual para Hash's D.

Após ler uma linha, o leitor envia a string resultande para o Tokenizador, que por meio de stringstreams separa os valores dos dados, e guarda a linha em que cada um foi restirado.

Abaixo estão os resultados obtidos em Teste:

![image](https://user-images.githubusercontent.com/84454532/202011661-f8c15b40-24ee-4287-a1db-d7530ccd0f4a.png)
Figura 1: D

![image](https://user-images.githubusercontent.com/84454532/202011471-574ab77c-c945-46ad-a82b-190770e3dcac.png)
Figura 2: T

# Etapa II

Para essa etapa, a função DadosPString pega os valores de T e tokeniza sua string para um vetor de strings, colocando tal vetor em uma hash com a linha nno arquivo como chave. Depois, tal Hash é comparada com os valores de D, e se ouver dois valores iguais, a Hash DadosString guarda ele e sua coluna em T com sua linha como chave.

Então entra função permuta, que de fato permuta a hash e salva as combinações do vetor em DadosStringSalvos, pra de pois exibí-los pela função mostraP como visto abaixo.

![image](https://user-images.githubusercontent.com/84454532/202016511-3383f7e7-e286-447e-aaa7-17b7b4e2efea.png)
Figura 3: Permutação da linha 4

# Etapa 3 e 4

Nessa Etapa, a função intercede verifica as classes para descubrir em qual delas há o maior número de interseções, utilizando a Hash DadosStringSalvos criada anteriormente. Há também uma Hash de Cache, a qual guarda o resultado de interseções já realizadas anteriormente. A partir de cada nova entrada, se o resultado já existir em hash o programa apenas testa os valores em função do resultado. Ao fim, o programa mostra quantas vezes cada classe teve o maior número de interseções.

![image](https://user-images.githubusercontent.com/84454532/202020053-e95b36c4-8778-4dc1-9e36-ed3935d1f563.png)
Figura 4: Interseções por classe.

# Makefile

Como executar:

  make clean - Apaga a última compilação realizada contida na pasta build
  
  make - Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build
  
  make run - Executa o programa da pasta build após a realização da compilação
