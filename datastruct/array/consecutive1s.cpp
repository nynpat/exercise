#include <vector>
#include <iostream>

using namespace std;

class solution {
    public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1s = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                count = 0;
            } else {
                count++;
            }
            if(max1s < count)
                max1s = count;
        }
        return max1s;
    }
};


int main() {
    vector<int> testData;

    testData.push_back(1);
    testData.push_back(1);
    testData.push_back(1);
    testData.push_back(0);
    testData.push_back(1);
    testData.push_back(1);
    testData.push_back(1);
    testData.push_back(1);
    testData.push_back(0);
    testData.push_back(1);
    testData.push_back(1);
    testData.push_back(1);
    testData.push_back(1);
    testData.push_back(1);

    class solution *mySolution = new solution();
    cout << "Maximum Consecutive 1's : " << mySolution->findMaxConsecutiveOnes(testData) << endl;
}