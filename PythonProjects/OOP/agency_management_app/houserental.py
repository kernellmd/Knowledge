from purchase_rental import Rental
from apartment_house import House

class HouseRental(Rental, House):
    @staticmethod
    def prompt_init():
        init=House.prompt_init()
        init.update(Rental.prompt_init())
        return init
