#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
		string * _s;
		string * _p;
		//int dbg = 0;
		unordered_map<int, unordered_map<int, bool>> dp;
	private:
		bool dfs(int i, int j)
		{
			//if(dbg++ > 300){
			//	return false;
			//}
			//cout << "i = " << i << "," << j << endl;
			if(i >= _s->size() && j >= _p->size()){
				return true;
			}
			if(j >= _p->size()){
				return false;
			}

			if(dp.find(i)!= dp.end() ){ 
				if(dp[i].find(j) != dp[i].end()){
					//cout << "dp:" << dp[i][j] << endl;
					return dp[i][j];
				}
			}
			//very important to check if i is still in s[]
			auto match = (i < _s->size())&&(((*_s)[i] == (*_p)[j]) || (*_p)[j] == '.');

			if((j + 1)< _p->size() && (*_p)[j+ 1] == '*'){
				//cout << __LINE__ << endl;
				dp[i][j] = dfs(i, j + 2) || (match?dfs(i + 1, j):0);
				//cout << __LINE__ << ":"<< dp[i][j] << endl;
				return dp[i][j];
			}

			if(match){
				//cout << __LINE__ << endl;
				dp[i][j] = dfs(i+1, j+1);
				return dp[i][j];
			}

			//cout << __LINE__ << endl;

			dp[i][j] = false;
			return false;
		}
	public:
		bool isMatch(string s, string p) 
		{
			_s = &s;
			_p = &p;
			return dfs(0, 0);
		} 
};


int main()
{
	string s = "ab";
	string p = ".*c";
	Solution S;
	cout << S.isMatch(s, p) << endl;
	return 0;
}
