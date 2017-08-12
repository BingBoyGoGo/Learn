import urllib.request
import urllib.parse
import re
import json

payload = {}

def chat(url,context):
    payload = {'perception': {'inputText': {'text': context}},
               'userInfo': {'userId': "07bfc6365bbb22b14e4443d78924d973"}}
    # 转换成json格式
    payload = json.dumps(payload,sort_keys=True)
    # 不打上这个会报错，Post data should be bytes ...
    payload = bytes(payload, 'utf-8')
    
    # 打开网页机器人
    req = urllib.request.Request(url)
    req.data = payload
    req.add_header('User-Agent','Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.101 Safari/537.36')
    # 不加上该头会报错,Http Error 415，不支持的媒体类型
    req.add_header('Content-Type','application/json')

    html = urllib.request.urlopen(req).read().decode('utf-8')
    jresp = json.loads(html)

    try:
        print(">>> " + str(jresp['data']['results'][0]['values']['text']))
    except:
        pass
if __name__ == '__main__':
    print("\t\t-------------图灵机器人----------------\t\t")
    print("\t\t版本号：1.0\t    copyright：@bingogo\t\t")
    print("\t\t输入聊天内容即可得到回答，输入:q/:Q结束\t\t")
    url = 'http://www.tuling123.com/robot-chat/robot/chat/23803/xWfX?geetest_challenge=&geetest_validate=&geetest_seccode='
    context = input("<<< ")
    while(True):
        if(context == ':q' or context == 'exit' or context == ':Q'):
            break
        else:
            chat(url,context)
            context = input("<<< ")    
    
