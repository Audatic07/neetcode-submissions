class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxvol=0;
        int i=0, j=heights.size()-1;
        while(i<j){
            int vol=(j-i)*min(heights[j],heights[i]);
            maxvol=max(vol,maxvol);
            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxvol;
    }
};
