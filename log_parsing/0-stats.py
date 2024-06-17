#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.
"""
import sys
import re


def print_metrics(status_codes, file_size):
    """
    Function that prints file size and status codes.
    """
    print("File size: {:d}".format(file_size))
    for key, value in sorted(status_codes.items()):
        if value != 0:
            print("{:s}: {:d}".format(key, value))


codes = {"200": 0, "301": 0, "400": 0, "401": 0,
         "403": 0, "404": 0, "405": 0, "500": 0}
file_size = 0
counter = 0

pattern = re.compile(
    r'\d+\.\d+\.\d+\.\d+ - \[.*\] "GET /projects/260 HTTP/1\.1" '
    r'(\d+) (\d+)'
)

try:
    for line in sys.stdin:
        match = pattern.search(line)
        if match:
            counter += 1
            code, size = match.groups()
            file_size += int(size)
            if code in codes:
                codes[code] += 1
            if counter == 10:
                print_metrics(codes, file_size)
                counter = 0
except KeyboardInterrupt:
    print_metrics(codes, file_size)

print_metrics(codes, file_size)
