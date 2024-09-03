#include<stdio.h>
#include<string.h>
#include<ctype.h> //para verificar se é isalpha, se são letras o que se está a escrever na parte do nome de aluno.

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:12 de Março de 2020
 Programa/Exercicio: ficha 2.1 / exercicio 6
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
 void flush_in(){ // codigo para limpeza de buffer do teclado..
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
    return;
}

 int AddStudent(int counter, char memoryStudent[50][50], int memoryNumber[50]){
   char aluno[50];
   unsigned int number;

   if(counter<50){
     printf("Nome de Aluno: ");
     scanf("%50[^\n]", aluno);//usando o %[^\n] já se pode usar espaços no nome que ele lê. scanf que é string e pode-se manipular o que quer que ele leia..
     flush_in();
      for(int i=0; aluno[i]!='\0'; ++i){
        if(aluno[i]==' ' || isalpha(aluno[i])){
          continue;
        }
        else{
          printf("Erro, nome de aluno contem algo diferente de caracteres\n");
          printf("Clique enter para voltar ao menu..");
          getchar();
          return counter;
        }
      }

     printf("\nNome do aluno inserido correctamente na memoria...\n");
     printf("%s", aluno);
     strcpy(memoryStudent[counter], aluno);
     printf("\nNumero de aluno: ");
     if((scanf("%u", &number))){
       if(number>0){
         for(int i=0; i<50; ++i){
           if(memoryNumber[i]==number){ // cada aluno tem o seu número de aluno, assim na pesquisa por número não há erros..
             printf("\nNumero de aluno já existe\n");
             printf("Clique enter para voltar ao menu..");
             getchar();
             return counter;
           }
       }
       printf("\nNumero de aluno inserido correctamente na memoria...\n");
       memoryNumber[counter]=number;
     }
     else{
       printf("Erro, numero de aluno algo diferente de digitos ou menor/Igual que 0\n");
       printf("Clique enter para voltar ao menu..");
       getchar();
       flush_in();
       return counter;
     }
     counter++;
     printf("Clique enter para voltar ao menu..");
     flush_in();
     getchar();
     return counter;
     }
   else{
     printf("Erro, numero maximo de alunos\n");
     printf("Clique enter para voltar ao menu..");
     getchar();
   return counter;
   }
  }
  }

 int RemoveStudent(int counter, char memoryStudent[50][50], int memoryNumber[50]){
   int numbstudent;
   printf("Insira o numero de Aluno a remover\n");
   scanf("%d", &numbstudent);
   flush_in();
     for(int i=0; i<50; i++){
         if(numbstudent==memoryNumber[i]){
           for(int t=i; t<50; ++t){
             for(int q=0; q<50; ++q){
               memoryStudent[t][q]='\0'; // caso o nome que venha a seguir seja menor e assim tenho a certeza que não ficam lá caracteres desse nome.
             }
             strcpy(memoryStudent[t], memoryStudent[t+1]);
             memoryNumber[t]=memoryNumber[t+1]; //uso este ciclo para logo não deixar espaços em branco na lista de alunos
             memoryNumber[t+1]=-1; // este menos um serve depois para a lista em texto.
           }
           printf("Aluno e seu numero removido\n");
           counter--; // assim retiro um valor ao total da lista de alunos.. serve depois para dar load no inicio do programa ao que já está gravado e assim preencher tudo na memoriaAluno
           printf("Clique enter para voltar ao menu..");
           getchar();
           return counter;
         }
     }
   printf("Aluno não existe\n");
   printf("Clique enter para voltar ao menu..");
   getchar();
   return counter;
   }

   void saveData(char memoryStudent[50][50], int memoryNumber[50]){
     FILE *saveStudent, *saveNumber;

     saveStudent = fopen("SaveAlunos.txt", "w"); //gravação de alunos associados

     if(saveStudent==NULL){
       printf("Nao foi possivel gravar Alunos\n");
       printf("Clique para continuar\n");
       getchar();
       return;
     }
     else{
       for(int i=0; i < 50; i++){
           fprintf(saveStudent, "%s\n", memoryStudent[i]);
         }
       }
     fclose(saveStudent);


   saveNumber = fopen("SaveNumeros.txt", "w"); //gravação de numeros de alunos

   if(saveNumber==NULL){
     printf("Nao foi possivel gravar Numeros\n");
     printf("Clique para continuar\n");
     getchar();
     return;
   }
   else{
     for(int a=0; a < 50; a++){
         fprintf(saveNumber, "%d\n", memoryNumber[a]);
         }
   }
   fclose(saveNumber);
   printf("Dados gravados com sucesso, clique para continuar\n");
   getchar();
   return;
 }

 int loadData(int valor, int memoryNumber[50], char memoryStudent[50][50]){

   char strAux[50];
   int deleteLine, number=0, a=0;

   FILE *readStudent, *readNumber;

   readStudent = fopen("SaveAlunos.txt", "r");          //ler alunos associados

   if(readStudent==NULL){
     printf("Nao ha dados sobre alunos anteriormente guardados\n");
     readStudent = fopen("SaveAlunos.txt", "w"); //caso seja a primeira vez a iniciar o programa ele cria um documento para guardar..
   }
   else{
     for(int i=0; i<50; ++i){
       fgets(strAux, 49, readStudent);
       deleteLine = strlen(strAux)-1;
       if(strAux[deleteLine] == '\n'){
         strAux[deleteLine] = '\0';
       }
       strcpy(memoryStudent[i], strAux); //copiar para o destino, vindo da fonte.
     }

     for(int f=0; f<50; ++f){          // estou a usar esta função para actualizar o contador logo no load..
       if(strlen(memoryStudent[f])>1){
         valor++;
       }
       else{
         break;
       }
       }
     }
   fclose(readStudent);

   readNumber = fopen("SaveNumeros.txt", "r");      //ler numeros de alunos

   if(readNumber==NULL){
     printf("Nao foi possivel encontrar dados sobre Numeros\n");
     readNumber = fopen("SaveNumeros.txt", "w");
   }
   else{
     while((fscanf(readNumber, "%d", &number)) != EOF){
         memoryNumber[a]=number;
         ++a;
     }
   }
   fclose(readNumber);
   printf("Inicializacao do programa completa clique para continuar\n");
   getchar();
   return valor;
 }

 void ListStudent(int counter, char memoryStudent[50][50], int memoryNumber[50]){
   if(counter>0){
     for(int i=0; i<counter; ++i){
       printf("Nome: %s \t Numero: %d\n", memoryStudent[i], memoryNumber[i]);
     }
     printf("\n\n\nClique para sair.");
     getchar();
     return;
   }
   else{
     printf("Não existem alunos inscritos\n");
     printf("Voltar ao menu\n");
     getchar();
     return;
   }
 }
 void starter(int memoryNumber[50]){
   for(int i=0; i<50; ++i){
     memoryNumber[i]=-1; //isto devido que por defeito no meu pc o número um fica ocupado assim sei que não há números negativos de alunos..
   }
   return;
 }

 int main(){
   int option=0, memoryNumber[50], counter=0;
   char memoryStudent[50][50];
   starter(memoryNumber);
   counter=loadData(counter, memoryNumber, memoryStudent); //para ir buscar dados aos ficheiros..
    do{
      printf("Insira a sua opcao\n");
      printf("Opcao 1 - Listar alunos\n");
      printf("Opcao 2 - Inscrever aluno\n");
      printf("Opcao 3 - Remover aluno\n");
      printf("Opcao 4 - Gravar dados\n");
      printf("Opcao 5 - Sair\n");
      printf("Opcao: ");
      scanf("%d", &option);
      flush_in();
      switch(option){
        case 1: ListStudent(counter, memoryStudent, memoryNumber); break;
        case 2: counter=AddStudent(counter, memoryStudent, memoryNumber); break;
        case 3: counter=RemoveStudent(counter, memoryStudent, memoryNumber); break;
        case 4: saveData(memoryStudent, memoryNumber);break;
        case 5: break;
        default:
        printf("Opcao não valida volte a tentar\n\n"); break;
      }

    }while(option!=5);


	return 0;
}
