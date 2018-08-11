"""
多重继承的实现:
通过设置参数默认值，把所有参数编程关键字参数。同时
包含一个**kwargs参数，它可以捕获任何特殊方法不知
道如何处理的额外参数。通过调用super方法，它把这些
参数传递给下一个类。
"""

class Contact:
    all_contacts = []

    def __init__(self, name="", email="", **kwargs):
        super.__init__(**kwargs)
        self.name = name
        self.email = email
        self.all_contacts.append(self)

class AddressHolder:
    def __init__(self, street="", city="", state="",
                 code="" **kwargs):
        super().__init__(**kwargs)
        self.street = street
        self.city = city
        self.state = state
        self.code = code

class Friend:
    def __init__(self, phone="", **kwargs):
        super().__init__(**kwargs)
        self.phone = phone
