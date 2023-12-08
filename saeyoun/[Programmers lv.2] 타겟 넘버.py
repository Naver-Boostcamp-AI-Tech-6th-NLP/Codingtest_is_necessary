global cnt 
cnt = 0
def dfs(lev, path, numbers, target):
    global cnt
    if lev == len(numbers):
        sum = 0
        for op, n in zip(path, numbers):
            sum += op*n
        if sum == target:
            cnt += 1
        return
    dfs(lev+1, path+[1], numbers, target)
    dfs(lev+1, path+[-1], numbers, target)
    
def solution(numbers, target):
    answer = 0
    path = []
    
    dfs(0, path, numbers, target)
    
    return cnt
