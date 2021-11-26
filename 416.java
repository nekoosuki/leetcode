class Solution416 {
    public boolean canPartition(int[] nums) {
        int sum=0;
        for(int e:nums)sum+=e;
        if(sum%2==1)return false;
        sum/=2;
        boolean[] dp = new boolean[sum+1];
        dp[0] = true;
        for(int e:nums){
            for(int j=sum;j>=0;j--){
                if(j>=e)dp[j] = dp[j] || dp[j-e];
                if(dp[sum])return true;
            }
        }
        return dp[sum];
    }
}