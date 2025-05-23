#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

#define INV "investidores.bin"

int login_existe(const char *login) {
    FILE *fp = fopen(INV, "rb");
    if (!fp) return 0;
    usuario temp;
    while (fread(&temp, sizeof(usuario), 1, fp)) {
        if (strcmp(temp.login, login) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int senha_valida(const char *senha) {
    if (strlen(senha) > 4) return 0;
    for (int i = 0; senha[i]; i++) {
        if (senha[i] < '0' || senha[i] > '9') return 0;
    }
    return 1;
}
