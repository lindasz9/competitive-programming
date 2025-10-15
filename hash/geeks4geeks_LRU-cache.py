# this is not the most optimal way, but I wanted to show my solution

from collections import deque

class LRUCache:
    def __init__(self, cap):
        self.cap = cap                # Maximum capacity of the cache
        self.cache = {}              # Stores key-value pairs
        self.q = deque()             # Maintains the order of key usage (oldest at the front)

    def get(self, key):
        if key in self.cache:
            self.q.remove(key)       # Remove key from its current position
            self.q.append(key)       # Re-add it to the end to mark it as recently used
            return self.cache[key]   # Return the corresponding value
        else:
            return -1                # Key not found

    def put(self, key, value):
        if key not in self.cache and len(self.cache) == self.cap:
            # Cache is full and new key is being inserted, remove least recently used
            del self.cache[self.q.popleft()]
        
        self.cache[key] = value      # Insert or update the key-value pair
        
        if key in self.q:
            self.q.remove(key)       # Remove existing key to update its position
        
        self.q.append(key)           # Append key as most recently used
