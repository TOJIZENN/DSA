class Solution {
public:
    bool check(string smaller, string bigger) {
        return bigger.find(smaller) != string::npos;
    }

    vector<string> stringMatching(vector<string>& words) {
        set<string> ans;
        sort(words.begin(), words.end(),
             [](string a, string b) { return a.length() < b.length(); });
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {

                if (i != j && check(words[i], words[j])) {
                    ans.insert(words[i]);
                }
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
};