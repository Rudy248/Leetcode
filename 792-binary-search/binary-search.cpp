class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, r=n;
        while((l+1)<r){
            int mid=(l+r)/2;
            if(nums[mid]<=target){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        if(nums[l]==target){
            return l;
        }
        else{
            return -1;
        }
    }
};