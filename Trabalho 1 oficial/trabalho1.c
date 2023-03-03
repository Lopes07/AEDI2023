//Lucas Lopes Silva -  Turma: M2
#include <stdio.h>
#include <stdlib.h>

int converterHorario(char* horarioEvento){
    int hora = 0, min = 0, horarioConvertido;

    hora = ( horarioEvento[0] * 10 )  + horarioEvento[1] ;
    min = ( horarioEvento[2] * 10 )  + horarioEvento[3] ;

    horarioConvertido = hora*60 + min;
    
    return horarioConvertido;
}

bool haveConflict(char** evento1, int evento1Tamanho, char** evento2, int evento2Tamanho){
    if(evento1Tamanho != 2 || evento2Tamanho != 2){
        return 1;
    }
    
    int comeco1, final1, comeco2, final2;
    
    comeco1 = converterHorario( evento1[0] );
    final1 = converterHorario( evento1[1] );
    comeco2 = converterHorario( evento2[0] );
    final2 =  converterHorario( evento2[1] );

    if ( comeco2 > final1 || comeco1 > final2 ){
        return false;
    } else {
        return true;
    }
}