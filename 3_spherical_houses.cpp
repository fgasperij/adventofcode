#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <utility>

using namespace std;

int main() {
  ifstream ifile("io/day_3.in");
  if (!ifile.is_open()) {
    cout << "Couldn't open the file!\n";
    return 1;
  }


  unordered_set<string> hs;
  unordered_set<string> hs_robot;
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  int x = 0, y = 0;
  int houses = 1, houses_robot = 1;
  hs.insert("0,0");
  hs_robot.insert("0,0");
  string s;
  ifile >> s;
  while (!ifile.eof()) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '<') --x;
      if (s[i] == '<' && i % 2 == 0) --x1;
      if (s[i] == '<' && i % 2 == 1) --x2;
      if (s[i] == '>') ++x;
      if (s[i] == '>' && i % 2 == 0) ++x1;
      if (s[i] == '>' && i % 2 == 1) ++x2;
      if (s[i] == '^') ++y;
      if (s[i] == '^' && i % 2 == 0) ++y1;
      if (s[i] == '^' && i % 2 == 1) ++y2;
      if (s[i] == 'v') --y;
      if (s[i] == 'v' && i % 2 == 0) --y1;
      if (s[i] == 'v' && i % 2 == 1) --y2;

      string hash = to_string(x) + "," + to_string(y);
      unordered_set<string>::iterator it = hs.find(hash);
      if (it == hs.end()) {
        ++houses;
        hs.insert(hash);
      }
      string hash1 = to_string(x1) + "," + to_string(y1);
      string hash2 = to_string(x2) + "," + to_string(y2);
      unordered_set<string>::iterator it1 = hs_robot.find(hash1);
      unordered_set<string>::iterator it2 = hs_robot.find(hash2);
      if (it1 == hs_robot.end()) {
        ++houses_robot;
        hs_robot.insert(hash1);
      }
      if (it2 == hs_robot.end()) {
        ++houses_robot;
        hs_robot.insert(hash2);
      }
    }
    ifile >> s;
  }

  cout << houses << " houses received presents\n";
  cout << houses_robot << " robot houses received presents\n";

  return 0;
}
