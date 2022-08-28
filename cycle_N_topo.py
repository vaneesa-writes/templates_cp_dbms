class Graph():
    def __init__(self,vertices):
        self.graph = defaultdict(list)
        self.V = vertices
    def addEdge(self,u,v):
        self.graph[u].append(v)
    def isCyclicUtil(self, v, visited, recStack):
        visited.add(v)
        recStack.add(v)
        for neighbour in self.graph[v]:
            if neighbour not in visited:
                if self.isCyclicUtil(neighbour, visited, recStack) == True:
                    return True
            elif neighbour in recStack:
                return True
        recStack.remove(v)
        return False
    def isCyclic(self):
        visited = set()
        recStack = set()
        nodes=set(self.graph.keys())
        for node in nodes:
            if visited not in visited:
                if self.isCyclicUtil(node,visited,recStack) == True:
                    return True
        return False
    def topologicalSortUtil(self, v, visited, stack):
        visited.add(v)
        for node in self.graph[v]:
            if node not in visited:
                self.topologicalSortUtil(node, visited, stack)
        stack.append(v)
    def topologicalSort(self):
        visited = set()
        stack = []
        nodes=set(self.graph.keys())
        for node in nodes:
            if node not in visited:
                self.topologicalSortUtil(node, visited, stack)
        return stack[::-1]
