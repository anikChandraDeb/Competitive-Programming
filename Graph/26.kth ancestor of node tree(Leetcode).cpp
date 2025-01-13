class TreeAncestor {
public:
    int LCA[50002][17];
    TreeAncestor(int n, vector<int>& parent) {
        memset(LCA,-1,sizeof(LCA));
        for(int i=0;i<n;i++) LCA[i][0]=parent[i];
        for(int j=1;j<=16;j++){
            for(int i=0;i<n;i++){
                if(LCA[i][j-1]!=-1){
                    int par=LCA[i][j-1];
                    LCA[i][j]=LCA[par][j-1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        while(k>0){
            int i=log2(k);
            node=LCA[node][i];
            if(node==-1) break;
            k-=(1<<i);
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
