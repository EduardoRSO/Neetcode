#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices){
    int buy = 0, sell = 0, profit = 0;
    for(int i = 1; i < prices.size();i++){
        cout << buy << " " << sell << endl;
        if(prices[i] < prices[buy]){
            buy = i;
            sell = 0;
        }else{
            sell = i;
            profit = max(prices[sell] - prices[buy], profit);
        }

    }
    return profit;
}

int main(){
    // vector<int> v = {7,1,5,3,6,4};
    // vector<int> v = {7,1,5,3,6,4};
    // vector<int> v = {7,1,5,3,6,4};
    vector<int> v = {2,4,1};

    cout << maxProfit(v) << endl;
    return 0;
}