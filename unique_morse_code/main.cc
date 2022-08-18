#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

class Solution {
private:
	vector<string> alphabet = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	set<string> _set;
public:
    int uniqueMorseRepresentations(vector<string>& words) {
	
	for(auto _w:words){
		string _tmp;
		_tmp.clear();
		for(int i=0; i < _w.length(); i++){
			int offset = _w[i] - 'a';
			//cout << _w[i] << " offset" << offset << endl;
			//cout << alphabet[offset] << endl;
			_tmp.append(alphabet[offset]);
		}
		cout << _w <<":" << _tmp << endl;
		_set.insert(_tmp);
	}
	return _set.size();
    }
};


int main()
{
	Solution s;
	vector<string> a = {"gin", "zen", "gig", "msg"};
	cout << s.uniqueMorseRepresentations(a) << endl;
}
