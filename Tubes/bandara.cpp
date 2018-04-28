#include "bandara.h"
#include "maskapai.h"
#include "koneksi.h"
void createList2(List2 &L) //Muhammad Fadhil Ihsan 1301170505
{
    first(L)=NULL;
    last(L)=NULL;
}

address_b allocate2(infobandara x) //Muhammad Fadhil Ihsan 1301170505
{
    address_b P = new elmlist;
    info(P) = x;
    next(P)=NULL;
    prev(P) = NULL;
    return P;
}

void deallocate2(address_b &P) //Muhammad Fadhil Ihsan 1301170505
{
    delete P;
}

void insertFirst2(List2 &L, address_b P) //Muhammad Fadhil Ihsan 1301170505
{

    if (first(L)!= NULL)
    {
        prev(first(L)) = P;
        next(P) = first(L);
        first(L) = P;
    }
    else
    {
        first(L) = P;
        last(L) = P;
    }
}

void insertLast2(List2 &L, address_b P) //Muhammad Fadhil Ihsan 1301170505
{

    if (first(L) != NULL)
    {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
    else
    {
        insertFirst2(L,P);
    }
}

address_b findElm2(List2 L, infobandara x) //Muhammad Fadhil Ihsan 1301170505
{
    address_b Q = new elmlist;
    bool ketemu = false;

    if (first(L)!=NULL)
    {
        Q = first(L);
        while(Q!=NULL && !ketemu)
        {
            if(info(Q).id_bandara == x.id_bandara)
            {
                return Q;
                ketemu = true;
            }
            Q = next(Q);
        }
    }
    else if (first(L)==NULL || !ketemu)
    {
        return NULL;
    }
}

void deleteFirst2(List2 &L, address_b &P) //Muhammad Fadhil Ihsan 1301170505
{
    P=first(L);
    if ((next(first(L)))==NULL) {
        first(L)=NULL;
        last(L)=NULL;
    }
    else if (first(L)!=NULL) {
        first(L)=next(P);
        prev(first(L))=NULL;
        next(P)=NULL;
    }
    else
    {
        cout << "Listnya sudah kosong."<< endl;
    }

}

void deleteLast2(List2 &L, address_b &P) //Muhammad Fadhil Ihsan 1301170505
{

    if (first(L)!=NULL)
    {
        if (first(L)==last(L))
        {
            deleteFirst2(L, P);
        }
        else
        {
            address_b Q = prev(last(L));
            P = last(L);
            prev(last(L)) = NULL;
            next(Q) = NULL;
            last(L) = Q;
        }
    }
    else
    {
        cout << "List sudah kosong." << endl;
    }
}

void printInfo2(List2 L) //Muhammad Fadhil Ihsan 1301170505
{
    address_b P = new elmlist;
    if (first(L)!=NULL)
    {
        P = first(L);
        do
        {
            view_data2(P);
            P = next(P);
        }
        while(P!=NULL);
    }
    else
    {
        cout << "[Kosong]" << endl;
    }
}


void insertAfter2(List2 &L, address_b Prec, address_b P) //Muhammad Fadhil Ihsan 1301170505
{
    if (Prec!=NULL && P!=NULL)
    {
        if(next(Prec)!=NULL)
        {
            address_b Q = next(Prec);
            next(P) = Q;
            prev(Q) = P;
            next(Prec) = P;
            prev(P) = Prec;
        }
        else
        {
            insertLast2(L, P);
        }
    }

    //----------------------------------------

}
void deleteAfter2(List2 &L, address_b Prec, address_b &P) //Muhammad Fadhil Ihsan 1301170505
{
    if(Prec!=NULL)
    {
        if(next(next(Prec))!=NULL)
        {
            P = next(Prec);
            address_b Q = next(P);
            next(Prec) = Q;
            prev(Q) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }
        else
        {
            deleteLast2(L, P);
        }
    }


    //----------------------------------------
}


void deletebyID2(List2 &L, infobandara x) //Muhammad Fadhil Ihsan 1301170505
{
    address_b P;
    P = findElm2(L, x);
    if (P!=NULL)
    {
        if (P==first(L))
        {
            deleteFirst2(L, P);
            deallocate2(P);
        }
        else
        {
            address_b Prec = new elmlist;
            bool ketemu = false;
            Prec = first(L);
            while(Prec!=NULL && !ketemu)
            {
                if (next(next(Prec))==NULL)
                {
                    deleteLast2(L, P);
                }
                else if (next(Prec)!=NULL)
                {
                    if(info(next(Prec)).id_bandara == info(P).id_bandara)
                    {
                        deleteAfter2(L,Prec,P);
                        ketemu = true;
                    }
                }
                Prec = next(Prec);
            }
            deallocate2(P);
        }
    }
}



b_list create_data2(b_list &d) //Muhammad Fadhil Ihsan 1301170505
{

    cout<<"Masukkan Nama Bandara Tujuan : ";
    cin>>d.bandara;
    cout<<"Masukkan Kode bandara Tujuan : ";
    cin>>d.id_bandara;
    cout<<"Masukkan Nama daerah Tujuan  : ";
    cin>>d.daerah;

    return d;
}

void view_data2(address_b P) //Muhammad Fadhil Ihsan 1301170505
{
    if (P==NULL){}
    else {
    cout<<endl<<"Nama Bandara        : "<<info(P).bandara<<endl;
    cout<<"Nama Kode Bandara   : "<<info(P).id_bandara<<endl;
    cout<<"Nama Daerah         : "<<info(P).daerah<<endl;
    cout<<endl<<"--------------------------------------"<<endl;
    }
}

void viewalltujuan(List2 L){ //Muhammad Fadhil Ihsan 1301170505
    address_b P=first(L);
    while (P!=NULL) {
        view_data2(P);
        P=next(P);
    }
}
void edit_data2(b_list &d) //Muhammad Fadhil Ihsan 1301170505
{
    char jawaban;
    cout<<"Ingin mengubah Bandara?: ";
    cin>>jawaban;
    if (jawaban == 'y')
    {
        cout<<"Masukkan Nama Bandara: "<<endl;
        cin>>d.bandara;
    }
    cout<<"Ingin mengubah Kode Bandara?: ";
    cin>>jawaban;
    if (jawaban == 'y')
    {
        cout<<"Masukkan Kode bandara: "<<endl;
        cin>>d.id_bandara;
    }
    cout<<"Ingin mengubah daerah?: ";
    cin>>jawaban;
    if (jawaban == 'y')
    {
        cout<<"Masukkan Nama Daerah: "<<endl;
        cin>>d.daerah;
    }
}
