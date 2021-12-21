# LKM-Command-Line-Parsing

  👾 Hoje iremos falar sobre Command Line Parsing diretamente no LKM. Esse é a <b>segunda parte</b> da nossa série de estudos para Rootkits.


  - Compreendendo a estrutura do nosso LKM.
  - Criando novos módulos e funções de int, string, long, array e short.
  - Imprimindo as funções nos Registros do Kernel.
    - Entendendo para que servem as FLAGS de Registros.
    - Entendendo sobre as novas bibliotecas.
<br>
<br>

# Compreendendo a estrutura do nosso LKM.

<img src="https://imgur.com/oAcCbs8.png">
<br>
  - Temos então todo nosso cabeçalho de <code>#include's</code> com algumas bibliotecas que expliquei no artigo passado que ensinei a construir um <a href="https://github.com/MarktwainSTDLL/Linux-Kernel-Module-basic-explanation/">LKM</a> simples. Nesse artigo estarei explicando sobre as novas bibliotecas que foram importadas.
  <br>
  <br>
  - Possuímos abaixo do nosso cabeçalho as funções de licenciamento e descrição. Como não expliquei no artigo passado, nesse artigo irei explicar para que elas servem e como vê-las em nosso LKM montado.
  <code>
