#为Contact列表添加搜索方法

class ContactList(list):
    def search(self, name):
        """Research all contact that contain the search value
        in their name."""
        matching_contacts = []
        for contact in self:
            if name in contact.name:
                matching_contacts.append(contact)
        return matching_contacts

class Contact:
    #所有实例共享
    #all_contact = []
    all_contacts = ContactList()

    def __init__(self, name, email):
        self.name = name
        self.email = email
        self.all_contacts.append(self)

    
#创建Supplier类，继承Contact类，但有额外的order方法
class Supplier(Contact):
    def order(self, order):
        print("If this were a real system we will send "
              "{} order to {}".format(order, self.name))

#使用super创建Friend类
class Friend(Contact):
    def __init__(self, name, email, phone):
        super().__init__(name, email)
        self.phone = phone

#通过多重继承增加发邮件功能
class MailSender:
    def send_email(self, message):
        print("Sending mail to " + self.email)

class EmailableContact(Contact, MailSender):
    pass