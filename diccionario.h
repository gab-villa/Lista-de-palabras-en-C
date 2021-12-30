#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    unsigned tam;
    char* lang, *cad;
}tDic;
int poseeRep(const char* cad);
int recorrerRec(char* pCad, char* pLang);
void mostrarDic(const tDic* dic);
int inicializarDic(tDic* dic, const char* lang, unsigned tam);
void crearDiccionario(const char* arch, tDic* dic);
void borrarDiccionario(tDic* dic);
int abrirArchivo(FILE **fp, const char *archivo, const char *apertura);
#endif // DICCIONARIO_H_INCLUDED
