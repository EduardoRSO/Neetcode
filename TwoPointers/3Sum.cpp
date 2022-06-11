#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//I was trying to use a set of vectors to avoid duplicate, but I soon found out that without sorting it would cost O(n^3), so I gave up and surrendered me to O(nlogn) and used the two pointers strategy.

/*
namespace std {
	template <>
	struct hash<std::vector<int>> {
		size_t operator()(const vector<int>& v) const {
			std::hash<int> hasher;
			size_t seed = 0;
			for (int i : v) {
			seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
			}
			return seed;
		}
	};
}

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> r;
	unordered_set<vector<int>> s;
	for(int i = 0; i < nums.size()/3;i++){
		for(int j = nums.size()/3; j < 2*nums.size()/3;j++){
			for(int k = 2*nums.size()/3; k < nums.size(); k++){
				cout << i << " "<< j << " " << k << endl;
				if(nums[i] + nums[j] + nums[k] == 0){
					vector<int> t = {nums[i], nums[j], nums[k]};
					s.insert(t);
					//r.push_back(t);
				}
			}
		}
	}
	for(auto v : s)
		r.push_back(v);
	return r;
}
*/

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> r;
	if(nums.size() < 3) return r;
	sort(nums.begin(), nums.end());
	
	for(auto n : nums)
		cout << n << " ";
	cout << endl;

	for(int i = 0; i < nums.size(); i++){
		if(nums[i] > 0) break;
		if(i > 0 and nums[i] == nums[i-1]) continue;
		int left = i+1, right = nums.size()-1;
		//cout << nums[i] << " "<< nums[left] << " " << nums[right] << endl;
		while(left < right){
			//cout << i << " "<< left << " " << right << endl;
			if(nums[i] + nums[left] + nums[right] > 0){
				right--;
			}
			else if(nums[i] + nums[left] + nums[right] < 0){
				left++;
			}
			else{
				r.push_back({nums[i], nums[left], nums[right]});
				int lastLeft = left, lastRight = right;
				while(left < right and nums[left] == nums[lastLeft]) left++;
				while(left < right and nums[right] == nums[lastRight]) right--;
			}
		}
	}
	return r;
}
int main(){
	//vector<int> v = {-1,0,1,2,-1,-4};
	vector<int> v = {1,-1,-1,0};
	//vector<int> v = {0};
	//vector<int> v = {0,0,0,0};
	//vector<int> v = {3,0,-2,-1,1,2};
	vector<vector<int>> r = threeSum(v);
	cout<<"[ ";
	for(auto a : r){
		cout <<"[ ";
		for(auto n : a)
			cout << n << " ";
		cout<<"] ";
	}
	cout<<"]" << endl;
	return 0;
}
