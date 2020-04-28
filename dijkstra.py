import time

dist = []
for i in range(0, 10):
    row = []
    for j in range(0, 10):
        if i == j:
            row.append(0)
        else:
            row.append(1000000)
    dist.append(row)

def dijkstra(edges):
    for i in range(0, 10):
        for j in range(i+1, 10):
            global dist
            dist[i][j] = checkNeighbors(edges, i, j, 1)
            dist[j][i] = dist[i][j]

def checkNeighbors(edges, n, m, k):
    mn = 1000000
    for i in range(k, 10):
        global dist
        if i != n and i != m:
            if (dist[n][m] > (edges[n][i] + checkNeighbors(edges, n, i, i+1)) or dist[n][m] > (edges[m][i] + checkNeighbors(edges, m, i, i+1))):
                val =  min(edges[n][i] + checkNeighbors(edges, n, i, i+1), edges[m][i] + checkNeighbors(edges, m, i, i+1))
                if val < mn:
                    mn = val
    if mn != 1000000:
        return mn
    else:
        return edges[n][m]

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
dijkstra(e)
end = time.time()

print(dist)
print("The spanning tree above was found in " + str(end - start) + " seconds.")

