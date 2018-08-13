from purchase_rental import *
from apartment_house import *

"""
注意多继承顺序，如果Rental和House反过来，
Rental的display方法将不起作用

一个可行的解决方案：
使Rental和Purchase继承Property类，而不是
从object类继承
"""

class HouseRental(Rental, House):
    @staticmethod
    def prompt_init():
        init=House.prompt_init()
        init.update(Rental.prompt_init())
        return init


class ApartmentRental(Rental, Apartment):
    @staticmethod
    def prompt_init():
        init = Apartment.prompt_init()
        init.update(Rental.prompt_init())
        return init


class ApartmentPurchase(Purchase, Apartment):
    @staticmethod
    def prompt_init():
        init = Apartment.prompt_init()
        init.update(Purchase.prompt_init())
        return init


class HousePurchase(Purchase, House):
    @staticmethod
    def prompt_init():
        init = House.prompt_init()
        init.update(Purchase.prompt_init())
        return init
