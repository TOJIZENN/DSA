class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int prev = 0;
        
        for (auto &log : logs) {
            int id = stoi(log.substr(0, log.find(':')));
            string type = log.substr(log.find(':')+1, 5); // "start" or "end"
            int time = stoi(log.substr(log.rfind(':')+1));
            
            if (type == "start") {
                if (!st.empty()) res[st.top()] += time - prev;
                st.push(id);
                prev = time;
            } else {
                res[st.top()] += time - prev + 1;
                st.pop();
                prev = time + 1;
            }
        }
        return res;
    }
};