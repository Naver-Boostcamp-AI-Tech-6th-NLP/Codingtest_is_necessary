from collections import deque

def solution(maps):
    n, m = len(maps), len(maps[0])
    visited = [[0]*m for i in range(n)]
    dy = [-1,1,0,0]
    dx = [0,0,-1,1]

    visited[0][0] = 1
    queue = deque([(0,0)])
    
    while queue:
        y,x = queue.popleft()
        if (y, x) == (n-1, m-1):
            return visited[y][x]
        for i in range(4):
            ny = y+dy[i]
            nx = x+dx[i]
            if  ny<0 or nx<0 or ny>=n or nx>=m:
                continue
            if maps[ny][nx]==0 or visited[ny][nx]!=0:
                continue
            visited[ny][nx]=visited[y][x]+1
            queue.append((ny,nx))
            
    return -1
