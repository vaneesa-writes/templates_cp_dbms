class DisjSet {
	long long int *rank, *parent, n;
 
public:
 
	DisjSet(long long int n)
	{
		rank = new long long int[n];
		parent = new long long int[n];
		this->n = n;
		makeSet();
	}
 
	
	int count_comp(){
	    long long int ans=0;
	    for (long long int i = 0; i < n; i++) {
			ans+=parent[i] == i;
		}
		return ans;
	}
	
	void makeSet()
	{
		for (long long int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
 
	int find(int x)
	{
		if (parent[x] != x) {
 
			parent[x] = find(parent[x]);
 
		}
 
		return parent[x];
	}
 
	void Union(int x, int y)
	{
		long long int xset = find(x);
		long long int yset = find(y);
 
		if (xset == yset)
			return;
 
		if (rank[xset] < rank[yset]) {
			parent[xset] = yset;
		}
		else if (rank[xset] > rank[yset]) {
			parent[yset] = xset;
		}
 
		else {
			parent[yset] = xset;
			rank[xset] = rank[xset] + 1;
		}
	}
};


