#include "mesinconfig.h"

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point dimensi;
} Peta;

typedef struct {
    Point posisi;
    char C;
} Bangunan;

typedef struct {
    Bangunan bangunan[100];
} ListBangunan;

typedef struct {
    int Mat[100][100];
} Graph;

void extract_config(Peta *peta, int *banyak_bangunan, ListBangunan *list_bangunan, Graph *relasi);
// Mengekstrak informasi dalam "Config"

void extract_dimensi_peta(Peta *peta);
// Mengekstrak dimensi peta

void extract_banyak_bangunan(int *banyak_bangunan);
// Mengekstrak banyak bangunan

void extract_listBangunan(int banyak_bangunan, ListBangunan *list_bangunan);
// Mengekstrak list bangunan

void extract_relasi(int banyak_bangunan, Graph *relasi);
// Mengekstrak relasi


