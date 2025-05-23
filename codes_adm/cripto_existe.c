#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

#define CRIPTOMOEDA "criptomoedas.bin"

int cripto_existe(const char *nome) {
    FILE *fp = fopen(CRIPTOMOEDA, "rb");
    if (!fp) return 0;
    cripto temp;
    while (fread(&temp, sizeof(cripto), 1, fp)) {
        if (strcmp(temp.nome, nome) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}