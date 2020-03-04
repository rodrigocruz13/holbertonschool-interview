#!/usr/bin/python3
"""
Level: 0x03. Minimum Operations
Task title: 0. Minimum Operations
Filename: 0-main.py
"""
minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)

n = 12
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)

n = 7
print("Expected: 7")
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)

n = 12
print("Expected: 7")
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)

n = 30
print("Expected: 10")
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)

n = 9
print("Expected: 6")
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)

n = 0
print("Expected: 0")
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)

n = -1
print("Expected: 0")
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)

n = 3.2
print("Expected: 0")
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)
n = 9
print("Expected: 6")
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)
n = 1
print("Expected: 0")
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)
n = 2
print("Expected: 2")
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)
n = 99999999999999999999
print("Expected: 4223966")
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)
n = []
print("Expected: 0")
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

print("="*30)
n = ()
print("Expected: 0")
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))