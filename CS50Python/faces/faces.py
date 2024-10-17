# if input == :) then print emoji 🙁
# define a function called convert
def convert(string):
    print(string.replace(":)","🙂").replace(":(","🙁"))

# define a function called main
def main():
    user_input = input("")
    convert(user_input)


main()
