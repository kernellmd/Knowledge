#简单的使用request.get请求，会被Amazon的服务器拒绝，因为request.get请
#求的头部默认的User-agent为Python-request，这会被Amazon服务器识别为爬
#虫而拒绝

import requests

url = "https://www.amazon.cn/dp/B0083DP0CY/ref=cngwdyfloorv2_recs_0/459-2106455-8599868?pf_rd_m=A1AJ19PSB66TGU&pf_rd_s=desktop-2&pf_rd_r=TMXQ8S3GXFPF8RTRX8R5&pf_rd_r=TMXQ8S3GXFPF8RTRX8R5&pf_rd_t=36701&pf_rd_p=19fc3fc8-b320-45dc-a7e8-b4ecd543eea8&pf_rd_p=19fc3fc8-b320-45dc-a7e8-b4ecd543eea8&pf_rd_i=desktop"
kv = {'user-agent':'Mozilla/5.0'}  #伪装为Mozilla/5.0浏览器发起的请求

try:
    r = requests.get(url, headers=kv)
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(r.text[:1000])
except:
    #print(r.request.headers)
    print("爬取失败")