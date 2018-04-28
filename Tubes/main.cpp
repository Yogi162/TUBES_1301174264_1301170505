#include <iostream>
#include "maskapai.h"
#include "bandara.h"
#include "koneksi.h"

using namespace std;

void mainMenu();
List L;
List2 L2;
List3 L3;
address_m P;
address_b Q;
address_h R;
b_list Y,e;
infomaskapai X,d;
int main()
{
    createList(L);
    createList2(L2);
    createList3(L3);

    d.kode="LI231";
    d.nama="Lion";
    d.tanggal=17;
    d.bulan=8;
    d.tahun=2018;
    d.asal="Banjarbaru";
    d.harga=1000000;
    P=allocate(d);
    insertLast(L,P);
    e.bandara="Husein_Sastranegara";
    e.id_bandara="BDO";
    e.daerah="Bandung";
    Q=allocate2(e);
    insertLast2(L2,Q);
    connect(L3,P,Q);

    d.kode="GA983";
    d.nama="Garuda";
    d.tanggal=21;
    d.bulan=8;
    d.tahun=2018;
    d.asal="Padang";
    d.harga=1500000;
    P=allocate(d);
    insertLast(L,P);
    connect(L3,P,Q);

    d.kode="SA867";
    d.nama="Susi";
    d.tanggal=21;
    d.bulan=8;
    d.tahun=2018;
    d.asal="Bali";
    d.harga=500000;
    P=allocate(d);
    insertLast(L,P);
    connect(L3,P,Q);

    d.kode="WA437";
    d.nama="Wings";
    d.tanggal=17;
    d.bulan=8;
    d.tahun=2018;
    d.asal="Bandung";
    d.harga=900000;
    P=allocate(d);
    insertLast(L,P);
    e.bandara="Sukarno-Hatta";
    e.id_bandara="CGK";
    e.daerah="Jakarta";
    Q=allocate2(e);
    insertLast2(L2,Q);
    connect(L3,P,Q);

    d.kode="AA254";
    d.nama="Susi";
    d.tanggal=21;
    d.bulan=8;
    d.tahun=2018;
    d.asal="Bali";
    d.harga=400000;
    P=allocate(d);
    insertLast(L,P);
    connect(L3,P,Q);

    mainMenu();

    return 0;
}

void mainMenu()
{
    int t=1;

    int choice;
    do
    {
        cout<<" _________________________________"<<endl;
        cout<<"|Menu                             |"<<endl;
        cout<<"|1. Masukkan Data Penerbangan     |"<<endl;
        cout<<"|2. Lihat Semua Data              |"<<endl;
        cout<<"|3. Lihat Data Maskapai           |"<<endl;
        cout<<"|4. Lihat Data Tujuan Penerbangan |"<<endl;
        cout<<"|5. Cari Data Penerbangan         |"<<endl;
        cout<<"|6. Cari Data Maskapai            |"<<endl;
        cout<<"|7. Cari Data Tujuan Penerbangan  |"<<endl;
        cout<<"|8. Hapus Data Penerbangan        |"<<endl;
        cout<<"|9. Hapus Tujuan Penerbangan      |"<<endl;
        cout<<"|10. Rata2 Harga Tiket Ke Tujuan  |"<<endl;
        cout<<"|11. Tiket Termurah Ke Tujuan     |"<<endl;
        cout<<"|0. exit                          |"<<endl;
        cout<<"|_________________________________|"<<endl;
        cout<<"input choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1: //Muhammad Fadhil Ihsan 1301170505
            X = createdata(d);
            P=findElm(L,X);
            if (P==NULL)
            {
                P=allocate(X);
                insertLast(L,P);
            }
            Y = create_data2(e);
            Q=findElm2(L2,Y);
            if (Q==NULL)
            {
                Q=allocate2(Y);
                insertLast2(L2,Q);
            }
            connect(L3,P,Q);
            break;
        case 2: //Muhammad Fadhil Ihsan 1301170505
            P=first(L);
            do
            {
                view(P);
                R=child(P);
                cout<<endl<<"Tujuan Penerbangan"<<endl;
                if (R!=NULL){
                    view_data2(info(R));
                }
                P=next(P);
            } while (P!=first(L));
            break;
        case 3: //Muhammad Fadhil Ihsan 1301170505
            viewallmaskapai(L);
            break;
        case 4: //Muhammad Fadhil Ihsan 1301170505
            viewalltujuan(L2);
            break;
        case 5: //Supra Yogi 1301174264
            cout<<"Masukkan Kode Penerbangan yang ingin dicari : ";
            cin>>X.kode;
            P=findElm(L, X);
            if (P!=NULL) {
                view(P);
                cout<<endl<<"Tujuan Penerbangan"<<endl;
                view_data2(info(child(P)));
            }
            else {
                cout<<endl<<"--------------------------------------";
                cout<<"Data tidak ditemukan"<<endl;
                cout<<"--------------------------------------"<<endl<<endl;
            }
            break;
        case 6: //Supra Yogi 1301174264
            cout<<"Masukkan Nama Maskapai yang ingin dicari : ";
            cin>>X.nama;
            cout<<"--------------------------------------"<<endl<<endl;
            cout<<"Hasil Pencarian :"<<endl<<endl;
            findElmnama(L, X);
            break;
        case 7: //Supra Yogi 1301174264
            cout<<"Masukkan Kode Bandara yang ingin dicari : ";
            cin>>Y.id_bandara;
            cout<<"--------------------------------------"<<endl<<endl;
            cout<<"Hasil Pencarian :"<<endl<<endl;
            Q=findElm2(L2,Y);
            view_data2(Q);
            break;
        case 8: //Supra Yogi 1301174264
            cout<<"Masukkan Kode Penerbangan yang ingin dihapus : ";
            cin>>X.kode;
            P=findElm(L,X);
            deletebyID(L,P);
            break;
        case 9: //Supra Yogi 1301174264
            cout<<"Masukkan Kode Penerbangan yang ingin dihapus tujuannya : ";
            cin>>X.kode;
            P=findElm(L,X);
            Q=info(child(P));
            disconnect(L,L3,P,Q);
            break;
        case 10: //Supra Yogi 1301174264
            cout<<"Masukkan Kode Bandara yang ingin dicari rata2 harganya : ";
            cin>>Y.id_bandara;
            cout<<"--------------------------------------"<<endl<<endl;
            Q=findElm2(L2,Y);
            if (Q!=NULL){
                average(L,Q);
            }
            break;
        case 11: //Muhammad Fadhil Ihsan 1301170505
            cout<<"Masukkan Kode Bandara Yang Ingin Dituju : ";
            cin>>Y.id_bandara;
            Q=findElm2(L2,Y);
            if (Q!=NULL){
                cheapest(L,Q);
            }
            break;
        case 0:
            t=0;
            break;
        }
    }
    while(t==1);

    //----------------------------------------
}
