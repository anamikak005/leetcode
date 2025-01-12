/*
Runtime: 10 ms
Beats: 4.68%
*/

class Solution {
public:
    int getLucky(string s, int k) {
        string convertedStr = convert(s);
        cout<<convertedStr<<endl;
        while(k--) {
            convertedStr = sum(convertedStr);
        }
        return stoi(convertedStr);
    }
    string convert(string s) {
        string ans = "";
        int i = 0;
        while(i < s.size()) {
            //since for 'a' we want 1
            ans += to_string(s[i] - 96);
            i++;
        }
        return ans;
    }
    string sum(string str) {
        string ans = "";
        int j = str.size() - 1;
        while(j >= 0) {
            ans = sum(ans, str.substr(j, 1));
            j--;
        }
        return ans;
    }
    string sum(string s1, string s2) {
        int c = 0, i = s1.size() - 1, j = s2.size() - 1;
        string ans = "";
        while (i >= 0 && j>= 0) {
            int s = s1[i] - '0' + s2[j] - '0' + c;
            c = s / 10;
            ans = to_string(s%10) + ans;
            i--; j--;
        }

        while( i >= 0) {
            int s = s1[i] - '0' + c;
            c = s / 10;
            ans = to_string(s%10) + ans;
            i--;
        }

        while( j >= 0) {
            int s = s2[j] - '0' + c;
            c = s / 10;
            ans = to_string(s%10) + ans;
            j--;
        }
        // ex: "9" + "9"
        if (c > 0 && i < 0 && j < 0)
            ans = to_string(c) + ans;
        return ans;
    }
};