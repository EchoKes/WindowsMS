#include <iostream>
#include "Dictionary.h"
using namespace std;

int dictmain() {
	//Dictionary dic;
	string s = "sex";
	//cout << dic.hash(s);

	return 0;

	int total = 0;
	int n = s.length();

	for (int i = 0; i < n; i++) {
		char c = s.at(i);
		int ascChar = int(c);
		total += ascChar * (pow(n, n - 1));
		n -= 1;
	}
	cout << total % MAX_SIZE;
}