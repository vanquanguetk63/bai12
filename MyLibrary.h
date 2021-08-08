#include <fstream>
using namespace std;
#ifndef MYLIBRARY_H_INCLUDED
#define MYLIBRARY_H_INCLUDED

bool isEmptyFile(fstream &file) {
    if (!file.is_open()) {
        cout << "File chua dc mo" << endl;
        return false;
    }
    else {
        file.seekp(0, ios::end);
        size_t size = file.tellg();
        file.seekp(0, ios::beg);
        if (size == 0)
            return true;
        else
            return false;
    }
}

#endif // MYLIBRARY_H_INCLUDED
