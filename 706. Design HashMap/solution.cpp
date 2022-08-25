#include "../common.h"

class MyHashMap {
public:
  using Pair_t = std::pair<int, int>;
  using Bucket_t = std::deque<Pair_t>;

private:
  std::vector<Bucket_t> Storage;
  static constexpr int M = 233;

  auto searchInBucket(Bucket_t &bucket, int key) {
    return find_if(
        bucket.begin(), bucket.end(),
        [key](std::pair<int, int> pair) { return pair.first == key; });
  }

public:
  MyHashMap() { Storage.resize(M); }

  void put(int key, int value) {
    auto &bucket = Storage[key % M];

    auto it = searchInBucket(bucket, key);
    if (it == bucket.end()) {
      bucket.push_back({key, value});
    } else {
      it->second = value;
    }
  }

  int get(int key) {
    auto &bucket = Storage[key % M];

    auto it = searchInBucket(bucket, key);
    return it != bucket.end() ? it->second : -1;
  }

  void remove(int key) {
    auto &bucket = Storage[key % M];

    auto it = searchInBucket(bucket, key);
    if (it != bucket.end()) {
      bucket.erase(it);
    }
  }
};