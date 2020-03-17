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
        if(dict_sc[i] is not "0"):
            print("{:}: {:d}".format(i, int(dict_sc[i])))


parsed_line = []
dict_sc = {200: "0",
           301: "0",
           400: "0",
           401: "0",
           403: "0",
           404: "0",
           405: "0",
           500: "0"
           }
total_file_size = 0
count = 0

try:
    for line in sys.stdin:
        parsed_line = re.split(r'[-+#\s*$ ]', line)  # ✄ trimming
        if (len(parsed_line) > 2):
            sc = int(parsed_line[10])  # status code
            total_file_size += int(parsed_line[11])  # file size

            if (sc in sorted(dict_sc.keys())):
                temp = int(dict_sc[sc]) + 1
                dict_sc[sc] = str(temp)
            count += 1

        if (count % 10 == 0 and count > 0):
            print_msg(dict_sc, total_file_size)

except Exception:
    pass
finally:
    print_msg(dict_sc, total_file_size)
