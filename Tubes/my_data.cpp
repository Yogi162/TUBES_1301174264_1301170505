
#include "my_data.h"

/**
    CLASS      : IF-41-08
    NAME       : M. fadhil ihsan
    STUDENT ID : 1301170505
**/

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

