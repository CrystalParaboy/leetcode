class Solution {
    
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        typedef pair<int,int> Ipair;
        vector<int> res(tem.size(),0);
        if(tem.size()==0) return res; 
        res[0]=0;
        Ipair temp{0,tem[0]};
        stack<Ipair> st;
        st.push(temp);
        for(int i=1;i<tem.size();i++){
            while(!st.empty()&&tem[i]>st.top().second){
                    res[st.top().first]=i-st.top().first;
                    st.pop();
                }
            st.push(make_pair(i,tem[i]));
            
        }
        return res;

    }
};
