//NIM/Nama : 13518024/Jovan Karuna Cahyadi
//Tanggal  : 28 September 2019
//Topik    : ADT Queue
//Deskripsi: queue.c

#include "../queue.h"
int main(){
    Queue Q;
    int i, X;
    CreateEmptyQueue (&Q, 10);
    if(IsEmptyQueue(Q)) printf("Kosong\n");
    for(i=1; i<=10; i++){
        Add(&Q,i);
    }
    if(IsFullQueue(Q)) printf("Penuh\n");
    Del(&Q,&X);
    printf("Queue pertama %d\n", X);
    X = CountQueue(Q);
    printf("sisa di dalam Queue adalah %d\n", X);
    
    return 0;
}