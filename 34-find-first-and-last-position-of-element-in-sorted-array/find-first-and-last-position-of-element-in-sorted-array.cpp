class Solution {
public:
    int lpredicate(int m, vector<int> & nums, int target){
        if(nums[m]>=target){
            return 1;
        }
        else{
            return 0;
        }
    }
    int rpredicate(int m, vector<int> & nums, int target){
        if(nums[m]<=target){
            return 0;
        }
        else{
            return 1;
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
       int n=nums.size();
       if (n == 0) return {-1, -1};
       
       int l=-1; int r=n;
       vector<int> ans{-1,-1};
       while((l+1)<r){
        int m=(l+r)/2;
        if(lpredicate(m,nums, target)==0){
            l=m;
        }
        else{
            r=m;
        }
       }  
        if(r<n && nums[r]==target){

            ans[0]=r;
        }
        else{
        
           return ans;
        }
        
        l=0; r=n;
         while((l+1)<r){
        int m=(l+r)/2;
        if(rpredicate(m,nums, target)==0){
            l=m;
        }
        else{
            r=m;
        }
       }  
        ans[1]=l;
        return ans;
       
    }
};