# <div align="center" styles="font-size:75px;" >Contextualização</div>

<p style="text-align: justify;">
A área de processamento e análise de imagens digitais teve um desenvolvimento significativo nos anos iniciais do século XXI. Este crescimento foi derivado do interesse de pesquisa e desenvolvimento de tecnologias pertinentes a áreas como medicina, biologia, automação industrial, sensoriamento remoto, entre outros. O processamento digital de imagens consiste em um conjunto de técnicas para capturar, representar e transformar imagens com o auxílio do computador. Com isso, pode-se extrair e identificar informações das imagens e melhorar a qualidade visual de alguns elementos estruturais, o que facilita a percepção humana e, também, a interpretação automática por meio de programas computacionais.
</p>


  Existem várias etapas que são aplicadas a uma imagem para se ter um processamento
completo. Dentre elas, destaca-se a segmentação, que realiza a extração e identificação de
áreas de interesse contidas na imagem como, por exemplo, detecção de descontinuidades
(bordas) ou similaridades (regiões) na imagem processada.
A tarefa de detecção de bordas consiste em determinar o limite, ou fronteira, entre duas regiões
com propriedades e características distintas das intensidades dos pixels da imagem.
Considerando que a imagem consiste em um array M por N, no qual podem-se definir as
direções x e y, a detecção de bordas poderá ser obtida através de uma operação de
convolução entre uma máscara (que configura-se como um operador) que é aplicado sobre um
pixel de interesse da imagem e também em seus pixels vizinhos. Há diversos operadores para realizar essa tarefa. Um exemplo são os operadores de Prewitt, dados pelas matrizes a seguir: 

<div align="center">
  <img src="https://github.com/Minnael/TRATAMENTO-DE-IMAGENS/assets/31865359/1597b857-e6b0-4b62-8e75-659875551803" alt="Descrição da Imagem">
</div>

<div align="center" width=30%>
  <img src="https://github.com/Minnael/TRATAMENTO-DE-IMAGENS/assets/31865359/d843ddd1-62b5-4bb9-be62-479874cf45fa" alt="Descrição da Imagem" style="width:322px; height:99px;" >
</div>


onde Gx[][] e Gy[][] são as máscaras para detecção de bordas nas direções x e y da
imagem digital. A imagem final segmentada é dada pela junção das imagens das duas bordas
obtidas.
Por exemplo, a figura a seguir mostra como é a aplicação do operador de Prewitt na direção x
para detectar a existência de borda no pixel (i, j) da imagem I. No caso, considera-se que a
imagem I é em nível de cinza. Ou seja, seus pixels têm valores que variam no intervalo [0, 255],
onde 0 é atribuído ao nível preto e 255 ao nível branco (os valores inteiros intermediários
correspondem aos diferentes níveis de cinza).

<div align="center">
  <img src="https://github.com/Minnael/TRATAMENTO-DE-IMAGENS/assets/31865359/0446f64b-79f8-4565-aa07-802ad5439aaf" alt="Descrição da Imagem" style="width:65%; height:65%;">
</div>

## <div align="center" styles="font-size:50px;" >Problema 01</div>
Elabore um programa, escrito em C ou C++, em um sistema operacional com suporte a POSIX
(Linux, por exemplo), de tal modo que possam ser usados os compiladores GCC ou G++, para:
1. Criar um processo pai que possa fazer a abertura de uma imagem em nível de cinza
(que será disponibilizada e usada para detecção de bordas) e que crie as estruturas de
dados necessárias para representar essa imagem (como uma matriz I, por exemplo);

3. O processo pai deve executar a função fork() para criar um processo filho. Este novo
processo deve usar a matriz I para gerar as informações das bordas, na direção x, da
imagem de entrada. Estas informações da borda devem ficar em uma matriz Rx e,
posteriormente, disponibilizadas para o processo pai (a utilização de arquivo é uma
possibilidade de solução para este problema). Após executar fork(), o processo pai deve
aguardar a execução do processo filho através da função wait(). Ele retorna à execução
quando o filho for finalizado.

4. O processo pai deve executar uma nova chamada da função fork(), gerando um novo
processo filho. Este novo processo deve usar a matriz I para gerar as informações da
borda da imagem na direção y, salvando os resultados em uma matriz Ry e
disponibilizando-a para o email processo pai (de forma similar ao aplicado com a matriz
Rx). Do mesmo modo, o pai deve executar a chamada wait(), fazendo com que ele fique
em estado de espera até que este novo filho finalize sua tarefa.

5. Por fim, após a execução dos filhos, o processo pai utiliza as informações das matrizes
Rx e Ry para gerar a matriz com as informações das bordas (matriz R). Esse resultado
deve ser salvo como uma imagem.

<div align="center">
  <img src="https://github.com/Minnael/TRATAMENTO-DE-IMAGENS/assets/31865359/def19e47-4485-497b-9775-bd18a8b92ca4" style="width:65%; height:65%;">
</div>



