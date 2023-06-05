#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    // configurações e variáveis
    setlocale(LC_ALL, "Portuguese_Brazil");
    char *q[12];
    char *questao[12];
    int r[12];
    int resp[12];
    int i = 0, x, j;
    int jogador = 1;
    int resposta;
    int ptsa = 0, ptsb = 0, pts;
    char p1[20], p2[20];

    // Declarar varáveis como não usadas
    for (i = 0; i < 12; i++)
    {
        questao[i] = NULL;
        resp[i] = 0;
    }

    // questões
    q[0] = "Quais são as formas de representação de um algoritmo?\n 1) Descritivo narrativo, fluxograma, pseudocódigo\n 2) Narrativo, fluxograma, código\n 3) Receita de bolo, fluxograma, pseudocódigo\n 4) Descrição narrativa, fluxograma, pseudocódigo\n 5) Narração, gráfico, portugol\n";
    q[1] = "Qual a estrutura correta de um for?\n 1) for(x=0;x<4;x++){}\n 2) for(x=0,x<=4,x++){}\n 3) for x=0;x<4;x++{}\n 4) for(0=0;0<4;0++)[]\n 5) for(x=0;x=>4;x++){}\n";
    q[2] = "Qual o conjunto correto de operadores relacionais?\n 1) +, -, >, =>, =\n 2) =>, >, =, !=, <\n 3) >=, >, ==, !=, <\n 4) +, -, *, /, =\n 5) ==, &&, ||, !=, =\n";
    q[3] = "Qual a estrutura correta de um include?\n 1) #include <stdlib.h>\n 2) #include stdlib.h\n 3) #include <sttdlib.h>\n 4) include <stdlib.h>\n 5) #import <stdlib>\n";
    q[4] = "Qual a maneira correta de declarar um vetor em C?\n 1) int vetor [] = new int[10];\n 2) vetor[10];\n 3) vetor[10][10];\n 4) int vetor[10]\n 5) int vetor[10];\n";
    q[5] = "Quais os tipos de variáveis em C?\n 1) char, int, float, double, void\n 2) chat, inteiro, flutuante, dobro, vazio\n 3) byte, long, short, int, char\n 4) bigint, integer, date, varchar, longint\n 5) smallint, String, real, nulo, char\n";
    q[6] = "Qual das alternativas representa uma declaração correta de matriz 4x3?\n 1) int matriz[3][4];\n 2) matriz[4][3];\n 3) int matriz[4][3];\n 4) int matriz(4)(3);\n 5) int matriz[4][3]\n";
    q[7] = "Em qual alternativa o while está declarado corretamente?\n 1) while(x=>0);{}\n 2) while(x>5){x++}\n 3) while(x<5){x++}\n 4) while(x==1);\n 5) while(x>4 && <6){}\n";
    q[8] = "Qual a comparação feita pelo operador lógico &&?\n 1) or\n 2) and\n 3) or\n 4) not\n 5) diferente\n";
    q[9] = "Quais as coordenadas da última posição de uma matriz 9x9?\n 1) [8][8]\n 2) [9][9]\n 3) [10][10]\n 4) [81][81]\n 5) [81][18]\n";
    q[10] = "Qual o valor da posição [2] do vetor[6]={10,20,30,40,50,60}?\n 1) 30\n 2) 40\n 3) 20\n 4) 60\n 5) 10\n";
    q[11] = "Qual o valor da posição [1][1] de uma matriz[2][2]={{5,4},{2,1}}?\n 1) 1\n 2) 2\n 3) 3\n 4) 4\n 5) 5\n";
    
    
    // respostas
    r[0] = 4;
    r[1] = 1;
    r[2] = 3;
    r[3] = 1;
    r[4] = 5;
    r[5] = 1;
    r[6] = 3;
    r[7] = 3;
    r[8] = 2;
    r[9] = 1;
    r[10] = 1;
    r[11] = 1;

    // embaralhamento das questões
    srand(time(NULL));
    i = 0;
    while (i < 12)
    {
        x = rand() % 12;

        if (questao[x] == NULL && resp[x] == 0)
        {
            questao[x] = q[i];
            resp[x] = r[i];
            i++;
        }
    }

    // Receber nome dos jogadores
    printf("\nInsira o nome do jogador 1:\n");
    scanf("%s", p1);
    printf("\nInsira o nome do jogador 2:\n");
    scanf("%s", p2);


    // Perguntas do quiz funcionando
    for (j = 0; j < 12; j++)
    {
        for (i = 0; i < 3; i++)
        {
            printf("\n|Vez de %s|\n", jogador == 1 ? p1 : p2);
            printf("======================\n");
            printf("%s", questao[j]);
            printf("\nSua resposta: ");
            scanf("%d", &resposta);
            printf("______________________\n");

            //Alternar valor dos pontos baseado no número da tentativa
            switch (i)
            {
            case 0:
                pts = 10;
                break;
            case 1:
                pts = 7;
                break;
            case 2:
                pts = 5;
                break;
            }
            
            if (resposta == resp[j])
            {
                printf("\nResposta correta! Jogador %s recebe %d pontos.\n", jogador == 1 ? p1 : p2, pts);
                if (jogador == 1)
                {
                    ptsa += pts;
                }
                else 
                {
                    ptsb += pts;
                }
                break;
            }
            //Alternar jogador
            else
            {
                printf("\nRespota incorreta!\n");
                jogador = jogador == 1 ? 2 : 1;
            }
        }
    }

    // Pontos e vencedor
    printf("\nPontos de %s: %d\n", p1, ptsa);
    printf("\nPontos de %s: %d\n", p2, ptsb);
    if (ptsa > ptsb)
    {
        printf("\nQuem venceu foi %s\n", p1);
    }
    else if(ptsb>ptsa)
    {
        printf("\nQuem venceu foi %s\n", p2);
    }
    else
    {
        printf("\nHouve um empate!\n");
    }


    return 0;
}
