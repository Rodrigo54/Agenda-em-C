/** AGENDA EM LIMGUAGUEM C
 *
 * Agenda feita para obtenção de nota parcial na mateira de 'Algoritmos e Estrutura de Dados'.
 *
 * @autor Rodrigo Alves Mesquita
 * Aluno do 3° periodo do curso de Bacharel em Ciências da Computação na Faculdade Pitágoras
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "agenda.h"

void salvar()
{
  arq = fopen ("agenda.txt", "w+");
  _setmode(_fileno(arq), UTF_8); //Define nos arquivos o conjunto UTF8 de caracteres
  fwprintf(arq, L"\n");
  fwprintf(arq, L"\t  █████╗  ██████╗ ███████╗███╗   ██╗██████╗  █████╗ \n");
  fwprintf(arq, L"\t ██╔══██╗██╔════╝ ██╔════╝████╗  ██║██╔══██╗██╔══██╗\n");
  fwprintf(arq, L"\t ███████║██║  ███╗█████╗  ██╔██╗ ██║██║  ██║███████║\n");
  fwprintf(arq, L"\t ██╔══██║██║   ██║██╔══╝  ██║╚██╗██║██║  ██║██╔══██║\n");
  fwprintf(arq, L"\t ██║  ██║╚██████╔╝███████╗██║ ╚████║██████╔╝██║  ██║\n");
  fwprintf(arq, L"\t ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝\n");

  fclose(arq);
}

/*========  Incluir Contatos na Agenda  ===========*/
void Incluir(void){
     int cont = 0;   //cont sera a variavel contadora
     int retorno;    //retorno seve para definir se fwrite funcionou
     char op = 's';  //seve para definir a opção na função AddMais()

     arq = fopen("agenda.txt", "a");// fopen cria arquivo de entrada
     if (arq == NULL){//caso o sistema não consiga criar o arquivo
        wprintf(L"Erro!\nO arquivo da lista não pode ser aberto!\n");//sera mostrada esta mensagen
        getch();// espera que o usuário pressione uma tecla
        exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     while ((cont < TAM) && (op == 's')){
           wprintf(L" Digite o nome: ");
           gets(max[cont].nome);
           wprintf(L" Digite o numero: ");
           gets(max[cont].fone);
           wprintf(L" Digite o E-mail: ");
           gets(max[cont].email);

           /* fwrite grava 1 contato na struct Agenda
           essa lilha pode ser escrita da seguinte forma:
           retorno = fwrite (&max[cont], sizeof(struct Agenda) ,1,arq);*/
           retorno = fwrite (&max[cont], sizeof(contatos) ,1,arq);
           // fwrite retornara um valor int 1 para sucesso e 0 para fracasso
           if (retorno == 1) {
               wprintf(L"\n Gravacao ok! ");
           }
           cont++;//enquanto cont for menor 100 adiciona mais um contato
           op = AddMais();//chama a função que pergunta se deseja inserir novos contatos
           qtd++;//acrecenta 1 contato a mais
     }
     fclose (arq);//fecha o arquivo agenda.txt
}

/*==============  Adicionar mais Contatos  ===============*/
char AddMais() {
   char op;
   do {
      wprintf(L"\n Deseja inserir novos dados? [S ou N]? " );
      op = getch();
      wprintf(L"\n" );
   } while (op != 's' && op != 'n');
   return op;
}

/*=====================  Apagar tudo  ====================*/
void Formata() {
    /* w+ abre um arquivo para leitura e escrita.
    Se o arquivo não existir, o sistema operacional tentará criá-lo.
    Se o arquivo existir, todo o seu conteúdo será substituído pelo novo conteúdo.*/
    arq = fopen("agenda.txt","w+"); //recria um arquivo limpo
    wprintf(L"\n\tLista limpa!\n ");
    fclose(arq);//fecha o arquivo agenda.txt
    getch();// espera que o usuário pressione uma tecla
}

/*=============  Organizar em ordem alfabetica  ==========*/
void Organizar(void){//algoritmo de ordenação do tipo selection sort (ordenação por seleção)
     contatos vet; //vet é um variavel do tipo struct Agenda
     int aux,i,j,k,retorno;
     char *str, *str2, *straux;//o asterisco [*] indica que a variavel é uma string
     aux = qtd; // aux recebe a quantidade de contatos inscritos
     // Rotina de ordenação
     for (i = 0 ; i < aux ; i++){
         str = max[i].nome;//a variavel str recebe o primeio contato
         for (j = i+1 ; j < aux ; j++){
             str2 = max[j].nome;//a variavel str2 recebe o segundo contato
             //strcmp faz a comparação entre as strings onde 0 são strings iguais
             if ( strcmp ( str, str2 ) > 0 ){
                 vet = max[i];
                 max[i] = max[j];
                 max[j] = vet;
             }
         }
     }
     remove("agenda.txt");//Apaga o Arquivo
     arq = fopen("agenda.txt", "w+");//Recria um arquivo limpo
     if (arq == NULL){//caso o sistema não consiga criar o arquivo
        wprintf(L" ERRO!\n ");// sera mostrada esta mensagens
        getch();// espera que o usuário pressione uma tecla
        exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     for (k = 0 ; k < aux ; k++){
           retorno = fwrite (&max[k], sizeof(contatos) ,1,arq);
           if (retorno != 1) { //se fwrite retornar com erro
               wprintf(L"\n ERRO! ");//sera mostrada esta mensagen
           }
     }
     fclose(arq);//fecha o arquivo agenda.txt
     wprintf(L"\n Lista Ordenada!\n ");
     getch();//espera que o usuário pressione uma tecla
}

/*============== Pesquisar contato pelo nome =====================*/
void Pesquisar(void){
     int i=0, retorno=1, cont=0;//
     char nome[50],op;//A variavel nome se refere ao nome a ser pesquisado

     arq = fopen("agenda.txt", "r");//fopen abre o arquivo no modo leitura "r"
     if (arq == NULL){//caso o SO não consiga abrir o arquivo
         wprintf(L" Erro!\nO arquivo da lista não pode ser aberto! \n");//sera mostrada esta mensagens
         getch();//espera que o usuário pressione uma tecla
         exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     wprintf(L" Digite o nome: ");// para procurar contato pelo nome
     gets(nome);
     retorno = fread(&max[i], sizeof(contatos), 1, arq);//fread le apenas 1 contato do arquivo
     while (retorno == 1){//o retorno recebe a quantidade de contatos lidos no fread
         if (strcmp(nome, max[i].nome) == 0 ){//strcmp compara as strings das variaveis
            wprintf(L"\n Nome....: %s",max[i].nome);
            wprintf(L"\n Fone....: %s",max[i].fone);
            wprintf(L"\n E-mail..: %s\n ",max[i].email);
            cont++;
         }
     i++;
     retorno = fread(&max[i], sizeof(contatos), 1, arq);//fread vai ler o proximo contato
     }
     if(cont == 0){//se strcmp não encontrar strings iguais
        wprintf(L"Nao ha contatos com este nome!\n ");//sera mostrada essa mensagen
     }
     getch();//espera que o usuário pressione uma tecla
     fclose(arq);//fecha o arquivo agenda.txt
}

/*================== Lista os contatos cadastrados ======================*/
void Listar(void){
    int i = 0, retorno;
    wchar_t *c;

    arq = fopen("agenda.txt", "r");//fopen abre o arquivo no modo leitura "r"
  _setmode(_fileno(arq), UTF_8); //Define nos arquivos o conjunto UTF8 de caracteres
    if (arq == NULL){//caso o SO não consiga abrir o arquivo
       wprintf(L"Erro!\nO arquivo da lista não pode ser aberto!\n");//sera mostrada esta mensagens
       getch();//espera que o usuário pressione uma tecla
       exit(1);//caso esse erro ocorra este comando encerra o programa
    }
  while (!feof(arq))
  {
      fwscanf(arq, L"%c",&c);
      wprintf(L"%c",c);
    }
    wprintf(L" \n\n %d Contatos salvos!\n ", i);
    getch();//espera que o usuário pressione uma tecla
    fclose(arq);//fecha o arquivo agenda.txt
}

/*========== Sobre os Autores ================*/
void Sobre(void){
    wprintf(L"\n\n\t\tAGENDA EM LINGUAGUEM C\n\n");
    wprintf(L"\tTrabalho para obtenção de nota Parcial\n\tNa Disciplina de Algoritmos e Estrutura de Dados\n");
    wprintf(L"\tIntegrantes da Equipe:\n\t\tRodrigo Alves\n\t\tAdailton\n\t\tEduardo Ramos\n\t\tRoseane Brito");
    getch();//espera que o usuário pressione uma tecla
}

/*=====================   Menu   =======================*/
void menu(void){
    char op;//variavel de opção
    do{
        system("cls");// limpar tela
        wprintf(L"\n\n\t\tAGENDA EM LINGUAGUEM C\n");
        wprintf(L"\n 1 = Incluir\n 2 = Listar\n 3 = Organizar por ordem alfabetica\n 4 = Pesquisar por nome\n");
        wprintf(L" 5 = Formatar lista\n 6 = Sobre\n 7 = Voltar\n\n");
        op = getch();
        switch(op){
            case '1':
                salvar();
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
                wprintf(L"\a Digite uma opção valida\n");
                getch();//espera que o usuário pressione uma tecla
        }
    }
    while (op);
}
