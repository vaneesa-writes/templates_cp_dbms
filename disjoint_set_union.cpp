class DisjSet {
	long long int *rank, *parent, n;
 
public:
 
	// Constructor to create and
	// initialize sets of n items
	DisjSet(long long int n)
	{
		rank = new long long int[n];
		parent = new long long int[n];
		this->n = n;
		makeSet();
	}
 
	// Creates n single item sets
	
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
 
	// Finds set of given item x
	int find(int x)
	{
		// Finds the representative of the set
		// that x is an element of
		if (parent[x] != x) {
 
			// if x is not the parent of itself
			// Then x is not the representative of
			// his set,
			parent[x] = find(parent[x]);
 
			// so we recursively call Find on its parent
			// and move i's node directly under the
			// representative of this set
		}
 
		return parent[x];
	}
 
	// Do union of two sets represented
	// by x and y.
	void Union(int x, int y)
	{
		// Find current sets of x and y
		long long int xset = find(x);
		long long int yset = find(y);
 
		// If they are already in same set
		if (xset == yset)
			return;
 
		// Put smaller ranked item under
		// bigger ranked item if ranks are
		// different
		if (rank[xset] < rank[yset]) {
			parent[xset] = yset;
		}
		else if (rank[xset] > rank[yset]) {
			parent[yset] = xset;
		}
 
		// If ranks are same, then increment
		// rank.
		else {
			parent[yset] = xset;
			rank[xset] = rank[xset] + 1;
		}
	}
};
