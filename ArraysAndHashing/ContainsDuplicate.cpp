#include <iostream>
#include <set>

#define MAXSIZE 100000
using namespace std;

/*This is the trivial solution*/

/*bool containsDuplicate(long int array[], int index){
	for(int i = 0; i < index-1;i++){
		for(int j = i+1; j < index; j++){
			if(array[i] == array[j]){
				return true;
			}
		}
	}
	return false;
}*/

/*In terms of efficiency, using a hash table or a set is easier since we would only need to compare the size of the structure choosed and the vector*/

bool containsDuplicate(long int array[], int index){
	set<int> s;
	for(int i = 0; i < index; i++)
		s.insert(array[i]);
	if(s.size() != index) return true;
	return false;
}
int main(){
	long int array[MAXSIZE] = {};
	int index = 0;
	char c;
	while(cin.get(c)){
		if(c == '\n') break;
		if(c >= '0' and c <= '9'){
			array[index] = c - '0';
			index++;
		}
	}
	return containsDuplicate(array, index);
}
