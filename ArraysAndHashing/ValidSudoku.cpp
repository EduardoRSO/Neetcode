#include <iostream>
#include <vector>
//#include <unordered_map>
#include <set>

using namespace std;

//I was trying to check row, column and subBox by using an unordered map and checking if each <key, value> had and value greater than 0 for symbols different than '.', but it was too much costful because I had to clear the map each time and was not using each (i,j) to verify row, column and subBox, but using 3 loops to each.
/*
bool isValidSudoku(vector<vector<char>>& board) {
	for(int i = 0; i < 9; i++){
		unordered_map<char,int> m;
		//rows
		for(int j = 0; j < 9; j++){
			if(board[i][j] != '.'){
				if(m[board[i][j]] != 0){
					return false;
				}
				else{
					m[board[i][j]]++;
				}
			}
		}
		m.clear();
		//columns
		for(int j = 0; j < 9; j++){
			if(board[j][i] != '.'){
				if(m[board[j][i]] != 0){
					return false;
				}
				else{
					m[board[j][i]]++;
				}
			}	
		}
		m.clear();
		//subBoxes
		if(i % 3 == 0){
			for(int step = 0; step <= 6; step+=3){
				for(int k = i+step; k < i+step+3; k++){
					for(int j = i+step; j < i+step+3; j++){
						if(board[k][j] != '.'){
							if(m[board[k][j]] != 0){
								return false;
							}
							else{
								m[board[k][j]]++;
							}
						}
					}
				}
			m.clear();
			}
		}
	}
	return true;
}*/


//The following solution uses a tricky expression to calculate in which set of row, columns and subBoxes each symbol must go. The last two are trivial, since the value of the set is the same as the value of i or j, but the first one uses i/3*3 + j/3, because there are 3 boxes for values of i = {0,3,6}, totalizing 9. And note that i/3*3 = {0,3,6} and j/3 = {0,1,2}, such as i,j = {0,1,2,3,4,5,6,7,8}. This function maps exactly in which subbox each board(i,j) should go. 

bool isValidSudoku(vector<vector<char>>& board) {
	vector<set<int>> r(9), c(9), s(9);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(board[i][j] == '.')
				continue;
			if(s[i/3 * 3 + j/3].count(board[i][j] - '0') ||
			   r[i].count(board[i][j] - '0')	     ||
			   c[j].count(board[i][j] - '0'))
				return false;
			s[i/3 * 3 + j/3].insert(board[i][j] - '0');
			r[i].insert(board[i][j] - '0');
			c[j].insert(board[i][j] - '0');
		}
	}
	return true;
}
int main(){
/*
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]	
*/
	return 0;
}
