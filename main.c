#include <stdio.h>
#include <stdlib.h>
#include "diccionario.h"

#define CHARSET "abc123"
#define MAXLEN 5
int main()
{
    tDic d1;
    if(!inicializarDic(&d1, CHARSET, MAXLEN)){
        printf("no se pudo inicializar el diccionario!");
        return -1;
    }

    mostrarDic(&d1);
    crearDiccionario("diccionario.txt", &d1);
    //if(!abrirArchivo(&dict,"diccionario.txt","wt"))
        //return -1;

    //calComb(dict,cad);
    borrarDiccionario(&d1);
    //fclose(dict);
    return 0;
}
