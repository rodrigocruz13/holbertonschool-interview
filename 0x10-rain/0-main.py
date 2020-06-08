#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))

    walls = [0, -1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))

    walls = [0, 'a', 0, 2, 0, 3, 0, 4]
    print(rain(walls))

    walls = [0]
    print(rain(walls))

    walls = []
    print(rain(walls))

    walls = (1, 3, 0, 3, 4)
    print(rain(walls))

    walls = [1, 3, 0, 3, 4]
    print(rain(walls))

    walls = [None, None, 0, None, None]
    print(rain(walls))
