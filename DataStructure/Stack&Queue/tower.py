def solution(heights):
    n = len(heights)
    answer = [0] * n
    
    idx = n - 1
    
    while idx >= 0:
        for i in range(idx, -1, -1):
            if heights[i] > heights[idx]:
                answer[idx] = i + 1
                break
        idx -= 1
        
    return answer
