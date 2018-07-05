#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <emscripten.h>

using namespace std;

char EMSCRIPTEN_KEEPALIVE add (char x, char y) {
	// string;
	string s = "This comes from C++.";
  cout << s << endl;

  // vector;
  vector<int> v{1, 2, 3, 4, 5};
  for (auto i : v) {
  	cout << i << endl;
  }

  // map
  map<int, int> m = {
    pair<int, int> (1, 2),
    pair<int, int> (2, 3)
  };
  for (auto i : m) {
  	cout << i.first << ":" << i.second << endl;
  }

  // general;
  int d = 10;
  double f = 1.5;
  cout << d << " " << f << endl; 

  return x + y;
}
