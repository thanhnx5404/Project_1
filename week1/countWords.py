#PYTHON 
import sys
cnt = 0
text = sys.stdin.read()
values = list(map(str,text.split()))
for x in values:
    cnt += 1
print(cnt)
