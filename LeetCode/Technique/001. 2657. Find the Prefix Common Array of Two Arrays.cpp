//a
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int frq[51]={0};
        vector<int> c;
        int n=(int)A.size();
        int commonCnt=0;
        for(int i=0;i<n;i++){
            frq[A[i]]++;
            if(frq[A[i]]==2) commonCnt++;
            frq[B[i]]++;
            if(frq[B[i]]==2) commonCnt++;
            
            c.push_back(commonCnt);
        }
        return c;
    }
};
