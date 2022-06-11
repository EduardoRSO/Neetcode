#include <iostream>
#include <vector>

using namespace std;

//I was stuck on a the decision of which pointer should be moved, but I later discovered that a good way to alternate and get each time closer to the optimal solution was to choose the one who has the minimal height.

int maxArea(vector<int>& height) {
	int i = 0, j = height.size()-1, maxArea = min(height[i],height[j]) * (j-i);
	while(i < j){
		int curArea = min(height[i],height[j]) * (j-i);
		maxArea = max(maxArea, curArea);
		if(height[i] <= height[j]) i++;
		else j--;
	}
	return maxArea;
}

int main(){
	//vector<int> v = {1,2,1};
	//vector<int> v = {1,8,6,2,5,4,8,3,7};
	//vector<int> v = {1,8,6,2,5,4,8,3,7};
	vector<int> v = {2,3,4,5,18,17,6};
	//vector<int> v = {1,3,2,5,25,24,5};
	cout << maxArea(v) << endl;
}
