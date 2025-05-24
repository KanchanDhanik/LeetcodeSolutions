class Solution {
public:
    int maxSubstrings(string word) {
        int n=word.size();
        int j=0;
        unordered_map<char,int>mpp;
        int cnt=0;
        int end=-1;
        while(j<n){
            if(mpp.find(word[j])!=mpp.end() && ((end==-1)||mpp[word[j]]>end)){
                int len=j-mpp[word[j]]+1;
                if(len>=4){
                    cnt++;
                    end=j;
                }
                
            }else{
                mpp[word[j]]=j;
            }
            j++;
        }
        return cnt;
        
    }
};