#ifndef SAVE_H
#define SAVE_H

#include "../util/config_reader.h"
#include "../game/game_condition.h"

extern SaveData Save_data;

void UpdateSavedGame(int NthData, Kata savename);
// Melakukan update pada Save_data setelah melakukan save
void SaveGame(int NthData, Kata savename);
// Menyimpan data pada slot ke-NthData dengan savename "savename"
void PrintSaveInfo();
// Menampilkan data yang tersimpan
void CheckSaveFile();
// Membaca seluruh file penyimpanan
// data ke-i bernilai true jika file save<i>.txt tidak kosong
void LoadSavedGame();
// Membaca keseluruhan data dan menyimpannya ke dalam Save_data


#endif