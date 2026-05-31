class Solution {
public:
    int trap(vector<int>& height) {
        int total=0, n=height.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0]=height[0];
        for(int i=1; i<n-1; i++){
            prefix[i]=max(prefix[i-1],height[i]);
        }
        suffix[n-1]=height[n-1];
        for(int j=n-2; j>=0; j--){
            suffix[j]=max(suffix[j+1],height[j]);
        }
        for(int i=0; i<n-1; i++){
            total+=min(prefix[i],suffix[i]) - height[i];
        }
        return total;
    }
};
