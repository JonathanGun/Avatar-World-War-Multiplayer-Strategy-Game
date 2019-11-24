#include "gui.h"

void read_file_color(char const* filename){
    START(filename);
    int cekblue = 0;
    int cekgreen = 0;
    int cekyellow = 0;
    int cekorange = 0;
    int cekred = 0;
    int cekcyan = 0;
    while(!EOP){
        if(CC == '^' && cekyellow == 0){
            cekyellow = 1;
            yellow();
        } else if(CC == '^' && cekyellow == 1){
            cekyellow = 0;
            normal();
        } else if(CC == '*' && cekblue == 0){
            cekblue = 1;
            blue();
        } else if(CC == '*' && cekblue == 1){
            cekblue = 0;
            normal();
        } else if(CC == '{' && cekgreen == 0){
            cekgreen = 1;
            green();
        } else if(CC == '{' && cekgreen == 1){
            cekgreen = 0;
            normal();
        } else if(CC == '&' && cekorange == 0){
            cekorange = 1;
            orange();
        } else if(CC == '&' && cekorange == 1){
            cekorange = 0;
            normal();
        } else if(CC == '%' && cekred == 0){
            cekred = 1;
            red();
        } else if(CC == '%' && cekred == 1){
            cekred = 0;
            normal();
        } else if(CC == '#' && cekcyan == 0){
            cekcyan = 1;
            cyan();
        } else if(CC == '#' && cekcyan == 1){
            cekcyan = 0;
            normal();
        } else {
            printf("%c",CC);
        }
        ADV();
    }
    normal();
    CC = ' ';
}

void gui_logo(){
    read_file_color("resources/logo.txt");
}

void show_valid_command(){
    read_file_color("resources/show_command.txt");
}
void map_description(){
    read_file_color("resources/map_description.txt");
}
void map_title(){
    green();printf("   ===============================================================");
    printf("\n   ║                             ");yellow();printf("PETA");green();printf("                            ║\n");
    printf("   ===============================================================");normal();
}