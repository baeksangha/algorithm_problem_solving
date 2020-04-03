'''
2020 카카오 신입 블라인드 코딩테스트 '자물쇠와 열쇠'

brute force 문제였는데, 2차원 배열이라 지레 겁먹었다.
배열의 크기가 최대 20x20이라 충분히 모든 경우를 생각해볼만 했다.
key를 이리저리 돌리고 움직여가며 자물쇠에 맞춰보는 알고리즘이다.
정답률 18%
'''

import copy

def is_match(key, lock, key_st_x, key_st_y):
        
    lock_copy = copy.deepcopy(lock)
    
    n_key = len(key)
    n_lock = len(lock_copy)
    
    for i in range(n_key):
        for j in range(n_key):
            if key_st_x+i < 0 or key_st_y+j < 0 or key_st_x+i >= n_lock or key_st_y+j >= n_lock:
                continue
            lock_x = key_st_x + i
            lock_y = key_st_y + j
            #print(i, j, lock_x, lock_y, key[i][j], lock_copy[lock_x][lock_y])
            token = lock_copy[lock_x][lock_y] ^ key[i][j]
            if token == 0:
                return False
            lock_copy[lock_x][lock_y] = token
    
    # for line in lock_copy:
    #     print(line)
    
    for line in lock_copy:
        if 0 in line:
            return False
    
    return True
    


def solution(key, lock):
    answer = False
    
    n_key = len(key)
    n_lock = len(lock)
    
    n_merge = n_key + n_lock - 1
    r = 0
    while r < 4:
        for elem in key:
            print(elem)
        for i in range(n_merge):
            for j in range(n_merge):
                key_st_x = -n_key + 1 + i
                key_st_y = -n_key + 1 + j
                if is_match(key, lock, key_st_x, key_st_y):
                    return True
        key = list(zip(*reversed(key)))
        r += 1
        
    
    
    return answer
