#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct ListNode {
    T value;
    ListNode<T>* pre;
    ListNode<T>* next;
};

template <typename T>
class List {
   public:
    using ListIter = ListNode<T>*;
    List() {
        dump = new ListNode<T>();
        list_size = 0;
    }

    void push_front(T value) {
        ListIter node = new ListNode<T>();
        node->value = value;

        if (!dump->next) {
            dump->next = node;
            dump->pre = node;
            node->pre = dump;
            node->next = nullptr;
        } else {
            dump->next->pre = node;
            node->next = dump->next;
            node->pre = dump;
            dump->next = node;
        }
        list_size++;
    }

    void erase(ListIter node) {
        if (!node) return;
        node->pre->next = node->next;
        if (node->next)
            node->next->pre = node->pre;
        else
            dump->pre = node->pre;

        delete node;
        list_size--;
    }

    ListIter begin() { return dump->next; }
    ListIter end() { return dump->pre; }

    T front() { return dump->next->value; }
    T back() { return dump->pre->value; }

    void pop_back() { erase(dump->pre); }

    void display() {
        ListIter p = dump->next;
        cout << list_size << ": ";
        while (p) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }

    int size() { return list_size; }

   private:
    ListIter dump;
    int list_size;
};

template <typename T>
class LRU {
   public:
    LRU(int c) : capcity(c) {}
    void insert(T key) {
        if (hash.find(key) != hash.end()) {
            list.erase(hash[key]);
        } else {
            if (list.size() == capcity) {
                T back = list.back();
                list.pop_back();
                hash.erase(back);
            }
        }
        list.push_front(key);
        hash[key] = list.begin();
    }

    void display() { list.display(); }

   private:
    List<T> list;
    using ListIter = ListNode<T>*;
    unordered_map<T, ListIter> hash;
    int capcity;
};

int main() {
    LRU<string> lru(3);
    lru.insert("hello");
    lru.insert("world");
    lru.insert("foo");
    lru.display();
    lru.insert("hello");
    lru.display();
    lru.insert("foo");
    lru.insert("you");
    lru.display();
    return 0;
}