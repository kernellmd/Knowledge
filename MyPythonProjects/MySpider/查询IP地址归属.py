#向ip138网站提交请求进行查询
#经过人工提交发现，该网站查询域名的url的形式为"http://www.ip38.com/ip.php?ip=xxx"（xxx为ip地址或域名）

import requests

url = "http://www.ip38.com/ip.php?ip="

try:
    r = requests.get(url + "www.baidu.com")
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(r.text[1000:2000])
except:
    print("爬取失败！")