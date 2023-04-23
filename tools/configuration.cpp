#include "configuration.h"

using namespace std;

/**
 * Constructor for class configuration
 * @brief configuration::configuration
 * @param filePath
 */
configuration::configuration()
{
    try {
        SHOW_WHERE;
        fs.open(filePath, ios::out | ios::in | ios::trunc);     //truncate -> will overwrite files!
        state = "start";
    } catch(...) {
        cerr << "Error detected" <<endl;
    }
}

/**
 * Destructor for class configuration
 * @brief configuration::~configuration
 */
configuration::~configuration() {
    fs.close();
}

/**
 * This method is the general read method for files
 * @brief configuration::read
 */
void configuration::read() {
    while (!fs.eof()) {
        while (fs.get() != ':') {
            keyID += fs.get();
        }
        while (fs.get() != '\n') {
            keyVAL += fs.get();
        }
        dorasMap.insert(pair<string, string>(keyID, keyVAL));
    }
}

/**
 * This method is the general write method for files
 * @brief configuration::write
 */
void configuration::write() {
    for (auto& pair:dorasMap) {
        fs << pair.first << ':' << pair.second << endl;
    }
}

/**
 * This method will control the state machine for the class
 * States: null: (from header file, has no functionality)
 *         start: defualt state, used to interfsace with user
 *         loading: reading specified file
 *         saving: writing specified file configuration
 *         edit: writing a new configuration in-program
 *         exit: program end
 * @brief configuration::currState
 */
void configuration::currState() {
    if (state == "start") {
        if (load == ('Y' | 'y')) {
            state = "loading";
        } else if (load == ('N' | 'n')) {
            state = "editFilePath";
        }
    }
    if (state == "loading") {
        read();
        state = "edit";
    }
    if (state == "saving") {
        write();
        state = "exit";
    }
    if (state == "edit") {
        editFilePath();
    }
    if (state == "exit") {
        dorasMap.clear();               //erase contents of map upon program shutdown
    }
}

/**
 * This method will run the editing environment of the program filepath
 * @brief configuration::edit
 */
void configuration::editFilePath() {
    if (rename == ('Y' | 'y')) {
        filePath = filePathNew;
    } else if (rename != ('N' | 'n')) {
        editFilePath();
    }
    edit();
 }

/**
 * This method will run the editing environment for the keys in the configuration file
 * @brief configuration::edit
 */
void configuration::edit() {
    if (erase == ('Y' | 'y')) {
        dorasMap.erase(keyID);
    } else if (erase != ('N' | 'n')) {
        edit();
    }
    map<string, string>::iterator it = dorasMap.find(keyID);
    if (it != dorasMap.end()) {
        it->second = keyVAL;
    }
    state = "saving";
}






