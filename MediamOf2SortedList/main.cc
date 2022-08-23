class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>::iterator _long, _short;
        int _llen, _slen;
        if(nums1.size() >nums2.size()){
            _long = nums1.begin();
            _llen = nums1.size();
            _short = nums2.begin();
            _slen = nums2.size();
        }else{
            _long = nums2.begin();
            _llen = nums2.size();
            _short = nums1.begin();
            _slen = nums1.size();
        }
        int m = (_llen + _slen)/2;
        int i_s = (_slen/2) -1;
        int i_l = (m - i_s) -2;
        //cout << "m=" << m << endl;
        //cout << "is = "<< i_s << endl;
        
        do{
            cout << i_l << ":" << i_s << endl;
#define __short(A)  (((A)>=0)?(((A) < _slen)?*(_short +(A)):INT_MAX):INT_MIN)
#define __long(A)  (((A) >=0)?(((A) < _llen)?*(_long + (A)):INT_MAX):INT_MIN)
           if((__short(i_s) <= __long(i_l+1)) &&
               (__long(i_l) <= __short(i_s+1))){
                //cout << i_l << "--" << i_s << endl;
                if((_llen + _slen)&0x1){
                   // cout << "min" << min(__long(i_l + 1), __short(i_s + 1)) << endl;
                    return min(__long(i_l + 1), __short(i_s + 1)); 
                }else{
                    //cout << __long(i_l) << "|" << __short(i_s)<<endl;
                    //cout << __long(i_l + 1) << "_" << __short(i_s + 1) <<endl;
                    return (max(__long(i_l), __short(i_s)) + min(__long(i_l + 1), __short(i_s + 1)))/2.0;
                }
            }else if(__short(i_s) >= __long(i_l +1)){
               i_s--;
                i_l++;
               //cout << "aa" << __short(i_s) << "bb" << __long(i_l + 1) << endl;
               //break;
            }else{
                i_l--;
                i_s++;
               //cout << "cc" << __short(i_s + 1) << "dd" << __long(i_l) << endl;
               //break;
            }
            //cout << __long(i_l) << endl;
           // i_s--;
            //cout << __long(i_s);
            //break;
        }while(1);
        //return 1;
    }
};
