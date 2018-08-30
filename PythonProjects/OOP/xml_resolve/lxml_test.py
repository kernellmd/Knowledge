from lxml.etree import fromstring

with open("html_document.html") as file:
    root = fromstring(file.read())

print("ROOT NODE")
print("\ttag:", root.tag)
print("\tnumber of children:", len(root))
print("\tchildren:", [c.tag for c in root.getchildren()])
head = root[0]
print("HEAD NODE")
print("\tfirst child:", head[0].tag)
print("\tsecond_child:", head[1].tag)
print("\tlink attributes:", head[1].attrib)
article = root[1][1]
print("ARTICLE NODE")
print("\ttag:", article.tag)
print("\ttext:", article.text)
print("\tfirst child:", article[0].tag, article[0].text)
print("\t\tem's tail:", article[0].tail)
print("\tsecond child:", article[1].tag, article[1].text)
print("\tstrong's tail:", article[1].tail)

print("xpath attribute:", root.xpath("//link[@href]"))
print("xpath text filter:", root.xpath('//*[contains(em, "my")]'))
print("xpath first child:", root.xpath('/html/body/article/em[1]'))
from lxml.cssselect import CSSSelector
print("css class selector:", CSSSelector('.simple')(root))
print("css tag selector:", CSSSelector("em")(root))
