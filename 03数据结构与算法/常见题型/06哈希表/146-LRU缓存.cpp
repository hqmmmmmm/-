struct Node {
    int key, val;
    Node *prev;
    Node *next;
    Node(): key(0), val(0), prev(nullptr), next(nullptr) {}
    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int cap, size;
    Node *head, *tail;
    unordered_map<int, Node *> h;

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new Node{};
        tail = new Node{};
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if(!h.count(key)) return -1;
        removeNode(h[key]);
        addNodeToHead(h[key]);
        return h[key]->val;
    }
    
    void put(int key, int value) {
        if(!h.count(key)) {
            if(size == cap) {
                h.erase(tail->prev->key);
                removeNode(tail->prev);
                size--;
            }
            auto node = new Node{key, value};
            addNodeToHead(node);
            size++;
            h[key] = node;
        } else {
            removeNode(h[key]);
            addNodeToHead(h[key]);
            h[key]->val = value;
        }
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToHead(Node *node) {
        head->next->prev = node;
        node->next = head->next;
        node->prev =head;
        head->next = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */