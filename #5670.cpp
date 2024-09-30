/*
BackJoon No.
#5670
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

const int SMALLCASE_NUM = 'z' - 'a' + 1;

class Trie{
private:
	unordered_map<char, Trie*> children;
	
public:
	~Trie(){
		for(auto& child : children){
			delete child.second;
		}
	}

	void insert(const string& str, const int idx){
		if(idx > str.length())		return;

		char ch = str[idx];
		if(children.find(ch) == children.end()){
			children[ch] = new Trie();
		}

		children[ch]->insert(str, idx+1);
	}

	double cnt(const string& str, int idx, double value){
		if(idx >= str.length())		return value;

		char ch = str[idx];
		if(children.find(ch) == children.end()){
			return value;
		}

		if(idx == 0){
			return children[ch]->cnt(str, idx+1, value+1);
		}

		if(children.size() == 1){
			return children[ch]->cnt(str, idx+1, value);
		}
		
		if(idx == str.length()-1){
			return children[ch]->cnt(str, idx+1, value);
		}

		return children[ch]->cnt(str, idx+1, value+1);
	}
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

			cout << words[i] << " 의 cnt 값 : " << root.cnt(words[i], 0, 1) << endl;
		}

		cout << total / wordNum << '\n'; 
	}

	return 0;
}