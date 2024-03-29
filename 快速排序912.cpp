class Solution {
public:
     void maxHeap(vector<int>& nums, int i, int len){
        while( (i<<1)+1<=len ){
            int lson = (i<<1) + 1;
            int rson = (i<<1) + 2;
            int large = i;
            if(lson <= len && nums[lson] > nums[large])
                large = lson;
            if(rson <= len && nums[rson] > nums[large])
                large = rson;
            if(large != i ){
                swap(nums[large], nums[i]);
                i =  large;
            }
            else break;
        }
    }
    void heapSort(vector<int>&nums){
        //build heap
        int len = nums.size()-1;
        for(int i =  len/2; i>=0; --i){
            maxHeap(nums, i, len);
        }

        //sort
        while(len >= 0){
            swap(nums[0], nums[len]);
            --len;
            maxHeap(nums, 0, len);
        }
        return;
    }
	
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
