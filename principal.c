#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>//cont�m declara��es para manipula��o de caracteres.
#include <locale.h> //para o programa aceitar acentua��o
#define TAM 100 //TAM recebe o valor de 100 inteiros

typedef struct Agenda{
        char nome[50];
        char fone[17];
        char email[80];
}contatos;

/*============  Prototipos  ===============*/
void Incluir(void);    // fun��o para Incluir dados
void Listar(void);     // fun��o para Mostrar os contatos ja incluidos
void Organizar(void);  // fun��o para Colocar em ordem os contatos da agenda
void Pesquisar(void);  // fun��o para Pesquisar contatos
char AddMais();        // fun��o para Adicionar mais contatos na agenda
void Formata(void);    // fun��o para Apaga todos os contatos na agenda

/*============  Variaveis Globais  =============*/
static int qtd = 0;     // qtd � uma variavel do tipo estatica que conta a quantidade de contatos incritos
contatos Tab[TAM];      // agora contatos recebe o valor de Tab[100] que � o total de contatos
FILE *arq;              // declarar a vari�vel(*arq) como ponteiro do arquivo(FILE)

/*========  Incluir Contatos na Agenda  ===========*/
void Incluir(void){
     int cont = 0;   //cont sera a variavel contadora
     int retorno;    //retorno seve para definir se fwrite funcionou
     char op = 's';  //seve para definir a op��o na fun��o Validaresp()

     arq = fopen("agenda.txt", "a");// fopen cria arquivo de entrada
     if (arq == NULL){//caso o sistema n�o consiga criar o arquivo
        printf ("Erro!\nO arquivo da lista n�o pode ser aberto!\n");//sera mostrada esta mensagen
        getch();// espera que o usu�rio pressione uma tecla
        exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     while ((cont < TAM) && (op == 's')){
           printf (" Digite o nome: ");
           gets(Tab[cont].nome);
           printf (" Digite o numero: ");
           gets(Tab[cont].fone);
           printf (" Digite o E-mail: ");
           gets(Tab[cont].email);

           // fwrite grava 1 contato na struct Agenda
           retorno = fwrite (&Tab[cont], sizeof(struct Agenda) ,1,arq);
           // fwrite retornara um valor int 1 para sucesso e 0 para fracasso
           if (retorno == 1) {
               printf("\n Gravacao ok! ");
           }
           cont++;//enquanto cont for menor 100 adiciona mais um contato
           op = AddMais();//chama a fun��o que pergunta se deseja inserir novos contatos
           qtd++;//acrecenta 1 contato a mais
     }
     fclose (arq);//fecha o arquivo agenda.txt
}

/*==============  Adicionar mais Contatos  ===============*/
char AddMais() {
   char op;
   do {
      printf("\n Deseja inserir novos dados? [S ou N]? " );
      op = getch();
      printf("\n" );
   } while (op != 's' && op != 'n');
   return op;
}

/*=====================  Apagar tudo  ====================*/
void Formata() {
    /* w+ abre um arquivo para leitura e escrita.
    Se o arquivo n�o existir, o sistema operacional tentar� cri�-lo.
    Se o arquivo existir, todo o seu conte�do ser� substitu�do pelo novo conte�do.*/
    arq = fopen("agenda.txt","w+"); //recria um arquivo limpo
    printf("\n\tLista limpa!\n ");
    fclose(arq);//fecha o arquivo agenda.txt
    getch();// espera que o usu�rio pressione uma tecla
}

/*=============  Organizar em ordem alfabetica  ==========*/
void Organizar(void){//algoritmo de ordena��o do tipo selection sort (ordena��o por sele��o)
     contatos vet;
     int aux,i,j,k,retorno;
     char *str, *str2, *straux;//o asterisco [*] indica que a variavel � uma string
     aux = qtd; // aux recebe a quantidade de contatos inscritos
     // Rotina de ordena��o
     for (i = 0 ; i < aux ; i++){
         str = Tab[i].nome;//a variavel str recebe o primeio contato
         for (j = i+1 ; j < aux ; j++){
             str2 = Tab[j].nome;//a variavel str2 recebe o segundo contato
             //strcmp faz a compara��o entre as strings onde 0 s�o strings iguais
             if ( strcmp ( str, str2 ) > 0 ){
                 vet = Tab[i];
                 Tab[i] = Tab[j];
                 Tab[j] = vet;
             }
         }
     }
     remove("agenda.txt");//Apaga o Arquivo
     arq = fopen("agenda.txt", "w+");//Recria um arquivo limpo
     if (arq == NULL){//caso o sistema n�o consiga criar o arquivo
        printf (" ERRO!\n ");// sera mostrada esta mensagens
        getch();// espera que o usu�rio pressione uma tecla
        exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     for (k = 0 ; k < aux ; k++){
           retorno = fwrite (&Tab[k], sizeof(struct Agenda) ,1,arq);
           if (retorno != 1) { //se fwrite retornar com erro
               printf("\n ERRO! ");//sera mostrada esta mensagen
           }
     }
     fclose(arq);//fecha o arquivo agenda.txt
     printf("\n Lista Ordenada!\n ");
     getch();//espera que o usu�rio pressione uma tecla
}

/*============== Pesquisar contato pelo nome =====================*/
void Pesquisar(void){
     int i=0, retorno=1, cont=0;//
     char nome[50],op;//A variavel nome se refere ao nome a ser pesquisado

     arq = fopen("agenda.txt", "r");//fopen abre o arquivo no modo leitura "r"
     if (arq == NULL){//caso o SO n�o consiga abrir o arquivo
         printf (" Erro!\nO arquivo da lista n�o pode ser aberto! \n");//sera mostrada esta mensagens
         getch();//espera que o usu�rio pressione uma tecla
         exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     printf (" Digite o nome: ");// para procurar contato pelo nome
     gets(nome);
     retorno = fread(&Tab[i], sizeof(struct Agenda), 1, arq);//fread le apenas 1 contato do arquivo
     while (retorno == 1){//o retorno recebe a quantidade de contatos lidos no fread
         if (strcmp(nome, Tab[i].nome) == 0 ){//strcmp compara as strings das variaveis
            printf("\n Nome....: %s",Tab[i].nome);
            printf("\n Fone....: %s",Tab[i].fone);
            printf("\n E-mail..: %s\n ",Tab[i].email);
            cont++;
         }
     i++;
     retorno = fread(&Tab[i], sizeof(struct Agenda), 1, arq);//fread vai ler o proximo contato
     }
     if(cont == 0){//se strcmp n�o encontrar strings iguais
        printf("Nao ha contatos com este nome!\n ");//sera mostrada essa mensagen
     }
     getch();//espera que o usu�rio pressione uma tecla
     fclose(arq);//fecha o arquivo agenda.txt
}

/*================== Lista os contatos cadastrados ======================*/
void Listar(void){
    int i = 0, retorno;

    arq = fopen("agenda.txt", "r");//fopen abre o arquivo no modo leitura "r"
    if (arq == NULL){//caso o SO n�o consiga abrir o arquivo
       printf ("Erro!\nO arquivo da lista n�o pode ser aberto!\n");//sera mostrada esta mensagens
       getch();//espera que o usu�rio pressione uma tecla
       exit(1);//caso esse erro ocorra este comando encerra o programa
    }
    retorno = fread(&Tab[i], sizeof(struct Agenda), 1, arq);//fread le apenas 1 contato do arquivo
    while (retorno == 1){ //o retorno recebe a quantidade de contatos lidos no fread
      printf("\n Nome....: %s",Tab[i].nome);
      printf("\n Fone....: %s",Tab[i].fone);
      printf("\n E-mail..: %s\n",Tab[i].email);
      i++;
      retorno = fread(&Tab[i], sizeof(struct Agenda), 1, arq);//fread vai ler o proximo contato
    }
    printf(" \n\n %d Contatos salvos!\n ", i);
    getch();//espera que o usu�rio pressione uma tecla
    fclose(arq);//fecha o arquivo agenda.txt
}

/*========== Sobre os Autores ================*/
void Sobre(void){
    printf("\n\n\t\tAGENDA EM LINGUAGUEM C\n\n");
    printf("\tTrabalho para obten��o de nota Parcial\n\tNa Disciplina de Algoritmos e Estrutura de Dados\n");
    printf("\tIntegrantes da Equipe:\n\t\tRodrigo Alves\n\t\tAdailton\n\t\tEduardo Ramos\n\t\tRoseane Brito");
    getch();//espera que o usu�rio pressione uma tecla
}

/*=====================   Menu   =======================*/
void menu(void){
    char op;//variavel de op��o
    do{
        system("cls");// limpar tela
        printf("\n\n\t\tAGENDA EM LINGUAGUEM C\n");
        printf("\n 1 = Incluir\n 2 = Listar\n 3 = Organizar por ordem alfabetica\n 4 = Pesquisar por nome\n");
        printf(" 5 = Formatar lista\n 6 = Sobre\n 7 = Voltar\n\n");
        op = getch();
        switch(op){
            case '1':
                Incluir();
                break;
            case '2':
                Listar();
                break;
            case '3':
                Organizar();
                break;
            case '4':
                Pesquisar();
                break;
            case '5':
                Formata();
                break;
            case '6':
                system("cls");
                Sobre();
                break;
            case '7':
                system("cls");
                main();
                break;
            default:
                printf("\a Digite uma op��o valida\n");
                getch();//espera que o usu�rio pressione uma tecla
        }
    }
    while (op);
}

/*=========== Fun��o Principal ================*/
int main (){
    int var;
    system("title AGENDA");
    system("color 9f");
    setlocale(LC_ALL, "Portuguese");//Define no console o idioma Portugues
    printf("\n\n\t\tAGENDA EM LINGUAGUEM C\n\n");
    printf("\tVeja todas as fun��es disponiveis no menu.\n");
    printf("\tUse os numeros para selecionar a op��o desejada.\n");
    printf("\tPressione qualquer tecla para continuar ou\n\tEspa�o para sair do programa agora.\n\t");
    var=getch();
    if(var == 32){ exit(0);}// 32 corresponde a espa�o no teclado conforme Tabela ASCII
menu();// chamando a fun�ao menu para a main
system("pause");
}
