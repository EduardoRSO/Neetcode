#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// I was trying to use set, since values should not repeat, but I realized that I was not saving the index on the array, so I started to use a unordered hashmap due to the fact that I would only check values strictly by keys.

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int,int> m;
	vector<int> r = { -1, -1};
	for(int i = 0; i < nums.size(); i++){
		if(m.find(target - nums[i]) != m.end()){
			r[0] = m[target-nums[i]];
			r[1] = i;
			return r;
		}
		else{
			m[nums[i]] = i;
		}		
	}
	return r;
		
}

int main(){
	//vector<int> a = {2,7,11,15};
	//vector<int> a = {2,3,4};
	vector<int> a = {3,3};
	vector<int> r = twoSum(a,6);
	cout << r[0] << r[1] << endl;
	return 0;
}
