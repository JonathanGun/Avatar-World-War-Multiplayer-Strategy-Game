#include "ConfigReader.h"
#include <stdlib.h>
#include <stdio.h>

Config BacaConfig;

void BacaDimensiPeta()
{   
    STARTCONFIG(1);
    BacaConfig.DimensiPeta.x = CConfig.Bil;
    ADVKATACONFIG();
    BacaConfig.DimensiPeta.y = CConfig.Bil;
}

void BacaBanyakBangunan()
{
    STARTCONFIG(2);
    printf("%c\n",CC);
    BacaConfig.BanyakBangunan = CConfig.Bil;
}

void BacaListInfoBangunan()
{
    int i,x,y;
    ListInfoBangunan(BacaConfig) = (InfoBangunan*)malloc(sizeof(InfoBangunan)*(BanyakBangunan(BacaConfig)+1));

    for ( i = 1; i <= BanyakBangunan(BacaConfig); i++ ) {
        STARTCONFIG(i + 2);
        GetInfoBangunan(BacaConfig,i).TipeBangunan = CConfig.Val;

        ADVKATACONFIG();
        x = CConfig.Bil;
        ADVKATACONFIG();
        y = CConfig.Bil;

        GetInfoBangunan(BacaConfig,i).PosisiBangunan = MakePoint(x,y);
    }
}

void BacaMatriksRelasiBangunan()
{
    int N = BanyakBangunan(BacaConfig);
    MakeMatriks(N,N,&MatriksRelasiBangunan(BacaConfig));

    int i,j;
    for ( i = 1; i <= N; i++ ) {
        STARTCONFIG(i+2+N);
        for ( j = 1; j <= N; j++ ) {
            MatElmt(MatriksRelasiBangunan(BacaConfig),i,j) = CConfig.Bil;
            ADVKATACONFIG();
        }
    }
}