class Solution {
public:
    int largestElement(vector<int>& nums) {
       int maxVal= nums[0];

        for(int i=1; i<=nums.size(); i++){
            if(nums[i]>maxVal){
                 maxVal = nums[i];
            }
           
        }
        return maxVal;

    }
};
