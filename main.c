#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>

#define CIMA 72
#define BAIXO 80
#define ESQ 75
#define DIR 77

#define ESC 27
void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x-1,y-1
    });
}
int main()
{
    int linha = 1;
    int coluna = 1;
    int ch;
    int incrementoLinha = 0;
    int incrementoColuna = 0;
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

        if (linha >= 25)
        {
            linha = 0;
        }
        else if (linha <= 0)
        {
            linha = 25;
        }

        if (coluna >= 80)
        {
            coluna = 0;
        }
        else if (coluna <= 0)
        {
            coluna = 80;
        }

        Sleep(100); // Faz o jogo não ficar rápido.
        gotoxy(coluna+=incrementoColuna, linha+=incrementoLinha);
        printf("*");
    }
    return 0;
}
