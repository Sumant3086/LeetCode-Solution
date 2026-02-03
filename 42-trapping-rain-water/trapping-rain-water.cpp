class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int lvl=0;
        int maxW=0;
        while(l<r){
             int hold=(height[l]<height[r])?height[l++]:height[r--];
             lvl=max(lvl,hold);
             maxW+=lvl-hold;
        }
        return maxW;
    }
};