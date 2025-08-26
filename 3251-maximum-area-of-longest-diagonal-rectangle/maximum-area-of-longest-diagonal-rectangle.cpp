class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) 
    {
        priority_queue<pair<double,int>>q;
       for(int i=0;i<dimensions.size();i++)
        {
          double x=sqrt((dimensions[i][0]*dimensions[i][0])+(dimensions[i][1]*dimensions[i][1]));
          int y=(dimensions[i][0]*dimensions[i][1]);
          q.push({x,y});
        }

        return q.top().second;
    }
};