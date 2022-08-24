class Solution {
public:
    int reverse(int x) {
        int tmp = x;
        int out = 0;
        do{
            
            auto digit = tmp%10;
            //cout << "out:" << out << endl;
            if(out > INT_MAX/10){
                //cout << __LINE__ << endl;
                return 0;
            }else if(out < INT_MIN/10){
                //cout << __LINE__ << endl;
                return 0;
            }
            
            out *= 10;
            if(out > 0 && out > (INT_MAX - (tmp%10))){
                //cout << __LINE__ << endl;
                return 0;
            }else if(out < 0 && out < INT_MIN - (tmp%10)){
                //cout << __LINE__ << endl;
                return 0;
            }
            out += digit;
            tmp /= 10;
        }while(tmp != 0);
        return out;
    }
};
