def sttt(strg): # 2개씩 분리해주는 함수
    result = []
    for i in range(len(strg)-1):
        if (strg[i].lower() in 'abcdefghijklmnopqrstuvwxyz') and (strg[i+1].lower() in 'abcdefghijklmnopqrstuvwxyz'):
            st = strg[i]+strg[i+1]
            result.append(st.lower())
    return result

def solution(str1, str2):
    answer = 0
    str11 = []
    str22 = []
    str11 = sttt(str1)
    str22 = sttt(str2)
    # print(str11, str22)
    
    hab = []
    kyo = []
    
    k_temp = []
    for wd in str11:
        for j in str22:
            if (wd == j) and (wd not in k_temp):
                k_temp.append(wd)
    # print(k_temp)
    for i in k_temp:
        for j in range(min(str11.count(i), str22.count(i))):
            kyo.append(i)
    # print(kyo)
    temp = list(set(str11+str22))
    for i in temp:
        for j in range(max(str11.count(i), str22.count(i))):
            hab.append(i)
    # print(hab)
    
    if len(kyo)==0 and len(hab) == 0:
        answer = 65536
    else :
        answer = int(65536*(len(kyo)/len(hab)))
    return answer
