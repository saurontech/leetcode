#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

template <typename T,
          typename TIter = decltype(std::begin(std::declval<T>())),
          typename = decltype(std::end(std::declval<T>()))>
constexpr auto enumerate(T && iterable)
{
    struct iterator
    {
        size_t i;
        TIter iter;
        bool operator != (const iterator & other) const { return iter != other.iter; }
        void operator ++ () { ++i; ++iter; }
        auto operator * () const { return std::tie(i, *iter); }
    };
    struct iterable_wrapper
    {
        T iterable;
        auto begin() { return iterator{ 0, std::begin(iterable) }; }
        auto end() { return iterator{ 0, std::end(iterable) }; }
    };
    return iterable_wrapper{ std::forward<T>(iterable) };
}

using namespace std;

class Solution {
	private:
		// {1, 1, 2, 3, -1, 3, -1, -2, 2, -3, 1}
		
	public:
		//{-4, 0, 1, -3, 1, 1, 2, 3, -1, 4};
		auto kadans(vector<int>&nums)
		{	
			int best_start, best_end;
			int tmp_end, tmp_start;
			int tmp_sum = 0;
			int best_sum = INT_MIN;
			for( auto && [tmp_end, val] : enumerate(nums)){
		//the sum of the [tmp_start:tmp_end] must overway the effect of adding val
		//otherwise, we ignore the previus sum and start over again
				if(tmp_sum <= 0){
					tmp_start = tmp_end;
					tmp_sum = val;
				}else{
					tmp_sum += val;
				}

				if(tmp_sum > best_sum){
					best_sum = tmp_sum;
					best_start = tmp_start;
					best_end = tmp_end;
				}


			}
			return make_tuple(best_sum, best_start, best_end);
		}
		auto kadans2(vector<int>&nums)
		{	
			//int sum,
			//int tmp_end, tmp_start;
			int tmp_sum1 = 0;
			int tmp_sum2 = 0;	
			int max_sum = INT_MIN;
			int min_sum = INT_MAX;
			for( auto && [tmp_end, val] : enumerate(nums)){
				if(tmp_sum1 <= 0){
					//tmp_start = tmp_end;
					tmp_sum1 = val;
				}else{
					tmp_sum1 += val;
				}

				if(tmp_sum1 > max_sum){
					max_sum = tmp_sum1;
				}

				if(tmp_sum2 >= 0){
					tmp_sum2 = val;
				}else{
					tmp_sum2 += val;
				}				
				
				if(tmp_sum2 < min_sum){
					min_sum = tmp_sum2;
				}

			}
			return make_tuple(max_sum, min_sum);
		}


		int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
			vector<int> diff1, diff2;
			int sum1, sum2;
			sum1 = sum2 = 0;
			for(auto i = 0; i < nums1.size(); i++){
				diff1.push_back(nums1[i] - nums2[i]);
				sum1 += nums1[i];
				sum2 += nums2[i];
			}

			auto [_max, _min] = kadans2(diff1);

			return max(sum1 - _min, sum2 + _max);
		 }
};

int main(){
	vector<int> input = {-400, 0, 1, -3, 4, 1, 2, 3, -1, 4};

	Solution s;
	auto [max, start, end] = s.kadans(input);
	cout << "max:" << max << " ";
	cout << "start:" << start << " ";
	cout << "end:" << end << "\n";
	auto [max1, min] = s.kadans2(input);
	cout << "max:" << max1 << " ";
	cout << "min:" << min << "\n";

	vector<int> nums1 = {60,60,60};
	vector<int> nums2 = {10,90,10};

	cout << s.maximumsSplicedArray(nums1, nums2) << endl;

	return 0;
}
