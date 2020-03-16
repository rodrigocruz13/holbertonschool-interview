#!/usr/bin/python3
import random
import sys
from time import sleep
import datetime

for i in range(10000):
    sleep(random.random())
    sys.stdout.write(
        "{:d}.{:d}.{:d}.{:d} - [{}] \"GET /projects/260 HTTP/1.1\" {} {}\n"
        .format(
            random.randint(1, 255),  # <IP Address>
            random.randint(1, 255),  # <IP Address>
            random.randint(1, 255),  # <IP Address>
            random.randint(1, 255),  # <IP Address>
            datetime.datetime.now(),  # [<date>]
            # <status code>
            random.choice([200, 301, 400, 401, 403, 404, 405, 500]),
            random.randint(1, 1024)))  # <file size>
    sys.stdout.flush()
