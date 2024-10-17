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

# 1.Define the function to accept one parameter for the string
def every_other_letter(word):
# 2.Create a new empty string to hold every other letter from the input strnig
    new_string = ""
# 3.Loop through the input string while incrementing by two everytime
    for index in range(0, len(word), 2):
# 4.Inside the loop, append the character at the current location to the new string we initialized earlier
        new_string += word[index]
# 5.Return the new string
    return new_string

# 1. Define the function to accept one parameter for the string
def reverse_string(word):
# 2. Create a new empty string to hold the reversed string
    new_string = ""
# 3. Loop through the input string by starting at the end, and working towards the beginning
    for index in range(len(word) - 1, -1, -1):
# 4. Inside the loop, append the character at the current location to the new strnig we initialized earlier
        new_string += word[index]
# 5. Return the result
    return new_string
print(reverse_string("Codecademy"))

def make_spoonerism(word1, word2):
    first_char1 = word1[0]
    first_char2 = word2[0]
    remaining_char1 = word1[1:]
    remaining_char2 = word2[1:]
    first_char2 += remaining_char1
    first_char1 += remaining_char2
    spoonerism = first_char2 + " " + first_char1
    return spoonerism
print(make_spoonerism("Codecademy", "Learn"))

# 1. Define the function to accept one parameter for out string
def add_exclamation(word):
# 2. Loop while the length of our input string is less than 20
    while len(word) < 20:
# 3. Inside the loop, append an exclamation mark
        word += "!"
# 4. Once done, return the result
    return word
print(add_exclamation("Codecademy"))

def add_ten(my_dictionary):
    for key in my_dictionary.keys():
        my_dictionary[key] += 10
    return my_dictionary
print(add_ten({1: 1, 2: 2, 3: 3}))


def values_that_are_keys(my_dictionary):
    my_list = []
    key_list = []
    value_list = []
    for key, value in my_dictionary.items():
        key_list.append(key)
        value_list.append(value)
        # it only check for one iteration not the entire dictionary
    for val in value_list:
        if val in key_list:
            my_list.append(val)
    print(key_list, value_list)
    return my_list
print(values_that_are_keys({1: 1, 2: 2, 3: 3, 4: 4, 5: 5}))
print(values_that_are_keys({1:100, 2:1, 3:4, 4:10}))

# Find maximum value in the dictionary and return the associated key
def max_key(my_dictionary):
    max_val = float("-inf")
    max_key = float("-inf")
    for key, value in my_dictionary.items():
        # get the max value
        if value > max_val:
            max_val = value
            max_key = key
    return max_key
print(max_key({1:100, 2:1, 3:4, 4:10}))
print(max_key({"a":100, "b":10, "c":1000}))

def word_length_dictionary(words):
    word_lenghts = {}
    for word in words:
        word_lenghts[word] = len(word)
    return word_lenghts
print(word_length_dictionary(["Codecademy", "is", "the", "best"]))


#1. Define the function to accept one parameter for our list of strings
def frequency_dictionary(words):
#2. Createa a new empty dictionary
    new_dict = {}
#3. Loop thruogh every string in the list of strings
    for word in words:
#4. Inside the loop, if the string is NOT already in our dictionary. Otherwise, if the string is already in our dictionary, incremetn the value by 1
        if word not in new_dict.keys():
            new_dict[word] = 1
        else:
            new_dict[word] += 1
#5. After the loop return the new dictionary
    return new_dict
print(frequency_dictionary(["Codecademy", "is", "the", "best"]))
print(frequency_dictionary(["Codecademy", "is", "the", "best", "Codecademy", "is", "the", "best"]))


# Define the function to accept one parameter for our dictionary
def unique_values(my_dictionary):
# Create a new empty list
    empty_list = []
# Loop through every value in our dictionary
    for value in my_dictionary.values():
# Inside the loop, if the value is not arleady in our list,  append the vlaue to our list
        if value not in empty_list:
            empty_list.append(value)
        else:
            continue
# After the loop return the length of our list
    return len(empty_list)
print(unique_values({1:100, 2:1, 3:4, 4:10}))
print(unique_values({"a":100, "b":10, "c":1000}))


# define the function to accept one parameter for our dictionary
def count_first_letter(names):
    # createa a new empty dictionary called letters
    letters = {}
    # loops through every key in our names dictionary
    for name in names.keys():
        first_letter = name[0]
        if first_letter not in letters.keys():
            letters[first_letter] = len(names[name])
        else:
            letters[first_letter] += len(names[name])
    return letters
# should print {"S": ["Sara", "Simon"], "N": ["Nick", "Nicky"]}
print(count_first_letter({"Stark": ["Ned", "Robb", "Sansa"], "Snow" : ["Jon"], "Lannister": ["Jaime", "Cersei", "Tywin"]}))
# should print {"S": 4, "L": 3}
print(count_first_letter({"Stark": ["Ned", "Robb", "Sansa"], "Snow" : ["Jon"], "Sannister": ["Jaime", "Cersei", "Tywin"]}))
# should print {"S": 7}

class Rectangle:
    sides = 4

    def __init__(self, width, height):
        self.width = width
        self.height = height

    def calculate_area(self):
        self.area = self.width * self.height
        return self.area

rectangle = Rectangle(4, 5)
print(rectangle.calculate_area())