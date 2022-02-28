def binaryToDecimal(value: str):
    result = value.split(" ")
    for index, binary in enumerate(result):
        if len(binary) == 0:
            continue
        try:
            result[index] = str(int("0b"+binary, 2))
        except Exception as e:
            print(e)
            result[index] = "??"
    return " ".join(result)


def binaryToHex(value: str):
    result = value.split(" ")
    for index, binary in enumerate(result):
        if len(binary) == 0:
            continue
        try:
            tmp = hex(int("0b"+binary, 2))[2:]
            while len(tmp) % 2 != 0:
                tmp = "0" + tmp
            result[index] = tmp+" "
        except Exception as e:
            result[index] = "???? "
            print(e)
    return "".join(result)


def hexadecimalToDecimal(value: str):
    value.lower()
    result = value.split(" ")
    for i, h in enumerate(result):
        try:
            result[i] = str(int("0x"+h, 16))+" "
        except Exception as e:
            print(e)
            result[i] = "".join(["?" for i in range(len(result[i]))])
    return " ".join(result)


def hexadecimalToBinary(value: str):
    value.lower()
    result = value.split(" ")
    for i, h in enumerate(result):
        try:
            result[i] = bin(int("0x"+h, 16))[2:]
            while len(result[i]) % 8 != 0:
                result[i] = "0"+result[i]
        except Exception as e:
            print(e)
            result[i] = "????????"
    return " ".join(result)


def resizeElement(ls: list, minSize: int):
    for index, elt in enumerate(ls):
        while len(elt) % minSize != 0:
            elt = "0" + elt
        ls[index] = elt
    return ls


def binaryToAscii(binaryValue: str):
    binaryValue = ["0b" + i for i in binaryValue.split(" ")]
    for index, value in enumerate(binaryValue):
        if len(value) <= 2:
            binaryValue[index] = ""
            continue
        try:
            binaryValue[index] = chr(int(value, 2))
        except Exception as e:
            print(e)
            binaryValue[index] = " "
            pass
    return "".join(binaryValue)


def asciiToBinary(asciiValue: str, useSpace=True):
    result, asciiValue = "", asciiValue
    if not useSpace:
        asciiValue = asciiValue.split(" ")
        asciiValue = "".join(asciiValue)

    for value in asciiValue:
        try:
            tmp = bin(ord(value))[2:]
            while len(tmp) % 8 != 0:
                tmp = "0" + tmp
            result += tmp + " "
        except Exception as e:
            result += value + " "
    return result


hexadecimalItem = "0123456789abcdef"
hexadecimalDic = {}
for i in range(16):
    hexadecimalDic[i] = hexadecimalItem[i]
    hexadecimalDic[hexadecimalItem[i]] = i
