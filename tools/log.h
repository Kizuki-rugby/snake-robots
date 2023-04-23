// The header file for the minimal Log class.
#include <fstream>
#include <string>
#include <iostream>
#include <stdbool.h>
#include "macros.h"

using namespace std;

class Log {

public:
    Log(char*, char*);
    // default constructor
    ~Log(); // destructor
    void write();
    void status();
    bool is_open();
    void flush();

    Log& operator<<(string str); // the overloaded handler operator
    // The overloaded operator can be replicated multiple times
    // with different data types to allow different kinds of
    // information to be written to the log file.
    Log& operator <<(int num);
    Log& operator <<(double num);


    //variables
    static int id_cnt;
    int id;
    string state = "close";
    string filePath = "path";
    string fileName = "name";

private:
    // The file handler.
   ofstream fh;
};


