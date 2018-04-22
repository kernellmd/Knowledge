def copy_img():
    with open('test.jpg', 'rb') as src:
        with open('test1.jpg', 'wb') as targ:
            tmp = src.read()
            targ.write(tmp)

def main():
    copy_img()

if __name__ == '__main__':
    main()