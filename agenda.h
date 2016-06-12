#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
   //define something for Windows
   #include <conio.h>
#else
  //define it for a Unix machine
  #include <curses.h>
#endif
#include <wchar.h>  //Biblioteca para conjunto UTF8 de caracteres
#include <io.h>     //Biblioteca para conjunto UTF8 de caracteres
#include <fcntl.h>  //Biblioteca para conjunto UTF8 de caracteres
#define UTF_8  0x20000

/*============  Variaveis Globais  =============*/
typedef struct Agenda{
        wchar_t nome[128];
        wchar_t fone[128];
        wchar_t email[128];
}contato;

FILE *arq;  // declarar a variável(*arq) como ponteiro do arquivo(FILE)

/*============  Prototipos  ===============*/
void Incluir(void);    // função para Incluir dados
void Listar(void);     // função para Mostrar os contatos ja incluidos
void Formata(void);    // função para Apaga todos os contatos na agenda
void menu(void);
void titulo(char output);
FILE* abrirArquivo(char *caminho, char modo);
int main(void);

#endif // AGENDA_H_INCLUDED
