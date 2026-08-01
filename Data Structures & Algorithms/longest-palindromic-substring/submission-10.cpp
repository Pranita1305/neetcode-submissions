class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if(n <= 1) return s;

        int start = 0;
        int maxLength = 1;

        for(int center = 0; center < n; center++) {

            // Odd length palindrome
            int l = center;
            int r = center;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > maxLength) {
                    maxLength = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }

            // Even length palindrome
            l = center;
            r = center + 1;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > maxLength) {
                    maxLength = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, maxLength);
    }
};