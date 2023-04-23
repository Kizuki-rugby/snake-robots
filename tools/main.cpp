#include "log.h"
#include "configuration.h"
#include <cmath>
using namespace std ;


// For this lab we are not doing unit testing, for now just
// Object of type Log globally instantiated.
//int main(int argc, char* argv[])
int main ()
{
//    Log log = Log(argv[1], argv[2]);
//    log.write();
//    cout << log.isOpen() << endl;
//    log.~Log();
//    cout << log.isOpen() << endl;

    configuration config = configuration();
    config.currState();

    return 0;
}

