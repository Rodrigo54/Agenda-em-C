#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#include <conio.h>
#include <ctype.h>      //contém declarações para manipulação de caracteres.
#include <locale.h>     //para o programa aceitar acentuação
#include <wchar.h>  //Biblioteca para conjunto UTF8 de caracteres
#include <io.h>     //Biblioteca para conjunto UTF8 de caracteres
#include <fcntl.h>  //Biblioteca para conjunto UTF8 de caracteres
#define UTF_8  0x20000

typedef struct Agenda{
        wchar_t nome[128];
        wchar_t fone[128];
        wchar_t email[128];
}contato;

/*============  Variaveis Globais  =============*/
static int qtd = 0;     // qtd é uma variavel do tipo estatica que conta a quantidade de contatos incritos
FILE *arq;              // declarar a variável(*arq) como ponteiro do arquivo(FILE)

/*============  Prototipos  ===============*/
void Incluir(void);    // função para Incluir dados
void Listar(void);     // função para Mostrar os contatos ja incluidos
//void Organizar(void);  // função para Colocar em ordem os contatos da agenda
//void Pesquisar(void);  // função para Pesquisar contatos
char AddMais();        // função para Adicionar mais contatos na agenda
void Formata(void);    // função para Apaga todos os contatos na agenda
void menu(void);
void salvar(void);
void titulo(char output);
FILE* abrirArquivo(char *caminho, char modo);
int main(void);



#endif // AGENDA_H_INCLUDED
