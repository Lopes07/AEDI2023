/*Lucas Lopes Silva - Turma M2 - Trabalho agenda*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNTER (sizeof(int))
#define OPTION (sizeof(int))
#define AUX_PPOINTER (sizeof(void **))

//Informações da Pessoa
#define NAME (sizeof(char) * 10)
#define AGE (sizeof(int))
#define TELEPHONE (sizeof(int))

//Informacoes da lista
#define FIRST (sizeof(int))
#define LAST (sizeof(int) + sizeof(void **))
#define NEXT (sizeof(char) * 10 + sizeof(int) + sizeof(int) + sizeof(void **))
#define PREVIOUS (sizeof(char) * 10 + sizeof(int) + sizeof(int))

void add(void *pBuffer, void *aux);
void removePerson(void *pBuffer, void *linkedList, void *sweep);
void search(void *aux, void *sweep);
void list(void *aux);
void quit(void *aux);

int main(){
    void *aux = malloc(COUNTER + AUX_PPOINTER + AUX_PPOINTER);

    *(int *)(aux) = 0;

    void *pBuffer = malloc(OPTION + AUX_PPOINTER);

    void *sweep = NULL;

    if (!pBuffer || !aux){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    printf("\n\nBem vindo!\n\n");
    do{
        printf("------------------------------------------------\n");
        printf("\tDigite a operacao que deseja realizar: \n");
        printf("\t1. Adicionar pessoa:\n");
        printf("\t2. Remover pessoa:\n");
        printf("\t3. Buscar pessoa:\n");
        printf("\t4. Listar:\n");
        printf("\t5. Sair :\n");
        printf("------------------------------------------------\n");
        scanf("%d", (int *)(pBuffer));
        getchar();
        printf("\n");

        switch (*(int *)(pBuffer)){
        case 1:
            system("clear || cls");
            add(pBuffer, aux);
            break;
        case 2:
            system("clear || cls");
            removePerson(pBuffer, aux, sweep);
            break;
        case 3:
            system("clear || cls");
            search(aux, sweep);
            break;
        case 4:
            system("clear || cls");
            list(aux);            
            break;
        case 5:
            system("clear || cls");
            quit(aux);
            free(pBuffer);
            free(aux);
            exit(0);
            break;
        default:
            printf("\nOpcao invalida, tente novamente!\n");
            break;
        }
    } while ((*(int *)(pBuffer) >= 1) || (*(int *)(pBuffer) <= 5));
}

void add(void *pBuffer, void *aux){
    int *counter = (int *)(aux);

    void *personInfo = malloc(NAME + AGE + TELEPHONE + AUX_PPOINTER + AUX_PPOINTER);

    void *personInfoAux = NULL;

    if (!personInfo){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    printf("\nOpcao 1 - Adicionar pessoa\n");

    printf("\nDigite o nome:\n ");
    scanf("%s", (char *)personInfo);
    getchar();

    printf("\nDigite a idade:\n ");
    scanf("%d", &*(int *)(personInfo + NAME));
    getchar();
   
    printf("\nDigite o telefone:\n ");
    scanf("%d", &*(int *)(personInfo + NAME + AGE));
    getchar();

    *(void **)(personInfo + NEXT) = NULL;   
    *(void **)(personInfo + PREVIOUS) = NULL;

    if (*counter == 0){
        *(void **)(aux + LAST) = personInfo;
        *(void **)(aux + FIRST) = personInfo;
        
        *counter += 1;

        return;
    }

    pBuffer = *(void **)(aux + FIRST);

    while(pBuffer != NULL){
        //verifica se a primeira letra vem antes da que ja esta armazenada
        if(strcmp((char *)personInfo, (char *)pBuffer) < 0){
            *(void **)(personInfo + PREVIOUS) = *(void **)(pBuffer + PREVIOUS);
            *(void **)(personInfo + NEXT) = pBuffer;

            //pessoa vai ser adicionada no inicio
            if(*counter > 1 && *(void **)(pBuffer + PREVIOUS) != NULL){
                personInfoAux = *(void **)(pBuffer + PREVIOUS);
                *(void **)(personInfoAux + NEXT) = personInfo;
            }

            *(void **)(pBuffer + PREVIOUS) = personInfo;

            if(*(void **)(personInfo + PREVIOUS) == NULL){
                *(void **)(aux + FIRST) = personInfo;
            }

            if(*counter == 1 && *(void **)(pBuffer + NEXT) == NULL){
                *(void **)(aux + LAST) = pBuffer;
            }

            *counter += 1; 

            return;
        }

        if(*(void **)(pBuffer + NEXT) == NULL){
            personInfoAux = pBuffer;
        }

        pBuffer = *(void **)(pBuffer + NEXT);
    }

    *(void **)(personInfo + PREVIOUS) = personInfoAux;
    *(void **)(personInfoAux + NEXT) = personInfo;
    *(void **)(aux + LAST) = personInfo;

    *counter += 1;

    return;
}

void removePerson(void *pBuffer, void *aux, void *sweep){
    int *counter = (int *)(aux);

    if (*counter == 0){
        printf("\nOpcao 2 - Remover pessoa\n");
        printf("\nA agenda esta vazia, insira algo e tente novamente\n");
    } else {
        printf("\nOpcao 2 - Remover nome\n\n");
        printf("\nO primeiro nome da lista foi removido.\n");
        sweep = *(void **)(aux + FIRST);
        *(void **)(aux + FIRST) = *(void **)(sweep + NEXT);
        free(sweep);
        *(void **)(pBuffer + PREVIOUS) = NULL;

        *counter -= 1;
    }
}

void search(void *aux, void *sweep){
    int *counter = (int *)(aux);

    void *auxSearch = malloc(NAME);

    sweep = *(void **)(aux + FIRST);

    if(*counter == 0){
        printf("\nOpcao 3 - Buscar pessoa\n");
        printf("\nA agenda esta vazia, insira algo e tente novamente\n\n");

        free(auxSearch);

        return;
    } else {
        printf("\nOpcao 3 - Buscar pessoa\n\n");

        printf("Digite o nome que queira buscar: \n");
        scanf("%s", (char *)auxSearch);
        getchar();

        while(sweep != NULL){
            if(strcmp(sweep ,(char *)auxSearch) == 0){
                printf("Nome: %s\n", (char *)sweep);
                printf("Idade: %d\n", *(int *)(sweep + NAME));
                printf("Numero: %d\n\n", *(int *)(sweep + NAME + AGE));

                free(auxSearch);
                
                return;
            }
            sweep = *(void **)(sweep + NEXT);
        }
    }

    free(auxSearch);

    return;
}


void list(void *aux){
    void *personInfo = *(void **)(aux + FIRST);

    int *counter = (int *)(aux); 

    if(*counter == 0){
        printf("\nOpcao 4 - Listar\n");
        printf("\nAgenda esta vazia, insira algo e tente novamente\n");
    } else {
        printf("\nOpcao 4 - Listar nomes\n\n");
        while(personInfo != NULL){
            printf("Nome: %s\n", (char *)personInfo);
            printf("Idade: %d\n", *(int *)(personInfo + NAME));
            printf("Numero: %d\n\n", *(int *)(personInfo + NAME + AGE));

            personInfo = *(void **)(personInfo + NEXT);
        }
    }
}


void quit(void *aux){
    void *pFree = *(void **)(aux + FIRST);
    int *counter = (int *)(aux);

    if (*counter == 0){
        printf("Lista vazia.");
    } else {
        while (*(void **)(aux + FIRST) != NULL) {
            pFree = *(void **)(aux + FIRST);
            *(void **)(aux + FIRST) = *(void **)(pFree + NEXT);
            free(pFree);

            *counter -= 1;
        }
    }
}