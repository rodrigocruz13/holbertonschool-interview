#!/usr/bin/python3

import sys
import re


def print_msg(dict_sc, total_file_size):
    """
    Method to print
    Args:
        dict_sc: dict of status codes
        total_file_size: total of the file
    Returns:
        Nothing
    """

    print("File size: {}".format(total_file_size))
    for i in sorted(dict_sc.keys()):
        if(dict_sc[i] != 0):
            print("{}: {}".format(i, dict_sc[i]))


total_file_size = 0
count = 0
dict_sc = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

try:
    for line in sys.stdin:
        parsed_line = re.split(r'[-+#\s*$ ]', line)  # ✄ trimming

        if (len(parsed_line) > 9):
            count += 1
            if count <= 10:
                total_file_size += int(parsed_line[11])  # file size
                sc = int(parsed_line[10])  # status code

            if (sc in sorted(dict_sc.keys())):
                dict_sc[sc] += 1

            if (count % 10 == 0):
                print_msg(dict_sc, total_file_size)

finally:
    print_msg(dict_sc, total_file_size)
