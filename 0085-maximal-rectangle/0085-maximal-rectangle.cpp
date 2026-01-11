class Solution {
public:
    int maximalRectangle(vector<vector<char>>& m) { 
        if(m.empty() || m[0].empty()) return 0;

        int rows=m.size();
        int cols=m[0].size();
        vector<int>heights(cols+1,0);
        int maxArea=0;
        for(const auto& row:m){
            for(int i=0;i<cols;i++){
                heights[i]=(row[i]=='1')? heights[i]+1:0;
            }
            int n=heights.size();
            vector<int>st;
            for(int i=0;i<n;i++){
                while(!st.empty() && heights[i]<heights[st.back()]){
                    int h=heights[st.back()];
                    st.pop_back();
                    int w=st.empty()? i:i-st.back()-1;
                    maxArea=max(maxArea,h*w);
                }
                st.push_back(i);
            }
        }
        return maxArea;
    }
};