#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace::std;

class Solution {
private:
	vector<vector<int>> out;
	int prev;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
	/*for(auto ptr: nums){
		cout << ptr << " ";
	}
	cout << endl;*/
	for(auto ptr = nums.begin(); ptr != nums.end(); ++ptr){
		if(ptr == nums.begin()){
		}else if(prev == *ptr){
			continue;
		}
		prev = *ptr;
		auto left = ptr + 1;
		auto right = nums.end() - 1;
		
		while(left < right){
			//cout << "l:" << *left << "r:" << *right << endl;
			int _tmp = *left + *right;
			if( _tmp > -(*ptr)){
				--right;
			}else if(_tmp < -(*ptr)){
				++left;
			}else{
				//cout << *ptr << " " << *left << " " << *right << endl;
				int _tmp;
				out.push_back(vector<int>{*ptr, *left, *right});
				_tmp = *left;
				while((left++) < right){
					//cout << "tmp" << _tmp << endl;
					if(*left == _tmp){
						//cout << "left = " << *left << endl;
						continue;
					}
					break;
				}
			}
			
		}
		
	}
	return out;
    }
};

int main()
{
	Solution s;
	//vector<int> input = {2,7,11,15};
	vector<int> input = {-1,0,1,2,-1,-4};
	auto out =  s.threeSum(input);
	cout << "{";
	for(auto a :out){
		cout << "{";
		for(auto b :a){
			cout << b << ",";
		}
		cout << "},";
	}
	cout << "}";
	
}
