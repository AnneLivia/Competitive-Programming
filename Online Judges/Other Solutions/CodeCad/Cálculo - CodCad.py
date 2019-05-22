def insert_zeros(number, to):
    for i in range(len(number), to):
        number.insert(i, '0')


def calculate_sum(number1, number2):
    number1.reverse()
    number2.reverse()

    # nibble receives the upper number that exceeds
    nibble = []
    res = []
    for i in range(len(number1)):
        nibble.append('0')
        res.append('0')

    nibble.append('0')

    for i in range(len(number1)):
        if (number1[i] == '1' and number2[i] == '0') or (number1[i] == '0' and number2[i] == '1'):
            if nibble[i] != '1':
                res[i] = '1'
            else:
                nibble[i + 1] = '1'
        elif number1[i] == '0' and number2[i] == '0':
            if nibble[i] == '1':
                res[i] = '1'
        else:
            if nibble[i] == '1':
                res[i] = '1'
            nibble[i + 1] = '1'

    while res[0] == '0':
        res.pop(0)

    res.reverse()
    return res


m, n = [int(x) for x in input().split()]

n1 = []
n2 = []

# read number separated by space
n1 = [x for x in input().split()]
n2 = [x for x in input().split()]

# while n:
#    n2.append(input())
#    n -= 1

if len(n1) < len(n2):
    insert_zeros(n1, len(n2))
elif len(n2) < len(n1):
    insert_zeros(n2, len(n1))

print(' '.join(calculate_sum(n1, n2)))
