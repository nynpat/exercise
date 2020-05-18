/**
 * @author  :   Nayan Patel
 * @date    :   17th May 2020
 * @brief   :   Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 *              Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 *              The order of output does not matter.
 *              
 *              Example 1:
 *              Input:
 *              s: "cbaebabacd" p: "abc"
 * 
 *              Output:
 *              [0, 6]
 *              Explanation:
 *              The substring with start index = 0 is "cba", which is an anagram of "abc".
 *              The substring with start index = 6 is "bac", which is an anagram of "abc".
 *              for more info use https://leetcode.com/
 */
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if (p.size() > s.size() || p.size() == 0 || s.size() == 0) { 
            return {};
        }

        int sFreq[26] = { 0 };
        int pFreq[26] = { 0 };

        // create a window of start = 0 and end = p.size()
        for (int i = 0; i < p.size(); ++i) {
            sFreq[s[i] - 'a']++;
        }

        // create a frequency list of string p
        for (const auto &n: p) {
            pFreq[n - 'a']++;
        }

        // check the anagrams at index 0
        if (compare(sFreq, pFreq)) {
            ret.push_back(0);
        }

        // shift the window by appending a new character and removing the first one and iterate 
        // over all possible windows to find the match or not
        for (int i = p.size(); i < s.size(); ++i) {
            // this will add s[3], s[4], s[5].... iteratively
            sFreq[s[i] - 'a']++;

            // this will remove s[0], s[1], s[2].... iteratively
            sFreq[s[i - p.size()] - 'a']--;

            // Compare the two occurances of character
            if (compare(sFreq, pFreq)) {
                ret.push_back(i - p.size() + 1);
            }
        }
        return ret;
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
    vector<int> sol;
    cout << " Input s : \"cbaebabacd\" p : \"abc\"" << endl;
    sol = mySolution->findAnagrams("cbaebabacd","abc");
    for(auto const &i : sol) {
        cout << "-> " << i << "\t";
    }
    cout << endl;
    sol.clear();

    cout << " Input s : \"abab\" p : \"ab\"" << endl;
    sol = mySolution->findAnagrams("abab","ab");
    for(auto const &i : sol) {
        cout << "-> " << i << "\t";
    }
    cout << endl;
    sol.clear();
    delete(mySolution);
}