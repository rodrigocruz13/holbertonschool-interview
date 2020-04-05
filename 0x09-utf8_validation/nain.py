#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8
from validate_utf8 import find_utf8_errors


def make_bitseq(s: str) -> str:
    if not s.isascii():
        return "Error"
    return " ".join(f"{ord(i):08b}" for i in s)

a = ["bits", "CAPS", "$25.43", "~5", " "]
b = []

for i in range(len(a)):
    try:
        b.append(list(a[0].encode('utf-8')))
    except:
        b.append("")
    print(validUTF8(b[i]))
