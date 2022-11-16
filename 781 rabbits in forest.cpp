class Solution {
public:
    int numRabbits(vector<int>& answer) {
        sort(answer.begin(),answer.end());
        bool con=true;
        int result=0;
        int i=0;
        while(i<answer.size()){
            if(con==false){
                result+=answer[i]+1;
                i++;
                while(i<answer.size()&&answer[i]==answer[i-1]){i++;} 
            }
            if(answer[i]+i>=answer.size()) con=false;
            if(con==true){
                if(answer[answer[i]+i]==answer[i]){
                result+=answer[i]+1;
                i+=answer[i]+1;
                }
                else{
                    result+=answer[i]+1;
                    i++;
                    while(answer[i]==answer[i-1]) {i++;}
                }
            }
            
        }
        return result;
        
    }
};
