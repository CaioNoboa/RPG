# Jogo RPG desenvolvido para a disciplina de Estrutura de Dados do Centro Universitário Barão de Mauá

  - Caio Salvador Noboa - 2201926

  ## Introdução
    O presente Algoritmo contempla a simulação de um jogo RPG.

    O jogo segue alguns padrões:
      - Ao iniciar o jogo, o usuário deverá escolher entre nível de dificuldade fácil ou difícil, informar seu nome e o de seu herói;
      - Serão 15 fases no total, sendo 8 iniciais cujo objetivo é acumular elementos. Outras 3 intermediárias e 3 difíceis, onde há chance de encontrar inimigos a serem combatidos. A última fase é composta pelo "chefão", o inimigo mais forte;
      - Ao iniciar uma fase, há a possibilidade de encontrar elementos, armas ou poções. Tais elementos podem ser guardados na mochila ou no cinto e possuem uso único;
      - Na mochila, o herói só pode colocar um objeto sobre o outro e, em todo momento, só pode acessar o elemento que está sobre os demais. Para poder atingir os elementos mais ao fundo, deverá retirar (e perder) os elementos anteriores. Não há limite de espaço;
      - No cinto, o herói pode colocar elementos em qualquer posição, assim como acessá-los à vontade. Há limite de cinco itens ou que somatório do peso dos itens não ultrapasse 100;
      - Para atacar um inimigo, uma arma deve ser escolhida da mochila ou do cinto;
      - Para se curar, uma poção curadora deve ser escolhida da mochila ou do cinto;
      - Ao encontrar um inimigo, o herói começa com uma ação. Caso o inimigo continue vivo, irá atacar o herói;
      - Ao finalizar o jogo, ganhando ou perdendo, será adicioando um registro em `high_scores.txt`.

  ## Inicialização
    Em sistema operacional Windows, no prompt de comando, na pasta que contém os arquivos rode:
      `g++ driver.cpp Backpack.cpp Belt.cpp Character.cpp Element.cpp Game.cpp Enemy.cpp -o jogoRPG.exe`
      `./jogoRPG.exe`
