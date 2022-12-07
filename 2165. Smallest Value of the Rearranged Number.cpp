class Solution {
public:
    long long smallestNumber(long long num) {
        bool positive;
        if(num>0) positive=1;
        else positive=0;
        if(!positive) num=abs(num);
        vector<int> list;
        long long bit=1;
        long long result=0;
        int fd;
        long long db;
        while(num>0){
            fd=num%10;
            list.push_back(fd);
            num/=10;
            bit*=10;
        }
        
        if(positive){
            sort(list.begin(),list.end(),greater<int>());
            
            long long temp=1;
            for(int i=0;i<list.size();i++){
                if(list[i]==0){
                    long long first=result/(temp/10)*(bit/10);
                    cout<<first<<endl;
                    long long last=result%(temp/10);
                    cout<<last;
                    result=first+last;
                    return result;
                }
                else{
                    db=list[i]*temp;
                    result+=db;
                    temp*=10;
                }
            }
            return result;
        }
        else{
            sort(list.begin(),list.end());
            long long temp=1;
            for(int i=0;i<list.size();i++){
                db=list[i]*temp;
                result-=db;
                temp*=10;
            }
            return result;
        }
        return 0;
    }
};
