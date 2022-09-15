#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
/*
class Solution {
	vector<int> out;
	public:
	vector<int> findOriginalArray(vector<int>& changed) {
		sort(changed.begin(), changed.end());
		for(auto ptr = changed.begin(); ptr != changed.end();){
			auto target = (*ptr)*2;
			auto _ptr = find(ptr+1, changed.end(), target);
			if( _ptr != changed.end()){
				changed.erase(_ptr);
				out.push_back(*ptr);
				ptr = changed.erase(ptr);
			}else{
				return {};
			}
		}
		return out;
	}
};
*/
class Solution {
	vector<int> out;
	multiset<int> s;
	public:
	vector<int> findOriginalArray(vector<int>& changed) {
		//sort(changed.begin(), changed.end());
		s.insert(changed.begin(), changed.end());
		/*for(auto ptr = changed.begin(); ptr != changed.end();){
			auto target = (*ptr)*2;
			auto _ptr = find(ptr+1, changed.end(), target);
			if( _ptr != changed.end()){
				changed.erase(_ptr);
				out.push_back(*ptr);
				ptr = changed.erase(ptr);
			}else{
				return {};
			}
		}*/
		while(s.size()){
			int smallest = *s.begin();
			out.push_back(smallest);
			s.erase(s.begin());
			auto target_ptr = s.find(smallest * 2);
			if(target_ptr == s.end()){
				return {};
			}

			s.erase(target_ptr);
		}

		return out;
	}
};

int main()
{
	Solution s;
	//vector<int> input = {1, 3, 4, 2, 6, 8};
	vector<int> input {6, 3, 0, 1};
	auto out = s.findOriginalArray(input);
	cout << "{";
	for(auto i: out){
		cout << i << ",";
	}
	cout << "}" << endl;

	return 0;
}
