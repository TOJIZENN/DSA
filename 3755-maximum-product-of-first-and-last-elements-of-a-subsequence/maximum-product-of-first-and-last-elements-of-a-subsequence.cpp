class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        if(m==1){
            long long ans=LLONG_MIN;
            for(int i=0;i<n;i++){
                ans=max(ans,1LL*nums[i]*nums[i]);
            }
            return ans;
        }
        long long ans=LLONG_MIN;
        vector<int>mxneg(n),mxpos(n);
        long long mx=LLONG_MIN; long long mn=LLONG_MAX;
        for(int i=n-1;i>=0;i--){
            mx=max(mx,1ll*nums[i]);
            mn=min(mn,1ll*nums[i]);
            mxneg[i]=mn;
            mxpos[i]=mx;
        }
        for(int i=0;i<n;i++){
            if(i+m-1<n){
                ans=max(ans,1ll*nums[i]*mxneg[i+m-1]);
                ans=max(ans,1ll*nums[i]*mxpos[i+m-1]);                
            }
        } 
        return ans;
    }
};