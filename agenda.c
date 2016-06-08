/** AGENDA EM LIMGUAGUEM C
 *
 * Agenda feita para obtenção de nota parcial na mateira de 'Algoritmos e Estrutura de Dados'.
 *
 * @autor Rodrigo Alves Mesquita
 * Aluno do 3° periodo do curso de Bacharel em Ciências da Computação na Faculdade Pitágoras
 *
 */

#include "agenda.h"

FILE* abrirArquivo(char *caminho, char modo){
  FILE *arquivo;
  switch(modo){
    case 'g':
      arquivo = fopen(caminho, "wt");
      break;
    case 'l':
      arquivo = fopen(caminho, "rt");
      break;
    case 'a':
      arquivo = fopen(caminho, "a");
      break;
    case 'f':
      arquivo = fopen(caminho, "w+");
      break;
  }
  if (arquivo == NULL){//caso o sistema não consiga criar o arquivo
    wprintf(L"\a\nErro! O arquivo da agenda não pode ser aberto!\n");//sera mostrada esta mensagen
    getch();// espera que o usuário pressione uma tecla
    exit(1);//caso esse erro ocorra este comando encerra o programa
  }
  _setmode(_fileno(arquivo), UTF_8); //Define nos arquivos o conjunto UTF8 de caracteres
  return arquivo;
}

/*========  Incluir Contatos na Agenda  ===========*/
void Incluir(void){
  contato pessoa;
  char op = 's';  //seve para definir a opção na função AddMais()

  arq = abrirArquivo("agenda.txt", 'a');
  while (op == 's'){
    system("cls");// limpar tela
    titulo('t');
    wprintf(L"\n\tDigite o nome: ");
    wscanf(L"%ls", pessoa.nome);
    // Limpar buffer do teclado
    //fflush(stdin); // Para Windows
    __fpurge(stdin); // Linux
    fwprintf(arq, L"\n\tNome....: %s", pessoa.nome);
    wprintf(L"\n\tDigite o numero: ");
    wscanf(L"%ls", pessoa.fone);
    // Limpar buffer do teclado
    //fflush(stdin); // Para Windows
    __fpurge(stdin); // Linux
    fwprintf(arq, L"\n\tFone....: %s", pessoa.fone);
    wprintf(L"\n\tDigite o E-mail: ");
    wscanf(L"%ls", pessoa.email);
    // Limpar buffer do teclado
    //fflush(stdin); // Para Windows
    __fpurge(stdin); // Linux
    fwprintf(arq, L"\n\tE-mail..: %s", pessoa.email);
    wprintf(L"\n\tGravacao ok! ");
    fwprintf(arq, L"\n");
    do {
      wprintf(L"\n\tDeseja inserir novos dados? S/N? " );
      op = getch();
      wprintf(L"\n");
    } while (op != 's' && op != 'n');
   }
  fclose (arq);//fecha o arquivo agenda.txt
}

/*=====================  Apagar tudo  ====================*/
void Formata() {
    /* w+ abre um arquivo para leitura e escrita.
    Se o arquivo não existir, o sistema operacional tentará criá-lo.
    Se o arquivo existir, todo o seu conteúdo será substituído pelo novo conteúdo.*/
    arq = abrirArquivo("agenda.txt", 'f');
    wprintf(L"\n\tLista limpa!\n ");
    titulo('a');
    fclose(arq);//fecha o arquivo agenda.txt
    getch();// espera que o usuário pressione uma tecla
}

/*================== Lista os contatos cadastrados ======================*/
void Listar(void){
    wchar_t *c;

    system("cls");// limpar tela
    arq = abrirArquivo("agenda.txt",'l');
    while (!feof(arq))
    {
      fwscanf(arq, L"%c",&c);
      wprintf(L"%c",c);
    }
    wprintf(L"\n\t");
    getch();//espera que o usuário pressione uma tecla
    fclose(arq);//fecha o arquivo agenda.txt
}

