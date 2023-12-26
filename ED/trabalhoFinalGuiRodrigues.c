# include < stdio.h >
# include < conio.h >

void  creation( ) ;
void  deposit( ) ;
void  withdraw( ) ;
void  lowbal( ) ;

int  a = 0 , i = 1001 ;

struct bank
{
  int n_conta;
  char nome[20];
  float balanco;
  float deposito;
} s[100];

int  main( )
{
  int  ch ;
  do
  {
    printf(" \n**************************** ");
    printf(" \nBanco ");
    printf(" \n**************************** ");
    printf(" \n1. Criar nova conta ");
    printf(" \n2. Depositar Dinheiro ");
    printf(" \n3. Retirar Dinheiro ");
    printf(" \n4. Ver balanço ");
    printf(" \n5. Sair ");
    printf(" \nInsira a opçao : ");
    scanf("%d ",& ch);

    switch (ch)
    {
      case 1 :  add_conta( ) ;
      break ;
      case 2 :  depositar( ) ;
      break ;
      case 3 :  levantamento( ) ;
      break ;
      case 4 :  lowbal( ) ;
      break ;
      case 5 :  ;
      break ;
      defalut :  printf(" Choice a Valid option !! ") ;
      break ;
      getch( ) ;
    }
  } while( ch != 5 ) ;
}

void add_conta( )
{
  puts(" **************************** ");
  puts(" Nova Conta ");
  puts(" **************************** ");
  puts(" Insira o numero da conta :%d ",i);

  s[a].no = i ;

  puts(" Enter your Name : ");
  scanf("%s",& s[a].name);
  puts(" O deposito minimo e de 500");

  s[a].dep=500 ;

  a++;
  i++;

  getch();
}

void depositar( )
{
  int  n_conta, b = 0, m = 0 ;
  int  aa ;
  puts(" **************************** ");
  puts(" Deposito ");
  puts(" **************************** ");
  puts(" Insira o numero da conta : ");
  scanf("%d ",& no);
  for (b = 0 ; b < i ; b++)
  {
    if (s[b].no == no)
    m = b;
  }
  if (s[m].no == no)
  {
    puts(" Numero de conta : %d ",s[m].no);
    puts(" Nome : %s ",s[m].name);
    puts(" Deposito : %f ",s[m].dep);
    puts(" Quantia Depositada : ");
    scanf("%f ",& &aa);
    s[m].dep+=aa;
    puts(" Balanço da conta : %f ",s[m].dep);
    getch();
  }
  else
  {
    puts("Numero da conta invalido ");
    getch();
  }
}

void levantamento()
{
  int  no, b = 0, m = 0 ;
  int  aa ;
  puts(" **************************** ") ;
  puts(" Lenvantamento ") ;
  puts(" **************************** ") ;
  puts(" Numero de conta : ") ;
  scanf("%d ",& no) ;
  for (  b = 0 ; b < i ; b++)
  {
    if (  s[b].no == no)
    m = b ;}
  if (  s[m].no == no)
  {
    puts(" Numero da conta : %d ",s[m].no);
    puts(" Nome : %s ",s[m].name);
    puts(" Deposito : %f ",s[m].dep);
    puts(" Quantia a levantar : ");
    scanf("%f ",& aa);

    if (  s[m].dep < aa+500)
    {
      puts("Impossivel levantar ! ");
      getch();
    }
    else
    {
      s[m].dep-=aa;
      puts("o novo saldo da conta e : %f ",s[m].dep);
    }
  }
  else
  {
    puts(" Numero da conta invalido ");
    getch();
  }
  getch();
}
