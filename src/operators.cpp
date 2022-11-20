#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void clear() {
  ofstream file;
  file.open("./test.qcir");
  file.close();
}

void write(string const &s) {
  ofstream file;
  file.open("./test.qcir", std::ios::app);
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
void Or(string n, vector<string> const &vt) {
  write(n + " = or(");
  addParams(vt);
  write(")\n");
}

// Set n = vt[0] and vt[1] or ...
void And(string n, vector<string> const &vt) {
  write(n + " = and(");
  addParams(vt);
  write(")\n");
}

void Exists(vector<string> const &vt) {
  write("exists(");
  addParams(vt);
  write(")\n");
}

void Forall(vector<string> const &vt) {
  write("forall(");
  addParams(vt);
  write(")\n");
}
