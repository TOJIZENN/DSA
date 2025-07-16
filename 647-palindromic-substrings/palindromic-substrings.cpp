class Solution {
public:
    bool isp(string &s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        
        // Try all substrings (i, j)
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isp(s, i, j)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
