#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define CIMA 72
#define BAIXO 80
#define ESQ 75
#define DIR 77

#define ESC 27
void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
int main()
{

      int linha = 1;
      int coluna = 1;
      int ch;
      gotoxy(1,1);
      printf("*");
	  for(;;) // Loop infinito
      {
          if (kbhit())
          {
              ch = getch(); // Pega a tecla pressionada.
              if (ch == ESC)
              {
                  break;
              }
              if (ch == 224)  // 224 é uma tecla estendida.
              {
                  ch = getch();
                  switch(ch)
                  {
                      case CIMA:
                               linha--;
                               break;
                      case BAIXO:
                               linha++;
                               break;
                      case ESQ:
                               coluna--;
                               break;
                      case DIR:
                               coluna++;
                               break;
                  }
                  gotoxy(coluna,linha);
                  printf("*");
              }
          }
      }
      return 0;
}
