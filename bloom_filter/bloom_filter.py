from typing import List, Callable

from bitarray import bitarray


class BloomFilter(object):

    def __init__(self, filter_size: int, *, hash_functions=None) -> None:
        self.filter_size = filter_size
        self.bloom_filter = bitarray(self.filter_size)
        self.bloom_filter.setall(0)

        if hash_functions is not None:
            self.hash_functions: List[Callable] = hash_functions
        else:
            def _hash_djb2(s: str):
                hash = 5381
                for x in s:
                    hash = ((hash << 5) + hash) + ord(x)
                return hash % self.filter_size

            self.hash_functions: List[Callable] = [lambda x: _hash_djb2(x + str(i)) for i in range(5)]

    def add(self, item) -> None:
        for func in self.hash_functions:
            self.bloom_filter[func(item)] = 1

    def not_exist(self, item) -> bool:
        for func in self.hash_functions:
            if self.bloom_filter[func(item)] == 0:
                return True
        return False
