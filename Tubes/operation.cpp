#include "doublelist.h"
#include "operation.h"
#include "my_data.h"



void insertAndSort(List &L, address P) {

    bool ada = false;
    bool ketemu = false;
    address Q = new elmlist;
    if (first(L)==NULL)
    {
        insertFirst(L, P);
        ada = true;
    }
    else
    {
        Q = first(L);
        while (Q !=NULL)
        {
            if (info(Q).id_bandara==info(P).id_bandara)
            {
                ada = true;
            }
            Q = next(Q);
        }
        if (!ada)
        {
            if (first(L)!=NULL)
            {
                if (info(P).id_bandara<info(first(L)).id_bandara)
                {
                    insertFirst(L,P);
                }
                else
                {
                    Q = first(L);
                    while(Q!=NULL && !ketemu)
                    {
                        if(next(Q)!=NULL)
                        {
                            if(info(P).id_bandara < info(next(Q)).id_bandara)
                            {
                                insertAfter(L, Q, P);
                                ketemu = true;
                            }
                        }
                        else
                        {
                            insertLast(L, P);
                            ketemu = true;
                        }
                        Q = next(Q);
                    }
                }
            }
        }
        else
        {
            cout << "ID yang dimasukkan telah ada! " << endl;
        }

    }


}


void deletebyID(List &L, infotype x) {


    address P;

    P = findElm(L, x);
    if (P!=NULL)
    {
        if (P==first(L))
        {
            deleteFirst(L, P);
            deallocate(P);
        }
        else
        {
            address Prec = new elmlist;
            bool ketemu = false;
            Prec = first(L);
            while(Prec!=NULL && !ketemu)
            {
                if (next(next(Prec))==NULL)
                {
                    deleteLast(L, P);
                }
                else if (next(Prec)!=NULL)
                {
                    if(info(next(Prec)).id_bandara == info(P).id_bandara)
                    {
                        deleteAfter(L,Prec,P);
                        ketemu = true;
                    }
                }
                Prec = next(Prec);
            }
            deallocate(P);
        }
    }

}
