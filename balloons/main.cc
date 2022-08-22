#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <map>
#include <climits>

using namespace std;

class Solution11 {
	int cnt = 0;
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        int start=0;
        int end=nums.size()-1;
        return fun(nums,dp,start,end);
    }
    int fun(vector<int>&nums,vector<vector<int>>&dp,int start,int end)
    {
	//cout << cnt++ << "[" << start << ", " << end << "]\n";
        if(start>end)
        {
            return 0; //no balloon left
        }
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        int ans=INT_MIN;
        for(int k=start;k<=end;k++)
        {
            int val1=1;//nums[start-1]
            int val2=1;//nums[end+1]
            int val3=nums[k];
            if(start-1>=0)
            {
                val1=nums[start-1];
            }
            if(end+1<=nums.size()-1)
            {
                val2=nums[end+1];
            }
            ans=max(ans,val1*val3*val2+fun(nums,dp,start,k-1)+fun(nums,dp,k+1,end));
        }
        dp[start][end]=ans;
        return dp[start][end];
    }
};


class Solution {
	vector<int>::iterator _b;
	vector<int>::iterator _e;
	//int indent;
	int cnt = 0;
	//map<pair<vector<int>::iterator, vector<int>::iterator>, int> _dp;
	vector<vector<int>> *__dp;
	int _dac(vector<int>::iterator start, vector<int>::iterator end, int front, int back)
	{
		//indent++;
		int x = start - _b;
		int y = end - _b - 1;
		/*cout << cnt++ << "(" << front << "," << back << ")[" << start - _b << "," << end -_b << "]handle:";
		for(auto i = start; i != end; ++i){
			cout << *i << " ";
		}
		cout << endl;*/

		priority_queue<int> _max;
		/*if(_dp.find(make_pair(start, end)) != _dp.end()){
			cout << "using dp " << endl;
			return _dp[make_pair(start, end)];
		}*/
		if((*__dp)[x][y] != -1){
			/*cout << "using dp " << x << "," << y << ":"<< (*__dp)[x][y] << endl;
			for(auto i = 0 ; i < (*__dp).size(); i++){
			for(auto j = 0; j < (*__dp)[i].size(); j++){
				cout  << (*__dp)[i][j] << " "; 
			}
			cout << endl;
		}*/
			return (*__dp)[x][y];
		}
		if(end - start == 1){
			int tmp = 1;
			tmp = front * back * (*start);
			//_dp[make_pair(start, end)] = tmp;
			//cout << "leaf" << *start << ":" << tmp <<endl;
			//indent--;
			(*__dp)[x][y] = tmp;
			return tmp;
		}
		int i = 0;
		int __max = 0;
		for(auto last = start; last < end; ++last){
			//if(start == _b && end == _e){
			//	cout << "_______________________root" << endl;
			//}
			//cout << "indent =" << indent << endl;
			//cout << "ptr(" << start - _b << ","<<last - _b << "," <<  end - _b << ")" << endl;
			int coins = 0;
			if(last != start){
				//cout << "front----" << endl;
				coins += _dac(start, last, front, *last);
			}
			if(last < (end -1)){
				//cout << "back----" << endl;
				coins += _dac(last + 1, end, *last, back);
			}
			coins += front * back *(*last);
			//cout<< front << ":"<< *last << ":"<< back << endl;
			//cout<< " coins" << coins << endl;
			//_max.push(coins);
			if(coins > __max){
				__max = coins;
			}
		}
		//cout << "indent =" << indent << endl;
		//cout << "max" << __max << endl;
		//indent--;
		//_dp[make_pair(start, end)] = __max;
		(*__dp)[x][y] = __max;
		//return _max.top();
		return __max;
	}
	public:
	int maxCoins(vector<int>& nums) {
		_b = nums.begin();
		_e = nums.end();
		//indent = 0;
		__dp = new vector<vector<int>>(nums.size(),vector<int>(nums.size(),-1));
		/*for(auto i : (*__dp)){
			for(auto _i : i){
				cout  << _i << " "; 
			}
			cout << endl;
		}
		//cout << "222222222222" << endl;
		for(auto i = 0 ; i < (*__dp).size(); i++){
			for(auto j = 0; j < (*__dp)[i].size(); j++){
				cout  << (*__dp)[i][j] << " "; 
			}
			cout << endl;
		}*/
		return _dac(nums.begin(), nums.end(), 1, 1);
	}
};

class Solution1 {
public:
    
    /*
        this problem is variation of matrix chain multiplication and here we use gap strategy and what are we doing is we are assuming if the current balloon is burst at last so our answer will be answer from left + answer from right + nums[k]*previous and next after the current choosen 
        say if gap is 4 so we are taking those balloons first and finding its maximum value
    */ 
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        int dp[n][n];
        
        for(int gap = 0;gap<n;gap++)
        {
            for(int i = 0, j = gap;i<n , j<n ;i++,j++)
            {
                int mx = INT_MIN;
                for(int k = i;k<=j;k++)
                {
                    int left = 0;
                    if(k>i)
                        left = dp[i][k-1];
                    
                    int right = 0;
                    if(k<j)
                        right = dp[k+1][j];
                    
                    int val = nums[k];
                    if(i>0)
                        val *= nums[i-1];
                    if(j+1<n)
                        val *= nums[j+1];
                    
                    int total = val + left + right;
                    mx = max(mx,total);
                }
                dp[i][j] = mx;
            }
        }
        
        return dp[0][n-1];
    }
};

int main()
{
	//vector<int> balloons = {3, 1, 5, 8};
vector<int> balloons = {70,53,55,58,46,3,75,69,30,75,79,41,93,92,37,90,74,68,69,80,67,1,48,46,66,50,26,45,56,36,98,12,41,39,83,63,70,75,40,8,41,43,61,37,68,27,0,11,12,20,79,24,60,52,11,74,12,51,76,12,32,61,0,79,44,50,28,13,85,67,92,93,15,77,70,5,2,50,19,9,69,71,45,24,40,34,53,1,77,12,34,26,51,63,28,59,100,68,48,11,27,3,13,64,59,44,15,53,34,15,1,17,10,13,0,84,38,2,8,53,12,1,36,49,2,83,72,33,38,11,55,27,66,74,100,100,46,34,60,0,3,19,27,49,9,33,28,4,54,79,49,52,61,11,5,78,56,67,39,68,86,1,41,59,72,99,81,75,15,20,88,49,41,21,70,42,29,93,44,43,94,68,66,23,37,92,21,2,34,8,11,48,36,22,61,83,22,72,96,64,39,16,98,46,60,60,92,49,100,68,0,87,87,31,47,47,43,10,85,35,32,58,43,61,40,93,1,86,50,53,88,6,30,41,49,63,35,40,0,95,86,5,64,62,1,17,24,30,61,18,57,97,99,7,39,64,73,17,72,8,25,82,3,18,13,27,61,18,17,17,94,63,35,65,18,96,9,92,51,73,81,89,13,22,77,84,17,73,77,4,27,61,71,10,25,30,16,16,64,100};
	
	Solution s;
	Solution11 s1;
	cout << "111111111111111111" << endl;
	cout << s.maxCoins(balloons) << endl;
	cout << s1.maxCoins(balloons) << endl;
	return 0;
}
