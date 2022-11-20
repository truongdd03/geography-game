#include <solver.h>

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <memory>
#include <array>
#include <sstream>

using namespace std;

std::string exec(const char* cmd) {
  std::array<char, 128> buffer;
  std::string result;
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }
  return result;
}

void processResult(string const &result) {
  istringstream iss(result);

  char c; iss >> c;
  if (c != 'V') {
    cout << "Player 1 can't win :(\n";
    return;
  }
  string val;
  while (iss >> val) {
    if (val == "r") return;
    if (val.length() != 2) continue;
    if ((val[0] - '0') % 2 == 1) cout << "Player 1 ";
    else {
      cout << "Player 2 ";
    }
    cout << "chooses " << val[1] << "\n";
  }
}

int main() {
  generateFormula();
  string const &result = exec("./lib/quabs --partial-assignment ./test.qcir");
  processResult(result);

  return 0;
};