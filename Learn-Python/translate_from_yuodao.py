import urllib.request
import urllib.parse
import json
import re

class Translator:
    # 属性
    data = {}
    url = ''
    context = ''
    response = ''
    
    # 方法
    # 构造函数
    def __init__(self):
        self.url = 'http://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule&smartresult=ugc'
    # __str__
    def __str__(self):
        return "我是你的有道翻译器啊"

    # Post的信息
    def postdata(self):
        self.context = input("翻译内容：")
        self.data = {
            "type" : "AUTO",
            "i" : self.context,
            "doctype" : "json",
            "xmlVersion" : "1.8",
            "keyfrom" : "fanyi.web",
            "ue" : "UTF-8",
            "action" : "FY_BY_CLICKBUTTON",
            "typoResult" : "true"
        }
        self.data = urllib.parse.urlencode(self.data).encode('utf-8')

    # 打开网页
    def openurl(self):
        req = urllib.request.Request(self.url)
        req.data = self.data
        req.add_header('User-Agent','Mozilla/5.0 (Windows NT 10.0; WOW64)AppleWebKit/537.36 (KHTML,like Gecko) Chrome/45.0.2454.101 Safari/537.36')
        try:
            self.response = urllib.request.urlopen(req).read().decode('utf-8')
        except:
            print("打开翻译网页错误")
        
    # json
    def tojson(self):
        return json.loads(self.response)

    # 开始翻译
    def translate(self):
        self.postdata()
        self.openurl()
        
    # 结果
    def result(self):
        self.translate()
        target = self.tojson()
        # 翻译结果
        print("翻译结果：%s" %(target['translateResult'][0][0]['tgt']))
        # 详细解释
        try:
            means = re.findall(r"'', (.+)]", str(target['smartResult']['entries']))
            # 结果
            print("详细解释：%s" %(means[0]))
        except:
            print("详细解释：无详细解释")
        finally:
            print("")

# 执行
if __name__ == '__main__':
    translator = Translator()
    print("\t\t-------------有道翻译器----------------\t\t")
    print("\t\t版本号：1.0\t    copyright：@bingogo\t\t")
    print("\t\t  输入翻译内容即可得到结果，输入#结束\t\t")
    while(translator.context != '#'):
        translator.result()
    
