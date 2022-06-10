#include <iostream>
#include <vector>

using namespace std;

//My solution is based on the difference between target - minValue, such as we search for the first value which !(maxValue > target - minValue). After that, I iterate through the vector positions until I find a value that numbers[i] + numbers[j].

vector<int> twoSum(vector<int>& numbers, int target) {
	int i = 0, j = numbers.size() -1;
	vector<int> r = {0,0};
	while(true){
		if(target - numbers[i] - numbers[j] == 0)
			break;
		else
			if(target - numbers[i] < numbers[j])
				j--;
			else
				i++;	
	}
	r[0] = min(i+1,j+1);
	r[1] = max(i+1,j+1);
	return r;
}

int main(){
	//vector<int> v = {2,3,4};int target = 6;
	//vector<int> v = {-1,0};int target = -1;
	//vector<int> v = {2,7,11,15};int target = 9;
	//vector<int> v = {12,13,23,28,43,44,59,60,61,68,70,86,88,92,124,125,136,168,173,173,180,199,212,221,227,230,277,282,306,314,316,321,325,328,336,337,363,365,368,370,370,371,375,384,387,394,400,404,414,422,422,427,430,435,457,493,506,527,531,538,541,546,568,583,585,587,650,652,677,691,730,737,740,751,755,764,778,783,785,789,794,803,809,815,847,858,863,863,874,887,896,916,920,926,927,930,933,957,981,997};int target = 542;	
	vector<int> r = twoSum(v,target);
	cout << r[0] << " " << r[1] << endl;
	return 0;
}
