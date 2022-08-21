//https://leetcode.com/problems/sum-of-two-integers/
class Solution {
public:
    int getSum(int a, int b) {
        int out = 0;
        int c = 0;
        for(unsigned int mask = 1; mask != 0; mask <<= 1){
            int tmp = 0;
            
            if((a^b)&mask){
                out |= mask;
            }else if((a&b)&mask){
                c |= (mask << 1);
            }else{
                
            }
            //cout << "ab(" <<  bitset<8>(a) << "," << bitset<8>(b);
            //cout << ")" <<mask << "|" << bitset<8>(c) << "|"<<out<<endl;
            if(c&mask){
                if(out&mask){
                    c |= mask << 1;
                    out &=(~mask);
                }else{
                    out |= mask;
                }
            }
        }
        return out;
    }
};
