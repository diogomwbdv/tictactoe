#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include <unistd.h>

//VARIAVEIS GLOBAIS
char tabuleiro[3][3];
const char JOGADOR1 = 'X';
const char JOGADOR2 = '0';
const char COMPUTADOR = 'S';
char menu;
char nomeJogador[50];
int galosupremo=0;
char continuar;

//FUNCOES
void inicio();
void inicioMenu();
void iniciarTabuleiro();
void imprimirTabuleiro();
int verificaEspacosEmBranco();
void turnoJogador1();
void turnoJogador2();
void turnoComputador();
char verificaVencedor();
void imprimirVencedor(char);
void exibirMenu();
void exibirPlaca();




int main ()
{
    setlocale(LC_ALL, "Portuguese");

    int partidas = 0;
    char texto[]= ("\n\n Há muitos, muitos, muitos ovos atrás, numa quinta distante, os galos eram muito mais do que apenas despertadores irritantes.\n\n Eles eram os líderes do galinheiro, com as suas penas coloridas e jeitos divertidos.\n\n Cada galo acreditava ser o melhor cantor, o mais charmoso e claro, o mais inteligente!\n\n A competição para ser o GALO SUPREMO era emocionante, quase tanto, como as batalhas diárias para controlar a população minhocas no galinheiro.\n\n");

    inicio();
    //introducaoTexto(texto);
    exibirPlaca();
    inicioMenu();

    return 0;
}


void inicio()
{

    char jogar;
    do
    {
        printf("\t\t\t\t\tPRESSIONA 'A' PARA ENTRAR NO GALINHEIRO");
        jogar= getch();
        jogar= toupper(jogar);
        system("cls");
    }
    while(jogar != 'A');

    system("cls");

}


void introducaoTexto(char *texto)
{

    int i = 0;
    while (texto[i] != '\0')
    {
        putchar(texto[i]);
        fflush(stdout); // Força a impressão imediata do caractere
        usleep(50000); // Atraso de 50 milissegundos (ajuste conforme desejado)
        i++;
    }

    printf(" Bem-vindo ao galinheiro, como te chamas?\n");
    scanf("%s", &nomeJogador);

    system("cls");


    printf("\n\n%s, para que possas entrar no galinheiro... temos que te tornar num galo.", nomeJogador);
    printf("\nEstás pronto para desafiar os nossos galos pelo titulo de GALO SUPREMO?");


    do
    {
        printf("\n\n\n\t\t\t\t\t\tTecla 'A' para te tornares num galo!");
        continuar=getch();
        continuar= toupper(continuar);
        system("cls");

    }
    while(continuar != 'A');
}
void exibirPlaca()
{
    printf("  ____________________________________________________________\n");
    printf(" /                                                            \\\n");
    printf("|                      BEM-VINDO AO GALINHEIRO!               |\n");
    printf("|                                                             |\n");
    printf("|         (o_o)                         (o_o)                 |\n");
    printf("|          (   )                       (   )                  |\n");
    printf("|           ^ ^                         ^ ^                   |\n");
    printf("|     /¯|_/¯\\                    /¯|_/¯\\                    |\n");
    printf("|    / _|_ | \\                  / _|_ | \\                   |\n");
    printf("|     //   \\\\                    //   \\\\                  |\n");
    printf("|           / \\                         / \\                 |\n");
    printf("|        (o_o)                       (o_o)                    |\n");
    printf("|         (   )                       (   )                   |\n");
    printf("|          ^ ^                         ^ ^                    |\n");
    printf(" \\                                                            /\n");
    printf("  ------------------------------------------------------------\n");

    printf("Temos disponíveis 3 desafios para ti:\n\nPodes defrontar o Sargento Penas de Aço em modo fácil ou díficil, onde ele jogará primeiro. Podes também jogar contra um amigo/a. Se ganhares 3 partidas do jogo do galo recebes o maior título do nosso galinheiro, o GALO SUPREMO!\n\nEstás pronto/a para jogar?");

    do
    {
        printf("\n\n\n\t\t\t\t\t\tTecla 'A' para jogar");
        continuar=getch();
        continuar= toupper(continuar);
        system("cls");

    }
    while(continuar != 'A');
}

