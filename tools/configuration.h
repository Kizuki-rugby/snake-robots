#include <fstream>
#include <string>
#include <iostream>
#include <stdbool.h>
#include <map>
#include "macro.h"

using namespace std;

class configuration
{
public:
    configuration();    //constructor
    ~configuration();   //destructor
    fstream fs;        //file I/O

    void read();
    void write();
    void editFilePath();
    void edit();
    void currState();

    map <string, string> dorasMap;     //yes, dora the explorer
    string filePath;
    string keyID;
    string keyVAL;
    string state;
    char erase;
    char load;
    char rename;
    string filePathNew;
    char Edit;

    static int id_cnt;
    int id;


};

