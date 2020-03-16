#!/usr/bin/python3

import sys
import re

parsed_line = []
dict_sc = { 200: "0",
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

def print_msg(dict_sc, total_file_size):
    """
    Method that determines if all the boxes can be opened.
    Args:
        lst_sc: list of status codes
        count_sc: # lines per status codes
        total_file_size: total of the file
    Returns:
        Nothing
    """

    print("File size: {}".format(total_file_size))
    for i in sorted(dict_sc.keys()):
        if(dict_sc[i] is not "0"):
            print("{}: {}".format(i, dict_sc[i]))

try:
    for line in sys.stdin:
        parsed_line = re.split(r'[-+#\s*$ ]', line) # ✄ trimming
        sc = int(parsed_line[10])  # status code
        total_file_size += int(parsed_line[11])  # file size

        if (sc in sorted(dict_sc.keys())):
            temp = int(dict_sc[sc]) + 1
            dict_sc[sc] = str(temp)

        if (count % 10 == 0 and count > 0):
            print_msg(dict_sc, total_file_size)
        count += 1

except KeyboardInterrupt:
    print_msg(dict_sc, total_file_size)
    sys.exit()
