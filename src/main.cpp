#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file;
    file.open("./test.qcir");
    file << "haha";
    file.close();
    return 0;
};