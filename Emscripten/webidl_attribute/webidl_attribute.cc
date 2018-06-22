/*
#include <iostream>

using namespace std;
*/

class WebIDL {
public:
	WebIDL (int x) : x(x) {}
	int x;
};

/*
int main (int argc, char **argv) {
	WebIDL* i = new WebIDL(1);
	WebIDL* j = new WebIDL(2);
	WebIDL k = i->passThroughToValue(j);
	cout << k.getValueXByValue() << endl;
}
*/