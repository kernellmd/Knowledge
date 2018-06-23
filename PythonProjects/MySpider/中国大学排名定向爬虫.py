#输入：大学排名URL链接
#输出：大学排名信息的屏幕输出（排名，大学名称，总分）
#技术路线：requests‐bs4
#定向爬虫：仅对输入URL进行爬取，不扩展爬取

import requests
from bs4 import BeautifulSoup
import bs4

#获取url信息，输出url内容
def get_HTML_text(url):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        print("获取信息失败")
        raise

#将html页面放到list列表（ulist）中
def fill_univlist(ulist, html):
    soup = BeautifulSoup(html, "html.parser")
    for tr in soup.find('tbody').children:
        #过滤掉字符串标签
        if isinstance(tr, bs4.element.Tag):
            tds = tr('td')
            ulist.append([tds[0].string, tds[1].string, tds[3].string])

#打印ulist信息
def print_univlist(ulist, num):
    #打印表头
    #会产生对齐问题，解决方案如下
    print("{0:{3}^10}\t{1:{3}^15}\t{2:{3}^10}".format("排名", "学校名称", "总分", chr(12288)))
    for i in range(num):
        u = ulist[i]
        #与表头相一致的字符串表示
        print("{0:{3}^10}\t{1:{3}^15}\t{2:{3}^10}".format(u[0], u[1], u[2], chr(12288)))

def main():
    uinfo = []
    url = "http://www.zuihaodaxue.cn/zuihaodaxuepaiming2018.html"
    html = get_HTML_text(url)
    fill_univlist(uinfo, html)
    print_univlist(uinfo, 20)  #列出20所学校的相关信息

if __name__ == "__main__":
    main()