/*
BackJoon No.
#1271
*/

#include <iostream>
#include <string>

using namespace std;

class BigInt{
private:
	string value;
public:
	friend istream& operator>>(istream& is, BigInt& target){
		is >> target.value;
		return is;
	}

	friend ostream& operator<<(ostream& os, const BigInt& target){
		os << target.value;
		return os;
	}

	void operator=(const string& str){
		this->value = str;
	}
	void operator=(const BigInt& target){
		this->value = target.value;
	}

	bool operator>=(const BigInt& target){
		if(this->value.size() != target.value.size()){
			return (this->value.size() > target.value.size());
		}

		for(int i=0; i<this->value.size(); ++i){
			if(this->value[i] != target.value[i]){
				return (this->value[i] > target.value[i]);
			}
		}

		return true;
	}

	BigInt& operator++(){
		this->value[this->value.size() -1] += 1;

		for(int idx = this->value.size()-1; idx >=0; --idx){
			if(this->value[idx] > '9'){
				this->value[idx] -= 10;
				if(idx == 0){
					this->value = "1" + this->value;
				}else{
					this->value[idx-1] += 1;
				}
			}
		}

		return (*this);
	}

	BigInt& operator-=(const BigInt& target){
		for(int idxA = this->value.size()-1, idxB = target.value.size()-1; idxB >= 0; --idxA, --idxB){
			this->value[idxA] = (this->value[idxA] - target.value[idxB]) + '0';

			if(this->value[idxA] < '0'){
				this->value[idxA] += 10;
				this->value[idxA -1] -= 1;
			}
		}

		for(int idxA = this->value.size()-1; idxA >=0; --idxA){
			if(this->value[idxA] < '0'){
				this->value[idxA] += 10;
				this->value[idxA -1] -= 1;
			}
		}

		while(this->value.size() > 1 && this->value[0] == '0'){
			this->value = this->value.substr(1);
		}

		return (*this);
	}

};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	BigInt n, m;
	cin >> n >> m;

	BigInt q;
	q = "0";

	while(n >= m){
		n -= m;
		++q;
	}

	cout << q << '\n' << n;

	return 0;
}