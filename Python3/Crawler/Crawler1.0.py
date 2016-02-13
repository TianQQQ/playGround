import re
import urllib.request
import urllib
 
from collections import deque
 
queue = deque()
visited = set()
 
url = 'http://news.dbanotes.net'  # start uniform resource locate
 
queue.append(url)
cnt = 0
 
while queue:
  url = queue.popleft()    # pop queue
  visited |= {url}  # mark visited
 
  print('Already taken: ' + str(cnt) + '  taking <---  ' + url)
  cnt += 1

  try:
      urlop = urllib.request.urlopen(url, timeout = 2)  # avoid timeout error
  except:
      continue


  if 'html' not in urlop.getheader('Content-Type'):
    continue
 
  
  try:
    data = urlop.read().decode('utf-8')         # avoid decode exception
  except:
    continue
 
  # Regex take elements for not visited
  linkre = re.compile('href=\"(.+?)\"')

  for x in linkre.findall(data):
    if 'http' in x and x not in visited:
      queue.append(x)
      print('Join Queue --->  ' + x)

saveFile(queue)

def saveFile(data):
    save_path = '~data.out'
    f_obj = open(save_path, 'wb') 
    f_obj.write(data)
    f_obj.close()
    
    
