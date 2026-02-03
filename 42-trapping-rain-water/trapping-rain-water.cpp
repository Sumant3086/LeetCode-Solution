// class Solution {
// public:
//     int trap(vector<int>& height) { 
//         int n=height.size();
//         int left=0;
//         int right=n-1;
//         int res=0;
//         int maxLeft=0;
//         int maxRight=0;
//         while(left<=right){
//             if(height[left]<=height[right]){
//                 if(height[left]>maxLeft)
//                 maxLeft=height[left];
//                 else res+=maxLeft-height[left];
//                 left++;
//             }else{
//                 if(height[right]>maxRight)
//                 maxRight=height[right];
//                 else res+=maxRight-height[right];
//                 right--;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    //total water is trapped into the bars
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1,lmax=INT_MIN,rmax=INT_MIN,ans=0;
        while(l<r){
            lmax=max(lmax,h[l]);
            rmax=max(rmax,h[r]);
            ans+=(lmax<rmax)?lmax-h[l++]:rmax-h[r--];            
        }
        return ans;
    }
};