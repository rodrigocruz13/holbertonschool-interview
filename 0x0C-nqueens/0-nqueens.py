#!/usr/bin/python3
"""
N queens
"""

import sys


def is_not_safe_position(board, i, j, r):
    """
    Method that determines if position (i, j) on the chessboard is safe
    to allocate a queen.

    Args:
        - board (list):     list
        - i     (int):      x coordinate to be evaluated
        - j     (int):      y coordinate to be evaluated
        - r     (int):      current row

    Returns:
        True    (bool):     in case it is safe
        False   (bool):     in case it is not safe
    """

    # Is board[i] in line of attack ?
    if (board[i] == j) or (board[i] == j - i + r) or (board[i] == i - r + j):
        return True
    return False


def find_positions(board, row, n):
    """
    Recursive method that finds all safe position (i, j) where n queens
    can be allocated.

    Args:
        - board (list):     list
        - row   (int):      current row
        - n     (int):      number of queens to be allocated

    Returns:
        -       (lists):    lists of all possible solutions
    """

    if row == n:
        print_chess_board(board, n)

    else:
        for j in range(n):
            legal = True
            for i in range(row):
                if is_not_safe_position(board, i, j, row):
                    legal = False
            if legal:
                board[row] = j
                find_positions(board, row + 1, n)


def print_chess_board(board, n):
    """
    Method that generates the list of positions (i, j) where n queens
    were allocated.

    Args:
        - board (list):     list
        - n     (int):      number of queens to be allocated

    Returns:
        - nothing
    """

    b = []

    for i in range(n):
        for j in range(n):
            if j == board[i]:
                b.append([i, j])
    print(b)


def create_chess_board(size):
    """
    Method that generates a list of zeros

    Args:
        - size  (int):      number of queens to be allocated

    Returns:
        - board (list)
    """

    return [0 * size for i in range(size)]


# 1. Read and validate size of the board
if len(sys.argv) != 2:
    print("Usage: nqueens N\n")
    exit(1)

try:
    n = int(sys.argv[1])
except BaseException:
    print("N must be a number\n")
    exit(1)

if (n < 4):
    print("N must be at least 4\n")
    exit(1)

# 2. Generate the board
board = create_chess_board(int(n))

# 3. Find the solutions
row = 0
find_positions(board, row, int(n))
