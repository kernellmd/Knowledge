"""
version1 的 prompt_init 方法看起来很丑陋，它会循环两次。
如果把这个验证逻辑提取出来会比较好，那样可以只在一个地方维护
它，对于后面的类也会有帮助

将验证功能做成一个模块级的函数，这个函数接收一个输入字符串并
且列出有效的答案
"""

#验证函数
def get_valid_input(input_string, valid_options):
    input_string += " ({}) ".format(", ".join(valid_options))
    response = input(input_string)
    while response.lower() not in valid_options:
        response = input(input_string)
    return response


class Property:
    def __init__(self, square_feet="", beds="",
                bath="", **kwargs):
        super().__init__(**kwargs)
        self.square_feet = square_feet
        self.num_bedrooms = beds
        self.num_baths = baths

    def display(self):
        print("PROPERTY DETAILS")
        print("================")
        print("square footage: {}".format(self.square_feet))
        print("bedrooms: {}".format(self.num_bedrooms))
        print("bathrooms: {}".format(self.num_baths))
        print()

    def prompt_init():
        return dict(square_feet=input("Enter the square feet:"),
                    beds=input("Enter number of bedrooms:"),
                    baths=input("Enter number of baths:"))

    prompt_init = staticmethod(prompt_init)


class Apartment(Property):
    valid_laundries = ("coin", "ensuite", "none")
    valid_balconies = ("yes", "no", "solarium")

    def __init__(self, balcony="", laundry="", **kwargs):
        super().__init__(**kwargs)
        self.bacony = balcony
        self.laundry = laundry

    def display(self):
        super().display()
        print("APARTMENT DETAILS")
        print("laundry: %s" % self.laundry)
        print("has balcony: %s" % self.valid_balcony)

        parent_init = Property.prompt_init()
        laundry = ""
        while laundry.lower() not in \
                Apartment.valid_laundries:
            laundry = input("What laundry facilities does "
                            "the property have? ({})".format(
                                ",".join(Apartment.valid_laundries)))
        balcony = ""
        while balcony.lower() not in \
                Apartment.valid_balconies:
            balcony = input(
                "Does the property have a balcony?"
                "({})".format(
                    ",".join(Apartment.valid_balconies)))
        parent_init.update({
            "laundry": laundry,
            "balcony": balcony
            })
        return parent_init

    @staticmethod
    def prompt_init():
        parent_init = Property.prompt_init()
        laundry = get_valid_input("What laundry facilities does"
                                  "the property have?",
                                  Apartment.valid_laundries)

        balcony = get_valid_input("Does the property have a balcony?",
                                  Apartment.valid_balconies)
        parent_init.update({"laundry": laundry,
                            "balcony": balcony})
        return parent_init


class House(Property):
    valid_garage = ("attached", "detached", "none")
    valid_fenced = ("yes", "no")

    def __init__(self, num_stories="",
                 garage="", fenced="", **kwargs):
        super().__init__(**kwargs)
        self.garage = garage
        self.fenced = fenced
        self.num_stories = num_stories

    def display(self):
        super().display()
        print("HOUSE DETAILS")
        print("# of stories: {}".format(self.num_stories))
        print("garage: {}".format(self.garage))
        print("fenced yard: {}".format(self.fenced))

    @staticmethod
    def prompt_init():
        parent_init = Property.prompt_init()
        fenced = get_valid_input("Is the yard fenced?",
                                 House.valid_fenced)
        garage = get_valid_input("Is there a garage?",
                                 House.valid_garage)
        num_stories = input("How many stories?")
        parent_init.update({
            "fenced": fenced,
            "garage": garage,
            "num_stories": num_stories})
        return parent_init
