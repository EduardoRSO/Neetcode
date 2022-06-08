#include <iostream>
#include <map>

using namespace std;

// My first thought was to use a set<char> but it did not work because one word can have repeated letters, such as banana and ban. So, using a hash table made it easier because we can use hashmap[letter] = count

bool isAnagram(string s, string t) {
	map<char, int> s1, s2;
	for(auto c : s){
		s1[c]++;
	}
	for(auto c : t){ 
		s2[c]++;
	}
	if(s1.size() != s2.size())
		return false;
	for(auto c : s1)
		if(s1[c.first] != s2[c.first]) 
			return false;
	return true;
}

int main(){
	cout << isAnagram("aa", "ab")<<endl;
	return 0;
}
