#include <iostream>
using namespace std;

struct rect{
	int length;
	int breathe;
};

int main(int argc, char** argv) {
	struct rect r;
	r.length = 10;
	r.breathe = 15;
	cout << "Area : "<< r.length*r.breathe;
	return 0;
}
