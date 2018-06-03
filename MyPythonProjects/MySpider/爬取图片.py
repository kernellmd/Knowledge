#可以推广到其他二进制文件的爬取，如视频，音乐等

import requests
import os

#注意此url的获取，Chrome可以使光标停留在图片上，右击“获取图片地址”
url = "https://www.nationalgeographic.com/content/dam/travel/2018-digital/city-guides-2018/kansas-city-missouri/nelson-atkins-museum-kansas-city-missouri.adapt.885.1.jpg"       
root = "E:\\MyPhotos\\Crawled\\"
path = root + url.split('/')[-1]
kv = {'user-agent':'Mozilla/5.0'}

try:
    #如果根目录不存在，建立一个这样的目录
    if not os.path.exists(root):
        os.mkdir(root)
    #判断要爬取的文件是否存在
    if not os.path.exists(path):
        #文件不存在，则进行爬取
        r = requests.get(url, headers=kv)
        r.raise_for_status()
        #此处使用with语句可以不用写f.close()语句
        with open(path, 'wb') as f:
            f.write(r.content)
            #f.flush()
            #f.close()
            print("文件成功爬取并保存")
    else:
        print("文件已存在")
except:
    print("爬取失败")