#include <iostream>
#include <string>

using namespace std;

int main (int argc, char* argv[]) {
  string s;
  while(cin >> s) {
    if (s != "e")
      cout << s;
    else
      break;
  };

  return 0;
}
