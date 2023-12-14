"""
가장 많은 종류 선택하는 방법

총 종류가 n/2보다 큰 경우 -> n/2
총 종류가 n/2보다 작거나 같은 경우 -> 총 종류만큼

set 써서 풀면 끝??? -> 다 고려했나??
생각보다 쉽게 테케가 통과되었는데 다 고려한게 맞는지 의문

"""

def solution(nums):
    n=len(nums)
    num_type=set(nums)
    n_type=len(num_type)
    answer=n_type
    if n_type>n/2:
        answer=n//2
    return answer
