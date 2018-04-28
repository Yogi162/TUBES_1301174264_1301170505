#ifndef MASKAPAI_H_INCLUDED
#define MASKAPAI_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define child(P) P->child
#include "koneksi.h"
#include "bandara.h"
using namespace std;
typedef struct m_list *address_m;
typedef struct hubungan *address_h;
struct infomaskapai {
    int tanggal,bulan,tahun;
    int harga;
    string nama,asal,kode;
};


struct m_list {
    infomaskapai info;
    address_m next;
    address_h child;
    address_m prev;
};

struct List{
    //------------- your code here -----------

    address_m first;
    address_m last;
    //----------------------------------------
};

void createList(List &L);
address_m allocate(infomaskapai x);


void viewallmaskapai(List L);
void insertFirst(List &L, address_m P);
void insertLast(List &L, address_m P);
void insertAfter(List &L, address_m Prec, address_m P);
void deleteFirst(List &L, address_m P);
void deleteLast(List &L, address_m P);
void deleteAfter(List &L, address_m Prec, address_m P);
void deletebyID(List &L, address_m P);
address_m searchLast(List L);
address_m findElm(List L, infomaskapai x);
void findElmnama(List L, infomaskapai x);
void view(address_m P);
infomaskapai createdata(infomaskapai X);
void average(List L, address_b Q);
void cheapest(List L,address_b Q);
#endif // MASKAPAI_H_INCLUDED
