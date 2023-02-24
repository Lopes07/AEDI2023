//Lucas Lopes Silva - Turma M2 
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int degraus;

    do{
        printf("Informe quantos degraus deseja subir:\n(Escolha um numero entre 1 e 45)\n");
        scanf("%d", &degraus);
    } while( degraus < 1 || degraus > 45 );
    

    printf("Com %d degraus voce tem %d maneiras distintas de subir.\n", degraus, climbingStairs( degraus ));
    return 0;
}

int climbingStairs(int n){
    /*Pn = P(n-1) + P(n-2)*/
    if (n == 1 || n == 2){
        return n;
    } else {
        return climbingStairs( n-1 ) + climbingStairs( n-2 );
    }

}
