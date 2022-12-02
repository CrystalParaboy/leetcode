class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> list1(26,0);
        vector<int> list2(26,0);
        int idx;
        if(word1.length()!=word2.length()) return false;
        for(int i=0;i<word1.length();i++){
            idx=word1[i]-'a';
            list1[idx]++;
        }
        for(int i=0;i<word1.length();i++){
            idx=int(word2[i]-'a');
            if(!list1[idx]) return false;
            list2[idx]++;
        }
        for(int i=0;i<list1.size();i++){
            for(int j=0;j<list2.size();j++){
                if(list1[i]==list2[j]){
                    list2[j]=0;
                    break;
                }
                if(j==list2.size()-1) return false;
            }
        }
        return true;
    }
};
