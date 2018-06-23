import requests

kv = {"wd":"python"}  #360搜索引擎的代表关键字的参数为'q'而不是'wd'
url = "http://www.baidu.com/s"

try:
    r = requests.get(url, params=kv)
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print("返回信息的长度为", len(r.text))  #使用r.request.url可以查看发送给百度的request请求对应的url
except:
    print("爬取失败")