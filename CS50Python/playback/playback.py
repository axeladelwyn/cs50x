user_input = input("Please enter input ")
new_string = ""
## replace space with ... from input
## how to do it?
for char in user_input:
    if (char == " "):
        new_string += "..."
    else:
        new_string += char

print(new_string)


