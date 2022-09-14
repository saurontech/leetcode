#include <iostream>
#include <vector>
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

	int dfs(TreeNode * node, unsigned int __map){
		int ret = 0;
		__map ^= (1 << node->val);
		if(node->left == node->right &&
				node->left == nullptr){
				int _tmp = 0;
				for(auto i = 0; i < 31; i++){
					unsigned _val = 0x1 << i;
					if(_val & __map){
						_tmp++;
					}
					if(_tmp >= 2){
						return 0;
					}
				}
				return 1;
		}
		
		if(node->left){
			
			ret += dfs(node->left, __map);
		}
		if(node->right){
			//cout << "right path" << endl;
			ret += dfs(node->right, __map);
		}
		cout << "return" << ret << endl; 
		return ret;
	}
	public:
	int pseudoPalindromicPaths (TreeNode* root) {
		unsigned int tmp = 0;
		return dfs(root, tmp);
	}
};


/*
class Solution {

	int dfs(TreeNode * node, vector<int> __vector){
		int ret = 0;
		__vector.push_back(node->val);
		if(node->left == node->right &&
				node->left == nullptr){
				cout << "path ";
				for(auto _out: __vector){
					cout << _out <<",";
				}
				cout << endl;
			for(auto __a = __vector.begin(); __a < __vector.end();){
				//cout << "a loop";
				//cout << "__a" << __a - __vector.begin() << ",";
				//cout << "size" << __vector.size() << endl;
				auto __b = __a + 1;
				int __continue = 0;
				for( ; __b < __vector.end(); ){
						
						cout << "__a" << __a - __vector.begin() << ",";
						cout << "__b" << __b - __vector.begin() << ",";
						cout << "size" << __vector.size() << endl;
						
						if(*__a == *__b){
							cout << "bbbbb";
							__a = __vector.erase(__a);
							cout << "remove " << *__a;
							//__vector.erase(__b);
							cout << "ccc";
							cout << (long long) __b;
							__vector.erase(__b);
							//__a = __vector.erase(__a);
							cout << "ddd";
							//cout << " a = " << __a - __vector.begin() << endl;
							cout << "update path ";
							for(auto _out: __vector){
								cout << _out <<",";
							}
							cout << endl;
							__continue = 1;
							break;
						}
						__b++;
				}
				if(__continue){
					continue;
				}
				cout << "next a" << __a - __vector.begin() << endl;
				__a++;
			}
			if(__vector.size() <= 1){
				cout << "end check success" << endl; 
				return 1;
			}
			cout << "end check fail" << __vector.size() << endl;
			return 0;
		}
		if(node->left){
			//cout << "left path" << endl;
			ret += dfs(node->left, __vector);
		}
		if(node->right){
			//cout << "right path" << endl;
			ret += dfs(node->right, __vector);
		}
		cout << "return" << ret << endl; 
		return ret;
	}
	public:
	int pseudoPalindromicPaths (TreeNode* root) {
		vector<int> path;
		return dfs(root, path);
	}
};
*/

int main()
{
/*	TreeNode root(2);
	root.left = new TreeNode(3);
	root.left->left = new TreeNode(3);
	root.left->right = new TreeNode(1);
	root.right = new TreeNode(1);
	root.right->right = new TreeNode(1);*/
	TreeNode root(2);
	root.left = new TreeNode(8);
	root.left->right = new TreeNode(7);
	root.right = new TreeNode(4);
	root.right->right = new TreeNode(7);
	root.right->right->right = new TreeNode(4);
	root.right->right->right->left = new TreeNode(2);



	Solution s;
	auto cnt = s.pseudoPalindromicPaths(&root);
	cout << "result=" << cnt << endl;
	return 0;
}
