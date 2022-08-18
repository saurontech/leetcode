#include <vector>
#include <iostream>
#include <map>

using namespace::std;

/*class Solution {
	private:
		vector<int> output;
		int cnt;
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			cnt = 0;
			for(auto i = nums.begin(); i != nums.end(); ++i){
				for(auto j = next(i); j != nums.end(); ++j){
					cnt++;
					if(*i + *j == target){
						output.push_back(*i);
						output.push_back(*j);
					}
				}
			}
			cout << "cnt" << cnt << endl;

			return output;
		}
};*/

class Solution{
	private:
		int cnt;
		map<int, vector<int>::iterator> _m;
		vector <int> out;
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			cnt = 0;
			for(auto _i = nums.begin(); _i != nums.end(); ++_i){
				_m[*_i] = _i;
				cnt++;
			}
			
			for(auto _i = nums.begin(); _i != nums.end(); ++_i){
				auto j = target - *_i;
				cnt++;
				//cout << "i=" << *_i << "j = " << j << endl;
				if(_m.find(j) != _m.end() && _m[j] != _i){
					//out.push_back(*_i);
					out.push_back( _i - nums.begin());
					//out.push_back(j);
					out.push_back(_m[j] - nums.begin());
					break;
				}
			}
			cout << "cnt" << cnt << endl;
			return out;
		}
};

int main()
{
	Solution s;
	vector<int> input = {2,7,11,15};
	int target = 9;
	auto out =  s.twoSum(input, target);
	for(auto i :out){
		cout << i << " ";
	}
	cout << endl;
}
