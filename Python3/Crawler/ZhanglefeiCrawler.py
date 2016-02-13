#encoding: UTF-8
import urllib.request
import urllib


data = {}
data['word'] = 'Lefei Zhang'

url_values = urllib.parse.urlencode(data) # switch to url format string
# word=Lefei+Zhang
url = "http://www.baidu.com/s?"

full_url = url + url_values

data = urllib.request.urlopen(full_url).read()
data = data.decode('UTF-8')
print(data)
