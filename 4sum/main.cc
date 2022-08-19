#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
	private:
		vector<vector<int>> twosum(vector<int>&nums, long long target)
		{
			vector<vector<int>> out;
			auto l = nums.begin();
			auto r = nums.end() - 1;
			while(l < r){
				if((*l + *r) < target){
					++l;
				}else if((*l + *r) > target){
					--r;
				}else{
					vector<int> ans;
					int tmp = *l;
					ans.push_back(*l);
					ans.push_back(*r);
					out.push_back(ans);
					
					while(*(++l) == tmp){
						if(l >= r){
							break;
						}
					}
				}
			}
			return out;
		}

		vector<vector<int>> k_sum(int k, vector<int>&nums, long long target)
		{
			auto average = target/k;

			if(k > nums.size()){
				return {};
			}
			if(average < nums.front() || average > nums.back()){
				return {};
			}
			
			if(k == 2){
				return twosum(nums, target);
			}
			vector<vector<int>> out;
			int prev;
			for(auto ptr = nums.begin(); ptr < (nums.end() - 2); ptr++){
				if(ptr != nums.begin() && prev == *ptr){
					continue;
				}
				prev = *ptr;
				auto subnums = vector<int>(ptr + 1, nums.end());
				auto ans = k_sum(k - 1, subnums, target - *ptr);
				for(auto _ans: ans){
					
					_ans.push_back(*ptr);
					
					out.push_back(_ans);
				}
			}
			return out;
		}
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target)
		{
			sort(nums.begin(), nums.end());
			return k_sum(4, nums, target);
		}
};

int main()
{
	Solution s;
	vector<int> input = {1,0,-1,0,-2,2};
	
	auto a = s.fourSum(input, 0);
	//vector<int> input = {0,0,0,0};
	
	//auto a = s.fourSum(input, 0);

	cout << "{ ";
	for(auto _a: a){
		cout << "{ ";
		for(auto __a:_a){
			cout << __a << ", ";
		}
		cout << "}, ";
		
	}
	cout << "}" << endl;
	return 0;
}
