class Solution {
public:
    int countTriples(int n) { 
        int count=0;
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                int sum=a*a+b*b;
                int root=sqrt(sum);
                if(root<=n && root*root==sum){
                    count++;
                }
            }
        }
        return count;
    }
};


// class Solution {
// public:
//     int countTriples(int n) {
//         vector<int>sq(n*n+1,-1);
//         for(int i=1;i<=n;i++){
//             sq[i*i]=i;
//         }
//         int count=0;
//         for(int a=1;a<=n;a++){
//             for(int b=1;b<=n;b++){
//                 int sum=a*a+b*b;
//                 if(sum<=n*n && sq[sum]!=-1){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

// class Solution {
// public:
//     int countTriples(int n) {
//         int count=0;
//         for(int a=1;a<=n;a++){
//             for(int b=1;b<=n;b++){
//                 for(int c=1;c<=n;c++){
//                     if(a*a+b*b==c*c){
//                         count++;
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };