// 721. Accounts Merge
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

// Example 1:

// Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Explanation:
// The first and second John's are the same person as they have the common email "johnsmith@mail.com".
// The third John and Mary are different people as none of their email addresses are used by other accounts.
// We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
// Example 2:

// Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
// Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 

// Constraints:

// 1 <= accounts.length <= 1000
// 2 <= accounts[i].length <= 10
// 1 <= accounts[i][j].length <= 30
// accounts[i][0] consists of English letters.
// accounts[i][j] (for j > 0) is a valid email.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 536,514/897K
// Acceptance Rate
// 59.8%
// Topics
// icon
// Companies
// Hint 1
// Similar Questions
// Discussion (176)

// Choose a type













// Copyright © 2025 LeetCode. All rights reserved.

class Solution {
public:
    string find(const string& x, unordered_map<string, string>& parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent;
        unordered_map<string, string> owner;

        for (const auto& acc : accounts) {
            const string& name = acc[0];
            for (int i = 1; i < acc.size(); ++i) {
                const string& mail = acc[i];
                parent.emplace(mail, mail);
                owner[mail] = name;
            }
        }

        for (const auto& acc : accounts) {
            const string rootMail = find(acc[1], parent);
            for (int i = 2; i < acc.size(); ++i) {
                const string currMail = acc[i];
                parent[find(currMail, parent)] = rootMail;
            }
        }

        unordered_map<string, set<string>> groups;
        for (const auto& p : parent) {
            const string rep = find(p.first, parent);
            groups[rep].insert(p.first);
        }

        vector<vector<string>> result;
        for (auto& [rep, emails] : groups) {
            vector<string> account;
            account.push_back(owner[rep]);
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(move(account));
        }

        return result;
    }
};

// class Solution {
// public:
//     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//         vector<vector<string>>merged;
//         for(const auto& acc:accounts){
//             const string& name=acc[0];
//             unordered_set<string>currMail(acc.begin()+1,acc.end());
//             bool mergePossible=false;
//             for(auto& mAcc:merged){
//                 if(mAcc[0]!=name){
//                     continue;
//                 }
//                 if(common(currMail,mAcc)){
//                     mAcc.insert(mAcc.end(),currMail.begin(),currMail.end());
//                     mergePossible=true;
//                     normalize(mAcc);
//                     break;
//                 }
//             }
//             if(!mergePossible){
//                 vector<string>newAcc={name};
//                 newAcc.insert(newAcc.end(),currMail.begin(),currMail.end());
//                 normalize(newAcc);
//                 merged.push_back(std::move(newAcc));
//             }
//         }
//         bool changed=true;
//         while(changed){
//             changed=false;
//             for(size_t i=0;i<merged.size();++i){
//                 for(size_t j=i+1;j<merged.size();++j){
//                     if(merged[i][0]!=merged[j][0]){
//                         continue;
//                     }
//                     unordered_set<string>setI(merged[i].begin()+1,merged[i].end());
//                     if(common(setI,merged[j])){
//                         merged[i].insert(merged[i].end(),merged[j].begin()+1,merged[j].end());
//                         normalize(merged[i]);
//                         merged.erase(merged.begin()+j);
//                         changed=true;
//                         --j;
//                     }
//                 }
//             }
//         }
//         return merged;
//     }
//     private:
//     bool common(const unordered_set<string>& s, const vector<string>& vec) {
//         for(size_t i=1;i<vec.size();++i){
//             if(s.count(vec[i])){
//                 return true;
//             }
//         }
//         return false;
//     }
//     void normalize(vector<string>& acc) {
//         sort(acc.begin()+1,acc.end());
//         acc.erase(unique(acc.begin()+1,acc.end()),acc.end());
//     }
// };
