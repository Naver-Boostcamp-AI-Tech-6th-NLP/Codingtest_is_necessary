#애라토스테네스의 체 그냥 외워
# 이것도 풀었던 문제군요. 이런! 
# 하지만 에라토스테네스의 체는 중요한 알고리즘이니까 한번 더 공부하면서 복습하겠음

# 일단 문제를 딱!!! 보면 소수가 적혀있다? 그럼 에라토스테네스의 체 라고 볼 수 있다. 
# 솔직히 이걸 코테에 내는건 못본거같긴 한데, 그래도 소수판별을 이용해서 응용하는 문제는 기업 코테에서 본 적 있는거같음
# 
import math
 

#https://codingkwon.tistory.com/241
n = 1000 # 2부터 1,000까지의 모든 수에 대하여 소수 판별
'''
# 에라토스테네스의 체 알고리즘 
for i in range(2, int(math.sqrt(n)) + 1): # 2부터 n의 제곱근까지의 모든 수를 확인하며
    if array[i] == True: # i가 소수인 경우 (남은 수인 경우)
        # i를 제외한 i의 모든 배수를 지우기
        j = 2 
        while i * j <= n:
            array[i * j] = False
            j += 1

# 모든 소수 출력
for i in range(2, n + 1):
    if array[i]:
        print(i, end=' ')


def solution(numbers):
    answer = 0
    array = [True for i in range(n + 1)] # 처음엔 모든 수가 소수(True)인 것으로 초기화
    for i in range(2, int(math.sqrt(n)) + 1): # 2부터 n의 제곱근까지의 모든 수를 확인하며
        if array[i] == True: # i가 소수인 경우 (남은 수인 경우)
            # i를 제외한 i의 모든 배수를 지우기
            j = 2 
            while i * j <= n:
                array[i * j] = False
                j += 1
        from itertools import permutations

global ok 
ok = list()
'''
from itertools import permutations
# 앗 ㅎ 근데 다시 보니까 이것도 itertools 의 permutation 써서 하는거네 ㅎ 민석이가 잘 고려해서 문제를 골랐구나 헤헤
# 40분 실패! 
global ok 
ok = list()

def is_prime_number(n):
    # tuple -> list -> str -> int
    nums = list(n)
    string = ''.join(s for s in nums)
    num = int(string)
    # 소수 판별
    if num == 1 or num == 0 :
        return False
    for i in range(2,num):
        if (num % i == 0):
            return False
    ok.append(num)
    cnt = ok.count(num)
    if (cnt >= 2):
        return False
    return True

def solution(numbers):
    answer = 0
    length = len(numbers)
    for i in range(1,length+1):
        for j in permutations(numbers,i):
            result = is_prime_number(j)
            if (result == True):
                answer+=1
    return answer
<>#애라토스테네스의 체 그냥 외워 # 이것도 풀었던 문제군요. 이런! # 하지만 에라토스테네스의 체는 중요한 알고리즘이니까 한번 더 공부하면서 복습하겠음 # 일단 문제를 딱!!! 보면 소수가 적혀있다? 그럼 에라토스테네스의 체 라고 볼 수 있다. # 솔직히 이걸 코테에 내는건 못본거같긴 한데, 그래도 소수판별을 이용해서 응용하는 문제는 기업 코테에서 본 적 있는거같음 # import math #https://codingkwon.tistory.com/241 n = 1000 # 2부터 1,000까지의 모든 수에 대하여 소수 판별 ''' # 에라토스테네스의 체 알고리즘 for i in range(2, int(math.sqrt(n)) + 1): # 2부터 n의 제곱근까지의 모든 수를 확인하며 if array[i] == True: # i가 소수인 경우 (남은 수인 경우) # i를 제외한 i의 모든 배수를 지우기 j = 2 while i * j list -> str -> int nums = list(n) string = ''.join(s for s in nums) num = int(string) # 소수 판별 if num == 1 or num == 0 : return False for i in range(2,num): if (num % i == 0): return False ok.append(num) cnt = ok.count(num) if (cnt >= 2): return False return True def solution(numbers): answer = 0 length = len(numbers) for i in range(1,length+1): for j in permutations(numbers,i): result = is_prime_number(j) if (result == True): answer+=1 return answer
영한



구글번역
#애라토스테네스의 체 그냥 외워 # 이것도 풀었던 문제군요. 이런! # 하지만 에라토스테네스의 체는 중요한 알고리즘이니까 한번 더 공부하면서 복습하겠음 # 일단 문제를 딱!!! 보면 소수가 적혀있다? 그럼 에라토스테네스의 체 라고 볼 수 있다. # 솔직히 이걸 코테에 내는건 못본거같긴 한데, 그래도 소수판별을 이용해서 응용하는 문제는 기업 코테에서 본 적 있는거같음 # import math #https://codingkwon.tistory.com/241 n = 1000 # 2부터 1,000까지의 모든 수에 대하여 소수 판별 ''' # 에라토스테네스의 체 알고리즘 for i in range(2, int(math.sqrt(n)) + 1): # 2부터 n의 제곱근까지의 모든 수를 확인하며 if array[i] == True: # i가 소수인 경우 (남은 수인 경우) # i를 제외한 i의 모든 배수를 지우기 j = 2 while i * j list -> str -> int nums = list(n) string = ''.join(s for s in nums) num = int(string) # 소수 판별 if num == 1 or num == 0 : return False for i in range(2,num): if (num % i == 0): return False ok.append(num) cnt = ok.count(num) if (cnt >= 2): return False return True def solution(numbers): answer = 0 length = len(numbers) for i in range(1,length+1): for j in permutations(numbers,i): result = is_prime_number(j) if (result == True): answer+=1 return answer
