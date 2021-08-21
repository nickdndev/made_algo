from bloom_filter.bloom_filter import BloomFilter

def test_bloom_filter():
    bloom_filter = BloomFilter(100)

    bloom_filter.add("10.17.2013")
    bloom_filter.add("10.17.2014")

    assert not bloom_filter.not_exist("10.17.2013")
    assert not bloom_filter.not_exist("10.17.2014")
    assert  bloom_filter.not_exist("10.17.2021")
