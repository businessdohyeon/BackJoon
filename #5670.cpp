/*
BackJoon No.
#5670
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <memory.h>

using namespace std;

constexpr int SMALLCASE_NUM = 'z' - 'a' + 1;
constexpr int NULL_CHAR_IDX = SMALLCASE_NUM;
constexpr int CHILDREN_SIZE = SMALLCASE_NUM + 1;

class Trie{
public:
	Trie(){
		memset(children, 0, sizeof(children));
		childrenCnt = 0;
	}

	~Trie(){
		for(const auto& child : children){
			if(child != nullptr){
				delete child;
			}
		}
	}

	void insert(const string& str, const int idx){
		if(idx > str.length())		return;

		Trie*& aptChild = (idx == str.length() ? children[NULL_CHAR_IDX] : children[str[idx] - 'a']);
		if(aptChild == nullptr){
			aptChild = new Trie();
			++childrenCnt;
		}

		aptChild->insert(str, idx+1);
	}

	double cnt(const string& str, int idx, double value){
		if(idx >= str.length()){
			return value;
		}

		Trie*& aptChild = children[str[idx] - 'a'];
		if(aptChild == nullptr){
			return value;
		}

		if(idx == 0){
			return aptChild->cnt(str, idx+1, value+1);
		}

		if(childrenCnt == 1){
			return aptChild->cnt(str, idx+1, value);
		}
		
		return aptChild->cnt(str, idx+1, value+1);
	}

private:
	Trie* children[CHILDREN_SIZE];
	int childrenCnt;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout << fixed << setprecision(2);

	int wordNum;
	while(cin >> wordNum){
		Trie root;

		vector<string> words(wordNum);
		for(int i=0; i<wordNum; ++i){
			cin >> words[i];
			root.insert(words[i], 0);
		}

		double total = 0;
		for(int i=0; i<wordNum; ++i){
			total += root.cnt(words[i], 0, 0);
		}

		cout << total / wordNum << '\n'; 
	}

	return 0;
}