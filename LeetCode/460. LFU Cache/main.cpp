#include <iostream>
#include <unordered_map>

template<typename K, typename V>
class LfuMap {
private:
    struct Node {
        K key;
        V value;
        int cnt;
        Node *prev;
        Node *next;

        Node() : key(), value(), cnt(0), prev(nullptr), next(nullptr) {}

        Node(K key, V value, int cnt = 0, Node *prev = nullptr, Node *next = nullptr)
                : key(key), value(value), cnt(cnt), prev(prev),
                  next(next) {}
    };

    std::unordered_map<K, Node *> map{};
    std::unordered_map<int, std::pair<Node *, Node *>> range{};
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

        friend LfuMap;
    };

    explicit LfuMap(size_t capacity) : capacity(capacity) {
        head->next = tail;
        tail->prev = head;
    }

    ~LfuMap() {
        auto cur = head;
        while (cur != nullptr) {
            auto t = cur->next;
            delete cur;
            cur = t;
        }
    }

    void add_r_to_l_next(Node *l, Node *r) {
        r->prev = l;
        r->next = l->next;
        l->next->prev = r;
        l->next = r;
    }

    void add_l_to_r_prev(Node *l, Node *r) {
        l->prev = r->prev;
        l->next = r;
        r->prev->next = l;
        r->prev = l;
    }

    void add_to_head(Node *node) {
        add_r_to_l_next(head, node);
    }

    void add_to_tail(Node *node) {
        add_l_to_r_prev(node, tail);
    }

    void remove_node(Node *node) {
        std::pair<Node *, Node *> cur_range = range[node->cnt];

        // remove node in cnt
        if (cur_range.first == cur_range.second) { range.erase(node->cnt); }
        else if (node == cur_range.first) { range[node->cnt] = std::make_pair(node->next, cur_range.second); }
        else if (node == cur_range.second) { range[node->cnt] = std::make_pair(cur_range.first, node->prev); }

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void move_to_cnt_add_1(Node *node) {
        auto l_range_r = range[node->cnt].first->prev;
        remove_node(node);

        ++node->cnt;
        auto cnt = node->cnt;

        if (range.find(cnt) != range.end()) {
            std::pair<Node *, Node *> new_range = range[cnt];

            add_l_to_r_prev(node, new_range.first);
            range[cnt] = std::make_pair(node, new_range.second);
        } else {
            add_r_to_l_next(l_range_r, node);
            range.insert({cnt, std::make_pair(node, node)});
        }

    }

    Node *remove_tail() {
        auto res = tail->prev;
        remove_node(res);
        return res;
    }

    void insert(K key, V value) {
        if (map.find(key) == map.end()) {
            if (map.size() == capacity) {
                auto node = remove_tail();
                map.erase(node->key);
                delete node;
            }
            auto node = new Node{key, value};
            map.insert({key, node});

            if (range.find(0) == range.end()) {
                add_to_tail(node);
                range[0] = std::make_pair(node, node);
            } else {
                add_l_to_r_prev(node, range[0].first);
                range[0].first = node;
            }
        } else {
            map[key]->value = value;
            move_to_cnt_add_1(map[key]);
        }
    }

    iterator find(K key) {
        if (map.find(key) != map.end()) {
            auto node = map.find(key)->second;
            move_to_cnt_add_1(node);
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

class LFUCache {
private:
    LfuMap<int, int> lfu_map;
public:
    LFUCache(int capacity) : lfu_map(capacity) {}

    int get(int key) {
        auto it = lfu_map.find(key);
        if (it != lfu_map.end()) {
            return it.operator*().second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        lfu_map.insert(key, value);
    }
};

void case1() {
    LFUCache lfu_cache{3};

    lfu_cache.put(1, 1);
    lfu_cache.put(2, 2);
    std::cout << lfu_cache.get(1);
    lfu_cache.put(3, 3);
    std::cout << lfu_cache.get(2);
    std::cout << lfu_cache.get(3);

    lfu_cache.put(4, 4);

    std::cout << lfu_cache.get(1);
    std::cout << lfu_cache.get(3);
    std::cout << lfu_cache.get(4);
}

void case2() {
    LFUCache lfu_cache{2};

    lfu_cache.put(3, 1);
    lfu_cache.put(2, 1);
    lfu_cache.put(2, 2);
    lfu_cache.put(4, 4);
    std::cout << lfu_cache.get(2);
}

void case3() {
    LFUCache lfu_cache{3};

    lfu_cache.put(1, 1);
    lfu_cache.put(2, 2);
    lfu_cache.put(3, 3);
    lfu_cache.put(4, 4);
    std::cout << lfu_cache.get(4);
    std::cout << lfu_cache.get(3);
    std::cout << lfu_cache.get(2);
    std::cout << lfu_cache.get(1);
}

int main() {
    case3();
    return 0;
}
