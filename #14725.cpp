/*
BackJoon No.
#14725
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Trie{
	map<string, Trie*> children;

	void insert(vector<string>& info, int idx){
		if(idx == info.size())	return;
		
		auto aptChild = children.find(info[idx]);
		if(aptChild == children.end()){
			Trie* t = new Trie;
			children.insert({info[idx], t});
			t->insert(info, idx+1);
		}else{
			aptChild->second->insert(info, idx+1);
		}
	}

	void print(int depth){
		if(children.empty())	return;

		for(auto& child : children){
			for(int i=0; i<depth; ++i){
				cout << "--";
			}
			cout << child.first << '\n';

			child.second->print(depth+1);
		}
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int infoNum;
	cin >> infoNum;

	Trie root;
	for(int _=0; _<infoNum; ++_){
		int infoLen;
		cin >> infoLen;

		vector<string> info(infoLen);
		for(int i=0; i<infoLen; ++i)
			cin >> info[i];

		root.insert(info, 0);
	}

	root.print(0);

	return 0;
}