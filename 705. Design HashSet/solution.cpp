#include "../common.h"

class MyHashSet {
public:
  using Bucket_t = std::deque<int>;

private:
  std::vector<Bucket_t> Storage;
  static constexpr int M = 233;

  auto searchInBucket(Bucket_t &bucket, int key) {
    return find(bucket.begin(), bucket.end(), key);
  }

public:
  MyHashSet() { Storage.resize(M); }

  void add(int key) {
    auto &bucket = Storage[key % M];
    auto it = searchInBucket(bucket, key);
    if (it == bucket.end()) {
      bucket.push_back(key);
    }
  }

  void remove(int key) {
    auto &bucket = Storage[key % M];
    auto it = searchInBucket(bucket, key);
    if (it != bucket.end()) {
      bucket.erase(it);
    }
  }

  bool contains(int key) {
    auto &bucket = Storage[key % M];
    auto it = searchInBucket(bucket, key);
    return it != bucket.end();
  }
};