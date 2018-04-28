#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;
typedef struct child infotype;
typedef struct elmlist *address;

struct child {
    /**
     TODO:  create a new Data type with specification:
            - an integer variable acted as an ID
            - two other variables
            - a float variable
    */
    //=================================================
    // YOUR CODE STARTS HERE

    string bandara;
    string id_bandara;
    string daerah;



    // YOUR CODE ENDS HERE
    //=================================================
};

struct elmlist{
    //------------- your code here -----------
    infotype info;
    address next;
    address prev;
    //----------------------------------------
};

struct List{
    //------------- your code here -----------
    address first;
    address last;

    //----------------------------------------
};

void createList(List &L);
address allocate(infotype x);
void deallocate(address &P);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void insertAfter(List &L, address Prec, address P);
void deleteAfter(List &L, address Prec, address &P);
address findElm(List L, infotype x);
void printInfo(List L);

void insertAndSort(List &L, address P);
void deletebyID(List &L, infotype x);



child create_data(child &d);
void view_data(child d);
void edit_data(child &d);
#endif // CHILD_H_INCLUDED
