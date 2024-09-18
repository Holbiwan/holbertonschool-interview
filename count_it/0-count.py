#!/usr/bin/python3
"""
Count it! - Recursive function to count specific keywords
"""

import requests


def count_words(
        subreddit, word_list, keyword_count=None, after=None, repeats=None):
    """Queries Reddit API recursively to count keywords"""

    # Initialize keyword_count and repeats if first time calling the function
    if keyword_count is None:
        keyword_count = {word.lower(): 0 for word in word_list}
        repeats = {word.lower(): word_list.count(word) for word in word_list}

    # Set the API URL and headers
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    headers = {"User-Agent": "Mozilla/5.0"}
    params = {'after': after} if after else {}

    # Make the GET request to Reddit API
    response = requests.get(
        url, headers=headers, params=params, allow_redirects=False)

    # Check if the subreddit is invalid (404 error)
    if response.status_code == 404:
        return

    # Parse the JSON response
    data = response.json().get('data')
    after = data.get('after')
    posts = data.get('children')

    # Process each post title and count keywords
    for post in posts:
        title = post['data']['title'].lower().split()
        for word in title:
            if word in keyword_count:
                keyword_count[word] += 1

    # If there is another page, call the function recursively
    if after:
        count_words(subreddit, word_list, keyword_count, after, repeats)
    else:
        # Adjust counts by the number of duplicates in word_list
        for word, count in repeats.items():
            keyword_count[word] *= count

        # Sort results by count (descending), then alphabetically
        sorted_keywords = sorted(
            keyword_count.items(), key=lambda x: (-x[1], x[0]))

        # Print the results
        for word, count in sorted_keywords:
            if count > 0:
                print(f'{word}: {count}')
