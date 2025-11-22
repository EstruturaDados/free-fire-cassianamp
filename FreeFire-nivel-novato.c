// Código da Ilha – Edição Free Fire
// Nível: Novato

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da struct Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;


// Função para limpar o buffer do teclado após scanf()
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// Função para inserir item na mochila
void inserirItem(Item mochila[], int *qtdItens) {

    if (*qtdItens >= 10) {
        printf("\nA mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("\n--- Cadastro de Item ---\n");

    printf("Nome do item: ");
    fgets(mochila[*qtdItens].nome, 30, stdin);
    mochila[*qtdItens].nome[strcspn(mochila[*qtdItens].nome, "\n")] = '\0';

    printf("Tipo do item (arma, munição, cura, ferramenta...): ");
    fgets(mochila[*qtdItens].tipo, 20, stdin);
    mochila[*qtdItens].tipo[strcspn(mochila[*qtdItens].tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &mochila[*qtdItens].quantidade);
    limparBuffer(); // limpa ENTER do scanf

    printf("\nItem '%s' cadastrado com sucesso!\n", mochila[*qtdItens].nome);

    (*qtdItens)++;
}


// Função para remover item da mochila
void removerItem(Item mochila[], int *qtdItens) {

    if (*qtdItens == 0) {
        printf("\nA mochila está vazia. Não há itens para remover.\n");
        return;
    }

    char nomeRemover[30];
    int encontrado = -1;

    printf("\nDigite o nome do item que deseja remover: ");
    fgets(nomeRemover, 30, stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

    for (int i = 0; i < *qtdItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("\nO item '%s' não foi encontrado na mochila.\n", nomeRemover);
        return;
    }

    for (int i = encontrado; i < *qtdItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*qtdItens)--;

    printf("\nItem '%s' removido com sucesso!\n", nomeRemover);
}


// Função para buscar item na mochila
void buscarItem(Item mochila[], int qtdItens) {

    char nomeBuscado[30];
    int encontrado = 0;

    printf("\nDigite o nome do item a ser buscado: ");
    fgets(nomeBuscado, 30, stdin);
    nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';

    for (int i = 0; i < qtdItens; i++) {
        if (strcmp(mochila[i].nome, nomeBuscado) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nO item '%s' não foi encontrado na mochila.\n", nomeBuscado);
    }
}


// Função para listar os itens presentes na mochila
void listarItens(Item mochila[], int qtdItens) {
    if (qtdItens == 0) {
        printf("\nA mochila está vazia.\n");
        return;
    }

    printf("\n--- Itens na mochila (%d/10) ---\n", qtdItens);
    printf("------------------------------------------------------------\n");
    printf("%-20s | %-20s | %-20s\n", "NOME", "TIPO", "QUANTIDADE");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < qtdItens; i++) {
        printf("%-20s | %-20s | %-20d\n",
            mochila[i].nome,
            mochila[i].tipo,
            mochila[i].quantidade);
    }

    printf("------------------------------------------------------------\n");
}


// Função para pausar para não entrar o menu automaticamente
void pausar() {
    printf("\nPressione ENTER para voltar ao menu principal...");
    getchar();
}



// Função principal
int main() {

    Item mochila[10];
    int qtdItens = 0;
    int opcao;

    do {

        printf("===============================================\n");
        printf("   MOCHILA DE SOBREVIVÊNCIA - CÓDIGO DA ILHA\n");
        printf("===============================================\n");
        printf("Itens na Mochila: %d/10\n", qtdItens);

        printf("\n----- Menu de ação -----\n");
        printf("1. Adicionar um item\n");
        printf("2. Remover um item\n");
        printf("3. Buscar um item\n");
        printf("4. Listar todos os itens\n");
        printf("0. Sair\n");
        printf("-------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();  // limpa ENTER pendente do scanf

        switch (opcao) {

            case 1:
                inserirItem(mochila, &qtdItens);
                listarItens(mochila, qtdItens);
                pausar();
                break;

            case 2:
                removerItem(mochila, &qtdItens);
                listarItens(mochila, qtdItens);
                pausar();
                break;

            case 3:
                buscarItem(mochila, qtdItens);
                pausar();
                break;

            case 4:
                listarItens(mochila, qtdItens);
                pausar();
                break;

            case 0:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                pausar();
        }

    } while (opcao != 0);

    return 0;
}
