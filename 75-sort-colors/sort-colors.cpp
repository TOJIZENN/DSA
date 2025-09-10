class Solution {
public:
    void sortColors(vector<int>& nums) {
      //  sort(nums.begin(),nums.end());
        int two=0;
        int zero=0;
        int one=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0){zero++;}
            else if(nums[i]==1){one++;}
            else if(nums[i]==2){two++;}
        }
        int k=0;
        while(zero!=0)
        {
            nums[k]=0;
            zero--;
            k++;
        }
        while(one!=0)
        {
            nums[k]=1;
            one--;
            k++;
        }
        while(two!=0)
        {
            nums[k]=2;
            k++;
            two--;
        }
    }
};