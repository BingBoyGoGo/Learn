import urllib.request
import json

class Chat:
    # 属性
    url = ''
    payload = ''    # post的内容
    context = ''    
    html = ''

    # 方法
    # 构造函数
    def __init__(self):
        self.url = 'http://www.tuling123.com/robot-chat/robot/chat/23803/xWfX?geetest_challenge=&geetest_validate=&geetest_seccode='
        self.context = 'None'

    # post内容
    def postinfo(self):
        self.context = input("<<<< ")
        self.payload = {'perception': {'inputText': {'text': self.context}},
                        'userInfo': {'userId': "07bfc6365bbb22b14e4443d78924d973"}}
    
    # 将post内容转换成json格式
    def tojson(self):
        return json.dumps(self.payload, sort_keys=True)

    # 将get内容转换成字符串
    def tostr(self):
        return json.loads(self.html)

    # 打开机器人网页
    def openurl(self):
        # 网页请求
        req = urllib.request.Request(self.url)
        req.add_header('User-Agent','Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.101 Safari/537.36')
        # 不加上该头会报错,Http Error 415，不支持的媒体类型
        req.add_header('Content-Type','application/json')
        
        payload = json.dumps(self.payload, sort_keys=True)
        # 将payload转化成bytes，不然报错，Post data should be bytes...
        req.data = bytes(payload, 'utf-8')
        self.html = urllib.request.urlopen(req).read().decode('utf-8')
          
    # 开始聊天
    def chat(self):
        self.postinfo()
        try:
            self.openurl()
            response = self.tostr()
            print(">>>> " + str(response['data']['results'][0]['values']['text']))
        except:
            print("error")

if __name__ == '__main__':
    print("\t\t-------------图灵机器人----------------\t\t")
    print("\t\t版本号：1.0\t    copyright：@bingogo\t\t")
    print("\t\t输入聊天内容即可得到回答，输入:q/:Q结束\t\t")
    chatAI = Chat()
    while(True):
        if(chatAI.context == ':q' or chatAI.context == ':Q' or chatAI.context == 'exit'):
            break
        else:
            chatAI.chat()
