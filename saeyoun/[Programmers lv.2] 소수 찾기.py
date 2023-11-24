# yellow 개수 -> brown 개수
# 1-> 4 = 2(x+3)
# 2-> 6 / 6 = 2(x/2+4)
# 3-> 8 /  / 8 = 2(x/3+5)
# 4-> 10 / 8      = 2(x/4+6)
# 6 ->   / 10 / 10
#
# y=yellow개수, b=brown개수, l=yellow세로길이
# 2(y/l + l+2) = b
# 2y/l + 2l + 4 = b

def solution(brown, yellow):
    
    for line in range(1,2500): # line = 노란색의 세로 길이
        if (2*yellow/line + 2*line + 4) == brown: # yellow개수와 brown개수에 맞는 line 찾을 경우
            break
            
    answer = [yellow/line+2, line+2]
    
    return answer
