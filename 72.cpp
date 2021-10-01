#include <iostream>

using namespace std;

int minDistance(string word1, string word2) {
    int l1 = word1.size();
    int l2 = word2.size();
    int dp[l1+1][l2+1];
    for(int i=0;i<=l1;i++){
        dp[i][0] = i;
    }
    for(int i=0;i<=l2;i++){
        dp[0][i] = i;
    }
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            }
        }
    }
    return dp[l1][l2];
}

int main(int argc, char const *argv[])
{
    cout << minDistance("intention", "execution");
    return 0;
}
