'''
<문제>
한자리 숫자가 적힌 종이 조각 -> 종이 조각을 붙여 소수 몇개 만들 수 있을지
이때, 문자열에 있는 모든 숫자를 쓰지 않아도 ok

<풀이>
- 숫자를 랜덤으로 조합 // 소수인지 아닌지 판별하기 두가지로 나눌 수 있음
- 숫자 랜덤으로 조합하기 -> permutations 이용(검색해봄ㅎ)⭐️, set 이용해서 중복 없애기
- 소수인지 아닌지 판별 -> 에라토스테네스의 체 이용(검색해봄ㅎ) ⭐️
    - 0,1은 기본으로 소수가 아니므로, false
    - 2보다 큰 수는 2~sqrt(n) 까지 나눴을때 나머지가 0인게 한 개라도 있다면 소수!

'''

from itertools import permutations

def sosu(a):
    if(a <= 1):
        return False
    
    for k in range(2, int(a**0.5) + 1):
        if a % k == 0:
            return False    
    return True



def solution(numbers):
    answer = 0
    n = []
    
    for i in range(len(numbers)):
        n.extend(permutations(list(numbers), i+1))
    
    n = set([int(''.join(k)) for k in n])
        
    for s in n:
        if sosu(s) == True:
            answer += 1
    
    return answer