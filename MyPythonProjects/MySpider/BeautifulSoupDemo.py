from bs4 import BeautifulSoup
import requests

#也可以在浏览器中通过查看源码获得源html页面
#此demo使用requests库获取
url = "https://python123.io/ws/demo.html"

r = requests.get(url)
demo = r.text
#由BeautifulSoup类产生一个对应的对象，此对象可以解析demo为html页面
soup = BeautifulSoup(demo, 'html.parser')
#获取页面的title标签
#print(soup.title)
#获取页面的a标签
#print(soup.a)
print(soup.prettify())