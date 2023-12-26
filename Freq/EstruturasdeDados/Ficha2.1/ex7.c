#include<stdio.h>
#include<string.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data: 19 de Março de 2020
 Programa/Exercicio: Ficha 2 / Exercicio 7
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
 void flush_in(){ // codigo para limpeza de buffer do teclado..
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
    return;
  }

  int insertNames(char name[51][50], int counter){
    int option, tamanho;
    do{
      printf("Para inserir nome insira 1\n");
      printf("Para sair da inserção de nomes insira 2\n");
      printf("Insira a sua opção: "); scanf("%d", &option);
      flush_in();

      switch(option){
        case 1:
           if(counter<50){
             printf("\nMaximo de nomes será 50\n\n");
             printf("Número de nomes inseridos %d\n", counter);
             printf("Insira o nome: "); fgets(name[counter], 48, stdin);
             tamanho=strlen(name[counter]);
             name[counter][tamanho-1]='\0'; //eliminar a mudança de linha que vem por defeito..
             printf("Nome inserido com sucesso\n\n");
             counter++;
           }
           else{
             printf("Numero maximo de nomes alcançado");
             return counter;
           } break;
        case 2 : break;
        default: printf("Opção não aceite volte a tentar\n"); break;
      }

    }while(option!=2);

   return counter;
 }

 void saveData(char name[51][50], int counter){

   FILE *saveNames;

   saveNames=fopen("nomes.txt", "w");

   if(saveNames==NULL){
     printf("Erro ao abrir o ficheiro\n");
     printf("Clique para sair\n");
     getchar();
     fclose(saveNames);
     return;
   }
   else{
     for(int i=0; i<counter; ++i){
       fprintf(saveNames, "%s\n", name[i]);
     }
     fclose(saveNames);
   }
   printf("Matriz gravada em nomes.txt clique para continuar\n");
   getchar();
  return;
  }

  void loadData(char aux[50]){

    FILE *loadNames;

    loadNames=fopen("nomes.txt", "r");

    if(loadNames==NULL){
      printf("Erro ao abrir o ficheiro\n");
      printf("Clique para sair\n");
      getchar();
      fclose(loadNames);
      return;
    }
    else{
      while(fgets(aux, 48, loadNames)!=NULL){
        fprintf(stdout, "%s", aux);
      }
    }
    printf("Clique para continuar..\n");
    getchar();
    fclose(loadNames);
    return;
  }

  void saveBinTable(char name[51][50], int counter, char aux2[51][50], char aux3[51][50]){
    FILE *bin;
    int a=0;

                              //gravação linha a linha..
    bin=fopen("nomesBinario.dat", "w+b");
    if(bin==NULL){
      printf("Erro ao abrir ficheiro clique para continuar\n");
      getchar();
      return;
    }
    else{
      while(a<counter){
        fwrite(&name[a][0], sizeof(char), 50, bin); // poderia ser sizeof(char [50]) e depois ser 1 no bloco..
        a++;
      }
      rewind(bin);
      a=0;
      while(a<counter){
        fread(&aux2[a][0], sizeof(char), 50, bin);
        a++;
      }
      for(int i=0; i<counter; ++i){
        printf("string lido: %s\n",aux2[i]);
      }
      printf("Clique para continuar\n"); getchar();

      fclose(bin);
    }
        //gravação por tabela..
    bin=fopen("tabelaNomes.dat", "w+b");
    if(bin==NULL){
      printf("Erro ao abrir ficheiro clique para continuar\n");
      getchar();
      return;
    }
    else{

      fwrite(name, 50* sizeof(char[50]), 1, bin);
      rewind(bin);
      fread(aux3, 50* sizeof(char[50]), 1, bin);
      fclose(bin);

      for(int i=0; i<counter; ++i){
        printf("string lido: %s\n",aux3[i]);
      }

      printf("Clique para continuar\n"); getchar();
    }
    return;
  }


 int main(){
   int counter=0, option=0;
   char name[51][50], aux[50], aux2[51][50], aux3[51][50];

   counter=insertNames(name, counter);
   saveData(name, counter);
   loadData(aux);
   saveBinTable(name, counter, aux2, aux3);

	return 0;
}
