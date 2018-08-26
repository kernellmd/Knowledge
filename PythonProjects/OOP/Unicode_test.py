characters = b"\x63\x6c\x69\x63\x68\xe9"
print(characters)
print(characters[1:3])
print(characters.decode("latin-1"))
print(characters.decode("iso8859-5"))

b = bytearray(b"abcdefgh")
print(b)
b[4:6] = b"\x15\xa3"
print(b)
#b[1] = b"x15"
#print(b)

sb = bytearray(b"abcdef")
print(sb)
sb[3] = ord(b"g")
print(sb)
sb[4] = 68
print(sb)

print()
print("Test open function:")
file = open("open_test.txt", encoding="ascii", errors="replace")
print(file.read())
file.close

contents = "an oft-repeated cliche\n"
file = open("open_test.txt", "a", encoding="ascii", errors="replace")
file.write(contents)
#file.write("\n")
file.close()

class MyContextManager(list):
    def __enter__(self):
        return self
    
    def __exit__(self, type, value, tb):
        self.result = "".join(self)

import random, string
with MyContextManager() as joiner:
    for i in range(15):
        joiner.append(random.choice(string.ascii_letters))
print(joiner.result)