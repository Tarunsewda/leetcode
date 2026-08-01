class Solution {
public:
    string smallestSubsequence(string s) {

        int lastIdx[26];
        int isVisited[26] = {false};

        for(int i = 0; i < s.size(); i++) {
            lastIdx[s[i] - 'a'] = i;
        }

        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            if(isVisited[s[i] - 'a'] == true) continue;

            while(ans.size() > 0 && s[i] < ans.back() && lastIdx[ans.back() - 'a'] > i) {
                isVisited[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            isVisited[s[i] - 'a'] = true;
        }

        return ans;
    }
};