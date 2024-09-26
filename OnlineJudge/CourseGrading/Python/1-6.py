def is_parlindrom(string):
    return string == string[::-1]

string = input('Enter a string: ')
if is_parlindrom(string):
    print('The input is a parlindrom')
else:
    print('The input is not a parlindrom')