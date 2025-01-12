//
// Created by Anamika Kumari on 11/01/25.
//

#include <bits/stdc++.h>

class Solution {
public:
    string removeDigit(string number, char digit) {
        string finalStr = "";
        int smallestAdjacent = 10;
        for(int i = 0; i < number.size(); i++) {
            if(number[i] == digit) {
                string curStr = number.substr(0,i) + number.substr(i+1);
                if (finalStr == "") {
                    finalStr = curStr;
                    if(i < number.size())   smallestAdjacent = number[i+1];
                } else {
                    if(i+1 < number.size() && number[i+1] < smallestAdjacent) {
                        smallestAdjacent = number[i+1];
                        finalStr = curStr;
                    }
                }
            }
        }
        return finalStr;
    }

    string max_(string str1, string str2) {
        int i = 0;
        while (i < str1.size() && i < str2.size()) {
            if(str1[i] > str2[i]) {
                return str1;
            } else if(str2[i] > str1[i]) {
                return str2;
            }
            i++;
        }
        return str2;
    }
};



