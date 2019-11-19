// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 12 September 2019
// Topik/Deskripsi  : Array Din/array dan din dun dun

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {ElType tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define charput(a)    scanf("%c", &a)
#define floatput(a)   scanf("%f", &a)
#define print(a)      printf("%d\n", a)
#define ENDL          printf("\n")

#define fori(T, i)    for(IdxType i = GetFirstIdx(T);   i <= GetLastIdx(T);    ++i)
#define fori1(T, i)   for(IdxType i = GetFirstIdx(T)+1; i <= GetLastIdx(T);    ++i)
#define forii(T, i)   for(IdxType i = GetLastIdx(T);    i >= GetFirstIdx(T);   --i)
#define forii1(T, i)  for(IdxType i = GetLastIdx(T);    i >= GetFirstIdx(T)+1; --i)

TabInt InverseTab (TabInt T){
  TabInt T2; MakeEmpty(&T2, MaxElement(T)); CopyTab(T, &T2);
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
  TabInt newT; MakeEmpty(&newT, NbElmt(T));
  CopyTab(T, &newT);
  DelEli(&newT, 1, &tmp);
  return newT;
}

ElType ValMax(TabInt T) {return (NbElmt(T) == 1)?Head(T): max(Head(T), ValMax(Tail(T)));}
ElType ValMin(TabInt T) {return (NbElmt(T) == 1)?Head(T): min(Head(T), ValMin(Tail(T)));}

int NbElmt(TabInt T)                      {return Neff(T);}
int MaxElement(TabInt T)                  {return MaxEl(T);}
IdxType GetFirstIdx(TabInt T)             {return IdxMin;}
IdxType GetLastIdx(TabInt T)              {return NbElmt(T);}
boolean IsIdxValid(TabInt T, IdxType i)   {return ((GetFirstIdx(T) <= i) && (i <= MaxElement(T)));}
boolean IsIdxEff(TabInt T, IdxType i)     {return ((GetFirstIdx(T) <= i) && (i <= GetLastIdx(T)));}
boolean IsEmpty(TabInt T)                 {return (!NbElmt(T));}
boolean IsFull(TabInt T)                  {return (NbElmt(T) == MaxElement(T));}

void MakeEmpty(TabInt *T, int maxel){
  MaxEl(*T) = maxel; Neff(*T) = 0;
  TI(*T) = (ElType *) malloc (sizeof(int) * (maxel+1));
}

void Dealokasi(TabInt *T){
  MaxEl(*T) = 0; Neff(*T) = 0;
  free(TI(*T)); 
}

void BacaIsi(TabInt *T){
  int n;
  do intput(n); while ((n < 0) || (n > MaxElement(*T)));

  if (n){
    Neff(*T) = n;
    ElType tmp;
    fori(*T, i){
      intput(tmp);
      Elmt(*T, i) = tmp;
    }
  }
  else MakeEmpty(T, 0);
}

void TulisIsiTab(TabInt T){
  printf("[");
  fori(T, i)
    if (i != GetLastIdx(T)) printf("%d,",Elmt(T, i));
    else (printf("%d",Elmt(T, i)));
  printf("]");
}


TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
  TabInt T3; MakeEmpty(&T3, NbElmt(T1));
  Neff(T3) = NbElmt(T1);
  fori(T3, i)
    if (plus) Elmt(T3,i) = Elmt(T1,i) + Elmt(T2,i);
    else Elmt(T3,i) = Elmt(T1,i) - Elmt(T2,i);
  return T3;
}


boolean IsEQ(TabInt T1, TabInt T2)  {return (IsEmpty(T1) && IsEmpty(T2))?1:((Neff(T1) == Neff(T2)) && (Head(T1) == Head(T2)) && IsEQ(Tail(T1), Tail(T2)));}
IdxType Search1(TabInt T, ElType X){
  // if (IsEmpty(T)) return IdxUndef;
  // if (Head(T) == X) return 1;
  // IdxType idx = Search1(Tail(T),X);
  // if (idx != IdxUndef) return 1+idx;
  // return IdxUndef;
}

boolean SearchB(TabInt T, ElType X) {return IsEmpty(T)?0: ((Head(T) == X) || SearchB(Tail(T), X));}
void MaxMin(TabInt T, ElType *Max, ElType *Min){
  *Max = ValMax(T);
  *Min = ValMin(T);
}

void CopyTab(TabInt Tin, TabInt *Tout){
  MakeEmpty(Tout, NbElmt(Tin));
  Neff(*Tout) = NbElmt(Tin);
  fori(Tin,i) Elmt(*Tout,i) = Elmt(Tin,i);
}

ElType SumTab(TabInt T)           {return IsEmpty(T)?0:(Head(T) + SumTab(Tail(T)));}
int CountX(TabInt T, ElType X)    {return IsEmpty(T)?0:((Head(T) == X) + (CountX(Tail(T),X)));}
boolean IsAllGenap(TabInt T)      {return IsEmpty(T)?0: (Neff(T) == 1 && (!(Head(T)%2)))?1: ((!(Head(T)%2)) && IsAllGenap(Tail(T)));}

void Sort(TabInt *T, boolean asc){
  fori1(*T,i) fori1(*T,j) if (Elmt(*T,j) < Elmt(*T,j-1)) swap(Elmt(*T,j), Elmt(*T,j-1));  
  if (!asc) *T = InverseTab(*T);
}

void AddAsLastEl(TabInt *T, ElType X) {Elmt(*T,++Neff(*T)) = X;}
void DelLastEl(TabInt *T, ElType *X) {DelEli(T,NbElmt(*T),X);}

void GrowTab(TabInt *T, int num){
  TabInt T2; MakeEmpty(&T2, NbElmt(*T));
  CopyTab(*T, &T2);
  MaxEl(*T) += num;
  MakeEmpty(T, MaxElement(*T));
  Neff(*T) = NbElmt(T2);
  fori(T2,i) Elmt(*T,i) = Elmt(T2,i);
}

void ShrinkTab(TabInt *T, int num) {GrowTab(T, -num);}
void CompactTab(TabInt *T) {GrowTab(T, Neff(*T)-MaxEl(*T));}