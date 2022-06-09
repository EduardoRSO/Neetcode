#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <numeric>

using namespace std;

// I tried to make an hash of <number, frequency> and an inverse hash <frequency, [numbers with this frequency]>. It works, but after I saw other solutions I now think that I am carrying to much unused information. What I could have done is just get all <number, frequency> and put them in a vector of <pair<int,int>> and the sort it. The problem with my solution is that I must remove the value whenever it change its frequency, since I add them in O(nums.size()), buut this may something with amortized cost.

// sort(res.begin(),res.end(),[](const auto &p ,const auto &q){ return p.second > q.second ;});

//The code below will help me in the future
vector<int> popValue(vector<int> c, int value){
	for(int i = 0; i < c.size(); i++)
		if(value == c[i]){
			c.erase(c.begin()+i);
			break;
		}
	return c;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int,int> NumberCount;
	map<int,vector<int>> FrequentNumber;
	vector<int> v;
	int count = 0;
	for(auto n : nums){
		FrequentNumber[NumberCount[n]] = popValue(FrequentNumber[NumberCount[n]],n);
		NumberCount[n]++;
		FrequentNumber[NumberCount[n]].push_back(n);
	}
	for(auto it = FrequentNumber.crbegin(); it != FrequentNumber.crend(); ++it){
		for(auto n : it->second){
			v.push_back(n);
			count++;
			if(count == k) break;
		}	
		if(count == k) break;
	}
	return v;
}
        
int main(){
	//vector<int> v = {1,1,1,2,2,3};
	//vector<int> v = {1};
	vector<int> v = {3,0,1,0};
	vector<int> r = topKFrequent(v,3);
	for(auto n : r)
		cout << n << " ";
	cout << endl;
}    
