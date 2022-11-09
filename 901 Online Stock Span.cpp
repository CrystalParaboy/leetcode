class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        if(max_num.second==0){
            max_num.first=0;
            max_num.second=price;
            nums.push_back(price);
            return 1;
        }
        if(max_num.second<price){
            max_num.first=nums.size();
            max_num.second=price;
            nums.push_back(price);
            return max_num.first+1;
        }
        else{
            int span=0;
            nums.push_back(price);
            for(int i=nums.size()-1;i>=0;i--){
                if(nums[i]<=price) span++;
                else break;
            }

            return span;
        }
        
    }
private:
    vector<int> nums;
    pair<int,int> max_num;
};

//find solution faster
class StockSpanner {
public:

    // declare a stack of pair {price, count}

    // count will keep track of no. of consecutive elements less than or equal to price

    stack<pair<int, int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int count = 0;

        // find no. of elements less than or equal to curr price

        while(st.empty() == false && st.top().first <= price)
        {
            // update count

            count += st.top().second;

            // pop the smaller element

            st.pop();
        }

        // increment the count for curr price

        count++;

        // push the {price, count} into stack

        st.push({price, count});

        return count;
    }
};
