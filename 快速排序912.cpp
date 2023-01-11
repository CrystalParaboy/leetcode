class Solution {
public:
    void quickSort(vector<int> &nums, int l, int r){
        if(l<r){
			//swapping element at index l with element at random index
            swap(nums[l + rand() % (r -l + 1)], nums[l]);
            int mid, i, j;
            int pivotIndex = i = l;
            int end = j = r;
            i++;
        
            while(i<=j){
                while(i<=end && nums[i] < nums[pivotIndex]){
                    i++;
                }
                while(j >= pivotIndex && nums[j] > nums[pivotIndex]){
                    j--;
                }
                if(i<=j){
                    swap(nums[i++], nums[j--]);
                }
            }   
        swap(nums[pivotIndex], nums[j]);
        mid=j;
            quickSort(nums, l, mid-1);
            quickSort(nums, mid+1, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
