#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FUNCIONARIOS 100
#define MAX_PRODUTOS 100
#define MAX_MESAS 100
#define MAX_ENCOMENDAS 100

typedef struct 
{
    char nome[25];
    char funcao[25];
    char disponibilidade[25];
} Funcionario;

typedef struct 
{
    char p_nome[25];
    float preco;
    int quantidade;
} Produto;

typedef struct 
{
    char nome[25];
    int quantidade;
} Encomenda;
    
typedef struct ItemConta {
    char nomeProduto[25];
    int quantidade;
    float preco;
    struct ItemConta *proximo; // Ponteiro para o próximo ItemConta na lista
} ItemConta;

typedef struct Pedido {
    int n_Mesa;
    char nomeFuncionario[25];
    ItemConta *produtos; // Ponteiro para o primeiro ItemConta na lista de produtos
    int contadorProdutos;
    float total;
    struct Pedido *proximo; // Ponteiro para o próximo Pedido na lista
} Pedido;

typedef struct Mesa {
    int n_Mesa;
    int n_Lugares;
    char localizacao[25];
    char m_disponibilidade[25]; 
    Pedido *pedidos; // Ponteiro para o primeiro pedido (Pedido) na lista de pedidos
} Mesa;

void adicionarFuncionario(Funcionario *tabela, int *contador) 
{
    if (*contador >= MAX_FUNCIONARIOS) 
    {
        printf("Limite de funcionarios atingido!\n");
        return;
    }
    
    Funcionario *f = &tabela[*contador];

    // o uso de %24s serve para evitar overflow
    // f-> serve para enviar para dentro da tabela
    printf("Insira o nome do funcionario: ");
    scanf("%24s", f->nome);
    printf("Insira a função do funcionario: ");
    scanf("%24s", f->funcao);
    printf("Insira a disponibilidade atual do funcionario: ");
    scanf("%24s", f->disponibilidade); 

    // Limpamos o buffer 
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("\nPressione Enter para mostrar os dados do funcionario inserido...\n");
    getchar(); // Espera que o utilizador pressione Enter
    system("clear");

    printf("\n------------------Funcionario adicionado:------------------\n");
    printf("Nome: %s\n", f->nome);
    printf("Função: %s\n", f->funcao);
    printf("Disponibilidade: %s\n", f->disponibilidade);
    printf("\n-------------------------------------------------------------\n");

    (*contador)++;

    printf("\nPressione Enter para continuar\n");
    getchar(); // Espera que o utilizador pressione Enter
    system("clear");

}

