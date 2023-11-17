def solution(name):
    total = 0
    n = len(name)
    answer = 'A' * n
    left = 0
    right = 0
    
    if n == 1:
        return ord(name) - ord('A') if ord(name) - ord('A') <= 91 - ord(name) else 91-ord(name)
        
    for i in range(1, n): # idx 0과 근접한 A의 계수 구하기(진행방향 결정하기 위함)
        if name[i] == "A":
            right += 1
        else :
            break
    for i in range(1, n):
        i = -i
        if name[i] == "A":
            left += 1
        else :
            break
    
    if set(name) == {"A"}:
        return 0
    
    if left >= right : # 오른쪽 진행
        for i in range(n):
            A = ord(name[i]) - ord(answer[i])
            B = 91 - ord(name[i])
            
            if i > 0:
                total += 1
            
            if name[i] == answer[i]:
                continue
            
            if A <= B: # A->Z방향
                total += A
            else : # Z->A방향?
                total += B
        return total - left
    else :
        for i in range(n):
            i = -i
            A = ord(name[i]) - ord(answer[i])
            B = 91 - ord(name[i])
            
            if i < 0:
                total += 1
            
            if name[i] == "A":
                continue
            
            if A <= B: # A->Z방향
                total += A
            else : # Z->A방향
                total += B
        return total - right
    return total
