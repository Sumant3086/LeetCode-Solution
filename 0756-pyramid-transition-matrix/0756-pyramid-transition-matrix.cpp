// class Solution {
// public:
//     bool dfs(const string &curr,string next,int i,unordered_map<string,vector<char>> &mp){
//         if(curr.size()==1)return true;
//         if(i+1==curr.size())return dfs(next,"",0,mp);
//         string k=curr.substr(i,2);
//         if(!mp.count(k))return false;
//         for(char ch:mp[k]){
//             if(dfs(curr,next+ch,i+1,mp))return true;
//         }
//         return false;
//     }
//     bool pyramidTransition(string bottom, vector<string>& allowed) {
//         unordered_map<string,vector<char>>mp;
//         for(auto &i:allowed){
//             mp[i.substr(0,2)].push_back(i[2]);
//         }
//         return dfs(bottom,"",0,mp);
//     }
// };

class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(const string &curr) {

        if (curr.size() == 1)
            return true;

        if (memo.count(curr))
            return memo[curr];

        int n = curr.size();
        vector<string> rows;
        rows.push_back("");

        for (int i = 0; i < n - 1; i++) {
            string key = curr.substr(i, 2);

            if (!mp.count(key))
                return memo[curr] = false;

            vector<string> next;

            for (auto &prefix : rows) {
                for (char c : mp[key]) {
                    next.push_back(prefix + c);
                }
            }
            rows = move(next);
        }

        for (auto &row : rows)
            if (dfs(row))
                return memo[curr] = true;

        return memo[curr] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {

        for (auto &s : allowed)
            mp[s.substr(0, 2)].push_back(s[2]);

        return dfs(bottom);
    }
};
