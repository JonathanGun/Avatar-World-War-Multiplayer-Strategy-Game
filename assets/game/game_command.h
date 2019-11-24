#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include "../save/save.h"
#include "game_command_helper.h"

void get_next_command();
// I.S. sembarang
// F.S. command yang diinput user berjalan sesuai spek
void command_Start();
/* Fungsi yang digunakan untuk memulai(inisialisasi) game saat pemain memberi komando START */
void command_Load();
/* I.S. Player memilih komando LOAD
   F.S. player memilih slot data permainan yang pernah di-save */
void command_Attack();
/* I.S. Giliran player ke-X, player memilih komando attack
   F.S. player menyerang bangunan lawan dengan serangan sebesar jumlah pasukan, bangunan lawan bisa jatuh atau bisa tetap bertahan*/
void command_Level_up();
/* I.S. Player memilih komando LEVEL_UP
   F.S. Bila tidak ada bangunan yang bisa level up atau bangunan level maksimal semua, maka keluar pesan error,
   bila ada, akan ditampilkan daftar bangunan yang bisa level up dan player disuruh untuk memilih bangunan yang
   akan di level up. Lalu program melakukan level up ke bangunan tersebut
*/
void command_Skill();
/* I.S. Player memilih komando SKILL
   F.S. Menampilkan semua daftar skill yang ada, bila tidak ada keluar pesan error. Bila ada, player otomatis menggunakan skill yang didapatkan lebih awal */
void command_Undo();
/* I.S. Player memilih komando UNDO 
   F.S. Game tertunda satu turn sebelumnya */
void command_End_turn();
/* I.S. Player memilih komando END_TURN
   F.S. Game bergerak satu turn ke depan */
void command_Save();
/* I.S. Player memilih komando SAVE
   F.S. Player memilih slot yang ingin digunakan dan meng-input nama file save-an */
void command_Move();
/* I.S. Player memilih komando MOVE
   F.S. Player memilih bangunan yang ingin memindahkan troop. Bila tidak ada bangunan sekitar, akan keluar pesan error */
void command_Exit();
/* Keluar dari permainan saat player memilih EXIT */

#endif