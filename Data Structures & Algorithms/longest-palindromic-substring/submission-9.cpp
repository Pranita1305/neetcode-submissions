class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        if(n<=1) return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start=0;
        int length=1;

        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }

        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                start=i;
                length=2;
            }
        }

        for(int len=3;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;

                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    
                    if(len>length){
                        start=i;
                        length=len;
                    }
                }
            }
        }

        return s.substr(start,length);
    }
};