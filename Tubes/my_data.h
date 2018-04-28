#ifndef MY_DATA_H_INCLUDED
#define MY_DATA_H_INCLUDED

#include <iostream>
using namespace std;

/**
    CLASS      : IF-41-08
    NAME       : M. Fadhil ihsan
    STUDENT ID : 1301170505
**/

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


child create_data(child &d);
void view_data(child d);
void edit_data(child &d);

#endif // MY_DATA_H_INCLUDED
