/*Fac¸a um programa que leia numeros do teclado e os armazene em um vetor alocado ´
dinamicamente. O usuario ir ´ a digitar uma sequ ´ encia de n ˆ umeros, sem limite de quan- ´
tidade. Os numeros ser ´ ao digitados um a um e, sendo que caso ele deseje encerrar a ˜
entrada de dados, ele ira digitar o numero ZERO. Os dados devem ser armazenados na ´
memoria deste modo ´
• Inicie com um vetor de tamanho 10 alocado dinamicamente;
• Apos, caso o vetor alocado esteja cheio, aloque um novo vetor do tamanho do vetor ´
anterior adicionado espac¸o para mais 10 valores (tamanho N+10, onde N inicia com
10);
• Copie os valores ja digitados da ´ area inicial para esta ´ area maior e libere a mem ´ oria ´
da area inicial; ´
• Repita este procedimento de expandir dinamicamente com mais 10 valores o vetor
alocado cada vez que o mesmo estiver cheio. Assim o vetor ira ser ’expandido’ de ´
10 em 10 valores.
Ao final, exiba o vetor lido. Nao use a func¸ ˜ ao REALLOC. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int *vetor,valor, indice = 0, indiceParcial = 0;

    vetor = (int *) malloc(10 * sizeof(int));
    
    do{
        printf("Escreva o valor que deseja armazenar: \n");
        scanf("%i", &valor);

        vetor[indice++] = valor;

        if (indiceParcial++ == 9){
            int *vetorAux;
            vetorAux = (int *) malloc((indice + 10) *sizeof(int));
            memcpy(vetorAux, vetor, indice * sizeof(int));

            free(vetor);
            vetor = vetorAux;
            indiceParcial = 0;
        }
    } while(valor != 0);

    system("clear||cls");
    for(int i = 0; i < indice; i++){
        printf("\n%d\n", vetor[i]);
    }

    free(vetor);

    return 0;
}
