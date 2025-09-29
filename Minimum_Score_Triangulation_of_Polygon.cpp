#include <bits/stdc++.h>
using namespace std;

int minScoreTriangulation(vector<int>& values){
    int n=values.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int len=3;len<=n;len++){
        for(int i=0;i+len<=n;i++){
            int j=i+len-1;
            dp[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+values[i]*values[k]*values[j]);
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> values(n);
    for(int i=0;i<n;i++) cin>>values[i];
    cout<<minScoreTriangulation(values)<<endl;
    return 0;
}
