//https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
//practice to do it with unordered map
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
//#include <pair>
using namespace std;

/* too slow...
struct hash_pair{
	template<class T1, class T2>
		size_t operator()(const pair<T1, T2> &p)
		{
			auto hash1 = hash<T1>{}(p.first);
			auto hash2 = hash<T2>{}(p.second);
			if(hash1 != hash2){
				return hash1 ^ hash2;
			}

			return hash1;
		}
};

class Solution {
	unordered_map<pair<int, int>, int, hash_pair> dp;
	public:
		int rec(int idx,int st,int end,vector<int>& nums,vector<int>& multi){
			if(idx==multi.size()) return 0;
			if(dp.find(make_pair(idx, st)) != dp.end()) return dp[make_pair(idx,st)];
			int ans;
			ans= max(multi[idx]*nums[st]+ rec(idx+1,st+1,end,nums,multi),
					multi[idx]*nums[end]+ rec(idx+1,st,end-1,nums,multi));
			return dp[make_pair(idx, st)]= ans;
		}
		int maximumScore(vector<int>& nums, vector<int>& multi) {
			//vector<vector<int>> dp(multi.size(),vector<int>(multi.size(),INT_MIN));
			return rec(0,0,nums.size()-1,nums,multi);
		}
};
*/


class Solution {
	public:
		int rec(int idx,int st,int end,vector<int>& nums,vector<int>& multi,vector<vector<int>> &dp){
			if(idx==multi.size()) return 0;
			if(dp[idx][st]!=INT_MIN) return dp[idx][st];
			int ans=INT_MIN;
			ans= max(multi[idx]*nums[st]+ rec(idx+1,st+1,end,nums,multi,dp),
					multi[idx]*nums[end]+ rec(idx+1,st,end-1,nums,multi,dp));
			return dp[idx][st]= ans;
		}
		int maximumScore(vector<int>& nums, vector<int>& multi) {
			vector<vector<int>> dp(multi.size(),vector<int>(multi.size(),INT_MIN));
			return rec(0,0,nums.size()-1,nums,multi,dp);
		}
};

int main()
{
	vector<int> nums = {-5,-3,-3,-2,7,1};
	vector<int> multipliers = {-10,-5,3,4,6};

	Solution s;
	cout << s.maximumScore(nums, multipliers) << endl;
	return 0;

}
