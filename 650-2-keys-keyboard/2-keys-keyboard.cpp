class Solution {
public:
int solve(int curr,int cp,int n)
{
if(curr>n){return 10000;}
if(curr==n){return 0;}
int copy=2+solve(curr+curr,curr,n);
int paste=1+solve(curr+cp,cp,n);
return min(copy,paste);
}
    int minSteps(int n)
    {
        if(n==1){return 0;}
        int curr;
        int cp;
        return 1+solve(1,1,n);
    }
};