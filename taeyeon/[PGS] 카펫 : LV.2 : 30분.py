''' 
<문제>
- 중앙에는 노란색, 밖에 테두리는 갈색으로 칠해져 있음
- 갈색 격자 수, 노란색 격자 수가 주어질때, 카펫의 가로 세로 크기 순서대로 담아서 내보내기
- 카펫의 가로는 세로길이와 같거나 큼

<풀이> 
yellow가 어떻게 배열되느냐에 따라서 가로 세로가 정해짐.. 
yellow가 한줄이면 garo = yellow + 2
yellow가 두줄이면, garo = yellow // 2 +2, 
yellow가 3줄이면, yellow // 3 + 2 
-> yellow가 몇줄인가를 기준으로 for문 돌리고, 가로 세로와 brown,yellow 관계식으로 조건 걸어주기
'''

# brown과 garo, sero 관계, brown = garo * 2 + 2*(sero - 2)

def solution(brown, yellow):
    answer = []
    
    for i in range(1,yellow+1):  # i는 최대길이가 yellow, i : yellow가 몇줄일 것인가
        garo = (yellow // i) + 2
        sero = i + 2
        if garo >= sero and brown == garo * 2 + 2 * (sero-2) and (garo * sero) == (yellow+brown) :
            break
    
    answer = [garo, sero]
    return answer