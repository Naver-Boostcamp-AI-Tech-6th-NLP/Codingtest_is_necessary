def solution(nums):
    answer = 0
    num = len(nums)
    s = list(set(nums))
    if num//2 >= len(s) :
        return len(s)
    else :
        return num//2
