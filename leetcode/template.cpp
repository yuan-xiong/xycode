#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string int2Roman(int num) {
		string ret = "";
		return ret;
	}
};

int main(int argc, char **argv) {

	int test = 13;
	cout << "[+] test:\t" << test << endl;

	Solution *s = new Solution();

	string result = s->int2Roman(test);
	cout << "[+] result:\t" << result << endl;

	return 0;
}
