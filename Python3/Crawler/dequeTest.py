# deque test

from collections import deque


queue = deque(["E","J","M"])
queue.append("T")
print(queue.popleft())  # E
queue.popleft()  # J

print(queue)

