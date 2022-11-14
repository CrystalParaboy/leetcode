
class Solution {
public:
    void reverse_word(string &str, int i, int j)
    {
        while(i <= j)
        {
            swap(str[i], str[j]);           
            i++;            
            j--;
        }
    }  
    void remove_space(string &str){
        int slow=0;
        for(int i=0;i<str.size();++i){
            if(str[i]!=' '){
                if(slow!=0) str[slow++]=' ';
                while(str[i]!=' '&&i<str.size()) {str[slow++]=str[i++];}
            }
        }
        str.resize(slow);
    }
    string reverseWords(string str) {   
       remove_space(str);    
       reverse_word(str,0,str.size()-1);
       int start=0;
       for(int i=0;i<=str.size();i++){
           if(str[i]==' '||i==str.size()){
            reverse_word(str, start, i-1);
            start=i+1;
           }

       }
       return str;
    }
};
