import urllib.request as Req
import random
import time

targetUrl = ["http://bingbgg.blog.163.com/blog/static/27215016520174611715231/",\
             "http://bingbgg.blog.163.com/blog/static/272150165201744062491/",\
             "http://bingbgg.blog.163.com/blog/static/272150165201742102349732/",\
             "http://bingbgg.blog.163.com/blog/static/27215016520173300853926/"]

head={}

PV = int(input("输入访问量： "))
i  = 1

while i <= PV:
    url = random.choice(targetUrl)
    Req.urlopen(url).read()
    print("%s\n共访问了%d次" % (url,i))
    
    i += 1
    if i <= PV:
        time.sleep(random.randint(10,20))
    
