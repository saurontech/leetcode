class Solution {
	public:
		int myAtoi(string s) {
			int __access_number = 0;
			int signess = 1;
			int out = 0;
			for(auto i :s){
				if(__access_number == 0){
					if(i == ' '){
						continue;
					}else if(i == '+'){
					}else if(i == '-'){
						signess = -1;
					}else if(i >= '0' && i <= '9'){
						out = i - '0'; 
					}else{
						return 0;
					}
					__access_number = 1;
				}else{
					if(i >= '0' && i <= '9'){
						if(out > (INT_MAX/10)){
							cout << out << "out" << INT_MAX <<  endl;
							return (signess >= 0)?INT_MAX:INT_MIN;
						}
						out *= 10;
						if(out > (INT_MAX - (i-'0' ))){
							return (signess >= 0)?INT_MAX:INT_MIN;
						}
						out += i -'0';
						continue;
					}

					break;
				}
			}

			return signess * out;
		}
};
