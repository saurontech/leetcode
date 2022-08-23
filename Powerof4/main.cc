class Solution {
public:
    bool isPowerOfFour(int n) {
        unsigned int mask = 1;
        while(mask != 0){
            if(mask == n)
                return true;
            
            mask <<=2;
        }
        return false;
    }
};
