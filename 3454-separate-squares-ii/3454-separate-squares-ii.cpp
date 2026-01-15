// class Solution {
// public:
//     double separateSquares(vector<vector<int>>& squares) {
//         double tot=0;
//         vector<pair<double,double>>ele;
//         for(auto &s:squares){
//             ele.push_back({s[1],s[2]});
//             ele.push_back({s[1]+s[2],-s[2]});
//             tot+=1.0*s[2]*s[2];
//         }
//         sort(ele.begin(),ele.end());
//         double needed=tot/2.0;
//         double w=0,area=0; 
//         for(int i=0;i+1<ele.size();i++){
//             w+=ele[i].second;
//             double h=ele[i+1].first-ele[i].first;
//             if(area+w*h>=needed){
//                 return ele[i].first+(needed-area)/w;
//             }
//             area+=w*h;
//         }
//         return 0;
//     }
// };   Wrng lglogicic 

 

class Solution {
    vector<int> count;
    vector<long long> len;
    vector<int> X;

    // Segment Tree Update: handles range cover updates
    void update(int node, int l, int r, int ql, int qr, int v) {
        if (ql >= r || qr <= l) return; // No overlap
        if (ql <= l && r <= qr) {       // Total overlap
            count[node] += v;
        } else {                        // Partial overlap
            int mid = l + (r - l) / 2;
            update(2 * node, l, mid, ql, qr, v);
            update(2 * node + 1, mid, r, ql, qr, v);
        }

        // Calculate covered length for current node
        if (count[node] > 0) {
            len[node] = (long long)X[r] - X[l];
        } else if (l + 1 == r) {
            len[node] = 0; // Leaf with count 0
        } else {
            len[node] = len[2 * node] + len[2 * node + 1]; // Merge children
        }
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        // 1. Coordinate Compression for X
        for (auto& s : squares) {
            X.push_back(s[0]);
            X.push_back(s[0] + s[2]);
        }
        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());

        // Initialize Segment Tree
        int n = X.size();
        count.assign(4 * n, 0);
        len.assign(4 * n, 0);

        // 2. Create Events: (y, type, x_start, x_end)
        // type: 1 for bottom edge (add), -1 for top edge (remove)
        vector<tuple<int, int, int, int>> events;
        for (auto& s : squares) {
            events.emplace_back(s[1], 1, s[0], s[0] + s[2]);
            events.emplace_back(s[1] + s[2], -1, s[0], s[0] + s[2]);
        }
        sort(events.begin(), events.end());

        // 3. Sweep Line to Calculate Total Area & Record Widths
        double totalArea = 0;
        vector<pair<int, long long>> history; // Stores (y_end, active_width)

        for (int i = 0; i < events.size(); ++i) {
            auto [y, type, x1, x2] = events[i];

            // Calculate area for the strip between previous y and current y
            if (i > 0) {
                int prev_y = get<0>(events[i - 1]);
                long long w = len[1]; // Root stores total covered length
                long long h = y - prev_y;
                if (h > 0) {
                    totalArea += (double)w * h;
                    history.push_back({y, w});
                }
            }

            // Update Segment Tree for current event
            int l_idx = lower_bound(X.begin(), X.end(), x1) - X.begin();
            int r_idx = lower_bound(X.begin(), X.end(), x2) - X.begin();
            update(1, 0, n - 1, l_idx, r_idx, type);
        }

        // 4. Find the Split Line
        double target = totalArea / 2.0;
        double current = 0;
        double last_y = get<0>(events[0]);

        for (auto& [y, w] : history) {
            double h = y - last_y;
            double area = w * h;
            
            if (current + area >= target) {
                // Interpolate exact y position
                return last_y + (target - current) / w;
            }
            
            current += area;
            last_y = y;
        }

        return last_y;
    }
};