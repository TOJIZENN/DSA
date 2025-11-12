class Solution {
public:
    int getSum(int a, int b) 
    {
        int carry=a&b;
        int sum=a^b;
        int currcarry=carry<<1;

        while(carry!=0)
        {
            carry=sum&currcarry;
            sum=sum^currcarry;
            currcarry=carry<<1;
        }
        return sum;
        
    }
};