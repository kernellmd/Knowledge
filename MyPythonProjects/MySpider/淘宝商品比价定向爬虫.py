import requests
import re

def get_HTML_text(url):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except Exception as e:
        print("获取url链接失败")
        print(e)

#使用正则表达式而不是beautifulsoup库进行解析
def parse_page(ilt, html):
    try:
        #获取上坪名称
        tlt = re.findall(r'\"raw_title\"\:\".*?\"', html)
        #获取商品价格
        plt = re.findall(r'\"view_price\"\:\"[\d\.]*\"', html)

        for i in range(len(plt)):
            #eval 函数可以去掉字符串的双引号或单引号
            price = eval(plt[i].split(':')[1])
            title = eval(tlt[i].split(':')[1])
            ilt.append([title, price])
    except Exception as e:
        print("解析失败")
        print(e)

def print_goods_list(ilt):
    tplt = "{0:{3}<4}\t{1:{3}<25}\t{2:{3}<8}"
    print(tplt.format("序号", "商品名称", "价格", chr(12288)))
    count = 0
    for g in ilt:
        count += 1
        print(tplt.format(count, g[0], g[1], chr(12288)))

def main():
    goods = "书包"
    depth = 2  #爬取第一页和第二页的商品
    start_url = "https://s.taobao.com/search?q=" + goods
    info_list = []  #信息存储列表
    for i in range(depth):
        try:
            url = start_url + "&s=" + str(44 * i)
            html = get_HTML_text(url)
            parse_page(info_list, html)
        except:
            continue
    print_goods_list(info_list)

if __name__ == "__main__":
    main()