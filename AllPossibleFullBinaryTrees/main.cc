#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
	
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	private:
		map<int, vector<TreeNode*>> _m;
	public:
		vector<TreeNode*> allPossibleFBT(int n) {
			cout << "enter function" << ":" << n << endl;
			vector<TreeNode*> out = {};

			if(_m.find(n) != _m.end()){
				cout << "	lookup" << ":" << n << endl;
				return _m[n];
			}else if( n == 1){

				cout << "-----------------leaf" << ":" << n << endl;
				out.push_back(new TreeNode());
			}else if(n%2 == 1){
				for(int i = 1; i < n -1; i+=2){
					int j = n -1 -i;
					auto _l = allPossibleFBT(i);
					auto _r = allPossibleFBT(j);
					for(auto __r:_r){
						for(auto __l:_l){
							cout << "new" << ":" << n;
							cout << "i=" << i << " ";
							cout << "j=" << j << " " << endl;
							auto _node = new TreeNode(0, __l, __r);

							out.push_back(_node);
						}
					}
				}
			}else{
				cout << "output{} n=" << n << endl;
			}
			_m[n] = out;
			
			return out;
		}
};

int main()
{
	Solution s;
	s.allPossibleFBT(7);
	return 0;
}

