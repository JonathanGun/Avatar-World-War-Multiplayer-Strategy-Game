#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include "../util/util.h"
#include "../util/mesinfile.h"
#include "../bangunan/bangunan.h"
#include "../bangunan/arraydin_bangunan.h"
#include "../peta/peta.h"
#include "../graph/graph.h"

typedef struct {
    int conf_banyak_bangunan;
    Peta conf_peta;
    TabBangunan conf_list_bangunan;
    Graph conf_relasi;
} Config;

void extract_config(Config* conf);
// Mengekstrak informasi dalam "Config"

void extract_peta(Peta *peta);
// Mengekstrak dimensi peta

void extract_banyak_bangunan(int *banyak_bangunan);
// Mengekstrak banyak bangunan

void extract_listBangunan(int banyak_bangunan, TabBangunan* list_bangunan);
// Mengekstrak list bangunan

void extract_relasi(int banyak_bangunan, Graph* relasi);
// Mengekstrak relasi

#endif
