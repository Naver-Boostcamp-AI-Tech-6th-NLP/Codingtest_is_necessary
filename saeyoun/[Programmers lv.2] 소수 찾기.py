def isPrime(n): # 소수 판단 함수
    if n==0 or n==1:
        return False
    for i in range(2,n):
        if n%i==0:
            return False
    return True
    
def dfs(numbers, n, visited, path, results): # 숫자 조합 함수
    if path!="": # path = 조합 중인 숫자
        results.add(int(path)) # 숫자 result에 add
    if len(path)==n: # 최대 길이면 return
        return
    for i in range(n):
        if visited[i]==1: # 사용 숫자면 continue
            continue
        visited[i]=1 # 사용 숫자 체크
        dfs(numbers, n, visited, path+numbers[i], results) # path에 다음 숫자 이어서 재귀
        visited[i]=0 # 사용 숫자 체크 해제
        
        
def solution(numbers):
    n = len(numbers)
    visited = [0]*n
    path = ""
    results = set()
    
    dfs(numbers, n, visited, path, results)
    answer = len([r for r in results if isPrime(r)]) # 조합된 숫자들 중 소수인 숫자들 개수 세기
    
    return answer
