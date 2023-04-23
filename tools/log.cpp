#include "log.h"

using namespace std;

// In the default constructor the file handler is opened.
// name of the file should be passed to the constructor
/**
 * The constructor that gets passed filePath name. this will assign gloval variable filePath a filePath that's given by parameter.
 * Moreover, using that filePath, this constructor will open ofstream, and set the "state" variable to open, indicating that ofstream is currently open.
 * @brief Log::Log
 * @param filePath
 */

int Log::id_cnt = 0;

Log::Log(char* filePath, char* fileName)
{
    try
    {
    id = id_cnt;
    id_cnt++;
    SHOW_WHERE;
    this->filePath = filePath;
    this->fileName = fileName;
    fh.open(this->filePath, ofstream::out | ofstream::app);
//    cout << "Opened"<< endl;
    state = "open";
    }
    catch(...)
    {
        cerr << "There was something wrong" << endl;
    }
}

// In the destructor the file handler is closed.
/**
 * Destructor, this should close the ofstream, and set the "state" variable to close.
* @brief Log::~Log
*/
Log::~Log()
{
    fh.close();
    state = "close";
}

/*** * The overloaded operator will process the incoming string, then return
* itself as a reference. This allows chaining of multiple filehandler
* operations.
*/
/**
 * Write function writes its file path and file name to log file.
 * @brief Log::write
 */
void Log::write()
{
    // how to get
    fh << "File Path : ";
    fh << filePath;
    fh << ", File Name : ";
    fh << fileName;
    fh << "\n";
}
void Log::status()
{
    if(state == "open")
    {
        cout << id << "'s ofStream is Open" << endl;
    }
    else if(state == "flushed")
    {
        cout << id << "'s ofStream is flushed" << endl;
    }
    else
    {
        cout << id << "'s ofStream is close" << endl;
    }
}
/**
 * Flush function to flush the standard buffer. Internally, the function accesses the output sequence by first constructing a sentry object.
 *  Then (if good), it calls pubsync on its associated stream buffer object, and finally destroys the sentry object before returning.
 *
 * @brief Log::flush
 */
void Log::flush()
{
    fh.flush();
    cout << "flushed" << endl;
    state = "flushed";
}

/**
 * Status function indicates which state the ofstream is currently at.
 * There are three stages:
 * 1) open -> returns true
 * 2) flushed ->returns false
 * 3) close -> returns false
 * @brief Log::status
 * @return
 */
bool Log::is_open()
{
    if(state == "open") return true;
    else return false;
}
/**
 * @brief Log::operator <<
 * @param str
 * @return Log
 */
Log& Log::operator<<(string str)
{
    fh << str;
    return *this;
}

Log& Log::operator <<(int num)
{
    fh << num;
    return *this;
}
Log& Log::operator <<(double num)
{
    fh << num;
    return *this;
}
