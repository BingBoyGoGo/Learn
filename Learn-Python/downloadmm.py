import urllib.request
import os

# 程序未使用正则表达式

def url_open(url): # 打开URL
    req = urllib.request.Request(url)
    req.add_header('User-Agent','Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.101 Safari/537.36')
    response = urllib.request.urlopen(url)
    html = response.read()

    return html


def get_page(url): # 获取网页的URL
    html = url_open(url).decode('utf-8')
    a = html.find('current-comment-page') + 23
    b = html.find(']',a)

    return html[a:b]
    
    
def find_imgs(page_url): # 查找图片的URL并放到列表中
    html = url_open(page_url).decode('utf-8')
    img_addrs = []

    a = html.find("img src=")
    while -1 != a:
        b = html.find(".jpg",a,a+255)
        if -1 != b:
            addr = "http:"+html[a+9:b+4]
            img_addrs.append(addr)
        else:
            b = a + 9

        a = html.find('img src=',b)
        
    return img_addrs
    

def save_imgs(folder, img_addrs): # 通过列表中URL保存图片
    for each in img_addrs:
        filename = each.split('/')[-1]
        with open(filename,'wb') as f:
            img = url_open(each)
            f.write(img)
    

def download_mm(folder="ooxx", pages=4):
    os.mkdir(folder)
    os.chdir(folder)

    url = "http://jandan.net/ooxx/"
    page_num = int(get_page(url))

    for i in range(pages):
        page_num -= i
        page_url = url + 'page-' + str(page_num) + "#comments"
        img_addrs = find_imgs(page_url)
        save_imgs(folder, img_addrs)

if __name__ == "__main__":
    # 修改download_mm()的参数改变图片数量
    # Param1是文件夹名字，Param2是爬取的网页页数
    download_mm("mm",5)
