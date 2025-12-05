class Solution {
public:
    int countCollisions(string directions) {
        int coll=0;
        int movR=0;
        bool stat=false;
        for(char c:directions){
            if(c=='R'){
                movR++;
            }else if(c=='S'){
                coll+=movR;
                movR=0;
                stat=true;
            }else{
                if(movR>0){
                    coll+=movR+1;
                    movR=0;
                    stat=true;
                }else if(stat){
                    coll++;
                }
            }
        }
        return coll;
    }
};