// Função para exibir o menu dentro de um retângulo
void exibirMenu()
{
    system("cls");
    printf("  ____________________________________________________________\n");
    printf(" |                                                            |\n");
    printf(" |               ----JOGO DO GALO----                         |\n");
    printf(" |                                                            |\n");
    printf(" |               1- %s VS Sargento Penas de Aço                 |\n", nomeJogador);
    printf(" |                                                            |\n");
    printf(" |               2- %s VS Sargento Penas da Aço (Modo Díficil)  |\n", nomeJogador);
    printf(" |                                                            |\n");
    printf(" |               3- %s VS Jogador2                              |\n", nomeJogador);
    printf(" |                                                            |\n");
    printf(" |               4- Caça à minhoca                            |\n");
    printf(" |                                                            |\n");
    printf(" |               5- Sair do galinheiro                        |\n");
    printf(" |                                                            |\n");
    printf("  ------------------------------------------------------------\n");
}


void inicioMenu()
{
    char vencedor = ' ';
    char novoJogo;
    char menu;

    do
    {
        exibirMenu();
        menu = getch();
        system("cls");

        switch (menu)
        {
        case '1':
            do
            {
                vencedor= ' ';
                novoJogo= ' ';
                iniciarTabuleiro();

                while(vencedor == ' ' && verificaEspacosEmBranco()!= 0)
                {
                    system("cls");
                    imprimirTabuleiro();

                    //JOGADOR1
                    turnoJogador1();
                    vencedor = verificaVencedor();//caracter = funcao verifica
                    if(vencedor != ' ' || verificaEspacosEmBranco() == 0)
                    {
                        break;//se houver vencedor vamos querer sair do loop
                    }

                    //COMPUTADOR
                    turnoComputador();
                    vencedor = verificaVencedor();//caracter = funcao verifica
                    if(vencedor != ' ' || verificaEspacosEmBranco() == 0)
                    {
                        break;//se houver vencedor vamos querer sair do loop
                    }
                }

                imprimirTabuleiro();
                imprimirVencedor(vencedor);

                if(galosupremo < 3)
                {
                    printf("\nNova partida?S-SIM VOLTAR AO MENU: M: ");
                    novoJogo= getch();
                    novoJogo= toupper(novoJogo);
                    system("cls");

                }
                else
                {
                    fCreditos();
                }

            }
            while(novoJogo == 'S');
            break;


        case '2':
            do
            {
                vencedor = ' ';
                novoJogo = ' ';
                iniciarTabuleiro();

                while (vencedor == ' ' && verificaEspacosEmBranco() != 0)
                {
                    system("cls");

                    // COMPUTADOR
                    turnoComputador();
                    vencedor = verificaVencedor(); // caracter = funcao verifica
                    if (vencedor != ' ' || verificaEspacosEmBranco() == 0)
                    {
                        break; // se houver vencedor vamos querer sair do loop
                    }

                    // JOGADOR1
                    turnoJogador1();
                    vencedor = verificaVencedor(); // caracter = funcao verifica
                    if (vencedor != ' ' || verificaEspacosEmBranco() == 0)
                    {
                        break; // se houver vencedor vamos querer sair do loop
                    }
                }

                imprimirTabuleiro();
                imprimirVencedor(vencedor);

                if(galosupremo < 3)
                {
                    printf("\nNova partida?S-SIM ou QUALQUER TECLA- MENU");
                    novoJogo= getch();
                    novoJogo= toupper(novoJogo);
                    system("cls");

                }
                else
                {
                    fCreditos();
                }

            }
            while(novoJogo == 'S');
            break;


        case '3':
            do
            {
                vencedor = ' ';
                novoJogo = ' ';
                iniciarTabuleiro();

                while (vencedor == ' ' && verificaEspacosEmBranco() != 0)
                {
                    system("cls");
                    imprimirTabuleiro();

                    // JOGADOR1
                    turnoJogador1();
                    vencedor = verificaVencedor();
                    if (vencedor != ' ' || verificaEspacosEmBranco() == 0)
                    {
                        break;
                    }

                    system("cls");
                    imprimirTabuleiro();

                    // JOGADOR2
                    turnoJogador2();
                    vencedor = verificaVencedor();
                    if (vencedor != ' ' || verificaEspacosEmBranco() == 0)
                    {
                        break;
                    }
                }

                imprimirTabuleiro();
                imprimirVencedor(vencedor);

                if(galosupremo < 3)
                {
                    printf("\nNova partida?S-SIM ou QUALQUER TECLA- MENU");
                    novoJogo= getch();
                    novoJogo= toupper(novoJogo);
                    system("cls");

                }
                else
                {
                    fCreditos();
                }

            }
            while (novoJogo == 'S');
            break;

        case '4':

            printf("\n\n\n\n\t\t\t\t\tDesculpa %s, o Sargento Penas de Aço caçou todas as minhocas das redondezas.\n\n\n", nomeJogador);

            do
            {
                printf("\n\n\n\t\t\t\t\t\tTecla 'A' para voltar ao menu");
                continuar=getch();
                continuar= toupper(continuar);
                system("cls");
            }
            while(continuar != 'A');

            break;

        case '5':

            printf("\n\n\n\n\t\t\t\tTens sempre um lugar no nosso galinheiro %s, até breve\n\n\n\n", nomeJogador);
            break;

        default :
            do
            {
                printf("\n\n\n\t\t\t\t\t\tTecla 'A' para voltar ao menu");
                continuar=getch();
                continuar= toupper(continuar);
                system("cls");
            }
            while(continuar != 'A');
        }
    }
    while (menu != '5');
}


void iniciarTabuleiro()
{
//construção da matriz

    for(int i=0; i < 3; i++)
    {
        for(int j=0; j <3; j++)
        {
            tabuleiro[i][j]= ' '; //todos os elementos iniciam com um espaço em branco
        }
    }
}
void imprimirTabuleiro()
{
//ambiente gráfico do tabuleiro

    printf("\n");
    printf("\t\t   | 1 | 2 | 3 \n");
    printf("\t\t---|---|---|---\n");
    printf("\t\t 1 | %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("\t\t---|---|---|---\n");
    printf("\t\t 2 | %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("\t\t---|---|---|---\n");
    printf("\t\t 3 | %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

int verificaEspacosEmBranco()
{
    int posicoesLivres = 9; //no inicio do jogo existem 9 posicoes livres

    for(int i=0; i < 3; i++)
    {
        for(int j=0; j < 3; j++)
        {
            if(tabuleiro[i][j] != ' ')
            {
                posicoesLivres--;
            }
        }
    }
    return posicoesLivres;//quando o valor de posicoesLivres for 0 quer dizer que não existem mais jogadas possiveis
}

void turnoJogador1()
{
    int x, y;
    int scanfResult;

    do
    {
        printf("\nInsira o nº da linha #(1-3): ");
        scanfResult = scanf("%d", &x);
        if (scanfResult != 1)
        {

            printf("Entrada inválida! Por favor, insira um número inteiro.\n");
            sleep(2);
            system("cls");
            imprimirTabuleiro();
            // Limpar o buffer de entrada
            while (getchar() != '\n');
            continue;
        }
        x--; //para o jogador utilizar 1-3, no final decremento uma unidade para ter indice #(0-2)

        printf("\nInsira o nº da coluna #(1-3): ");
        scanfResult = scanf("%d", &y);
        if (scanfResult != 1)
        {
            printf("Entrada inválida! Por favor, insira um número inteiro.\n");
            sleep(2);
            system("cls");
            imprimirTabuleiro();
            // Limpar o buffer de entrada
            while (getchar() != '\n');
            continue;
        }
        y--; //para o jogador utilizar 1-3, no final decremento uma unidade para ter indice #(0-2)


        if (tabuleiro[x][y] != ' ')
        {
            printf("Jogada inválida!\n"); //posicao ocupada
            sleep(2);
            system("cls");
            imprimirTabuleiro();
        }
        else
        {
            tabuleiro[x][y] = JOGADOR1; // se não estiver ocupada aquela posicao ficará ocupada com o caracter do JOGADOR1
            break;
        }
    }
    while (tabuleiro[x][y] != ' '); // repetir ciclo enquanto o JOGADOR1 não inserir uma posicao desocupada
}

void turnoJogador2()
{
    int x, y;
    int scanfResult;

    do
    {
        printf("\nInsira o nº da linha #(1-3): ");
        scanfResult = scanf("%d", &x);
        if (scanfResult != 1)
        {

            printf("Entrada inválida! Por favor, insira um número inteiro.\n");
            // Limpar o buffer de entrada
             sleep(2);
            system("cls");
            imprimirTabuleiro();
            while (getchar() != '\n');
            continue;
        }
        x--; //para o jogador utilizar 1-3, no final decremento uma unidade para ter indice #(0-2)

        printf("\nInsira o nº da coluna #(1-3): ");
        scanfResult = scanf("%d", &y);
        if (scanfResult != 1)
        {
            printf("Entrada inválida! Por favor, insira um número inteiro.\n");
             sleep(2);
            system("cls");
            imprimirTabuleiro();
            // Limpar o buffer de entrada
            while (getchar() != '\n');
            continue;
        }
        y--; //para o jogador utilizar 1-3, no final decremento uma unidade para ter indice #(0-2)


        if (tabuleiro[x][y] != ' ')
        {
            printf("Jogada inválida!\n"); //posicao ocupada
             sleep(2);
            system("cls");
            imprimirTabuleiro();
        }
        else
        {
            tabuleiro[x][y] = JOGADOR2; // se não estiver ocupada aquela posicao ficará ocupada com o caracter do JOGADOR1
            break;
        }
    }
    while (tabuleiro[x][y] != ' '); // repetir ciclo enquanto o JOGADOR1 não inserir uma posicao desocupada
}

void turnoComputador()
{
    srand(time(0));
    int x, y;

    if (verificaEspacosEmBranco() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (tabuleiro[x][y] != ' ');

        tabuleiro[x][y] = COMPUTADOR;
        imprimirTabuleiro(); // Adicione essa linha para imprimir o tabuleiro após a jogada do computador
    }
    else
    {
        imprimirVencedor(' ');
    }
}

char verificaVencedor()
{
    //Existem 8 possibilidades: 3xlinhas; 3xcolunas; 2x diagonais
    //LINHAS
    for(int i=0; i < 3 ; i++)
    {
        if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2])
        {
            return tabuleiro[i][0];//devolve caracter que estiver nestas posicoes, tabuleiro[][] é char
        }
    }
    //COLUNAS
    for(int i=0; i < 3 ; i++)
    {
        if(tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i])
        {
            return tabuleiro[0][i];//devolve caracter que estiver nestas posicoes, tabuleiro[][] é char
        }
    }
    //DIAGONAIS
    if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2])
    {
        return tabuleiro[0][0];//devolve caracter que estiver nestas posicoes, tabuleiro[][] é char
    }
    else if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0])
    {
        return tabuleiro[0][2];
    }

    return ' ';// se depois de verificadas as condicoes nao devolver um caracter então ainda não existe vencedor
}

