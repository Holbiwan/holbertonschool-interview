#!/usr/bin/python3

"""Script that reads stdin line by line and computes metrics"""

import sys
import re


def print_metrics(status_codes, file_size):
    """Prints file size and status codes sorted by code."""
    print("File size: {:d}".format(file_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] != 0:
            print("{}: {:d}".format(code, status_codes[code]))


# Initialize all required variables and regex pattern
status_codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}
file_size = 0
counter = 0
pattern = re.compile(
    r'\d+\.\d+\.\d+\.\d+ - \[.*\] "GET /projects/260 HTTP/1\.1" (\d+) (\d+)')

try:
    for line in sys.stdin:
        match = pattern.search(line)
        if match:
            code, size = match.groups()
            file_size += int(size)
            if code in status_codes:
                status_codes[code] += 1
            counter += 1
            if counter == 10:
                print_metrics(status_codes, file_size)
                counter = 0  # Reset counter, keep file size and status codes
except KeyboardInterrupt:
    print_metrics(status_codes, file_size)
    raise  # Re-raise the KeyboardInterrupt to signal interruption

# Print final metrics
print_metrics(status_codes, file_size)
