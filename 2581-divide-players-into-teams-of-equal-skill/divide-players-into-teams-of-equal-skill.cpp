class Solution {
public:
    long long dividePlayers(vector<int>& skill)
    {
        int sum=accumulate(skill.begin(),skill.end(),0LL);
        if(skill.size()%2!=0){return -1;}
        int team=skill.size()/2;
        if(sum%team!=0){return -1;}
        int target=sum/team;
        unordered_map<int,int>mp;
        long long ans=0;
        for(auto it:skill)
        {
            mp[it]++;
        }
        int i=0;
      for(auto it : skill)
      {
        if(mp.find(it)==mp.end()){continue;}
        mp[it]--;
         if (mp[it] == 0) mp.erase(it);
         int x=target-it;
          if (mp.find(x) == mp.end()) return -1;
            mp[x]--;
        if (mp[x] == 0) mp.erase(x);

        ans += (long long)it * x;
      }
        return ans;
    }
};