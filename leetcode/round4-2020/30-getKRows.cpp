#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
void printVector(vector<T> vec) {
	//cout << "[-] " << __func__ << endl;
	for(int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

template<typename T>
void printVectorVector(vector<vector<T>> vec) {
	//cout << "[-] " << __func__ << endl;
	for(int i = 0; i < vec.size(); ++i) {
		for(int j = 0; j < vec[i].size(); ++j)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

template<typename T>
void freeVector(vector<T> vec) {
	cout << "[-] " << __func__ << endl;
	if(!vec.empty()) {
		vec.clear();
		vector<T>().swap(vec);
	}
}

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr) {};
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

void printList(ListNode *head) {
	//cout << "[-] " << __func__ << endl;
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void freeList(ListNode *head) {
	cout << "[-] " << __func__ << endl;
	while(head) {
		ListNode *p = head;
		cout << head->val << " ";
		head = head->next;
		delete p;
	}
	cout << endl;
}

void freeTree(TreeNode* root) {
	cout << "[-] " << __func__ << endl;
	if(root) {
		TreeNode* node = root;
		cout << __func__ << " node val:\t" << node->val << endl;
		freeTree(node->left);
		freeTree(node->right);
		//node = nullptr;	// not suitable for delete, only suitable for free
		delete node;
	}
}

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ret;
		for(int i = 0; i <= rowIndex; ++i) {
			for(int j = i - 1; j >= 0; --j) {
				if(j == 0)
					continue;
				ret[j] += ret[j-1];
			}
			ret.push_back(1);	
			//cout << "getRow_" << i << endl;
			//printVector(ret);
		}
		return ret;
	}
};

int main(int argc, char **argv) {

	Solution *s = new Solution();

	vector<int> result = s->getRow(5);
	printVector(result);

	delete s;
	return 0;
}
