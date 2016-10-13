#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>

#define CIMA 72
#define BAIXO 80
#define ESQ 75
#define DIR 77
#define ESC 27

signed char linha = 1;
signed char coluna = 1;
unsigned char guardaPosicao[80][25] = {{0}};

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x-1,y-1
    });
}

void antiEscape() // Esse método faz a cobra não "escapar" da tela.
{
    if (linha == 25)
    {
        linha = 0;
    }
    else if (linha == 0)
    {
        linha = 25;
    }

    if (coluna == 80)
    {
        coluna = 0;
    }
    else if (coluna == 0)
    {
        coluna = 80;
    }
}

void gameOver()
{
    for (coluna = 0; coluna <= 80; coluna++)
    {
        for (linha = 0; linha <= 25; linha++)
        {
            gotoxy(coluna, linha);
            printf(" ");
        }
    }

    // Pisca-pisca "game-over".
    for (;;)
    {
        gotoxy(37, 12);
        printf("GAME OVER! \n\n");
        Sleep(400);
        gotoxy(37, 12);
        printf("               ");
        Sleep(200);

    }
}

int main()
{
    unsigned char ch;
    signed char incrementoLinha = 0;
    signed char incrementoColuna = 1;
    gotoxy(1,1);
    printf("*");

    for(;;) // Loop infinito.
    {
        if (kbhit())
        {
            ch = getch(); // Pega a tecla pressionada.
            if (ch == ESC)
            {
                break;
            }
            if (ch == 224) // 224 é uma tecla estendida.
            {
                ch = getch();
                incrementoColuna = 0;
                incrementoLinha = 0;

                switch(ch)
                {
                case CIMA:
                    incrementoLinha = -1;
                    break;
                case BAIXO:
                    incrementoLinha = 1;
                    break;
                case ESQ:
                    incrementoColuna = -1;
                    break;
                case DIR:
                    incrementoColuna = 1;
                    break;
                }
            }
        }

        // Primeiro guarda a posição e depois altera a coluna e linha.
        guardaPosicao[coluna][linha] = 1;
        gotoxy(coluna += incrementoColuna, linha += incrementoLinha);

        antiEscape();

        if (guardaPosicao[coluna][linha] == 1)
        {
            gameOver();
        }
        Sleep(100); // Faz o jogo não ficar rápido.
        printf("*");
    }
    return 0;
}




