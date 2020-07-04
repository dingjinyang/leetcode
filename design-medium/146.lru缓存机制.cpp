/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
struct DLinkedNode {
  int key, value;
  DLinkedNode *prev;
  DLinkedNode *next;
  DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
  DLinkedNode(int _key, int _value)
      : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
  unordered_map<int, DLinkedNode *> cache;
  DLinkedNode *head;
  DLinkedNode *tail;
  int size, capacity;

public:
  LRUCache(int _capacity) : capacity(_capacity), size(0) {
    head = new DLinkedNode();
    tail = new DLinkedNode();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (!cache.count(key))
      return -1;
    DLinkedNode *node = cache[key];
    moveToHead(node);
    return node->value;
  }

  void put(int key, int value) {
    if (!cache.count(key)) {
      DLinkedNode *node = new DLinkedNode(key, value);
      cache.insert({key, node});
      insertToHead(node);
      size++;
      if (size > capacity) {
        DLinkedNode *removeNode = removeTail();
        cache.erase(removeNode->key);
        size--;
      }
    } else {
      DLinkedNode *node = cache[key];
      node->value = value;
      moveToHead(node);
    }
  }

  void moveToHead(DLinkedNode *node) {
    removeNode(node);
    insertToHead(node);
  }

  void insertToHead(DLinkedNode *node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }

  void removeNode(DLinkedNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  DLinkedNode *removeTail() {
    DLinkedNode *node = tail->prev;
    removeNode(node);
    return node;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
