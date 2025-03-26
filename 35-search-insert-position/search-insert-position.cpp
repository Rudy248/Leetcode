class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0; int r=n;
        while((l+1)<r){
            int m=(l+r)/2;
            if(nums[m]<=target){
                l=m;
              
            }
            else{
                r=m;
            }
        }
        if(nums[l]==target ){
            return l;
        }
        
        else{
            if(nums[l]< target){
                return r;
            }
            else{
                return l;
            }
                    
        }
    }
};