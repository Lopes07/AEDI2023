#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME (sizeof(char ) * 10)
#define IDADE (sizeof(int))
#define TELEFONE (sizeof(int))
#define NNOMES (sizeof(int))

void *adicionaPessoa(void *pBuffer);
void *removePessoa(void *pBuffer);
void buscaPessoa(void *pBuffer);
void listaPessoa(void *pBuffer);

int main(){
    int *opcao;
    opcao = malloc(sizeof(int));

    void *pBuffer = malloc(NNOMES);

    if (pBuffer == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    do{
        printf("------------------------\n");
        printf("\tEscolha uma opção: \n");
        printf("\t1)Adicionar pessoa \n");
        printf("\t2)Remover pessoa \n");
        printf("\t3)Buscar pessoa \n");
        printf("\t4)Listar \n");
        printf("\t5)Sair \n");
        printf("------------------------\n");
        scanf("%i", &opcao);

        switch (*opcao)
        {
        case 1:
            pBuffer = adicionaPessoa(pBuffer);
            break;
        case 2:
            removePessoa(pBuffer);
            break;
        case 3:
            buscaPessoa(pBuffer);
            break;
        case 4:
            listaPessoa(pBuffer);
            break;
        
        case 5:
            free(pBuffer);
            exit(0);
        
        default:
            printf("Digite um numero valido!");
            break;
        }

    } while (*(int*)opcao != 5);
}

/*
 *Essa função tem como objetivo adicionar os dados de uma pessoa e alocar o espaço
 *no buffer pBuffer.
 */

void *adicionaPessoa(void *pBuffer){
    pBuffer = realloc(pBuffer, NNOMES + (NOME + IDADE + TELEFONE) * (*(int *)pBuffer + 1));

    
    if (pBuffer == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    printf("Declare os dados que deseja armazenar: \n");
    printf("Nome: \n");
    scanf("%s", (char *)pBuffer,  NNOMES + (NOME + IDADE + TELEFONE) * (*(int *)pBuffer));
    getchar();

    printf("Idade: \n");
    scanf("%i", (int *)pBuffer,  NNOMES + NOME + (NOME + IDADE + TELEFONE) * (*(int *)pBuffer));
    getchar();

    printf("Telefone: \n");
    scanf("%i", (int *)(pBuffer,  NNOMES + NOME + IDADE +(NOME + IDADE + TELEFONE) * (*(int *)pBuffer)));
    getchar();
    
    *(int *)(pBuffer) += 1;

    return pBuffer;
    }

/*
 *Essa função tem como objetivo remover uma pessoa da agenda e realocar o espaco
 *no buffer pBuffer.
 */

void *removePessoa(void *pBuffer){
    char *nomeAux = malloc(NOME);

    if(*(int *)pBuffer == 0){
        printf("Agenda vázia, insira algo. \n");
    } else {
        printf("Declare o nome que deseja remover: ");
        scanf("%s", nomeAux);
        getchar();

        for(int i = 0; i <*(int *)pBuffer; i++){
            if(strcmp((char *)pBuffer,  NNOMES + (NOME + IDADE + TELEFONE) * i), nomeAux == 0){
                for(int j = i; j < *(int *)pBuffer; j++){
                    strcpy((char *)pBuffer + NNOMES + ((NOME + IDADE + TELEFONE) * j), (char *)pBuffer + NNOMES + ((NOME + IDADE + TELEFONE) * (j + 1)));
                    *(int *)(pBuffer + NNOMES + NOME + ((NOME + IDADE + TELEFONE) * j)) = *(int *)(pBuffer + NNOMES + NOME + (NOME + IDADE + TELEFONE) * (j + 1));
                    *(int *)(pBuffer + NNOMES + NOME + IDADE + ((NOME + IDADE + TELEFONE * j))) = *(int *)(pBuffer + NNOMES + NOME + IDADE + (NOME + IDADE + TELEFONE) * (j + 1));
                }

                *(int *)pBuffer -= 1;
                pBuffer =  realloc(pBuffer, NNOMES + (NOME + IDADE + TELEFONE) * (*(int *)pBuffer - 1));
                return pBuffer;
            } else {
                printf("Nome nao encontrado. \n");
            }
        }
    }
    free(nomeAux);

    return pBuffer;
}

/*
 *Essa função tem como objetivo buscar um nome dado pelo usuário na agenda
 *no buffer pBuffer.
 */

void buscaPessoa(void *pBuffer){
    char *nomeAux = malloc(NOME);

    printf("Declare o nome que deseja pesquisar: ");
    scanf("%s", nomeAux);
    getchar();

    for(int i = 0; i < *(int *)pBuffer; i++){
        if(strcmp((char *)pBuffer,  NNOMES + (NOME + IDADE + TELEFONE) * i), nomeAux == 0){
            printf("\nNome: %s\n", (char *)pBuffer,  NNOMES + (NOME + IDADE + TELEFONE) * i);
            printf("Idade: %i\n", (int *)pBuffer,  NNOMES + NOME +(NOME + IDADE + TELEFONE) * i);
            printf("Telefone: %i\n", (int *)pBuffer,  NNOMES + NOME + IDADE +(NOME + IDADE + TELEFONE) * i );
            return;
        } else {
            printf("Nome nao encontrado.\n");
        }
    }
    free(nomeAux);

    return;
}

/*
 *Essa função tem como objetivo imprimir os dados
 *do buffer pBuffer.
 */
void listaPessoa(void *pBuffer){
    if(*(int *)pBuffer == 0){
        printf("Agenda vázia, insira algo. \n");
    } else {
        for(int i = 0; i < *(int *)pBuffer; i++){
            printf("Pessoa [%i]\n", i + 1);
            printf("Nome: %s",  (char *)pBuffer,  NNOMES + (NOME + IDADE + TELEFONE) * i);
            printf("Idade: %i\n", (int *)pBuffer,  NNOMES + NOME +(NOME + IDADE + TELEFONE) * i);
            printf("Telefone: %i\n", (int *)pBuffer,  NNOMES + NOME + IDADE +(NOME + IDADE + TELEFONE) * i );
        }
    }
}