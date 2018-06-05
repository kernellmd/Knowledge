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
#打印
#prettify()函数可以为html文本增加换行符，也可以单独对标签进行处理
#print(soup.prettify())
#获取head标签
#print(soup.head)
#获取head标签的子标签节点
#.contents返回一个列表，此列表不仅包括子标签，还包括字符串如'\n'
#print(soup.head.contents)
#body标签
#body_children = soup.body.contents
#print(body_children)
#print(body_children[1])
#soup的父标签就是他本身
#print(soup.html)
#print(soup.html.parent)

#a标签的平行标签
a_tag = soup.a
print(a_tag.prettify())
#print(a_tag.next_sibling)
#print(a_tag.next_sibling.next_sibling)

#print()
#print(a_tag.previous_sibling)
#print(a_tag.previous_sibling.previous_sibling)  #为空