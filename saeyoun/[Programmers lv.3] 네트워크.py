def dfs(i, n, computers, visited):
    for j in range(n):
        if j==i: 
            continue
        if computers[i][j]==1 and visited[j]==0:
            visited[j]=1
            dfs(j, n, computers, visited)
    
def solution(n, computers):
    answer = 0
    
    visited = [0]*n
    for i in range(n):
        if visited[i] == 0:
            visited[i]=1
            answer += 1
            dfs(i, n, computers, visited)
        
    return answer
