#include <iostream>
#include <vector>
using namespace std;


int main() {
    
    vector<int> dp(5, -1);
    int i = 1;
    cout << dp[i - 2] + 1<< endl;
    return 0;
}