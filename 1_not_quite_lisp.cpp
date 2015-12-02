#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int solve_first() {
  ifstream ifile("io/day_1_1.in");
  if (!ifile.is_open()) {
    cout << "Couldn't open the file!\n";
    return 1;
  }

  string line;
  ifile >> line;
  int floor = 0;
  while (!ifile.eof()) {
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == '(') ++floor;
      if (line[i] == ')') --floor;
    }
    ifile >> line;
  }

  return floor;
}

int solve_second() {
  ifstream ifile("io/day_1_2.in");
  if (!ifile.is_open()) {
    cout << "Couldn't open the file!\n";
    return 1;
  }

  string line;
  ifile >> line;
  int position = 1;
  int floor = 0;
  while (!ifile.eof()) {
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == '(') ++floor;
      if (line[i] == ')') --floor;
      if (floor == -1) return position;
      ++position;
    }
    ifile >> line;
  }

  return -1;
}

int main() {

  cout << "To floor " << solve_first() << '\n';
  cout << "Position he enters the basement " << solve_second() << '\n';

  return 0;
}
