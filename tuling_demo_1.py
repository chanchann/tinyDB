import requests

KEY = '8edce3ce905a4c1dbb965e6b35c3834d'

def get_response(msg):
    apiUrl='http://www.tuling123.com/openapi/api'
    data={
        'key':KEY,
        'info':msg,
        'userid':'897158608',
    }
    try:
        r=requests.post(apiUrl,data=data).json()
        return r.get('text')
    except:
        return

def tuling_reply(msg):
    defaultReply='I received:'+msg['Text']
    reply=get_response(msg['Text'])
    print(reply)
    return reply or defaultReply

if __name__ == '__main__':
    while(True):
        msg=input('Chanchan:')
        print(get_response)
