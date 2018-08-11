import networkx as nx

N = 10000
M = 500000
P = 0.005
G = nx.fast_gnp_random_graph(N,P,None,True)	

while (len(G.edges()) > M):
	print len(G.edges())
	print M
	G = nx.fast_gnp_random_graph(N,P,None,True)	

E = G.edges()

f = open('input.txt','w')
print>>f,N,' ',len(E)
for i in xrange(0,len(E)):
	print>>f,E[i][0]+1,' ',E[i][1]+1
f.close()
