#include "koneksi.h"
#include "maskapai.h"
#include "bandara.h"

void createList3(List3 L) //Supra Yogi 1301174264
{
    first(L)=NULL;
}

address_h allocate3(address_b x) //Muhammad Fadhil Ihsan 1301170505
{
    address_h P=new hubungan;
    info(P)=x;
    next(P)=NULL;
    return P;
}

void deallocate3(address_h P){ //Muhammad Fadhil Ihsan 1301170505
    delete P;
}

void insertFirst3(List3 &L, address_h P) //Supra Yogi 1301174264
{
    if (first(L)!= NULL)
    {
        next(P) = first(L);
        first(L) = P;
    }
    else
    {
        first(L) = P;
    }
}

address_h findElm3(List3 L, address_b P) //Supra Yogi 1301174264
{
    address_h Q=first(L);
    while (Q!=NULL)
    {
        if (info(Q)==P)
        {
            return Q;
        }
        Q=next(Q);
    }
    return NULL;
}

void connect(List3 L, address_m P,address_b Q) //Muhammad Fadhil Ihsan 1301170505
{
    address_h R=findElm3(L,Q);
    if (R==NULL)
    {
        R=allocate3(Q);
        insertFirst3(L, R);
        child(P)=R;
    }
    else {
        child(P)=R;
    }
}

void disconnect(List L,List3 &L3, address_m P, address_b Q){ //Supra Yogi 1301174264
    int i=0;
    child(P)=NULL;
    address_h R=findElm3(L3,Q);
    P=first(L);
    do {
        P=next(P);
        if (child(P)==R){
            i++;
        }
    }while(P!=first(L));
    if (i==0) {
        address_h S=first(L3);
        while(next(S)!=R){
            S=next(S);
        }
        info(R)=NULL;
        next(S)=NULL;
        deallocate3(R);
    }
}

