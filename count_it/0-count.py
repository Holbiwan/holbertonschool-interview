#!/usr/bin/python3
"""
This module contains the recursive function count_words
"""

import requests


def count_words(subreddit, word_list, keyword_count={}, after=None):
    """
    Queries the Reddit API, parses the title of all hot articles,
    and prints a sorted count of given keywords
    """
    headers = {'User-Agent': 'Mozilla/5.0'}
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"

    params = {'limit': 100, 'after': after}
    response = requests.get(
        url, headers=headers, params=params, allow_redirects=False)

    if response.status_code != 200:
        return

    try:
        data = response.json().get('data')
        if data is None:
            return
    except ValueError:
        return

    children = data.get('children', [])
    for child in children:
        title = child['data']['title'].lower().split()
        for word in word_list:
            word = word.lower()
            keyword_count[word] = keyword_count.get(
                word, 0) + title.count(word)

    after = data.get('after')

    if after:
        count_words(subreddit, word_list, keyword_count, after)
    else:
        sorted_words = sorted(
            keyword_count.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_words:
            if count > 0:
                print(f"{word}: {count}")
