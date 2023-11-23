'''
20분

갈색과 노란색에 대한 정확한 설명?? 어떤 규칙을 갖는지, 노란색을 갈색이 뒤엎는 형태?
갈색 격자가 최외각만 두르는 건지?

brown/2를 기준으로 가능한 숫자 조합을 우선 array에 담기!
yello에 대입해보기!
-> brown이 기준이 되는게 시간복잡도가 훨씬 적기 때문에!

'''

def solution(brown, yellow):
    array,answer=[],[0,0]
    for i in range(2,brown//4+1):
        array.append([i+1,brown//2-i+1])
    for y,x in array:
        if yellow==(x-2)*(y-2):
            answer=[x,y]
            break
    return answer
