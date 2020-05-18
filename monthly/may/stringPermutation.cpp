/**
 * @author  :   Nayan Patel
 * @date    :   17th May 2020
 * @brief   :   Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
 *              In other words, one of the first string's permutations is the substring of the second string.
 *              for more info : https://leetcode.com/
 */
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size() || s1.size() == 0 || s2.size() == 0) {
            return false;
        }

        int s1Freq[26] = { 0 };
        int s2Freq[26] = { 0 };

        // create a window of start = 0 and end = p.size()
        for (int i = 0; i < s1.size(); ++i) {
            s2Freq[s2[i] - 'a']++;
        }

        // create a frequency list of string p
        for (const auto &n: s1) {
            s1Freq[n - 'a']++;
        }

        // check the anagrams at index 0
        if (compare(s1Freq, s2Freq)) {
            return true;
        }

        // shift the window by appending a new character and removing the first one and iterate 
        // over all possible windows to find the match or not
        for (int i = s1.size(); i < s2.size(); ++i) {
            // this will add s[3], s[4], s[5].... iteratively
            s2Freq[s2[i] - 'a']++;

            // this will remove s[0], s[1], s[2].... iteratively
            s2Freq[s2[i - s1.size()] - 'a']--;

            // Compare the two occurances of character
            if (compare(s1Freq, s2Freq)) {
                return true;
            }
        }
        return false;
    }

    bool compare(int *sFreq, int *pFreq) {
        for (int i = 0; i < 26; ++ i) {
            if (sFreq[i] != pFreq[i]) { 
                return false;
            }
        }
        return true;
    }
};

int main(){
    class Solution *mySolution = new Solution();
    bool sol;
    cout << " Input s1 : \"abc\" s2 : \"cbaebabacd\"";
    if(mySolution->checkInclusion("abc","cbaebabacd")) {
        cout << " : True" << endl;
    } else {
        cout << " : False" << endl;
    }

    cout << " Input s1 : \"ab\" s2 : \"abab\"";
    if(mySolution->checkInclusion("ab","abab")) {
        cout << " : True" << endl;
    } else {
        cout << " : False" << endl;
    }

    cout << " Input s1 : \"abc\" s2 : \"abab\"";
    if(mySolution->checkInclusion("abc","abab")) {
        cout << " : True" << endl;
    } else {
        cout << " : False" << endl;
    }

    delete(mySolution);
}