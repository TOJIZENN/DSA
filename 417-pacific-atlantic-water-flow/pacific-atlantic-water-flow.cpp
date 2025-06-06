class Solution {
public:

    
   void dfs(int i,int j,vector<vector<int>>& height, vector<vector<bool>> &ocean)
   {
        
        int n=height.size();
        int m=height[0].size();
        if(ocean[i][j]==false)
          ocean[i][j]=true;
          if(i>0 && height[i-1][j]>=height[i][j] && ocean[i-1][j]==false)dfs(i-1,j,height,ocean);
          if(j>0 && height[i][j-1]>=height[i][j] && ocean[i][j-1]==false)dfs(i,j-1,height,ocean);
          if(i<n-1 && height[i+1][j]>=height[i][j] && ocean[i+1][j]==false)dfs(i+1,j,height,ocean);
          if(j<m-1 && height[i][j+1]>=height[i][j] && ocean[i][j+1]==false)dfs(i,j+1,height,ocean);
          return;
   }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         vector<vector<int>> ans;
        
           
        int n=heights.size();
        int m=heights[0].size();
         vector<vector<bool>> pacific(n+1,vector<bool>(m+1,false));
         vector<vector<bool>> atlantic(n+1,vector<bool>(m+1,false));
  
      
        //Check Edges for Pacific ocean
        
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
              if(i==0 || j==0)
                dfs(i,j,heights,pacific);  
          }
        }
        
        
        //Check Edges for Atlantic ocean
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
              if(i==n-1 || j==m-1)
                dfs(i,j,heights,atlantic);  
          }
        }
       
        
        //If water can flow from a cell in both atlantic and pacific add that to our answer.
           for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(atlantic[i][j]==true && pacific[i][j]==true)
                     ans.push_back({i,j});
            }
        }
        return ans;
        
    }
};