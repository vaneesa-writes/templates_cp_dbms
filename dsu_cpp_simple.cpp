class DSU{
    
    int n,*par,*rank;
    public:
    
        DSU(int nodes){
            n=nodes;
            par = new int[n];
            rank = new int[n];
            for(int i=0;i<n;i++){
                par[i]=i;
                rank[i]=1;
            }
        }
        
        void merge(int a,int b){
            int x=find_par(a);
            int y=find_par(b);
            if(x!=y){
                if(rank[x]==rank[y]){
                    par[x]=y;
                    rank[y]++;
                }
                else if(rank[x]<rank[y]){
                    par[x]=y;
                }
                else{
                    par[y]=x;
                }
            }
        }
        
        int find_par(int node){
            if(node == par[node]){
                return node;
            }
            return par[node]=find_par(par[node]);
        }
        
        int count_components(){
            int comp=0;
            for(int i=0;i<n;i++){
                if(par[i]==i) comp++;
            }
            return comp;
        }
};
