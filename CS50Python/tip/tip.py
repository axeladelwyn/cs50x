## 15% for tips of your meal's cost

def main():
    # meal price
    dollars = dollars_to_float(input("How much was the meal? "))
    percent = percent_to_float(input("What percentage would you like to tip? "))
    tip = dollars * percent
    print(f"Leave ${tip:.2f}")

# should accept str as input formatted as $##.##
def dollars_to_float(d):
    ## TODO remove the dollar sign and return it as float
    new_string = d.replace("$", "")
    return float(new_string)

# accept string as input (formatted as ##%, wherein each # is a decimal digit)
def percent_to_float(p):
    ## TODO
    new_string = p.replace("%","")
    return float(new_string) / 100


main()
