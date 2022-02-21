def binaryToDecimal(value: str):
    for bit in value:
        if bit != "0" and bit != "1":
            return 0
    value = [int(item) for item in value]
    value.reverse()
    return sum([(int(bit) * pow(2, exp)) for exp, bit in enumerate(value)])


def binaryToHex(value: str):
    for bit in value:
        if bit != "0" and bit != "1":
            return 0
    while len(value) % 4 != 0:
        value = "0" + value
    result, i = [], 1
    while i < len(value):
        result.append(hexadecimalItem[binaryToDecimal(value[i - 1: i + 3])])
        i += 4
    return "".join(result)


def hexadecimalToDecimal(value: str):
    value.lower()
    for h in value:
        if h not in hexadecimalItem:
            return 0
    value = [hexadecimalDic[item] for item in value]
    value.reverse()
    return sum([(int(bit) * pow(16, exp)) for exp, bit in enumerate(value)])


def hexadecimalToBinary(value: str):
    value.lower()
    for h in value:
        if h not in hexadecimalItem:
            return 0
    value = [bin(hexadecimalDic[item])[2:] for item in value]
    for index, item in enumerate(value):
        while len(item) % 4 != 0:
            item = "0" + item
        value[index] = item
    return "".join(value)


def resizeElement(ls: list, minSize: int):
    for index, elt in enumerate(ls):
        while len(elt) % minSize != 0:
            elt = "0"+elt
        ls[index] = elt
    return ls

hexadecimalItem = "0123456789abcdef"
hexadecimalDic = {}
for i in range(16):
    hexadecimalDic[i] = hexadecimalItem[i]
    hexadecimalDic[hexadecimalItem[i]] = i
