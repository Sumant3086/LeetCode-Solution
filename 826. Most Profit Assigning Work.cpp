// 826. Most Profit Assigning Work
// Solved
// Medium
// Topics
// Companies
// You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

// difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
// worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
// Every worker can be assigned at most one job, but one job can be completed multiple times.

// For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
// Return the maximum profit we can achieve after assigning the workers to the jobs.

 

// Example 1:

// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
// Output: 100
// Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
// Example 2:

// Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
// Output: 0
 

// Constraints:

// n == difficulty.length
// n == profit.length
// m == worker.length
// 1 <= n, m <= 104
// 1 <= difficulty[i], profit[i], worker[i] <= 105


class Solution {
public:
Solution(){
ios::sync_with_stdio(0);
cout.tie(0);
cin.tie(0);
}
 
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int m=worker.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            int diff=difficulty[i];
            int prof=profit[i];
            pq.push({prof,diff});
        }
        sort(begin(worker),end(worker),greater<int>());
        int i=0;
        int totProf=0;
        while(i<m && !pq.empty()){
            if(pq.top().second>worker[i]){
                pq.pop();
            }else{
                totProf+=pq.top().first;
                i++;
            }
        }
        return totProf;
    }
};
// class Solution {
// public:
//     int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//         int n = worker.size();
//         int maxProfit = 0;
//         for(int i = 0; i < n; i++) {
//             int workerMaxProfit = 0;
//             for(int j = 0; j < difficulty.size(); j++) {
//                 if(difficulty[j] <= worker[i]) {
//                     workerMaxProfit = max(workerMaxProfit, profit[j]);
//                 }
//             }
//             maxProfit += workerMaxProfit;
//         }
//         return maxProfit;
//     }
// };