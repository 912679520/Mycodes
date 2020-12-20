import requests
import pprint
import time

#时间戳
star_time = time.time()

#确定正确的url
base_url = 'https://pvp.qq.com/web201605/js/herolist.json'
headers = {'User-Agent':'User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.88 Safari/537.36'}

#请求数据（大范围数据）
resqonse = requests.get(url = base_url, headers = headers)
data_list = resqonse.json()
#pprint.pprint(data_list)

#数据解析
for data in data_list:
    cname = data['cname'] #名字
    ename = data['ename'] #id
    try:
        skin_names = data['skin_name'].split('|') #皮肤
    except Exception as e:
        print(e)
    #print(cname,ename,skin_names)

    #构建皮肤数量的循环
    for skin_num in range(1,len(skin_names) + 1):
        #https://game.gtimg.cn/images/yxzj/img201606/skin/hero-info/109/109-bigskin-7.jpg
        #https://game.gtimg.cn/images/yxzj/img201606/skin/hero-info/+ id + / + id-bigskin-皮肤序号 + .jpg
        skin_url = 'https://game.gtimg.cn/images/yxzj/img201606/skin/hero-info/' + str(ename) + '/' + str(ename) + '-bigskin-' + str(skin_num)+'.jpg'
        #print(skin_url)

        skin_data = requests.get(url=skin_url,headers=headers).content

        #数据保存
        with open('img\\' + cname + '-' + skin_names[skin_num-1] + '.jpg', mode = 'wb') as f:
            print("正在下载皮肤：",cname + '-' + skin_names[skin_num-1])
            f.write(skin_data)

end_time = time.time()
print('花费时间：',int(end_time - star_time))
print("数据爬取完成")







