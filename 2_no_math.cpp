#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
  ifstream ifile("io/day_2_1.in");
  if (!ifile.is_open()) {
    cout << "Couldn't open the file!\n";
    return 1;
  }

  int area = 0, length = 0;
  int l, w, h;
  ifile >> l;
  while (!ifile.eof()) {
    char t;
    ifile >> t >> w >> t >> h;
    area += 2*l*w + 2*w*h + 2*h*l;
    area += min(min(l*w, w*h), h*l);
    length += l*w*h;
    length += min(min(2*l+2*h, 2*l+2*w), 2*h+2*w);
    ifile >> l;
  }

  cout << area << " square feet of paper needed\n";
  cout << length << " feet of ribbon needed\n";

  return 0;
}
