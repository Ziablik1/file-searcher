#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    string fileName;
    cout << "Enter file name you'd like to search (for example \"file.txt\"):" << endl;
    cin >> fileName;
    search(fileName);
    system("pause");
    return 0;
}