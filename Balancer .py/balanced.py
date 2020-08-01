# Bashier Dahman 

# Program to remove all comments from a 
# source code file (preferably JAVA)
# and check whether or not the code brackets are
# balanced out, if not it'll display how many open ones
# are left

import sys

# PART 1#

# OPENING MY PASSED IN ARGUMENT FILE#
# READING THE CHARACTERS AND SAVING THEM #
#        INSIDE A VARIABLE         #

with open(sys.argv[1], 'r') as inFile:
    characters = open(sys.argv[1]).read()

# CHECKING FOR COMMENTS IN MY .JAVA FILE#
#   STRIPPING THEM, AND SAVING IT IN   #
#             ANOTHER FILE             #

# this reads whatever you typed into the command line and writes it into another file
with open("{}.nocom".format(sys.argv[1]), "w") as outFile:
    charIndex = 0
    singleLine = False
    multLine = False
    stringLit = False
    quotes = 0
    asterisk = False
    endMult = False

    # Going through each character and if it's part of the comment#
    # skip it and increment index#
    for char in characters:
        if (singleLine == True and char != "\n"):
            charIndex += 1
            continue
        else:
            singleLine = False

        # Checking if it's a multi line comment
        if (multLine == True and characters[charIndex + 1] != '/'):
            # if characters[charIndex] == '*':
            #     if characters[charIndex + 1] == '/':
            #         charIndex += 1
            #         multLine = False
            charIndex += 1
            continue

        else:
            multLine = False

        if (asterisk == True and characters[charIndex + 1] == "/"):
            charIndex += 1
            continue
        else:
            asterisk = False

        # Write the string literals including // inside them#
        # in the new program file#
        if (stringLit == True and char != '"'):
            outFile.write(char)
            charIndex += 1
            continue

        # check if the character is equal to a comment
        if (char == "/"):
            if (characters[charIndex + 1] == "/"):  # check if it's a single line comment
                singleLine = True
                charIndex += 1
                continue  # continue to the next character if true
            # checking if it's a multiLine comment
            elif (characters[charIndex + 1] == "*"):
                multLine = True
                charIndex += 1
                continue
            elif (characters[charIndex - 1] == '*'):
                multLine = False
                charIndex += 1
                continue

        elif (char == '*'):
            asterisk = True
            # if (characters[charIndex - 1] == '/'):
            #     multLine = True
            # if (characters[charIndex + 1] == '/'):
            #     multLine = False
            charIndex += 1
            continue

        elif (char == '"' and characters[charIndex - 1] != "\\"):
            quotes += 1
            if (stringLit == False and quotes == 1):
                stringLit = True
            elif (quotes == 2):
                stringLit = False
                quotes = 0
            # Write characters that are in the string literals and increment my index
            outFile.write(char)
            charIndex += 1

        # writing everything not inside a comment into the new file
        else:
            outFile.write(char)
            charIndex += 1





# PART 2
# READING MY NEWLY CREATED .nocom file#
with open("{}.nocom".format(sys.argv[1]), "r") as outFile:
    balancedLines = outFile.read()
    # CREATING A LIST TO PUSH & POP MY SYMBOLS#
    balanced_parentheses = []
    balanced_bracket = []
    balanced_curly = []
    stringLit = False
    charIndex = 0
    quotes = 0

    # this for loop will iterate through all my characters searching for open/closed ([{ and pushing/popping them into my stack
    for push_symbols in balancedLines:
        # this if statement will check if the open/closed symbols are inside a string literal
        if (push_symbols == '"' and characters[charIndex - 1] != "\\"):
            quotes += 1
            if (stringLit == False and quotes == 1):
                stringLit = True
            elif (quotes == 2):
                stringLit = False
                quotes = 0
            charIndex += 1
        # if my stringLiteral variable is false, continue on and search for open / closed {[(
        elif (stringLit == False and push_symbols != '"'):
            # pushing my open symbols
            if (push_symbols == '('):
                balanced_parentheses.append('(')
            elif (push_symbols == '['):
                balanced_bracket.append('[')
            elif (push_symbols == '{'):
                balanced_curly.append('{')
            # popping my open symbols
            elif (push_symbols == ')'):
                try:
                    balanced_parentheses.pop()
                except IndexError:
                    raise IndexError("You cannot pop from an empty stack, your program is not balanced!")
            elif (push_symbols == ']'):
                try:
                    balanced_bracket.pop()
                except IndexError:
                    raise IndexError("You cannot pop from an empty stack, your program is not balanced!")
            elif (push_symbols == '}'):
                try:
                    balanced_curly.pop()
                except IndexError:
                    raise IndexError("You cannot pop from an empty stack, your program is not balanced!")

    # telling the user if the program is balanced
    if (balanced_parentheses.__len__() == 0 and balanced_bracket.__len__() == 0 and balanced_curly.__len__() == 0):
        print("Congratualations your program is balanced!")

    # if there's too many open symbols prompt the user with which symbols are left
    elif (balanced_parentheses.__len__() != 0 or balanced_bracket.__len__() != 0 or balanced_curly.__len__() != 0):
        print("\nSorry it seems like your program has too many open symbols! Please edit it and try again :)")
        print("For a reference here are the extra opening symbols you currently have: ")
        print("\nOpen Parentheses: ")
        print(balanced_parentheses)
        print("\nOpen Brackets: ")
        print(balanced_bracket)
        print("\nOpen Curly Brackets: ")
        print(balanced_curly)

# THIS PROGRAM SHOULD WORK #
# IF ANY ISSUES OCCUR PLEASE #
# CONTACT ME #
