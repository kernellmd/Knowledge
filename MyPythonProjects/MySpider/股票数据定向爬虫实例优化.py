#采用requests+beautifulsoup技术路线的爬虫速度不会很快

import requests
import re
from bs4 import BeautifulSoup
import traceback

def get_html_text(url):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except Exception as e:
        print("获取url链接失败")
        traceback.print_exc()

def get_stock_list(lst, stock_url):
    html = get_html_text(stock_url)
    soup = BeautifulSoup(html, "html.parser")
    a = soup.find_all("a")
    for i in a:
        try:
            href = i.attrs["href"]
            lst.append(re.findall(r"[s][hz]\d{6}", href)[0])
        except:
            #继续进行下轮查找
            continue

#增加动态显示进度的功能
def get_stock_info(lst, stock_url, file_path):
    count = 0
    for stock in lst:
        url = stock_url + stock + ".html"
        html = get_html_text(url)
        try:
            #如果是空页面，则继续执行
            if html == "":
                continue
            info_dict = {}
            soup = BeautifulSoup(html, "html.parser")
            stock_info = soup.find("div", attrs={"class" : "stock-bets"})
            
            #assert isinstance(stock_info, BeautifulSoup)
            #获取股票名称
            name = stock_info.find_all(attrs={"class" : "bets-name"})[0]
            info_dict.update({"股票名称" : name.text.split()[0]})

            #
            key_list = stock_info.find_all('dt')
            value_list = stock_info.find_all('dd')
            for i in range(len(key_list)):
                key = key_list[i].text
                val = value_list[i].text
                info_dict[key] = val

            #将相关信息写入文件
            with open(file_path, "a", encoding="utf-8") as f:
                f.write(str(info_dict) + "\n")
                count += 1
                #\r控制不换行打印
                print('\r当前进度：{:.2f}%'.format(count * 100 / len(lst), end=''))

        #为方便调试，需要获取异常信息
        except:
            count += 1
            #\r控制不换行打印
            print('\r当前进度：{:.2f}%'.format(count * 100 / len(lst), end=''))
            traceback.print_exc()
            continue

def main():
    #股票列表连接，来自东方财富网
    stock_list_url = "http://quote.eastmoney.com/stocklist.html"
    #股票信息主体连接，来自百度股票
    stock_info_url = "https://gupiao.baidu.com/stock/"
    #输出文件的路径
    output_file = "E://stockinfo.txt"
    #保存股票信息的列表
    slist = []
    #获取股票列表
    get_stock_list(slist, stock_list_url)
    #获取股票信息
    get_stock_info(slist, stock_info_url, output_file)

if __name__ == "__main__":
    main()
