#include "maskapai.h"
#include "bandara.h"
#include "koneksi.h"

void createList(List &L) //Supra Yogi 1301174264
{
    first(L)=NULL;
}

address_m allocate(infomaskapai x) //Supra Yogi 1301174264
{
    address_m P=new m_list;
    info(P)=x;
    return P;
}

void deallocate(address_m &P) //Supra Yogi 1301174264
{
    delete P;
}

void insertFirst(List &L, address_m P) //Supra Yogi 1301174264
{
    if (first(L)==NULL)
    {
        first(L)=P;
        next(P)=first(L);
    }
    else {
        address_m Q=searchLast(L);
        next(P)=first(L);
        first(L)=P;
        next(Q)=first(L);
    }
}

void insertLast(List &L, address_m P) //Supra Yogi 1301174264
{
    if (first(L)==NULL)
    {
        first(L)=P;
        next(P)=first(L);
    }
    else {
        address_m Q=searchLast(L);
        next(P)=first(L);
        next(Q)=P;
    }
}

void insertAfter(List &L, address_m Prec, address_m P){ //Supra Yogi 1301174264
    next(P)=next(Prec);
    next(Prec)=P;
}

address_m findElm(List L, infomaskapai x) //Supra Yogi 1301174264
{
    address_m P=first(L);
    do
    {
        if (info(P).kode==x.kode)
        {
            return P;
        }
        P=next(P);
    } while (P!=first(L));
    return NULL;
}

void findElmnama(List L, infomaskapai x){ //Supra Yogi 1301174264
    address_m P=first(L);
    do {
        P=next(P);
        if (info(P).nama==x.nama){
            view(P);
        }
    } while (P!=first(L));
}

void view(address_m P) //Supra Yogi 1301174264
{
    if (P!=NULL){
    cout<<endl<<"--------------------------------------"<<endl;
    cout<<"Kode Penerbangan    : "<<info(P).kode<<endl;
    cout<<"Nama Maskapai       : "<<info(P).nama<<endl;
    cout<<"Tanggal Penerbangan : "<<info(P).tanggal<<" - "<<info(P).bulan<<" - "<<info(P).tahun<<endl;
    cout<<"Daerah Asal         : "<<info(P).asal<<endl;
    cout<<"Harga Tiket         : "<<info(P).harga<<endl;
    }
}

void deleteFirst(List &L, address_m P){ //Supra Yogi 1301174264
    if (first(L)!=NULL){
        P=first(L);
        address_m Q=searchLast(L);
        next(Q)=next(P);
        first(L)=next(P);
        next(P)=NULL;
        child(P)=NULL;
        deallocate(P);
    }
}

void deleteLast(List &L, address_m P){ //Supra Yogi 1301174264
    if (first(L)!=NULL){
        address_m Q=first(L);
        do {
            Q=next(Q);
        } while (next(Q)!=P);
        next(Q)=first(L);
        next(P)=NULL;
        child(P)=NULL;
        deallocate(P);
    }
}

void deleteAfter(List &L, address_m Prec, address_m P){ //Supra Yogi 1301174264
    P=next(Prec);
    if (P==first(L)){
        deleteFirst(L,P);
    }
    else if (next(P)==first(L)){
        deleteLast(L,P);
    }
    else {
        next(Prec)=next(P);
        next(P)=NULL;
        deallocate(P);
    }

}

void deletebyID(List &L, address_m P){ //Supra Yogi 1301174264
    if (P==first(L)){
        deleteFirst(L,P);
    }
    else if (next(P)==first(L)){
        deleteLast(L,P);
    }
    else if (P!=NULL){
        address_m Q=first(L);
        do {
            Q=next(Q);
        } while (next(Q)!=P);
        deleteAfter(L,Q,P);
    }
}

address_m searchLast(List L){ //Supra Yogi 1301174264
    if (first(L)!=NULL){
        address_m Q=first(L);
        do {
            Q=next(Q);
        } while (next(Q)!=first(L));
        return Q;
    }
}

infomaskapai createdata(infomaskapai X) //Supra Yogi 1301174264
{
    cout<<"Masukkan Kode Penerbangan    : ";
    cin>>X.kode;
    cout<<"Masukkan Nama Maskapai       : ";
    cin>>X.nama;
    cout<<"Masukkan Tanggal Penerbangan : ";
    cin>>X.tanggal;
    cout<<"Masukkan Bulan Penerbangan   : ";
    cin>>X.bulan;
    cout<<"Masukkan Tahun Penerbangan   : ";
    cin>>X.tahun;
    cout<<"Masukkan Asal Daerah         : ";
    cin>>X.asal;
    cout<<"Masukkan Harga Tiket         : ";
    cin>>X.harga;
    return X;
}

void viewallmaskapai(List L){ //Supra Yogi 1301174264
    address_m P=first(L);
    do {
        view(P);
        P=next(P);
    } while (P!=first(L));
}

void average(List L, address_b Q){ //Supra Yogi 1301174264
    int i=0;
    int tot=0;
    address_m P=first(L);
    do {
        P=next(P);
        if (child(P)!=NULL){
            if (info(child(P))==Q){
                tot=tot+info(P).harga;
                i++;
            }
        }
    }while(P!=first(L));
    if (i!=0){
        tot=tot/i;
    }
    cout<<endl<<"Rata Rata Harga Tiket Tujuan "<<info(Q).daerah<<" adalah : "<<tot<<endl;
}

void cheapest(List L,address_b Q){ //Muhammad Fadhil Ihsan 1301170505
    int lowest=99999999;
    address_m P=first(L);
    do {
        if (child(P)!=NULL){
            if ((info(child(P))==Q)&&(info(P).harga<lowest)){
                lowest=info(P).harga;
            }
        }
        P=next(P);
    }while (P!=first(L));
    if (lowest!=99999999){
        cout<<endl<<"Harga Tiket Termurah Tujuan "<<info(Q).daerah<<" adalah : "<<lowest<<endl<<endl;
    }
}
