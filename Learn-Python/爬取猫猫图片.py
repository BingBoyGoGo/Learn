import urllib.request

while True:
    Quit = input("按q!退出")
    if 'q!' == Quit:
        break;
    pixel_w = int(input('图片宽度： '))
    pixel_h = int(input('图片高度： '))

    if pixel_w > 2000 or pixel_h > 2000:
        print("不知道有没有那么大的图片")

    # 开始抓取
    url = 'http://placekitten.com/g/' + str(pixel_w) + '/' + str(pixel_h)
    cat_img = urllib.request.urlopen(url).read()

    # 下载
    fname = "C:\\Users\\Administrator\\Pictures\\" + str(pixel_w) + '_' + str(pixel_h) + '.jpg'
    with open(fname,'wb') as f:
        f.write(cat_img)
