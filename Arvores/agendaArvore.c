#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct agenda Agenda;

struct agenda {
    char name[50];
    int age;
    char number[20];
    Agenda *left;
    Agenda *right;
};

Agenda *create_tree(char fatorPrecedencia[]);
Agenda *insert(Agenda *root, char name[], int age, char number[], char fatorPrecedencia[]);
Agenda *removed(Agenda *root, char name[], int age, char number[], char fatorPrecedencia[]);
Agenda *search(Agenda *root, char name[], int age, char number[], char fatorPrecedencia[]);
void printPreOrder(Agenda *root);
void printCentral(Agenda *root);
void printPosOrder(Agenda *root);
void liberarAgenda(Agenda *root);

int main() {
    char fatorPrecedencia[10];
    Agenda *root = NULL;
    int opcao = -1;

    printf("Escolha o fator de precedencia (nome, idade, ou telefone) :");
    scanf("%s", fatorPrecedencia);

    root = create_tree(fatorPrecedencia);

    while (opcao != 0) {
        printf("\nEscolha uma opcao: \n");
        printf("\t1 - Inserir\n");
        printf("\t2 - Buscar\n");
        printf("\t3 - Remover\n");
        printf("\t4 - Imprimir em pre-ordem\n");
        printf("\t5 - Imprimir em ordem central\n");
        printf("\t6 - Imprimir em pos-ordem\n");
        printf("\t0 - Sair\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            char name[50], number[20];
            int age;

            system("clear || cls");

            printf("Digite o nome: ");
            scanf("%s", name);
            printf("Digite a idade: ");
            scanf("%i", &age);
            printf("Digite o telefone: ");
            scanf("%s", number);

            root = insert(root, name, age, number, fatorPrecedencia);

            printf("contact inserido com sucesso!\n");
            break;
        
        case 2:
            char name[50];

            printf("Digite o nome que deseja buscar: ");
            scanf("%s", name);

            Agenda *contact = search(root, name, age, number, fatorPrecedencia);

            if(contact != NULL) {
                printf("Nome: %s\n", contact->name);
                printf("Idade: %i\n", contact->age);
                printf("Telefone: %s\n", contact->number);
            } else {
                printf("Contato nao encontrado.\n");
            }
            break;

        case 3:
            char name[50];

            printf("Digite o nome a remover: ");
            scanf("%s", name);

            root = removed(root, name, age, number, fatorPrecedencia);

            printf("Contato removido com sucesso!\n");
            break;

        case 4:
            printf("Impressao em pre-ordem: \n");
            printPreOrder(root);
            printf("\n");
            break;

        case 5:
            printf("Impresao em ordem central: \n");
            printCentral(root);
            printf("\n");
            break;

        case 6:
            printf("Impressao em pos-ordem: \n");
            printPosOrder(root);
            printf("\n");
            break;

        case 0:
            freeAgenda(root);
            break;

        default:
            break;
        }
    }

    free(root);
    return 0;
}

Agenda *create_tree(char fatorPrecendencia[]) {
    return NULL;
}

Agenda *insert(Agenda *root, char name[], int age, char number[], char fatorPrecedencia[]) {
    Agenda *newContact;
    int cmp;

    if (root == NULL) {
        newContact = (Agenda *) malloc(sizeof(Agenda));

        strcpy(newContact->name, name);
        newContact->age = age;
        strcpy(newContact->number, number);

        newContact->left = NULL;
        newContact->right = NULL;

        return newContact;
    }

    if (strcmp(fatorPrecedencia, "nome") == 0) {
        cmp = strcmp(name, root->name);
    } else if (strcmp(fatorPrecedencia, "idade") == 0) {
        if(age < root->age) {
            cmp = -1;
        } else if(age > root->age){
            cmp = 1;
        } else {
            cmp = 0;
        }     
    } else if (strcmp(fatorPrecedencia, "telefone") == 0) {
        cmp = strcmp(number, root->number);
    } else {
        printf("Fator de precedencia invalido.\n");
        return root;
    }

    if (cmp < 0) {
        root->left =  insert(root->left, name, age, number, fatorPrecedencia);
    } else if (cmp > 0) {
        root->right =  insert(root->right, name, age, number, fatorPrecedencia);
    } else {
        printf("Contato ja existente.\n");
    }

    return root;
}

Agenda *removed(Agenda *root, char name[], int age, char number[], char fatorPrecedencia[]) {
    Agenda *tmp;
    int cmp;

    if (root == NULL) {
        printf("Contato nao encontrado.\n");
        return NULL;
    }

    if(strcmp(fatorPrecedencia, "nome") == 0) {
        cmp = strcmp(name, root->name);
    } else if (strcmp(fatorPrecedencia, "idade") == 0) {
        if(age < root->age) {
            cmp = -1;
        } else if ( age > root->age) {
            cmp = 1;
        } else {
            cmp = 0;
        }
    } else if (strcmp(fatorPrecedencia, "telefone") == 0) {
        cmp = strcmp(number, root->number);
    } else {
        printf("Fator de precedencia invalido.\n");
        return root;
    }

    if (cmp < 0) {
        root->left = removed(root->left, name, age, number, fatorPrecedencia);
    } else if (cmp > 0) {
        root->right = removed(root->right, name, age, number, fatorPrecedencia);
    } else {

        if(root->left == NULL) {
            tmp = root->right;
            free(tmp);
            return tmp;
        } else if (root->right == NULL) {
            tmp = root->left;
            free(root);
            return tmp;
        }

        tmp = root->right;
        while(tmp->left != NULL) {
            tmp = tmp->left;
        }

        strcpy(root->name, tmp->name);
        root->age = tmp->age;
        strcpy(root->number, tmp->number);

        root->right = removed(root->right, tmp->name, age, number, fatorPrecedencia);
    }
    return root;
}

Agenda *search(Agenda *root, char name[], int age, char number[], char fatorPrecedencia[]) {
    int cmp;
    if (root == NULL) {
        printf("Contato nao encontrado.\n");
        return NULL;
    }

    if(strcmp(fatorPrecedencia, "nome") == 0) {
        cmp = strcmp(name, root->name);
    } else if (strcmp(fatorPrecedencia, "idade") == 0) {
        if(age < root->age) {
            cmp = -1;
        } else if ( age > root->age) {
            cmp = 1;
        } else {
            cmp = 0;
        }
    } else if (strcmp(fatorPrecedencia, "telefone") == 0) {
        cmp = strcmp(number, root->number);
    } else {
        printf("Fator de precedencia invalido.\n");
        return root;
    }

    if (cmp == 0) {
        printf("%s - %d - %s\n", root->name, root->age, root->number);
        return root;
    } else if (cmp < 0) {
        return search(root->left, name, age, number, fatorPrecedencia);
    } else {
        return search(root->right, name, age, number, fatorPrecedencia);
    }
}

void printPreOrder(Agenda *root) {
    if (root != NULL) {
        printf("%s - %d - %s\n", root->name, root->age, root->number);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printCentral(Agenda *root) {
    if (root != NULL) {
        printCentral(root->left);
        printf("%s - %d - %s\n", root->name, root->age, root->number);
        printCentral(root->right);
    }
}

void printPosOrder(Agenda *root) {
    if (root != NULL) {
        printPosOrder(root->left);
        printPosOrder(root->right);
        printf("%s - %d - %s\n", root->name, root->age, root->number);
    }
}

void freeAgenda(Agenda *root) {
    if(root != NULL) {
        freeAgenda(root->left);
        freeAgenda(root->right);
        free(root);
    }
}