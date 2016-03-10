#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main()
{
    setlocale(LC_ALL, "");
    _setmode(_fileno(stdout), UTF_8); //Define no console o conjunto UTF8 de caracteres
    system("title AGENDA");
    system("color 1f");// Define a o plano de Fundo Azul Marinho e o texto em Branco
    int var;
    titulo('t');
    wprintf(L"\tVeja todas as funções disponiveis no menu.\n");
    wprintf(L"\tUse os numeros para selecionar a opção desejada.\n");
    wprintf(L"\tPressione qualquer tecla para continuar ou\n\tEspaço para sair do programa agora.\n\t");
    var = getch();
    if(var == 32) exit(0);// 32 corresponde a espaço no teclado conforme Tabela ASCII
    menu();// chamando a funçao menu para a main
    return 0;
}
