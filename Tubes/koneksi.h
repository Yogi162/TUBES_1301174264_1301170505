#ifndef KONEKSI_H_INCLUDED
#define KONEKSI_H_INCLUDED
#include <iostream>
#include "bandara.h"
#include "maskapai.h"
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
struct List;
typedef struct hubungan *address_h;
typedef struct m_list *address_m;
struct hubungan{
    address_b info;
    address_h next;
};

struct List3 {
    address_h first;
};

void connect(List3 L, address_m P,address_b Q);
address_h findElm3(List3 L, address_b P);
void insertFirst3(List3 &L, address_h P);
address_h allocate3(address_b x);
void createList3(List3 L);
void disconnect(List L,List3 &L3, address_m P, address_b Q);

#endif // KONEKSI_H_INCLUDED
