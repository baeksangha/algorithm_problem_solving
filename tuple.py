'''
python re : 정규 표현식 library
Counter : dictionary 형태로 list의 원소의 갯수를 표현해줌
충격,..
'''

# KAKAO winter internship coding test

def solution(s):
    s = Counter(re.findall('\d+', s))
    return list(map(int, [k for k, v in sorted(s.items(), key=lambda x: x[1], reverse=True)]))

import re
from collections import Counter
