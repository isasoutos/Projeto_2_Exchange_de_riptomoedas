#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>
#include <time.h>

void atual_datahora(char *destino, int tamanho) { 
    time_t agora;
    struct tm *info_tempo;
    time(&agora);
    info_tempo = localtime(&agora);
    strftime(destino, tamanho, "%d/%m/%Y %H:%M:%S", info_tempo);
}