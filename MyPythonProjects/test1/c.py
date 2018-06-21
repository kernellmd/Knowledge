# -*- coding: utf-8 -*-
import scrapy
import re


class StocksSpider(scrapy.Spider):
    name = "stocks"
    start_urls = ['http://quote.eastmoney.com/stocklist.html']

    def parse(self, response):
        for href in response.css('a::attr(href)').extract():
            try:
                stock = re.findall(r"[s][hz]\d{6}", href)[0]
                url = 'https://gupiao.baidu.com/stock/' + stock + '.html'
                yield scrapy.Request(url, callback=self.parse_stock)
            except:
                continue

    def parse_stock(self, response):
        info_dict = {}
        stock_info = response.css('.stock-bets')
        name = stock_info.css('.bets-name').extract()[0]
        key_list = stock_info.css('dt').extract()
        value_list = stock_info.css('dd').extract()
        for i in range(len(key_list)):
            key = re.findall(r'>.*</dt>', key_list[i])[0][1:-5]
            try:
                val = re.findall(r'\d+\.?.*</dd>', value_list[i])[0][0:-5]
            except:
                val = '--'
            info_dict[key]=val

        info_dict.update(
            {'股票名称': re.findall('\s.*\(',name)[0].split()[0] + \
             re.findall('\>.*\<', name)[0][1:-1]})
        yield info_dict