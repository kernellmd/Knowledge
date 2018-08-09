#Contact类负责维护一个类变量中所有联系人的列表
class Contact:
    #所有实例共享
    all_contacts = []

    def __init__(self, name, email):
        self.name = name
        self.email = email
        Contact.all_contact.append(self)

    
#创建Supplier类，继承Contact类，但有额外的order方法
class Supplier(Contact):
    def order(self, order):
        print("If this were a real system we will send "
              "{} order to {}".format(order, self.name))
