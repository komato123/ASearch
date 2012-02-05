#include <iostream>
#include <vector>
#include <string>
#include "suffix_array.h"
using namespace std;


int main()
{
	string str = "abcbccab";
	vector<int> vi;

	a_search::SuffixArray sa;

	sa.makeSuffixArray(str.size(), str.c_str(), vi);

	cout << "input:" << str << endl;
	cout << "output:[" ;
	for (vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) {
		cout << *it << ",";
	}
	cout << "]" << endl;

	getchar();
}


