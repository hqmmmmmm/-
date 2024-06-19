struct Node {
    int key, val;
    Node *prev, *next;
    Node(): key(0), val(0), prev(nullptr), next(nullptr) {}
    Node(int key_, int val_): key(key_), val(val_), prev(nullptr), next(nullptr) {}
};


class LRUCache {
public:
    int size, capacity;
    Node *head, *tail;
    unordered_map<int, Node *> h;

    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new Node{};
        tail = new Node{};
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!h.count(key)) return -1;
        
        auto node = h[key];
        removeNode(node);
        addNodeToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(h.count(key)) {
            auto node = h[key];
            removeNode(node);
            addNodeToHead(node);
            node->val = value;
        } else {
            if(size == capacity) {
                auto last = tail->prev;
                h.erase(last->key);
                removeNode(last);
                --size;
            }
            auto node = new Node(key, value);
            h[key] = node;
            addNodeToHead(node);
            ++size;
        }
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToHead(Node *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */