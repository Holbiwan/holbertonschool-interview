import requests

def count_words(subreddit, word_list, keyword_count={}, after=None, repeats={}):
    headers = {'User-Agent': 'Mozilla/5.0'}
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    
    params = {'limit': 100, 'after': after} if after else {'limit': 100}
    
    response = requests.get(url, headers=headers, params=params)
    
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
        title = child['data']['title'].lower()
        for word in word_list:
            lower_word = word.lower()
            if lower_word in title:
                keyword_count[lower_word] = keyword_count.get(
                    lower_word, 0) + title.split().count(lower_word)
    
    after = data.get('after')
    if after:
        count_words(subreddit, word_list, keyword_count, after, repeats)
    else:
        for word, count in sorted(
                keyword_count.items(), key=lambda item: (-item[1], item[0])):
            if count > 0:
                print(f"{word}: {count}")
