#include "diccionario.h"
int poseeRep(const char* cad){
    const char* ini = cad;
    const char* fin = cad;
    while(*fin){
        while(ini < fin){
            if(*ini == *fin)
                return 1;
            ini++;
        }
        ini = cad;
        fin++;
    }
    return 0;
}
char carSig(char bus, char* pLang){
    while(*pLang != bus)
        pLang++;
    pLang++;
    return *pLang;
}
void crearDiccionario(const char* arch, tDic* dic){
    FILE* fDic;
    abrirArchivo(&fDic, arch, "wt");
    char* pCad = dic->cad;
    char* pLang = dic->lang;

    do{
        //pLang = dic->lang;
        while(*pLang){
            fprintf(fDic, "%s\n",pCad);
            pLang++;
            *pCad = *pLang;
        }
        pLang = dic->lang;
    }while(recorrerRec(pCad, pLang));

    fclose(fDic);
}
int recorrerRec(char* pCad, char* pLang){
    *pCad = *pLang;
    pCad++;

    if(*pCad){
        //plang no se puede ir al sig por si mismo
        //osea no funciona plang++ por alguna razon
        *pCad = carSig(*pCad, pLang);
        if(!*pCad)
            return recorrerRec(pCad, pLang);
    }else
        return 0;
    return 1;
}
int inicializarDic(tDic* dic, const char* lang, unsigned tam){
    if(poseeRep(lang))
        return 0;
    dic->cad = (char*)malloc(sizeof(char)*tam + 1);
    if(dic->cad == NULL)
        return 0;
    char* pCad = dic->cad;
    dic->tam = tam;
    unsigned i;

    strcpy(dic->lang, lang);
    for(i = 0;i < tam;i++){
        *pCad = *lang;
        pCad++;
    }
    *pCad = '\0';
    return 1;
}

void mostrarDic(const tDic* dic){
    printf("lenguaje: %s\n",dic->lang);
    printf("tamanio: %u\n",dic->tam);
    printf("cadenaInicial: %s\n", dic->cad);
}
void borrarDiccionario(tDic* dic){
    free(dic->cad);
}
int abrirArchivo(FILE **fp, const char *archivo, const char *apertura){
    *fp =fopen(archivo,apertura);
    if(!*fp){
        fprintf(stderr, "\nError al abrir/crear el archivo %s en modo %s.",
                                                    archivo,apertura);
        exit(0);
    }
    return 1;
}
