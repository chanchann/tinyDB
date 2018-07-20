#! /usr/bin/python3.6
# _*_ encode:utf-8_*_

import json

from urllib.request import urlopen,Request
from urllib.error import URLError
from urllib.parse import urlencode

class TuringChatMode(object):
    def __init__(self):
        # API接口地址
        self.turing_url = 'http://www.tuling123.com/openapi/api?'

    def get_turing_text(self,text):
        turing_url_data = dict(
            key = '8edce3ce905a4c1dbb965e6b35c3834d',
            info = text,
            userid = '1234444',

        )
        # print("The things to Request is:",self.turing_url + urlencode(turing_url_data))
        self.request = Request(self.turing_url + urlencode(turing_url_data))
        # print("The result of Request is:",self.request)

        try:
            w_data = urlopen(self.request)
            # print("Type of the data from urlopen:",type(w_data))
            # print("The data from urlopen is:",w_data)
        except URLError:
            raise IndexError("No internet connection available to transfer txt data")
            # 如果发生网络错误，断言提示没有可用的网络连接来传输文本信息
        except:
            raise KeyError("Server wouldn't respond (invalid key or quota has been maxed out)")
            # 其他情况断言提示服务相应次数已经达到上限

        response_text = w_data.read().decode('utf-8')
        # print("Type of the response_text :",type(response_text))
        # print("response_text :",response_text)

        json_result = json.loads(response_text)
        # print("Type of the json_result :",type(json_result))
        return json_result['text']

if __name__ == '__main__':
    print("Now u can type in something & input q to quit")

    turing = TuringChatMode()

    while True:
        msg = input("\nChanchan:")
        if msg == 'q':
            exit("u r quit the chat !")         # 设定输入q，退出聊天。
        else:
            turing_data = turing.get_turing_text(msg)
            print("小姐姐:",turing_data)
