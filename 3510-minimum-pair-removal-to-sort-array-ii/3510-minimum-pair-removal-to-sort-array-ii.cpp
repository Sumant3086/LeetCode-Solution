// class Solution {
// public:
//     int minimumPairRemoval(vector<int>& nums) {
//         int n=nums.size();
//         vector<long long>v(nums.begin(),nums.end());
//         vector<int>next(n),prev(n);
//         using T=tuple<long long, int, int>;
//         priority_queue<T,vector<T>,greater<T>>pq;
//         int inv=0; 
//         for(int i=0;i<n;++i){
//             next[i]=(i+1<n)?i+1:-1;
//             prev[i]=i-1;
//             if(next[i]!=-1){
//                 if(v[i]>v[next[i]])inv++;
//                 pq.push({v[i]+v[next[i]],i,next[i]});
//             }
//         }
//         int ops=0;
//         while(inv>0){
//             auto[sum,i,j]=pq.top();
//             pq.pop(); 
//             if(next[i]!=j) continue;
//             ops++;
//             int p=prev[i],k=next[j]; 
//             if(p!=-1 && v[p]>v[i])inv--;
//             if(v[i]>v[j])inv--;
//             if(k!=-1 && v[j]>v[k])inv--; 
//             v[i]+=v[j];
//             next[i]=k;
//             if(k!=-1)prev[k]=i; 
//             if(p!=-1 && v[p]>v[i])inv++;
//             if(k!=-1 && v[i]>v[k])inv++; 
//             if(p!=-1)pq.push({v[p]+v[i],p,i});
//             if(k!=-1)pq.push({v[i]+v[k],i,k});
//         }
//         return ops;
//     }
// };
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        // Use long long for values to prevent overflow during summing
        vector<long long> v(nums.begin(), nums.end());
        vector<int> next(n), prev(n);
        
        // Min-heap stores {sum, index_i, index_j}
        // sorted by sum (asc), then index_i (asc) for leftmost tie-breaking
        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        
        int inv = 0; // Inversion count to track if array is sorted

        // Initialization
        for (int i = 0; i < n; ++i) {
            next[i] = (i + 1 < n) ? i + 1 : -1;
            prev[i] = i - 1;
            if (next[i] != -1) {
                if (v[i] > v[next[i]]) inv++;
                pq.push({v[i] + v[next[i]], i, next[i]});
            }
        }

        int ops = 0;
        while (inv > 0) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            // VALIDATION CHECKS:
            // 1. Connectivity: Ensure i and j are still neighbors
            // 2. Data Integrity: Ensure the sum popped matches current values (handles stale updates)
            if (next[i] != j || prev[j] != i || sum != v[i] + v[j]) continue;

            ops++;
            int p = prev[i];
            int k = next[j];

            // 1. Remove OLD inversions involving i and j
            if (p != -1 && v[p] > v[i]) inv--;
            if (v[i] > v[j]) inv--;         // The internal inversion (if any) is resolved by merge
            if (k != -1 && v[j] > v[k]) inv--;

            // 2. Execute Merge: j is absorbed into i
            v[i] += v[j];
            
            // Update pointers (DLL deletion of j)
            next[i] = k;
            if (k != -1) prev[k] = i;

            // 3. Add NEW inversions involving the new v[i]
            if (p != -1 && v[p] > v[i]) inv++;
            if (k != -1 && v[i] > v[k]) inv++;

            // 4. Push new candidate pairs to heap
            if (p != -1) pq.push({v[p] + v[i], p, i});
            if (k != -1) pq.push({v[i] + v[k], i, k});
        }
        return ops;
    }
};