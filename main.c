#include "agenda.h"

int main()
{
    _setmode(_fileno(stdout), UTF_8); //Define no console o conjunto UTF8 de caracteres
    system("title AGENDA");
    system("color 0A"); // Define a o plano de Fundo Azul Marinho e o texto em Branco
    int var;
    titulo('t');
    wprintf(L"\n\t┌─────────────────────────────────────────────────────┐");
    wprintf(L"\n\t│                                                     │");
    wprintf(L"\n\t│  Veja todas as funções disponiveis no menu.         │");
    wprintf(L"\n\t│  Use os numeros para selecionar a opção desejada.   │");
    wprintf(L"\n\t│  Pressione qualquer tecla para continuar ou         │");
    wprintf(L"\n\t│  Pressione Espaço para sair do programa agora.      │");
    wprintf(L"\n\t│                                                     │");
    wprintf(L"\n\t└─────────────────────────────────────────────────────┘\n\t");
    var = getch();
    if (var == 32)
        exit(0); // 32 corresponde a espaço no teclado conforme Tabela ASCII
    menu();      // chamando a funçao menu para a main
    return 0;
}
