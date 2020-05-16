#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class solution {
    public:
    int findNumbers(vector<int>& nums) {
        int numOfEvens = 0;
        for(int i = 0; i < nums.size(); ++i) {
            // log of any number will return 1 number less than the total number of digits of a number
            int digits = nums[i] > 0 ? (int) log10(nums[i]) : 0;
            if((digits % 2) == 1) {
                numOfEvens++;
            }
        }
        return numOfEvens;
    }
};


int main() {
    vector<int> testData;

    testData.push_back(12);
    testData.push_back(345);
    testData.push_back(3);
    testData.push_back(6);
    testData.push_back(7896);

    class solution *mySolution = new solution();
    cout << "Numbers with Even Digits : " << mySolution->findNumbers(testData) << endl;
}