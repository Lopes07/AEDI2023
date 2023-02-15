#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarNome(char** nomes, int* tamanho, int* numNomes);
void removerNome(char** nomes, int* tamanho, int* numNomes);
void listarNomes(char* nomes);



int main() {
    char* nomes = NULL; // ponteiro para a string de nomes
    int tamanho = 0; // tamanho atual da string
    int numNomes = 0; // número de nomes armazenados
    
    int opcao;
    do {
       printf("------------------------\n");
        printf("\tEscolha uma opção: \n");
        printf("\t1)Adicionar pessoa \n");
        printf("\t2)Remover pessoa \n");
        printf("\t3)Listar \n");
        printf("\t4)Sair \n");
        printf("------------------------\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: // Adicionar nome
                adicionarNome(&nomes, &tamanho, &numNomes);
                break;
            case 2: // Remover nome
                removerNome(&nomes, &tamanho, &numNomes);
                break;
            case 3: // Listar
                listarNomes(&nomes);
                break;
            case 4: // Sair
                break;
        }
    } while (opcao != 4);
}

void adicionarNome(char** nomes, int* tamanho, int* numNomes) {
    char nome[100];
    printf("Digite um nome: ");
    scanf("%s", nome);
    int tamanho_nome = strlen(nome);
    if (*numNomes == 0) { // se a string estiver vazia, aloca o tamanho exato para o primeiro nome
        *tamanho = tamanho_nome + 1; // adiciona 1 para o caractere '\0'
        *nomes = (char*) malloc(sizeof(char) * (*tamanho));
    } else { // se a string não estiver vazia, realoca a memória para adicionar o novo nome
        *tamanho += tamanho_nome + 1; // adiciona 1 para o espaço entre nomes
        *nomes = (char*) realloc(*nomes, sizeof(char) * (*tamanho));
    }
    strcat(*nomes, nome);
    strcat(*nomes, " "); // adiciona um espaço após o nome
    (*numNomes)++;
    printf("Nome adicionado com sucesso!\n");
}

void removerNome(char** nomes, int* tamanho, int* numNomes) {
    if (*numNomes == 0) { // verifica se a string está vazia
        printf("Erro: nao ha nomes para remover!\n");
        return;
    }
    char nome_remover[100];
    printf("Digite o nome a ser removido: ");
    scanf("%s", nome_remover);
    char* posicao_nome = strstr(*nomes, nome_remover); // procura o nome na string
    if (posicao_nome == NULL) { // se o nome não foi encontrado, exibe mensagem de erro
        printf("Erro: nome nao encontrado!\n");
        return;
    }
    int tamanho_nome_remover = strlen(nome_remover);
    int posicao = posicao_nome - *nomes;
    if (posicao > 0) { // se o nome não é o primeiro da string, remove o espaço antes dele
        posicao--;
        tamanho_nome_remover++;
    }
    memmove((*nomes)+posicao, (*nomes)+posicao+tamanho_nome_remover+1, strlen(*nomes)-posicao-tamanho_nome_remover+1); // remove o nome da string
    *tamanho -= tamanho_nome_remover + 1; // atualiza o tamanho da string
    *nomes = (char*) realloc(*nomes, sizeof(char) * (*tamanho)); // realoca a memória para o novo tamanho
    (*numNomes)--;
    printf("Nome removido com sucesso!\n");
}

void listarNomes(char* nomes) {
    printf("Nomes armazenados: %s\n", nomes);
}


