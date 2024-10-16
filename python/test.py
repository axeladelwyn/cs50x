containers = [[2, 2], [3, 3], [4, 4], [5, 5]]
index = 0

for container in containers:
    if index == 3:
        print(container)
    index += 1

budget = 2000

food_bill = 200
electricity_bill = 100
internet_bill = 60
rent = 1500
total = food_bill + electricity_bill + internet_bill + rent

my_list = [2,3,4,5,8,9,10]
print(my_list[-3:])

def some_function(some_input1, some_input2):
    output = some_input1 + some_input2
    return output

def lengthdiff(str1, str2):
    return len(str1) - len(str2)

# 1.Define the functio to accept two parameters, one string or the sentence adn one string for the name
def check_for_name(sentence, name):
# 2.Convert all of the strings to the same case so we don't have to worry about differences in capitalization
    name = name.lower()
    sentence = sentence.lower()
# 3.Check if the name is withint the sentence. If so, then return True. Otherwise, return False
    if name in sentence:
        return True
    return False
print(check_for_name("My name is Jamie", "Jamie"))
print(check_for_name("My name is jamie", "Jamie"))
print(check_for_name("My name is JAMIE", "Jamie"))

