#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

#define print(a)      printf("%d\n", a)
#define ENDL          printf("\n")

#define fori(T, i)    for(IdxType i = GetFirstIdx(T);   i <= GetLastIdx(T);    ++i)
#define fori1(T, i)   for(IdxType i = GetFirstIdx(T)+1; i <= GetLastIdx(T);    ++i)
#define forii(T, i)   for(IdxType i = GetLastIdx(T);    i >= GetFirstIdx(T);   --i)
#define forii1(T, i)  for(IdxType i = GetLastIdx(T);    i >= GetFirstIdx(T)+1; --i)

TabInt InverseTab (TabInt T){
  TabInt T2; MakeEmptyArray(&T2, MaxElement(T)); CopyTab(T, &T2);
  fori(T2, i) Elmt(T2, GetFirstIdx(T2)+NbElmt(T2)-i) = Elmt(T,i);
  return T2;
}

void DelEli (TabInt * T, IdxType i, ElType * X){
  *X = Elmt(*T,Neff(*T)--);
  for(int ii = i; ii <= GetLastIdx(*T); ++ii) Elmt(*T,ii) = Elmt(*T,ii+1);
}

ElType Head(TabInt T)   {return Elmt(T, GetFirstIdx(T));}
TabInt Tail(TabInt T){
  int tmp = 0;
  TabInt newT; MakeEmptyArray(&newT, NbElmt(T));
  CopyTab(T, &newT);
  DelEli(&newT, 1, &tmp);
  return newT;
}

int NbElmt(TabInt T)                      {return Neff(T);}
int MaxElement(TabInt T)                  {return MaxEl(T);}
IdxType GetFirstIdx(TabInt T)             {return IdxMin;}
IdxType GetLastIdx(TabInt T)              {return NbElmt(T);}
boolean IsIdxValid(TabInt T, IdxType i)   {return ((GetFirstIdx(T) <= i) && (i <= MaxElement(T)));}
boolean IsIdxEff(TabInt T, IdxType i)     {return ((GetFirstIdx(T) <= i) && (i <= GetLastIdx(T)));}
boolean IsEmptyArray(TabInt T)                 {return (!NbElmt(T));}
boolean IsFull(TabInt T)                  {return (NbElmt(T) == MaxElement(T));}

void MakeEmptyArray(TabInt *T, int maxel){
  MaxEl(*T) = maxel; Neff(*T) = 0;
  TI(*T) = (ElType *) malloc (sizeof(int) * (maxel+1));
}

void Dealokasi(TabInt *T){
  MaxEl(*T) = 0; Neff(*T) = 0;
  free(TI(*T)); 
}
void TulisIsiTab(TabInt T){
  printf("[");
  fori(T, i)
    if (i != GetLastIdx(T)) printf("%d,",Elmt(T, i));
    else (printf("%d",Elmt(T, i)));
  printf("]");
}

boolean SearchB(TabInt T, ElType X) {return IsEmptyArray(T)?0: ((Head(T) == X) || SearchB(Tail(T), X));}

void CopyTab(TabInt Tin, TabInt *Tout){
  MakeEmptyArray(Tout, NbElmt(Tin));
  Neff(*Tout) = NbElmt(Tin);
  fori(Tin,i) Elmt(*Tout,i) = Elmt(Tin,i);
}

void AddAsLastEl(TabInt *T, ElType X) {Elmt(*T,++Neff(*T)) = X;}
void DelLastEl(TabInt *T, ElType *X) {DelEli(T,NbElmt(*T),X);}