void mostrarFuncionarios(Funcionario *tabela, int contador) 
{

    printf("\nLista de Funcionarios Registados:\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < contador; i++) 
    {
        Funcionario *f = &tabela[i];
        printf("Funcionario %d:\n", i + 1);
        printf("Nome: %s\n", f->nome);
        printf("Função: %s\n", f->funcao);
        printf("Disponibilidade: %s\n", f->disponibilidade);
        printf("-------------------------------------------------------------\n");
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("\n\nPressione Enter para continuar...\n");
    getchar(); // Espera que o utilizador pressione Enter
    system("clear");
}

void alterarFuncionarios(Funcionario *tabela, int contador)
{
    int opcao;
    char nomeFuncionario[25];
    int funcionarioEncontrado = 0;

    printf("insira o nome do funcionário que pretende alterar: ");
    scanf("%24s", nomeFuncionario);

    // Verificar existência do funcionário
    Funcionario *f = NULL;
    for (int i = 0; i < contador; i++) 
    {
        if (strcmp(tabela[i].nome, nomeFuncionario) == 0) 
        {
            funcionarioEncontrado = 1;
            f = &tabela[i];
            break;
        }
    }

    if (!funcionarioEncontrado) 
    {
        printf("Funcionário %s não encontrado.\n", nomeFuncionario);
        return;
    }

    // Atualizar as informações do funcionário
    printf("Insira a nova função do funcionário: ");
    scanf("%24s", f->funcao);
    printf("Insira a nova disponibilidade do funcionário: ");
    scanf("%24s", f->disponibilidade);

    // Limpar o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    
    printf("\nPressione Enter para mostrar os dados do funcionário alterado...\n");
    getchar(); // Espera que o utilizador pressione Enter
    system("clear");

    printf("\n------------------Funcionário alterado:------------------\n");
    printf("Nome: %s\n", f->nome);
    printf("Função: %s\n", f->funcao);
    printf("Disponibilidade: %s\n", f->disponibilidade);
    printf("\n--------------------------------------------------------\n");

    printf("\nPressione Enter para continuar\n");
    getchar(); // Espera que o utilizador pressione Enter
    system("clear");
}

void removerFuncionarios(Funcionario *tabela, int *contador)
{
    char nomeFuncionario[25];
    int funcionarioEncontrado = 0;
    int indiceFuncionario = -1;

    printf("Insira o nome do funcionário que deseja remover: ");
    scanf("%24s", nomeFuncionario);

    // Verificar existência do funcionário
    for (int i = 0; i < *contador; i++) 
    {
        if (strcmp(tabela[i].nome, nomeFuncionario) == 0) 
        {
            funcionarioEncontrado = 1;
            indiceFuncionario = i;
            break;
        }
    }

    if (!funcionarioEncontrado) 
    {
        printf("Funcionário %s não encontrado.\n", nomeFuncionario);
        return;
    }

    // Remover o funcionário deslocando os elementos do array para "cima"
    for (int i = indiceFuncionario; i < *contador - 1; i++) 
    {
        tabela[i] = tabela[i + 1];
    }

    (*contador)--;

    // Limpar o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("\nPressione Enter para confirmar a remoção do funcionário...\n");
    getchar(); // Espera que o utilizador pressione Enter
    system("clear");

    printf("\n------------------Funcionário removido:------------------\n");
    printf("Nome: %s\n", nomeFuncionario);
    printf("---------------------------------------------------------\n");

    printf("\nPressione Enter para continuar\n");
    getchar(); // Espera que o utilizador pressione Enter
    system("clear");
}

void salvarFuncionarios(Funcionario *f_tabela, int contador) 
{
    FILE *file = fopen("funcionarios.dat", "wb");
    if (file == NULL) 
    {
        printf("Erro ao abrir arquivo para salvar funcionários.\n");
        return;
    }
    fwrite(&contador, sizeof(int), 1, file);
    fwrite(f_tabela, sizeof(Funcionario), contador, file);
    fclose(file);
}

int carregarFuncionarios(Funcionario *f_tabela) 
{
    FILE *file = fopen("funcionarios.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir arquivo para carregar funcionários.\n");
        return 0;
    }
    int contador;
    fread(&contador, sizeof(int), 1, file);
    fread(f_tabela, sizeof(Funcionario), contador, file);
    fclose(file);
    return contador;
}

void menuFuncionarios(Funcionario *tabela, int *contador)
{
    int opcao;

    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Inserir funcionário\n");
        printf("2. Ver funcionarios\n");
        printf("3. Alterar funcionário\n");
        printf("4. Remover funcionário\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Limpar o buffer de entrada
        int c;

        switch (opcao) 
        {
            case 1:
                system("clear");
                adicionarFuncionario(tabela, contador);
                break;
            case 2:
                system("clear");
                mostrarFuncionarios(tabela, *contador);
                break;
            case 3:
                system("clear");
                alterarFuncionarios(tabela, *contador);
                break;
            case 4:
                system("clear");
                removerFuncionarios(tabela, contador);
                break;
            case 5:
                system("clear");
                printf("Saindo...\n");
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void adicionarProduto(Produto *p_tabela, int *contador) //como pensei que era para organizar apenas por quantidade escolhi organizar desde a adição do produto mas depois de ler que deveria ser tanto pela quantidade quanto pelo valor na funçao de mostrar tenho as duas opções
{
    if (*contador >= MAX_PRODUTOS) 
    {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto novoProduto;

    // o uso de %24s serve para evitar overflow
    printf("Insira o nome do produto: ");
    scanf("%24s", novoProduto.p_nome);
    printf("Insira o preço do produto: ");
    scanf("%f", &(novoProduto.preco));
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("Insira a quantidade atual do produto: ");
    scanf("%d", &(novoProduto.quantidade)); 

    // Limpamos o buffer 
    while ((c = getchar()) != '\n' && c != EOF) { }

    // Encontrar a posição correta para inserir o novo produto
    int posicao = *contador;
    for (int i = 0; i < *contador; i++) 
    {
        if (novoProduto.quantidade < p_tabela[i].quantidade) 
        {
            posicao = i;
            break;
        }
    }

    // Deslocar os elementos para a direita para abrir espaço para o novo produto
    for (int i = *contador; i > posicao; i--) 
    {
        p_tabela[i] = p_tabela[i - 1];
    }

    // Inserir o novo produto na posição correta
    p_tabela[posicao] = novoProduto;

    (*contador)++;

    system("clear");
    printf("\nPressione Enter para mostrar os dados do produto inserido...\n");
    getchar(); // Espera que o utilizador pressione Enter

    printf("\n------------------Produto adicionado:------------------\n");
    printf("Nome: %s\n", novoProduto.p_nome);
    printf("Preço: %0.2f\n", novoProduto.preco);
    printf("Quantidade: %d\n", novoProduto.quantidade);
    printf("\n-------------------------------------------------------------\n");

    printf("\nPressione Enter para continuar...\n");
    getchar(); // Espera que o utilizador pressione Enter
}

void mostrarProdutos(Produto *p_tabela, int contador) 
{
 int criterio;

    printf("Escolha o critério de exibição:\n");
    printf("1. Quantidade (padrão)\n");
    printf("2. Preço\n");
    printf("Digite sua escolha: ");
    scanf("%d", &criterio);

    // Limpar o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    if (criterio == 2) 
    {
        // Ordenar os produtos por preço usando bubble sort
        for (int i = 0; i < contador - 1; i++) 
        {
            for (int j = 0; j < contador - i - 1; j++) 
            {
                if (p_tabela[j].preco > p_tabela[j + 1].preco) 
                {
                    Produto temp = p_tabela[j];
                    p_tabela[j] = p_tabela[j + 1];
                    p_tabela[j + 1] = temp;
                }
            }
        }
    }

    printf("\nLista de Produtos Registrados:\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < contador; i++) 
    {
        Produto *produto = &p_tabela[i];
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", produto->p_nome);
        printf("Preço: %.2f\n", produto->preco); 
        printf("Quantidade: %d\n", produto->quantidade); 
        printf("-------------------------------------------------------------\n");
    }

    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("\n\nPressione Enter para continuar...\n");
    getchar(); // Espera que o utilizador pressione Enter
    system("clear");
}

void alterarProdutos(Produto *p_tabela, int contador)
{
    char nomeProduto[25];
    int produtoEncontrado = 0;

    printf("Insira o nome do produto que deseja alterar: ");
    scanf("%24s", nomeProduto);

    // Verificar existência do produto
    for (int i = 0; i < contador; i++) 
    {
        if (strcmp(p_tabela[i].p_nome, nomeProduto) == 0) 
        {
            produtoEncontrado = 1;
            Produto *p = &p_tabela[i];

            printf("Insira o novo nome do produto: ");
            scanf("%24s", p->p_nome);
            printf("Insira o novo preço do produto: ");
            scanf("%f", &(p->preco));
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("Insira a nova quantidade do produto: ");
            scanf("%d", &(p->quantidade));

            // Limpamos o buffer 
            while ((c = getchar()) != '\n' && c != EOF) { }

            system("clear");
            printf("\nPressione Enter para mostrar os dados do produto alterado...\n");
            getchar(); // Espera que o utilizador pressione Enter

            printf("\n------------------Produto alterado:------------------\n");
            printf("Nome: %s\n", p->p_nome);
            printf("Preço: %0.2f\n", p->preco);
            printf("Quantidade: %d\n", p->quantidade);
            printf("\n-------------------------------------------------------------\n");

            break;
        }
    }

    if (!produtoEncontrado) 
    {
        printf("Produto %s não encontrado.\n", nomeProduto);
    }

    printf("\nPressione Enter para continuar\n");
    getchar(); // Espera que o utilizador pressione Enter
    system("clear");
}

void removerProdutos(Produto *p_tabela, int *contador)
{
    char nomeProduto[25];
    int produtoEncontrado = 0;
    int indiceProduto = -1;

    printf("Insira o nome do produto que deseja remover: ");
    scanf("%24s", nomeProduto);

    // Verificar existência do produto
    for (int i = 0; i < *contador; i++) 
    {
        if (strcmp(p_tabela[i].p_nome, nomeProduto) == 0) 
        {
            produtoEncontrado = 1;
            indiceProduto = i;
            break;
        }
    }

    if (!produtoEncontrado) 
    {
        printf("Produto %s não encontrado.\n", nomeProduto);
        return;
    }

    // Remover o produto deslocando os elementos do array para "cima"
    for (int i = indiceProduto; i < *contador - 1; i++) 
    {
        p_tabela[i] = p_tabela[i + 1];
    }

    (*contador)--;

    // Limpar o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("\nPressione Enter para confirmar a remoção do produto...\n");
    getchar(); // Espera que o utilizador pressione Enter
    system("clear");

    printf("\n------------------Produto removido:------------------\n");
    printf("Nome: %s\n", nomeProduto);
    printf("---------------------------------------------------------\n");

    printf("\nPressione Enter para continuar\n");
    getchar(); // Espera que o utilizador pressione Enter
    system("clear");
}

void salvarProdutos(Produto *p_tabela, int contador) 
{
    FILE *file = fopen("produtos.dat", "wb");
    if (file == NULL) 
    {
        printf("Erro ao abrir arquivo para salvar produtos.\n");
        return;
    }
    fwrite(&contador, sizeof(int), 1, file);
    fwrite(p_tabela, sizeof(Produto), contador, file);
    fclose(file);
}

int carregarProdutos(Produto *p_tabela) 
{
    FILE *file = fopen("produtos.dat", "rb");
    if (file == NULL) 
    {
        printf("Erro ao abrir arquivo para carregar produtos.\n");
        return 0;
    }
    int contador;
    fread(&contador, sizeof(int), 1, file);
    fread(p_tabela, sizeof(Produto), contador, file);
    fclose(file);
    return contador;
}

void menuProdutos(Produto *p_tabela, int *contador)
{
    int opcao;

    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Inserir Produto\n");
        printf("2. Mostrar Produtos\n");
        printf("3. Alterar Produtos\n");
        printf("4. Remover Produtos\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada após ler um número

        switch (opcao) 
        {
            case 1:
                adicionarProduto(p_tabela, contador);
                system("clear");
                break;
            case 2:
                mostrarProdutos(p_tabela, *contador);
                system("clear");
                break;
            case 3:
                alterarProdutos(p_tabela, *contador);
                system("clear");
                break;
            case 4:
                removerProdutos(p_tabela, contador);
                system("clear");
                break;
            case 5:
                printf("Saindo...\n");
                system("clear");
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void adicionarMesa(Mesa *m_tabela, int *contador)
{
    if (*contador >= MAX_MESAS) 
    {
        printf("Limite de mesas atingido!\n");
        return;
    }
    
    Mesa *f = &m_tabela[*contador];

    printf("Insira o numero da mesa: ");
    scanf("%d", &(f->n_Mesa));
    printf("Insira o numero de lugares da mesa: ");
    scanf("%d", &(f->n_Lugares));
    printf("Insira a localizacao da mesa: ");
    scanf("%24s", f->localizacao);
    printf("Insira a disponibilidade atual da mesa: ");
    scanf("%24s", f->m_disponibilidade); 

    // Inicializa a lista de pedidos como NULL
    f->pedidos = NULL;

    // Limpar o buffer 
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    system("clear");
    printf("\nPressione Enter para mostrar os dados da mesa inserida...\n");
    getchar(); // Espera que o utilizador pressione Enter

    printf("\n------------------Mesa adicionada:------------------\n");
    printf("Numero: %d\n", f->n_Mesa);
    printf("Numero de lugares: %d\n", f->n_Lugares);
    printf("Localizacao: %s\n", f->localizacao);
    printf("Disponibilidade: %s\n", f->m_disponibilidade);
    printf("\n-------------------------------------------------------------\n");

    (*contador)++;

    printf("\nPressione Enter para continuar...\n");
    getchar(); // Espera que o utilizador pressione Enter
}

void salvarMesas(Mesa *m_tabela, int contador) 
{
    FILE *file = fopen("mesas.dat", "wb");
    if (file == NULL) 
    {
        printf("Erro ao abrir arquivo para salvar mesas.\n");
        return;
    }
    fwrite(&contador, sizeof(int), 1, file);
    fwrite(m_tabela, sizeof(Mesa), contador, file);
    fclose(file);
}

int carregarMesas(Mesa *m_tabela)
{
    FILE *file = fopen("mesas.dat", "rb");
    if (file == NULL) 
    {
        printf("Erro ao abrir arquivo para carregar mesas.\n");
        return 0;
    }
    int contador;
    fread(&contador, sizeof(int), 1, file);
    fread(m_tabela, sizeof(Mesa), contador, file);
    fclose(file);
    return contador;
}

void mostrarMesas(Mesa *m_tabela, int contadorMesas) 
{
int mesaEscolhida;
    int mesaEncontrada = 0;

    printf("Selecione a mesa para ver os pedidos: ");
    scanf("%d", &mesaEscolhida);

    for (int i = 0; i < contadorMesas; i++) 
    {
        if (m_tabela[i].n_Mesa == mesaEscolhida) 
        {
            mesaEncontrada = 1;
            Mesa *mesaAtual = &m_tabela[i];
            Pedido *pedidoAtual = mesaAtual->pedidos;

            if (pedidoAtual == NULL) 
            {
                printf("Não há pedidos para a mesa %d.\n", mesaEscolhida);
                return;
            }

            printf("\nPedidos da Mesa %d:\n", mesaEscolhida);
            printf("-------------------------------------------------------------\n");
            
            while (pedidoAtual != NULL) 
            {
                printf("Pedido referente à Mesa: %d\n", pedidoAtual->n_Mesa);
                printf("Nome do Funcionário: %s\n", pedidoAtual->nomeFuncionario);
                printf("Total de Produtos: %d\n", pedidoAtual->contadorProdutos);
                printf("Total do Pedido: %.2f\n", pedidoAtual->total);

                ItemConta *itemAtual = pedidoAtual->produtos;
                while (itemAtual != NULL) 
                {
                    printf("  Produto:\n");
                    printf("    Nome: %s\n", itemAtual->nomeProduto);
                    printf("    Quantidade: %d\n", itemAtual->quantidade);
                    printf("    Preço: %.2f\n", itemAtual->preco);
                    itemAtual = itemAtual->proximo;
                }

                printf("-------------------------------------------------------------\n");
                pedidoAtual = pedidoAtual->proximo;
            }
        }
    }

    if (!mesaEncontrada) 
    {
        printf("Mesa %d não encontrada.\n", mesaEscolhida);
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("\n\nPressione Enter para continuar...\n");
    getchar(); // Espera que o utilizador pressione Enter
    system("clear");
}

void abrirConta(Mesa *m_tabela, int contadorMesas, Funcionario *f_tabela, int contadorFuncionarios, Produto *p_tabela, int contadorProdutos) 
{
    int mesaEscolhida = 0;
    int mesaEncontrada = 0;
    char funcionarioEscolhido[25];
    int funcionarioEncontrado = 0;

    printf("Selecione a mesa a ser aberta: ");
    scanf("%d", &mesaEscolhida);
    printf("Selecione o nome do funcionário responsável: ");
    scanf("%24s", funcionarioEscolhido);

    Mesa *mesa = NULL;

    // Verificar existência da mesa
    for (int i = 0; i < contadorMesas; i++) 
    {
        if (m_tabela[i].n_Mesa == mesaEscolhida) 
        {
            mesaEncontrada = 1;
            mesa = &m_tabela[i];
            break;
        }
    }

    // Verificar existência do funcionário
    for (int i = 0; i < contadorFuncionarios; i++) 
    {
        if (strcmp(f_tabela[i].nome, funcionarioEscolhido) == 0) 
        {
            funcionarioEncontrado = 1;
            break;
        }
    }

    // Feedback ao usuário
    if (mesaEncontrada && funcionarioEncontrado) 
    {
        if (strcmp(mesa->m_disponibilidade, "Ocupada") == 0) 
        {
            printf("A mesa %d já está ocupada.\n", mesaEscolhida);
            return;
        }

        printf("Mesa %d aberta com sucesso pelo funcionário %s.\n", mesaEscolhida, funcionarioEscolhido);

        strcpy(mesa->m_disponibilidade, "Ocupada"); // Define a mesa como ocupada

        // Criar novo pedido
        Pedido *novoPedido = (Pedido *)malloc(sizeof(Pedido));
        novoPedido->n_Mesa = mesaEscolhida;
        strcpy(novoPedido->nomeFuncionario, funcionarioEscolhido);
        novoPedido->produtos = NULL;
        novoPedido->contadorProdutos = 0;
        novoPedido->total = 0.0;
        novoPedido->proximo = mesa->pedidos;
        mesa->pedidos = novoPedido;

        while (1) 
        {
            char produtoConsumido[25];
            int quantidadeConsumida;
            float preco;
            int produtoEncontrado = 0;

            printf("Insira o produto consumido: ");
            scanf("%24s", produtoConsumido);
            printf("Insira a quantidade consumida: ");
            scanf("%d", &quantidadeConsumida);

            // Verificar existência do produto e quantidade
            for (int i = 0; i < contadorProdutos; i++) {
                if (strcmp(p_tabela[i].p_nome, produtoConsumido) == 0) 
                {
                    if (p_tabela[i].quantidade >= quantidadeConsumida) 
                    {
                        produtoEncontrado = 1;
                        preco = p_tabela[i].preco;
                        p_tabela[i].quantidade -= quantidadeConsumida; // Atualiza a quantidade no estoque
                        break;
                    } 
                    else 
                    {
                        printf("Quantidade insuficiente para o produto %s.\n", produtoConsumido);
                    }
                }
            }

            if (produtoEncontrado) 
            {
                printf("Produto %s encontrado, preço %.2f.\n", produtoConsumido, preco);
                
                // Criar novo item de conta
                ItemConta *novoItem = (ItemConta *)malloc(sizeof(ItemConta));
                strcpy(novoItem->nomeProduto, produtoConsumido);
                novoItem->preco = preco;
                novoItem->quantidade = quantidadeConsumida;
                novoItem->proximo = novoPedido->produtos;
                novoPedido->produtos = novoItem;

                novoPedido->total += preco * quantidadeConsumida;
                novoPedido->contadorProdutos++;
            } 
            else 
            {
                printf("Produto %s não encontrado.\n", produtoConsumido);
            }

            char resposta[3];
            printf("Pretende adicionar outro produto? (s/n): ");
            scanf("%2s", resposta);
            // Limpar o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}

            if (strcmp(resposta, "s") != 0 && strcmp(resposta, "S") != 0) 
            {
                break;
            }
        }

        printf("\nConta total para a mesa %d:\n", novoPedido->n_Mesa);
        ItemConta *item = novoPedido->produtos;
        while (item != NULL) 
        {
            printf("%s - %d unidade(s) - Preço unitário: %.2f\n", item->nomeProduto, item->quantidade, item->preco);
            item = item->proximo;
        }
        printf("Total: %.2f\n", novoPedido->total);
    } 
    else 
    {
        if (!mesaEncontrada) 
        {
            printf("Mesa %d não existente.\n", mesaEscolhida);
        }
        if (!funcionarioEncontrado) 
        {
            printf("Funcionário %s não existente.\n", funcionarioEscolhido);
        }
    }

    // Limpar o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("\nPressione Enter para continuar...\n");
    getchar(); // Espera que o utilizador pressione Enter
}

void atualizarPedidos(Mesa *m_tabela, int contadorMesas, Funcionario *f_tabela, int contadorFuncionarios, Produto *p_tabela, int contadorProdutos) 
{
    int mesaEscolhida = 0;
    int mesaEncontrada = 0;
    char funcionarioEscolhido[25];
    int funcionarioEncontrado = 0;

    printf("Selecione a mesa: ");
    scanf("%d", &mesaEscolhida);

    Mesa *mesa = NULL;

    // Verificar existência da mesa
    for (int i = 0; i < contadorMesas; i++) 
    {
        if (m_tabela[i].n_Mesa == mesaEscolhida) 
        {
            mesaEncontrada = 1;
            mesa = &m_tabela[i];
            break;
        }
    }

    // Feedback ao usuário
    if (mesaEncontrada) 
    {
        printf("Mesa encontrada.\n");

        printf("Selecione o nome do funcionário responsável: ");
        scanf("%24s", funcionarioEscolhido);

        // Verificar existência do funcionário
        for (int i = 0; i < contadorFuncionarios; i++) 
        {
            if (strcmp(f_tabela[i].nome, funcionarioEscolhido) == 0) 
            {
                funcionarioEncontrado = 1;
                break;
            }
        }

        if (funcionarioEncontrado) 
        {
            printf("Funcionário encontrado.\n");

            // Verificar se já existe um pedido para esta mesa
            Pedido *pedidoExistente = NULL;
            for (Pedido *p = mesa->pedidos; p != NULL; p = p->proximo) 
            {
                if (strcmp(p->nomeFuncionario, funcionarioEscolhido) == 0) 
                {
                    pedidoExistente = p;
                    break;
                }
            }

            if (pedidoExistente == NULL) 
            {
                printf("Criando novo pedido.\n");

                // Criar novo pedido
                Pedido *novoPedido = (Pedido *)malloc(sizeof(Pedido));
                novoPedido->n_Mesa = mesaEscolhida;
                strcpy(novoPedido->nomeFuncionario, funcionarioEscolhido);
                novoPedido->produtos = NULL;
                novoPedido->contadorProdutos = 0;
                novoPedido->total = 0.0;
                novoPedido->proximo = mesa->pedidos;
                mesa->pedidos = novoPedido;
                pedidoExistente = novoPedido;
            }

            while (1) 
            {
                char produtoConsumido[25];
                int quantidadeConsumida;
                float preco;
                int produtoEncontrado = 0;

                printf("Insira o produto consumido: ");
                scanf("%24s", produtoConsumido);
                printf("Insira a quantidade consumida: ");
                scanf("%d", &quantidadeConsumida);

                // Verificar existência do produto e quantidade
                for (int i = 0; i < contadorProdutos; i++) 
                {
                    if (strcmp(p_tabela[i].p_nome, produtoConsumido) == 0) 
                    {
                        if (p_tabela[i].quantidade >= quantidadeConsumida) 
                        {
                            produtoEncontrado = 1;
                            preco = p_tabela[i].preco;
                            p_tabela[i].quantidade -= quantidadeConsumida; // Atualiza a quantidade no estoque
                            break;
                        } 
                        else 
                        {
                            printf("Quantidade insuficiente para o produto %s.\n", produtoConsumido);
                        }
                    }
                }

                if (produtoEncontrado) 
                {
                    printf("Produto %s encontrado, preço %.2f.\n", produtoConsumido, preco);
                    
                    // Verificar se o produto já está na lista de itens do pedido
                    ItemConta *itemExistente = NULL;
                    for (ItemConta *item = pedidoExistente->produtos; item != NULL; item = item->proximo) 
                    {
                        if (strcmp(item->nomeProduto, produtoConsumido) == 0) 
                        {
                            itemExistente = item;
                            break;
                        }
                    }

                    if (itemExistente == NULL) 
                    {
                        // Criar novo item de conta
                        ItemConta *novoItem = (ItemConta *)malloc(sizeof(ItemConta));
                        strcpy(novoItem->nomeProduto, produtoConsumido);
                        novoItem->preco = preco;
                        novoItem->quantidade = quantidadeConsumida;
                        novoItem->proximo = pedidoExistente->produtos;
                        pedidoExistente->produtos = novoItem;
                        pedidoExistente->total += preco * quantidadeConsumida;
                        pedidoExistente->contadorProdutos++;
                    } 
                    else 
                    {
                        // Produto já existe no pedido, apenas atualize a quantidade e o total
                        itemExistente->quantidade += quantidadeConsumida;
                        pedidoExistente->total += preco * quantidadeConsumida;
                    }
                } 
                else 
                {
                    printf("Produto %s não encontrado.\n", produtoConsumido);
                }

                char resposta[3];
                printf("Pretende adicionar outro produto? (s/n): ");
                scanf("%2s", resposta);
                // Limpar o buffer de entrada
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {}

                if (strcmp(resposta, "s") != 0 && strcmp(resposta, "S") != 0) 
                {
                    break;
                }
            }

            printf("\nConta total para a mesa %d:\n", pedidoExistente->n_Mesa);
            ItemConta *item = pedidoExistente->produtos;
            while (item != NULL) 
            {
                printf("%s - %d unidade(s) - Preço unitário: %.2f\n", item->nomeProduto, item->quantidade, item->preco);
                item = item->proximo;
            }
            printf("Total: %.2f\n", pedidoExistente->total);
        } 
        else 
        {
            printf("Funcionário %s não encontrado.\n", funcionarioEscolhido);
        }
    } 
    else 
    {
        printf("Mesa %d não encontrada.\n", mesaEscolhida);
    }

    // Limpar o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("\nPressione Enter para continuar...\n");
    getchar(); // Espera que o utilizador pressione Enter
}

void pagarPedido(Mesa *m_tabela, int *contador) 
{
    int mesaEscolhida;
    int mesaEncontrada = 0;

    printf("Selecione a mesa para pagar o pedido: ");
    scanf("%d", &mesaEscolhida);

    // Encontrar a mesa correspondente na lista
    for (int i = 0; i < *contador; i++) 
    {
        if (m_tabela[i].n_Mesa == mesaEscolhida) 
        {
            mesaEncontrada = 1;
            Mesa *mesa = &m_tabela[i];
            
            // Define a mesa como livre após o pagamento
            strcpy(mesa->m_disponibilidade, "livre");
            
            // Remover o pedido associado à mesa
            Pedido *pedidoAtual = mesa->pedidos;
            mesa->pedidos = pedidoAtual->proximo; // Avançar para o próximo pedido
            break;
        }

    }

    if (mesaEncontrada) 
    {
        printf("Mesa %d encontrada.\n", mesaEscolhida);
        printf("O pagamento foi realizado com sucesso.\n");
    } 
    else 
    {
        printf("Mesa %d não encontrada.\n", mesaEscolhida);
    }
}

void menuMesas(Mesa *m_tabela, int *contador, Funcionario *f_tabela, int *contadorFuncionarios, Produto *p_tabela, int *contadorProdutos) 
{
    int opcao;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar Mesa\n");
        printf("2. Ver Mesas\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }

        switch (opcao) 
        {
            case 1:
                system("clear");
                adicionarMesa(m_tabela, contador);
                break;
            case 2:
                system("clear");
                mostrarMesas(m_tabela, *contador);
                break;
            case 3:
                printf("Saindo...\n");
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void encomendas(Encomenda *e_tabela, int *E_contador, Produto *p_tabela, int P_contador)
{
    if (*E_contador >= MAX_ENCOMENDAS) 
    {
        printf("Limite de encomendas atingido!\n");
        return;
    }
    
    Encomenda *encomenda = &e_tabela[*E_contador];

    // Limpar o buffer do teclado
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("Insira o produto a encomendar: ");
    fgets(encomenda->nome, sizeof(encomenda->nome), stdin);
    encomenda->nome[strcspn(encomenda->nome, "\n")] = '\0'; // Remover a quebra de linha do fgets

    printf("Insira a quantidade a encomendar: ");
    scanf("%d", &(encomenda->quantidade)); 

    // Limpar o buffer do teclado
    while ((c = getchar()) != '\n' && c != EOF) { }

    // Verificar se o produto existe e atualizar a quantidade disponível
    int produtoEncontrado = 0;
    for (int i = 0; i < P_contador; i++) 
    {
        if (strcmp(p_tabela[i].p_nome, encomenda->nome) == 0) 
        {
            if (p_tabela[i].quantidade >= encomenda->quantidade) 
            {
                p_tabela[i].quantidade -= encomenda->quantidade;
                produtoEncontrado = 1;
            } 
            else 
            {
                printf("Quantidade insuficiente do produto '%s'.\n", encomenda->nome);
                return;
            }
        }
    }

    if (!produtoEncontrado) 
    {
        printf("Produto '%s' não registrado no sistema.\n", encomenda->nome);
        return;
    }

    system("clear");
    printf("\nPressione Enter para mostrar os dados da encomenda inserida...\n");
    getchar(); // Espera que o utilizador pressione Enter

    printf("\n------------------Encomenda adicionada:------------------\n");
    printf("Nome: %s\n", encomenda->nome);
    printf("Quantidade: %d\n", encomenda->quantidade);
    printf("\n-------------------------------------------------------------\n");

    (*E_contador)++;

    printf("\nPressione Enter para continuar...\n");
    while ((c = getchar()) != '\n' && c != EOF) { }
    getchar(); // Espera que o utilizador pressione Enter
}


void escreverPedidosCSV(Mesa *m_tabela, int M_contador, Encomenda *e_tabela, int E_contador, Produto *p_tabela, int *P_contador) 
{
    char dia1[] = "dia1.csv";

    FILE *fp;
    fp = fopen(dia1, "w");

    if (fp == NULL) 
    {
        printf("Erro ao abrir o arquivo %s!\n", dia1);
        return;
    }

    fprintf(fp, "Mesa,Nome do Funcionario,Total de Produtos,Total do Pedido,Produtos\n");

    for (int i = 0; i < M_contador; i++) 
    {
        Mesa *mesaAtual = &m_tabela[i];
        Pedido *pedidoAtual = mesaAtual->pedidos;

        while (pedidoAtual != NULL) 
        {
            fprintf(fp, "%d,%s,%d,%.2f,", pedidoAtual->n_Mesa, pedidoAtual->nomeFuncionario, pedidoAtual->contadorProdutos, pedidoAtual->total);

            if (pedidoAtual->produtos != NULL) // Verifica se a lista de produtos não é nula
            {
                ItemConta *itemAtual = pedidoAtual->produtos;
                while (itemAtual != NULL) 
                {
                    // Verifica se há encomendas correspondentes ao produto atual
                    int produtoEncontrado = 0;
                    for (int j = 0; j < *P_contador; j++) 
                    {
                        if (strcmp(itemAtual->nomeProduto, p_tabela[j].p_nome) == 0) 
                        {
                            // Atualiza a quantidade de produtos no estoque
                            if (p_tabela[j].quantidade >= itemAtual->quantidade) 
                            {
                                p_tabela[j].quantidade -= itemAtual->quantidade;
                            } 
                            else 
                            {
                                printf("Quantidade insuficiente do produto '%s'.\n", itemAtual->nomeProduto);
                            }
                            produtoEncontrado = 1;
                            break;
                        }
                    }

                    // Se não houver produto correspondente, exibir mensagem e não fazer alterações
                    if (!produtoEncontrado) 
                    {
                        printf("Impossível encomendar o produto '%s' pois este não está registrado no sistema.\n", itemAtual->nomeProduto);
                    }

                    fprintf(fp, "%s(%d,%.2f),", itemAtual->nomeProduto, itemAtual->quantidade, itemAtual->preco);
                    itemAtual = itemAtual->proximo;
                }
            }

            fprintf(fp, "\n");
            pedidoAtual = pedidoAtual->proximo;
        }
    }

    fclose(fp);   

    // Limpar as listas após escrever os dados no arquivo CSV
    for (int i = 0; i < M_contador; i++)  
    {
        Mesa *mesa = &m_tabela[i];
        Pedido *pedido = mesa->pedidos;

        while (pedido != NULL) 
        {
            Pedido *proxPedido = pedido->proximo;
            ItemConta *item = pedido->produtos;
            
            while (item != NULL) 
            {
                ItemConta *proxItem = item->proximo;
                free(item);
                item = proxItem;
            }
            free(pedido);
            pedido = proxPedido;
        }
        // Definir os ponteiros como NULL para indicar listas vazias
        mesa->pedidos = NULL;
    }
}


void menuPrincipal(Mesa *m_tabela, int *M_contador, Funcionario *f_tabela, int *F_contador, Produto *p_tabela, int *P_contador, Encomenda *e_tabela, int *E_contador)
{
    int opcao;
    escreverPedidosCSV(m_tabela, *M_contador, e_tabela, *E_contador, p_tabela, P_contador);

    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Funcionários\n");
        printf("2. Produtos\n");
        printf("3. Mesas\n");
        printf("4. Encomendas\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        switch (opcao) 
        {
            case 1:
                system("clear"); 
                menuFuncionarios(f_tabela, F_contador);
                break;
            case 2:
                system("clear");
                menuProdutos(p_tabela, P_contador);
                break;
            case 3:
                system("clear");
                menuMesas(m_tabela, M_contador, f_tabela, F_contador, p_tabela, P_contador);
                break;
            case 4:
                system("clear");
                encomendas(e_tabela, E_contador, p_tabela, P_contador);
                break;
            case 5:
                printf("Saindo...\n");
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    }
}

void menuPrincipal2(Mesa *m_tabela, int *M_contador, Funcionario *f_tabela, int *F_contador, Produto *p_tabela, int *P_contador) 
{
    int opcao;

    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Realizar Pedido\n");
        printf("2. atualizar um pedido\n");
        printf("3. Pagar Pedido\n");
        printf("4. Ver Mesas\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        switch (opcao) 
        {
            case 1:
               system("clear");
               abrirConta(m_tabela, *M_contador, f_tabela, *F_contador, p_tabela, *P_contador);
                break;
            case 2:
                system("clear");
                atualizarPedidos(m_tabela, *M_contador, f_tabela, *F_contador, p_tabela, *P_contador);
                break;
            case 3:
                system("clear");
                pagarPedido(m_tabela, M_contador);
                break;
            case 5:
                printf("Saindo...\n");
                return;  
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

int main()
{
    int opcao;
    Encomenda e_tabela[MAX_ENCOMENDAS];
    Funcionario f_tabela[MAX_FUNCIONARIOS];
    Produto p_tabela[MAX_PRODUTOS];
    Mesa m_tabela[MAX_MESAS];
    int E_contador = 0;
    int M_contador = 0;
    int P_contador = 0;
    int F_contador = 0;

    // Carregar os dados dos arquivos binários
    P_contador = carregarProdutos(p_tabela);
    F_contador = carregarFuncionarios(f_tabela);
    M_contador = carregarMesas(m_tabela);

    while (1) 
    { 
        printf("\nMenu:\n");
        printf("1. Abrir dia\n");
        printf("2. Fechar dia\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        switch (opcao) 
        {
            case 1:
                system("clear");
                // Supondo que menuPrincipal2 existe e foi definido anteriormente
                menuPrincipal2(m_tabela, &M_contador, f_tabela, &F_contador, p_tabela, &P_contador);
                break;
            case 2:
                system("clear");
                // Supondo que menuPrincipal existe e foi definido anteriormente
                menuPrincipal(m_tabela, &M_contador, f_tabela, &F_contador, p_tabela, &P_contador, e_tabela, &E_contador);
                break;
            case 3:
                printf("Saindo...\n");
                // Salvar os dados nos arquivos binários
                salvarProdutos(p_tabela, P_contador);
                salvarFuncionarios(f_tabela, F_contador);
                salvarMesas(m_tabela, M_contador);
                // Escrever pedidos em CSV
                escreverPedidosCSV(m_tabela, M_contador, e_tabela, E_contador, p_tabela, &P_contador);
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

