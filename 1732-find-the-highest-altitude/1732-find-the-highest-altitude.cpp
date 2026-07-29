class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       int currAlti = 0;
       int highAlti = currAlti;

       for (int i=0; i<gain.size(); i++) {
        currAlti += gain[i];
        highAlti = max(highAlti, currAlti);
       } 

       return highAlti;
    }
};