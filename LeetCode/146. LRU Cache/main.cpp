#include <iostream>
#include <unordered_map>
#include <vector>

template<typename K, typename V>
class LinkedHashMap {
private:
    struct Node {
        K key;
        V value;
        Node *prev;
        Node *next;

        Node() : key(), value(), prev(nullptr), next(nullptr) {}

        Node(K key, V value, Node *prev = nullptr, Node *next = nullptr) : key(key), value(value), prev(prev),
                                                                           next(next) {}
    };

    std::unordered_map<K, Node *> map{};
    size_t capacity{};

    Node *head = new Node();
    Node *tail = new Node();

public:
    class iterator {
    private:
        Node *cur;

    public:
        explicit iterator(Node *cur) : cur(cur) {}

        std::pair<K, V> operator*() {
            return std::make_pair(cur->key, cur->value);
        }


        iterator &operator++() {
            cur = cur->next;
            return *this;
        }

        iterator &operator--() {
            cur = cur->prev;
            return *this;
        }

        bool operator==(const iterator &rhs) const {
            return cur == rhs.cur;
        }

        bool operator!=(const iterator &rhs) const {
            return cur != rhs.cur;
        }

        friend LinkedHashMap;
    };

    explicit LinkedHashMap(size_t capacity) : capacity(capacity) {
        head->next = tail;
        tail->prev = head;
    }

    ~LinkedHashMap() {
        auto cur = head;
        while (cur != nullptr) {
            auto t = cur->next;
            delete cur;
            cur = t;
        }
    }

    void add_to_head(Node *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void remove_node(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void move_to_head(Node *node) {
        remove_node(node);
        add_to_head(node);
    }

    Node *remove_tail() {
        auto res = tail->prev;
        remove_node(res);
        return res;
    }

    void insert(K key, V value) {
        if (map.find(key) == map.end()) {
            auto node = new Node{key, value};
            map.insert({key, node});
            add_to_head(node);
        } else {
            map[key]->value = value;
            move_to_head(map[key]);
        }

        if (map.size() > capacity) {
            auto node = remove_tail();
            map.erase(node->key);
            delete node;
        }
    }

    iterator find(K key) {
        if (map.find(key) != map.end()) {
            auto node = map.find(key)->second;
            move_to_head(node);
            return iterator{node};
        }
        return end();
    }

    iterator begin() {
        return iterator{head};
    }

    iterator end() {
        return iterator{tail};
    }
};

class LRUCache {
private:
    LinkedHashMap<int, int> linkedHashMap;
public:
    LRUCache(int capacity) : linkedHashMap(capacity) {}

    int get(int key) {
        return linkedHashMap.find(key) != linkedHashMap.end() ? linkedHashMap.find(key).operator*().second : -1;
    }

    void put(int key, int value) {
        linkedHashMap.insert(key, value);
    }
};


int main() {
    LRUCache lru_cache{2};
    lru_cache.put(1, 1);
    lru_cache.put(2, 2);

    std::cout << lru_cache.get(1);
    lru_cache.put(3, 3);
    std::cout << lru_cache.get(2);
    lru_cache.put(4, 4);
    std::cout << lru_cache.get(1);
    std::cout << lru_cache.get(3);
    std::cout << lru_cache.get(4);
    return 0;
}
