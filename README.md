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
  <br><br>
  <code>Bom, podemos notar pela seguinte função após a montagem do nosso LKM: A partir da versão do Kernel 2.6, tiveram algumas mudanças na nomenclatura de arquivos que são compilados para trabalhar com Kernel. A antiga extensão .o que hoje é utilizada a .ko (Kernel Object) é uma forma mais fácil de distinguir os arquivos de objetos convencionais. O motivo pela qual isso ocorre se dá ao fato da existência de um arquivo chamado .modinfo onde são mantidas as informações adicionais sobre os módulos.
  <br>
  <br>
  Podemos checar nosso LKM para sabermos qual é o tipo de informação dele. Digite o comando ( modinfo CommandParsing.ko ) e veja os resultados que são retornados em seu terminal.
 </code>
 <br>
 <br>
 <img src="https://imgur.com/Ej6qWOt.png">
 <br><br>
 <code>Podemos então verificar que as opções que foram escritas dentro do campo MODULE_LICENSE e MODULE_DESCRIPTION tiveram um retorno dentro do terminal. Podemos notar que além dessas informações, foram retornadas outras informações do PARM que estaremos falando sobre elas daqui a pouco. Bom, acredito que surgiu uma dúvida em sua mente a respeito disso, certo? "Para que essas informações servem?" Respondendo a essa dúvida, essas informações dão mais credibilidade ao usuário do nosso LKM. As funções como MODULE_AUTHOR, MODULE_LICENSE, MODULE_DESCRIPTION e etc, servem para as informações abaixo.</code>
<br><br>

  - MODULE_AUTHOR -> Identifica quem é o autor do módulo escrito.
  - MODULE_LICENSE -> Identifica de quem é a licença do módulo escrito.
  - MODULE_DESCRIPTION -> Essa função permite que o autor do módulo explique um pouco mais sobre a sua finalidade para que o usuário não fique com um pé atrás a respeito do módulo a ser usado.

  <b>Uma coisa interessante que vale ressaltar, é que todas essas macros estão no <code>linux/modules.h</code> que foi importado em nosso projeto. Ou seja! Elas não são usadas pelo próprio kernel. Elas são apenas documentações e podem ser visualizadas pelo <code>objdump</code> e caso você tenha dúvida de como elas são usadas, procure em <code>linux/drivers</code> e entenda como os desenvolvedores de módulos utilizam elas em seus projetos.</b>
<br><br>

<img src="https://imgur.com/bYERex4.png">
<br><br>
 - Bom, agora vamos falar sobre toda essa estrutura do nosso LKM na qual definimos todas essas variáveis no corpo do nosso LKM.
    - Definimos então as seguintes variáveis: <code> short, int, char e long </code>.
    <br><br>
    🌟 - short/long: assim como long, ele é um modificador do tipo inteiro que altera o tamanho dos bytes.
    🌟 - int: a variável do tipo inteiro é declarada como uma função que trabalha apenas com números.
    🌟 - char: a variável do tipo char é declarada como uma função que trabalha apenas com caracteres.
    <br><br>
