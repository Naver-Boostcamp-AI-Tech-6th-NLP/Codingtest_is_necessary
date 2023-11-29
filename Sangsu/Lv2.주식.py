def solution(prices):
    answer = []
    count = []
    for idx, val in enumerate(prices):
        cnt = 1
        if len(prices) == idx+1 :
            # print('마지막 0추가')
            # print(count)
            count.append(0)
        for j in range(idx+1, len(prices)):
            # print(val, j, idx)
            if j == len(prices)-1:
                # print('j가 마지막 도달')
                # print(prices[j], val, cnt)
                count.append(cnt)
                break
            # print(val, j)
            if val <= prices[j]:
                cnt += 1
            else :
                # print('val보다 j가 하락')
                count.append(cnt)
                # print(count)
                break
    return count
