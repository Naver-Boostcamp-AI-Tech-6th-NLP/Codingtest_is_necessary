'''
<문제> 숫자가 제시되면 k개의 수를 제거했을때 얻을 수 있는 가장 큰 숫자 구하기
<풀이> 스택
앞자리에 큰 수가 와야 가장 큰 숫자를 구할 수 있음



'''

def solution(number, k):
    stack = []

    for i in number:
        while k > 0 and stack and stack[-1] < i:
            stack.pop()
            k -= 1
        stack.append(i)

    return ''.join(stack[:len(stack) - k])
    

