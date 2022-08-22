class Solution {
public:
    int rob(vector<int>& nums) {
        int max_rob = 0;
        int max_pass = 0;
        int _max;

        for(auto i = 0; i < nums.size(); i++){
            if(i == 0){
                _max = nums[i];
                continue;
            }
            
            max_rob = max_pass + nums[i];
            max_pass = _max;
            _max = max(max_pass, max_rob);
        }
        
        return _max;
    }
};
