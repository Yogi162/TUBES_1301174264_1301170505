#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;
typedef struct b_list infobandara;
typedef struct elmlist *address_b;

struct b_list{
    string bandara;
    string id_bandara;
    string daerah;
};

struct elmlist{
    //------------- your code here -----------
    infobandara info;
    address_b next;
    address_b prev;
    //----------------------------------------
};

struct List2{
    //------------- your code here -----------
    address_b first;
    address_b last;

    //----------------------------------------
};

void createList2(List2 &L);
address_b allocate2(infobandara x);
void deallocate2(address_b &P);
void insertFirst2(List2 &L, address_b P);
void insertLast2(List2 &L, address_b P);
void deleteFirst2(List2 &L, address_b &P);
void deleteLast2(List2 &L, address_b &P);
void insertAfter2(List2 &L, address_b Prec, address_b P);
void deleteAfter2(List2 &L, address_b Prec, address_b &P);
address_b findElm2(List2 L, infobandara x);
void printInfo2(List2 L);

void insertAndSort2(List2 &L, address_b P);
void deletebyID2(List2 &L, infobandara x);


void viewalltujuan(List2 L);
b_list create_data2(b_list &d);
void view_data2(address_b P);
void edit_data2(b_list &d);
#endif // CHILD_H_INCLUDED
