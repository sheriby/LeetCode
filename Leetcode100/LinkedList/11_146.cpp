#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value)
        : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

typedef DLinkedNode* List;

class LRUCache {
   private:
    unordered_map<int, List> cache;
    List head;
    List tail;
    int size;
    int capacity;

   public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        List node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            List node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity) {
                List removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        } else {
            List node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(List node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(List node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(List node) {
        removeNode(node);
        addToHead(node);
    }

    List removeTail() {
        List node = tail->prev;
        removeNode(node);
        return node;
    }
};