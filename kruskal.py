import time

connections = []
tree = []
for i in range(0, 10):
    row = []
    rowTree = []
    for j in range(0, 10):
        if i == j:
            row.append(True)
            rowTree.append(True)
        else:
            row.append(False)
            rowTree.append(False)
    connections.append(row)
    tree.append(rowTree)

def kruskal(edges):
    while(True):
        mn = 1000000
        for i in range(0, 10):
            for j in range(i+1, 10):
                global connections
                if edges[i][j] < mn and not connections[i][j]:
                    mn = edges[i][j]
                    mnX = i
                    mnY = j
        edges[mnX][mnY] = 1000000
        edges[mnY][mnX] = 1000000
        connections[mnX][mnY] = True
        connections[mnY][mnX] = True
        tree[mnX][mnY] = True
        tree[mnY][mnX] = True
        #print(tree)
        updateConnections(mnX, mnY, 0)
        
        flag = True
        for k in range(0, 10):
            flag = flag and connections[0][k]
        if flag:
            break

def updateConnections(n, m, k):
    for i in range(k, 10):
        if connections[i][n]:
            connections[i][m] = True
            connections[m][i] = True
            updateConnections(i, m, i+1)
        if connections[i][m]:
            connections[i][n] = True
            connections[n][i] = True
            updateConnections(i, n, i+1)

e =    [[0, 26, 48, 61, 15, 59, 84, 43, 51, 61],
        [26, 0, 24, 20, 71, 89, 5, 43, 7, 94], 
        [48, 24, 0, 37, 37, 39, 18, 55, 99, 23], 
        [61, 20, 37, 0, 4, 66, 3, 86, 64, 68], 
        [15, 71, 37, 4, 0, 15, 45, 62, 58, 36], 
        [59, 89, 39, 66, 15, 0, 8, 35, 84, 90], 
        [84, 5, 18, 3, 45, 8, 0, 13, 92, 8], 
        [43, 43, 55, 86, 62, 35, 13, 0, 13, 43], 
        [51, 7, 99, 64, 58, 84, 92, 13, 0, 50], 
        [61, 94, 23, 68, 36, 90, 8, 43, 50, 0]]

start = time.time()
kruskal(e)
end = time.time()

for i in range(0, 10):
    print(tree[i])
print("The tree outlined above was calculated in ", str(end - start), " seconds.")
