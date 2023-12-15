'''
문제 - N마리 포켓몬 중 N/2마리 가져가도 ok, 폰켓몬 종류에 따라 번호로 구분
    -> 최대한 많은 종류 수의 포켓몬을 가져가야 함! 
    -> N/2마리의 포켓몬을 선택하는 방법 중 가장 많은 종류의 폰켓몬 선택 방법 찾기, 그때의 종류 번호의 개수 return

풀이 - set()이용해서 중복되는 숫자 제거 -> unique값 확인하기, unique값이 N/2 보다 작으면 answer는 unique값이 되게, unique값이 N/2보다 크면 answer는 N/2일수밖에 없음! 
'''


def solution(nums):
    answer = 0
    n = len(set(nums))
    if n <= len(nums) // 2:
        answer = n
    if n > len(nums) // 2:
        answer= len(nums) //2
    
    return answer