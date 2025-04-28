#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        // Step 1: Sort by units per box in descending order
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });
        
        int ans = 0;
        for(int i = 0; i < boxTypes.size(); i++)
        {
            if(truckSize >= boxTypes[i][0])
            {
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                ans += truckSize * boxTypes[i][1];
                return ans;
            }
        }
        return ans;
    }
};
