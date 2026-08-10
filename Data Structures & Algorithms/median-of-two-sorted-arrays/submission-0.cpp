class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            swap(nums1,nums2);
        }
        int m=nums1.size();
        int n=nums2.size();
        int half = (m+n+1)/2;
        int lo=0, hi=m;
        while(lo <= hi){
            int i = (lo+hi)/2;
            int j = half-i;
            int left1 = (i==0) ? INT_MIN : nums1[i-1];
            int right1 = (i==m) ? INT_MAX : nums1[i];
            int left2 = (j==0) ? INT_MIN : nums2[j-1];
            int right2 = (j==n) ? INT_MAX : nums2[j];
            if (left1 <= right2 && left2 <= right1){
                if((m+n)%2==1){
                    return max(left2,left1);
                }
                else{
                    return (double)(max(left2,left1)+min(right1,right2))/2;
                }
            }
            else if(left1 > right2){
                hi=i-1;
            }
            else{
                lo=i+1;
            }
        }
    }
};
