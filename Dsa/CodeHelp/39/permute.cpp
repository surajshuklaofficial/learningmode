#include <iostream>
using namespace std;

void mixer(int x, vector<vector<int>> &nums)
{
    vector<int> modified_nums;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            modified_nums.push(nums[i].insert(j, x))
        }
    }
}

int main()
{

    return 0;
}