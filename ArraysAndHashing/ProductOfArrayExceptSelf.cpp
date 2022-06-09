#include <iostream>
#include <vector>

using namespace std;

//The algorithm must be O(n), so I can not simply acess all other positions, multiplying it.
//My idea was to use the 'Accumulated Value' acquired after multiplying al numbers between 0 ... i-1 and i+1 ... N so that I avoid using division or iterate through all other positions for each value of i. All I did is iterate 2 times, saving in each position of r[i] the left and right values and multiplying them.

/*
vector <int> productExceptSelf(vector<int>& nums) {
	vector<int> r(nums.size());
	int AccumulatedValue = 1;	
	for(int i = 0; i < nums.size(); i++){
		r[i] = AccumulatedValue;
		AccumulatedValue *= nums[i];
	}
	AccumulatedValue = 1;
	for(int i = 0; i < nums.size(); i++){
		r[nums.size()-i-1] *= AccumulatedValue;
		AccumulatedValue *= nums[nums.size()-i-1];
	}
	return r;
}
*/

//Tried to avoid using an extra variable to see if I could get some extra points in leetcode... Did not work. :(

vector <int> productExceptSelf(vector<int>& nums) {
        vector<int> r(nums.size() +1);
        r[nums.size()] = 1;
        for(int i = 0; i < nums.size(); i++){
                r[i] = r[nums.size()];
                r[nums.size()] *= nums[i];
        }
        r[nums.size()] = 1;
        for(int i = 0; i < nums.size(); i++){
                r[nums.size()-i-1] *= r[nums.size()];
                r[nums.size()] *= nums[nums.size()-i-1];
        }
        r.pop_back();
        return r;
}
int main(){
	vector<int> v = {-1,1,0,-3,3};
	vector<int> r = productExceptSelf(v);
	for(auto n : r)
		cout << n << " ";
	cout << endl;
}
