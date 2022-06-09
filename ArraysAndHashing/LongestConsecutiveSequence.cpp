#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//I was trying to use a set to garantee uniquee elements and then just iterate through the set verifying if [i-1] + 1 = [i], because I was worried that just sorting the vector and the comparing would be too much costful, but I ended up with O(nlogn) and the sort would be O(nlogn)

/*
int longestConsecutive(vector<int>& nums) {
	set<int> s;
	int maxCount = 0, curCount = 0, lastValue = 0;
	for(auto n : nums)
		s.insert(n);
	if(s.size() == 0)
		return 0;
	for(auto n : s){
		if(curCount == 0){
			lastValue = n;
			curCount++;
			continue;
		}
		if(lastValue == n-1){
			lastValue = n;
			curCount++;
		}else{
			if(curCount > maxCount)
				maxCount = curCount;
			curCount = 1;
			lastValue = n;
		}
	}
	if(curCount > maxCount)
		maxCount = curCount;

	return maxCount;
}
*/

int longestConsecutive(vector<int>& nums) {
	if(nums.size() == 0) return 0;
	sort(nums.begin(),nums.end());
	int maxCount = 0, curCount = 1;
	for(int i = 1; i < nums.size(); i++){
		if(nums[i-1] == nums[i]) 	continue;
		if(nums[i-1] == nums[i]-1) 	curCount++;
		else				maxCount = max(maxCount,curCount),curCount = 1;
	}
	return max(maxCount,curCount);
}	

int main(){
	//vector<int> v = {1,2,3,4,100,200};
	//vector<int> v = {0,3,7,2,5,8,4,6,0,1};
	//vector<int> v = {};
	vector<int> v = {9,1,4,7,3,-1,0,5,8,-1,6};
	int r = longestConsecutive(v);
	cout << r << endl;
	return 0;
}
