#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//I was trying to use a hash map inside a hash map because I thought this was the best way to see if two words are anagram, but I realized after some time that I can use only one hash map wich keys are the words sorted. This works because 'banana' and 'nnbaaa' when sorted are 'aaabnn', so the hash pair would be <'aaabnn', ['banana', 'nnbaaa']>. 

/*
bool isAnagram(map<char,int> s1, map<char, int> s2){
	if(s1.size() != s2.size())
		return false;
	for(auto c : s1)
		if(s1[c.first] != s2[c.first]) 
			return false;
	return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	map<string,map<char,int>> mapWords;
	map<string, int> index;
	vector<vector<string>> v;
	for(auto word : strs){
		bool hasAnagram = false;
		map<char,int> mapCharacters;
		vector<string> s;
		for(auto character : word) mapCharacters[character]++;
		s.push_back(word);
		for(auto wordsRead : mapWords)
			if(isAnagram(wordsRead.second, mapCharacters)){
				//cout << wordsRead.first << " e " << word << endl;
				hasAnagram = true;
				//index[word] = index[wordsRead.first];
				v.at(index[wordsRead.first]).push_back(word);
				break;
			}
		if(!hasAnagram){
			mapWords[word] = mapCharacters;
			v.push_back(s);
			index[word] = v.size() -1;
			//cout << "entrei aqui" << v.size()<< index[word]<< endl;
		}
	}
	return v;
}
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	map<string,vector<string>> mapWords;
	vector<vector<string>> v;
	for(auto s : strs){
		string temp = s;
		sort(temp.begin(), temp.end());
		mapWords[temp].push_back(s);
	}
	for(auto s : mapWords)
		v.push_back(s.second);
	return v;
}
int main(){
	//vector<string> s = {"eat","tea","tan","ate","nat","bat"};
	vector<string> s = {"", ""};
	//vector<string> s = {"a"};
	vector<vector<string>> r = groupAnagrams(s);
	cout<< "[ ";
	for(auto v : r){
		cout<< "[";
		for(auto w : v)
			cout << w << " ";
	
		cout<< "] ";
	}
	cout <<"]"<< endl;	
	return 0;
}
