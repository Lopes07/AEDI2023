/*Lucas Lopes Silva - Turma M2*/
#include <stdio.h>
#include <string.h>

int minOperations(char ** logs, int logSize);

int main(int argc, char const *argv[]){
    /*Teste de todos os logs dados no PDF do trabalho*/

    //Primeiro teste
    char * logs[5] = {"d1/","d2/","../","d21/","./"};
    int logSize = 5;

    int count = minOperations(logs, logSize);

    printf("Saida do primeiro log: %d \n", count);

    //Segundo teste
    char * logs2[6] = {"d1/","d2/","./","d3/","../","d31/"};
    int logSize2 = 6;

    int count2 = minOperations(logs2, logSize2);

    printf("Saida do segundo log: %d \n", count2);

    //Terceiro teste
    char * logs3[4] = {"d1/","../","../","../"};
    int logSize3 = 4;
    
    int count3 = minOperations(logs3, logSize3);

    printf("Saida do terceiro log: %d \n", count3);

    return 0;
}

int minOperations(char ** logs, int logSize) {
    int count = 0;

    for (int i = 0; i <logSize; i++) {
        if (strcmp (logs[i],"../") == 0){
            if (count > 0) {
                //Como o comando "../" volta pra pasta pai da atual, volta uma pasta, logo o contador tem que diminuir
                count--; 
            }
        } else {
            if (strcmp(logs[i], "./") != 0) {
                 //O único comando que faz ficar na mesma pasta é o "./", então se for diferente muda de pasta, aumentando o contador
                count++;
            }
        }
    }
    return count;
}