void imprimirVencedor(char vencedor)
{

    if(vencedor == JOGADOR1)
    {
        galosupremo= galosupremo +1;
        printf("\n\nPARABÉNS GALO %s, GANHOU! Está %d a vitória(s) de se tornar o GALO SUPREMO!\n", nomeJogador, 3 - galosupremo);

        if(galosupremo == 3)
        {
            system("cls");
        }
    }
    else if(vencedor == JOGADOR2)
    {
        printf("Parabéns JOGADOR2, GANHOU!");

    }
    else if(vencedor == COMPUTADOR)
    {
        printf("PERDEU, o titulo de GALO SUPREMO foi adiado!!");
    }
    else
    {
        printf("EMPATOU, o titulo de GALO SUPREMO foi adiado!!!");
    }
}

void fCreditos()
{

    char creditos[1000] = "\n\n\n\n\t\t\t\t\t\t\t------- CREDITOS -------\n\n\n"
                          "\t\t\t\tDesenvolvimento:\n"
                          "\t\t\t\t- Diogo Leitão - Aluno do curso de Programador Informático no CENCAL\n"
                          "\n"
                          "\t\t\t\tAgradecimentos Especiais:\n"
                          "\t\t\t\t- Bob o Galo - Pela construção do Galinheiro.\n"
                          "\t\t\t\t- Sr. Espantalho - Por afastar diariamente os predadores.\n"
                          "\t\t\t\t- Luigi - Pela tutoria aos nossos galos mais novos.\n"
                          "\t\t\t\t- José - Pelo torneio de futsal organizado no nosso Galinheiro.\n"
                          "\t\t\t\t- Felipe Moraes - Pelas aulas de Surf com os nossos galos surfistas.\n"
                          "\n"
                          "\t\t\t\tMenções Honrosas:\n"
                          "\t\t\t\t- Sargento Penas de Aço- Por ter sido o Galo Supremo durante 3 anos consecutivos.\n"
                          "\t\t\t\t- Professor Plumagem- Por criar a fórmula secreta de ração especial, a preferida de todo o Galinheiro!!\n"
                          "\t\t\t\t- CERCINA- Pelo transporte diário do Bruno.\n"
                          "\t\t\t\t- Prof.Dora- Pela paciência e orientação no desenvolvimento do jogo.\n"
                          "\n"
                          "\t\t\t\tEspecial Agradecimento a Todos os Galos e Galinhas do Galinheiro!\n"
                          "\t\t\t\tCOCORÓCOCOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n"
                          "\n\n\t\t\t\tVai voltar ao menu automaticamente\n";

    // Tamanho da string de créditos
    int len = strlen(creditos);

    // Exibe os créditos
    for (int i = 0; i < len; i++)
    {
        putchar(creditos[i]);
        usleep(30000); // Pausa por 30 milissegundos (0.03 segundos)
    }
    sleep(6);
    system("cls");
    galosupremo= 0;

}





