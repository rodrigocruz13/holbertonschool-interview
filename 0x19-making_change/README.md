# 0x19. Making Change
## Specializations - Interview Preparation ― Algorithms

![coins](https://imgur.com/a3t9GsS.png)

## Tasks

Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount total.

Prototype: def makeChange(coins, total)
Return: fewest number of coins needed to meet total

- If total is 0 or less, return 0
- If total cannot be met by any number of coins you have, return -1
coins is a list of the values of the coins in your possession
The value of a coin will always be an integer greater than 0
You can assume you have an infinite number of each denomination of coin in the list
Your solution’s runtime will be evaluated in this task

## Code

```bash
$cat 0-main.py
```

```python
#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = __import__('0-making_change').makeChange
print(makeChange([1, 2, 25], 37))
print(makeChange([1256, 54, 48, 16, 102], 1453))
```

```bash
$ ./0-main.py
7
-1
$
```
