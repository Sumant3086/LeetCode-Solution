class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>res; 
        int minD=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            int diff=arr[i+1]-arr[i];
            if(diff<minD){
                minD=diff;
                res.clear();        
            }
            if(diff==minD){
                res.push_back({arr[i],arr[i+1]});
            }
        }
        return res;
    }
};