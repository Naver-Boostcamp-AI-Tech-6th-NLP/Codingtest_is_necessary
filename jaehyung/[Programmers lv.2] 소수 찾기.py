def solution(numbers):
    '''
    초반에 삽질해서 시간 많이 씀!! ㅠㅠ
    
    
    1) numbers로 만들 수 있는 모든 경우의 수 만들고, 소수 탐색하기
    -> 가능한 경우의 수 2^7: 100개 정도 (소수 array 중복 사용가능하고, 작은 수부터 탐색하면 비용 거의 안듦)
    2) numbers 값 중 최대값 만들고, loop 돌아서 나올 수 있는 소수가 numbers 구성으로 가능한지 판별하기
    -> 시간 오버될 가능성 높음
    
    numbers 최대 len이 7: 10^7까지 경우의 수 가능
    nlogn까지 가능?
    
    에라토스(?)의 체 사용해서 풀기?
    약간의 트릭을 쓰자면 최대값 k의 제곱근까지만 loop 돌면 됨
    -> 소수 카운트 최적화해보기!! (더 이상 모르겠음)
    -> 굳이 카운트해서 소수 찾지 않아도 됨(여러번 왕복해야해서 시간복잡도 더 길어짐)
    그냥 숫자 나눠서 판별만 하기
    
    
    [0,1,1,2], 133
    소수 집합에서 어떻게 numbers 속 수 count해야 효율적?
    숫자가 많지 않으니 list로 check하는게 제일 빠를듯?
    -> permutation 쓰는게 가장 빨라보임...

    
    '''
    # 가능한 소수 집합 만들기
    import itertools

    list_num,perm=[s for s in numbers],[]
    for i in range(1,len(list_num)+1):
        perm=perm+[''.join(x) for x in list(itertools.permutations(list_num,i))]
    perm=[int(x) for x in perm]
    perm=list(set(perm))
    perm.sort()

    answer=0

    for p in perm:
        for i in range(2,int(p**0.5)+1):
            if p%i==0:
                break
        else:
            if p>1:
                answer+=1
    return answer