void titulo(char output){
  if (output == 't') //se o output for a tela
  {
    wprintf(L"\n");
    wprintf(L"\t  █████╗  ██████╗ ███████╗███╗   ██╗██████╗  █████╗ \n");
    wprintf(L"\t ██╔══██╗██╔════╝ ██╔════╝████╗  ██║██╔══██╗██╔══██╗\n");
    wprintf(L"\t ███████║██║  ███╗█████╗  ██╔██╗ ██║██║  ██║███████║\n");
    wprintf(L"\t ██╔══██║██║   ██║██╔══╝  ██║╚██╗██║██║  ██║██╔══██║\n");
    wprintf(L"\t ██║  ██║╚██████╔╝███████╗██║ ╚████║██████╔╝██║  ██║\n");
    wprintf(L"\t ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝\n");
    wprintf(L"\n\t\t\tAGENDA EM LINGUAGUEM C\n");
  }
  if (output == 'a')
  {
    fwprintf(arq, L"\n");
    fwprintf(arq, L"\t  █████╗  ██████╗ ███████╗███╗   ██╗██████╗  █████╗ \n");
    fwprintf(arq, L"\t ██╔══██╗██╔════╝ ██╔════╝████╗  ██║██╔══██╗██╔══██╗\n");
    fwprintf(arq, L"\t ███████║██║  ███╗█████╗  ██╔██╗ ██║██║  ██║███████║\n");
    fwprintf(arq, L"\t ██╔══██║██║   ██║██╔══╝  ██║╚██╗██║██║  ██║██╔══██║\n");
    fwprintf(arq, L"\t ██║  ██║╚██████╔╝███████╗██║ ╚████║██████╔╝██║  ██║\n");
    fwprintf(arq, L"\t ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝\n");
    fwprintf(arq, L"\n\t\t\tAGENDA EM LINGUAGUEM C\n");
  }
}

/*========== Sobre os Autores ================*/
void Sobre(void){
  titulo('t');
  wprintf(L"\n\t┌───────── Sobre Este Programa ───────────┐");
  wprintf(L"\n\t│                                         │");
  wprintf(L"\n\t│  Programa feito para obtenção de nota   │");
  wprintf(L"\n\t│  parcial de Estrutura de dados          │");
  wprintf(L"\n\t│  Obrigado por usar nosso app!           │");
  wprintf(L"\n\t│                                         │");
  wprintf(L"\n\t│  Criado por Rodrigo Alves Mesquita      │");
  wprintf(L"\n\t│                                         │");
  wprintf(L"\n\t└─────────────────────────────────────────┘\n\t");
  getch();//espera que o usuário pressione uma tecla
}

/*=====================   Menu   =======================*/
void menu(void){
  char op;//variavel de opção
  do{
    system("cls");// limpar tela
    titulo('t');
    wprintf(L"\n\t┌───────────── Menu de Opções ────────────┐");
    wprintf(L"\n\t│                                         │");
    wprintf(L"\n\t│    1 = Incluir                          │");
    wprintf(L"\n\t│    2 = Listar                           │");
    wprintf(L"\n\t│    5 = Formata Agenda                   │");
    wprintf(L"\n\t│    6 = Sobre                            │");
    wprintf(L"\n\t│  ESC = Voltar                           │");
    wprintf(L"\n\t│    0 = Sair                             │");
    wprintf(L"\n\t│                                         │");
    wprintf(L"\n\t└─────────────────────────────────────────┘");
    wprintf(L"\n\t");
    op = getch();
    switch(op){
      case '0':
        exit(0);
        break;
      case '1':
        Incluir();
        break;
      case '2':
        Listar();
        break;
      case '3':
        //Organizar();
        break;
      case '4':
        //Pesquisar();
        break;
      case '5':
        Formata();
        break;
      case '6':
        system("cls");
        Sobre();
        break;
      case 27:// 27 corresponde ao esc no teclado conforme Tabela ASCII
        system("cls");
        main();
        break;
      default:
        wprintf(L"\a Digite uma opção valida\n");
        getch();//espera que o usuário pressione uma tecla
        break;
    }
  }
  while (op);
}
