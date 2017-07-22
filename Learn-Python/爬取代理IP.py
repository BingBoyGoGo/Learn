import re
import urllib.request

def openURL(url):
    req = urllib.request.Request(url)
    # 伪装
    req.add_header('User-Agent','Mozilla/5.0 (Windows NT 10.0; WOW64)AppleWebKit/537.36 (KHTML,like Gecko) Chrome/45.0.2454.101 Safari/537.36')
    html = urllib.request.urlopen(req).read().decode('utf-8')
    return html

# 获取IP信息，返回IP与端口对应字典
def getIP(html):
    # 正则表达式，模式对象
    info = r'<td>(.+?)</td>'

    # 获取IP信息
    infolist = re.findall(info, html)

    # IP字典
    iplist = []
    portlist = []
    infodict = {}
    
    list_len = len(infolist)
    for i in range(0,list_len):
        if(not(i%5)):
            infodict[infolist[i]] = infolist[i+1]

    return infodict

if __name__ == '__main__':
    url = 'http://www.xicidaili.com/wt/'
    html = openURL(url)
    infodict = getIP(html)
    print(infodict)    
