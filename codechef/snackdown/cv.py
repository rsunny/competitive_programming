
import networkx as nx

G = nx.configuration_model([1,1,1])	

E = G.edges()

for i in xrange(0,len(E)):
	print>>E[i][0]+1,' ',E[i][1]+1
