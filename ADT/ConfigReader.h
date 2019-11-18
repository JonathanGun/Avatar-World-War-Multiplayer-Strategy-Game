#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include "mesinconfig.h"
#include "point.h"
#include "matriks.h"

typedef struct {
    char TipeBangunan;
    Point PosisiBangunan;
} InfoBangunan;

typedef struct {
    Point DimensiPeta;
    int BanyakBangunan;
    InfoBangunan* ListInfoBangunan;
    Matriks MatriksRelasiBangunan;
} Config;

#define DimensiPeta(C) (C).DimensiPeta
#define BanyakBangunan(C) (C).BanyakBangunan
#define ListInfoBangunan(C) (C).ListInfoBangunan
#define MatriksRelasiBangunan(C) (C).MatriksRelasiBangunan 
#define GetInfoBangunan(C,i) (C).ListInfoBangunan[(i)]

extern Config BacaConfig;

void BacaDimensiPeta();

void BacaBanyakBangunan();

void BacaListInfoBangunan();

void BacaMatriksRelasiBangunan();

#endif