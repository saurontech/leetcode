class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a, b;
        a = b = 0;
        int maxlen = 0;
        set<int> _s;
        //int i = 0;
        
        while(b < s.length()){
            //cout << a << ":" << b <<endl;
            if(_s.find(s[b]) != _s.end()){
                _s.erase(s[a]);
                a++;
                continue;
            }
            _s.insert(s[b]);
            b++;
            if(_s.size() > maxlen){
                maxlen = _s.size();
            }
        }
        return maxlen;
    }
};
