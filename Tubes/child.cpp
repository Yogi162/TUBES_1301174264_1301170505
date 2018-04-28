#include "child.h"


void createList(List &L) {

    first(L)=NULL;
    last(L)=NULL;
}

address allocate(infotype x) {


    address P = new elmlist;

    info(P) = x;
    next(P)=NULL;
    prev(P) = NULL;


    return P;
}

void deallocate(address &P) {

    delete P;

}

void insertFirst(List &L, address P) {

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

void insertLast(List &L, address P) {

    if (first(L) != NULL)
    {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
    else
    {
        insertFirst(L,P);
    }



}

address findElm(List L, infotype x) {

    address Q = new elmlist;
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

void deleteFirst(List &L, address &P) {

     if (first(L)!=NULL)
    {
        if(first(L)==last(L))
        {
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            P = first(L);
            prev(next(P)) = NULL;
            first(L) = next(P);
            next(P) = NULL;
        }
    }
    else
    {
        cout << "Listnya sudah kosong."<< endl;
    }

}

void deleteLast(List &L, address &P) {

    if (first(L)!=NULL)
    {
        if (first(L)==last(L))
        {
            deleteFirst(L, P);
        }
        else
        {
            address Q = prev(last(L));
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



    //----------------------------------------
}

void printInfo(List L) {
    /**
    * FS : view info of all element inside List L,
    *      call the view_data function from my_data.h to print the info
    */
    //-------------your code here-------------
    address P = new elmlist;
    if (first(L)!=NULL)
    {
        P = first(L);
        do
        {
            view_data(info(P));
            P = next(P);
        }
        while(P!=NULL);
    }
    else
    {
        cout << "[Kosong]" << endl;
    }

    //----------------------------------------
}


void insertAfter(List &L, address Prec, address P) {
    /**
    * IS : Prec and P is not NULL
    * FS : element pointed by P is placed behind the element
    *      pointed by pointer Prec
    */
    //-------------your code here-------------
    if (Prec!=NULL && P!=NULL)
    {
        if(next(Prec)!=NULL)
        {
            address Q = next(Prec);
            next(P) = Q;
            prev(Q) = P;
            next(Prec) = P;
            prev(P) = Prec;
        }
        else
        {
            insertLast(L, P);
        }
    }

    //----------------------------------------

}
void deleteAfter(List &L, address Prec, address &P) {
    /**
    * IS : Prec is not NULL
    * FS : element which was before behind an element pointed by Prec
    *      is removed and pointed by pointer P
    */
    //-------------your code here-------------
     if(Prec!=NULL)
    {
        if(next(next(Prec))!=NULL)
        {
            P = next(Prec);
            address Q = next(P);
            next(Prec) = Q;
            prev(Q) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }
        else
        {
            deleteLast(L, P);
        }
    }


    //----------------------------------------
}

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


child create_data(child &d) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    // ===========================
    // YOUR CODE HERE

    cout<<"Masukkan Nama Bandara: "<<endl;
    cin>>d.bandara;
    cout<<"Masukkan Kode bandara: "<<endl;
    cin>>d.id_bandara;
    cout<<"Masukkan Nama daerah: "<<endl;
    cin>>d.daerah;


    return d;
}

void view_data(child d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE

    cout<<"Nama Bandara: "<<d.bandara<<endl;
    cout<<"Nama Kode Bandara: "<<d.id_bandara<<endl;
    cout<<"Nama Daerah: "<<d.daerah<<endl;





    // ===========================
}


void edit_data(child &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
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

