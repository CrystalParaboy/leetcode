class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid=0,low=0,high=nums.size()-1;
        int temp;
        while(mid<=high){
            switch(nums[mid]){
                case 2:
                temp=nums[mid];
                nums[mid]=nums[high];
                nums[high]=temp;
                high--;
                break;
                case 0:
                temp=nums[mid];
                nums[mid]=nums[low];
                nums[low]=temp;
                mid++;
                low++;
                break;
                case 1:
                mid++;
                break;

            }
        }

        
    }
};
