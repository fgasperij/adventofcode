#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream ifile("io/day_1_1.in");
  if (!ifile.is_open()) {
    cout << "Couldn't open the file!\n";
    return 1;
  }

  string line;
  ifile >> line;
  int floor = 0;
  int position = -1;
  while (!ifile.eof()) {
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == '(') ++floor;
      if (line[i] == ')') --floor;
      if (floor == -1 && position == -1) position = i+1;
    }
    ifile >> line;
  }

  cout << "To floor " << floor << '\n';
  cout << "Position he enters the basement " << position << '\n';

  return 0;
}
