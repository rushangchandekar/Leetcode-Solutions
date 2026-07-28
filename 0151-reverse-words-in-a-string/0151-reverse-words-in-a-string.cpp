class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        string ans = "";
        int i = 0;

        while (i < s.length()) {
            while (i < s.length() && s[i] == ' ')
                i++;

            string word = "";

            while (i < s.length() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if (!word.empty()) {
                if (!ans.empty())
                    ans += " ";
                ans += word;
            }
        }

        return ans;
    }
};