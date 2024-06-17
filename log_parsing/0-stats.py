#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.
"""
import sys
import re


def print_metrics(status_codes, file_size):
    """ Function that prints file size and status codes sorted by code. """
    print(f"File size: {file_size}")
    for code in sorted(status_codes.keys()):
        if status_codes[code]:
            print(f"{code}: {status_codes[code]}")


codes = {str(code): 0 for code in [200, 301, 400, 401, 403, 404, 405, 500]}
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
            code, size = match.groups()
            file_size += int(size)
            if code in codes:
                codes[code] += 1
            counter += 1
            if counter == 10:
                print_metrics(codes, file_size)
                counter = 0  # Reset counter, keep file size and codes
except KeyboardInterrupt:
    print_metrics(codes, file_size)

print_metrics(codes, file_size)  # Final metrics print
