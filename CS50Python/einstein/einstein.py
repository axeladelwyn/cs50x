# prompt the uesr for mass an integer and then outputs thenumber of joules as an integer
# user_input = int(input())
# output as an integer


def convert(mass):
    c = 300000000
    return mass*(c**2)

user_input = int(input("Enter a mass "))
print(convert(user_input))

