using Printf

connections = []
tree = []
for i in 1:10
	row = []
	rowTree = []
	for j in 1:10
		if i == j
			append!(row, true)
			append!(rowTree, true)
		else
			append!(row, false)
			append!(rowTree, false)
		end
	end
	append!(connections, [row])
	append!(tree, [rowTree])
end

mn = 1000000
mnX = 1
mnY = 1
function kruskal(edges)
	global connections
	while(true)
		global mn
		mn = 1000000
		for i in 1:10
			for j in i+1:10
				global connections
				if (edges[i][j] < mn) & (!connections[i][j])
					global mn
					mn = edges[i][j]
					global mnX
					mnX = i
					global mnY
					mnY = j
				end
			end
		end
		edges[mnX][mnY] = 1000000
		edges[mnY][mnX] = 1000000
		global connections
		connections[mnX][mnY] = true
		connections[mnY][mnX] = true
		global tree
		tree[mnX][mnY] = true
		tree[mnY][mnX] = true
		updateConnections(mnX, mnY, 1)

		flag = true
		for k in 1:10
			flag = flag & connections[1][k]
		end
		if flag
			break
		end
	end
end

function updateConnections(n, m, k)
	global connections
	for i in k:10
		if connections[i][n]
			global connections
			connections[i][m] = true
			connections[m][i] = true
			updateConnections(i, m, i+1)
		end
		if connections[i][m]
			global connections
			connections[i][n] = true
			connections[n][i] = true
			updateConnections(i, n, i+1)
		end
	end
end


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

@time kruskal(e)

for i in 1:10
	println(string(tree[i]))
end
