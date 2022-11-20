#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void write(string const &s) {
    ofstream file;
    file.open("./test.qcir");
    file << s;
    file.close();
}

void addParams(vector<string> const &vt) {
    for (int i = 0; i < vt.size(); ++i) {
        write(vt[i]);
        if (i != vt.size() - 1) write(",");
    }
}

// Set n = vt[0] or vt[1] or ...
void Or(int n, vector<string> const &vt) {
    write(n + " = or(");
    addParams(vt);
    write(")\n");
}

// Set n = vt[0] and vt[1] or ...
void And(int n, vector<string> const &vt) {
    write(n + " = and(");
    addParams(vt);
    write(")\n");
}
