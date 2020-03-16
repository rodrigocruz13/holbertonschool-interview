#!/usr/bin/python3

import sys
import re

def print_msg(list_status_codes, line_status_codes, total_file_size):
    """
    Method that determines if all the boxes can be opened.
    Args:
        list_status_codes: list of status codes
        line_status_codes: # lines per status codes
        total_file_size: total of the file

    Returns:
        Nothing
    """

    print("File size: {}".format(total_file_size))
    for i in range(len(line_status_codes)):
        if line_status_codes[i] != 0:
            print("{}: {}".format(list_status_codes[i], line_status_codes[i]))


parsed_line = []
list_status_codes = [200, 301, 400, 401, 403, 404, 405, 500]
line_status_codes = [0, 0, 0, 0, 0, 0, 0, 0]
total_file_size = 0

count = 0
try:

    for line in sys.stdin:

        parsed_line = re.split(r'[-+#\s*$ ]', line) # ✄ trimming
        status_code = int(parsed_line[10])  # status code
        total_file_size += int(parsed_line[11])  # file size

        if (status_code in list_status_codes):
            i = list_status_codes.index(status_code)
            line_status_codes[i] += 1

        if (count % 10 == 0 and count > 0):
            print_msg(list_status_codes, line_status_codes, total_file_size)

        count += 1

except KeyboardInterrupt as e:
    print_msg(list_status_codes, line_status_codes, total_file_size)
    # print(e)


