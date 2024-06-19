struct Node {
    int key, val;
    Node *prev, *next;
    Node(): key(0), val(0), prev(nullptr), next(nullptr) {}
    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {} 
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
    
    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToHead(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if(!h.count(key)) return -1;
        removeNode(h[key]);
        addNodeToHead(h[key]);
        return h[key]->val;
    }
    
    void put(int key, int value) {
        if(!h.count(key)) {
            if(size == capacity) {
                auto last = tail->prev;
                h.erase(last->key);
                removeNode(last);
                size--;
            }
            auto node = new Node{key, value};
            h[key] = node;
            addNodeToHead(node);
            size++;
        } else {
            removeNode(h[key]);
            addNodeToHead(h[key]);
            h[key]->val = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */