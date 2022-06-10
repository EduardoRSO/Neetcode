#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

//This is a easy problem, since we can simply iterate through the string using two pointers from left and right, making sure that the current character is valid and compare then, increasing or decreasing the value of each pointer.

bool isPalindrome(string s) {
	int i = 0, j = s.size()-1;
	while(true){
		if(i >= j) break;
		if((s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= '0' and s[i] <= '9') or (s[i] >= 'a' and s[i] <= 'z')){
			if((s[j] >= 'A' and s[j] <= 'Z') or (s[j] >= '0' and s[j] <= '9') or (s[j] >= 'a' and s[j] <= 'z')){
				if(tolower(s[i]) != tolower(s[j])){
					return false;
				}else{
				//	cout << i << s[i] << " e " << j << s[j] << endl;
					i++;
					j--;
				}
			}else{
				j--;
			}
		}
		else{
			i++;
		}
	}
	return true;	
}

int main(){
	cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << isPalindrome("race a car") << endl;
	cout << isPalindrome(" ") << endl;
	cout << isPalindrome("aa") << endl;
	return 0;
}
