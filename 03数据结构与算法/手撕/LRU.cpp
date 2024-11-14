// 结点类
struct Node {
    int key_, value_;
    Node *prev, *next;
    Node(int k = 0, int v = 0): key_(k), value_(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int size_, cap_;
    Node *head, *tail;
    unordered_map<int, Node *> h;

    LRUCache(int capacity) {
        size_ = 0;
        cap_ = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!h.count(key)) {
            return -1;
        } else { // 访问一个元素后，将其移动到头结点
            RemoveNode(h[key]);
            AddNodeToHead(h[key]);
            return h[key]->value_;
        }
    }
    
    void put(int key, int value) {
        if(h.count(key)) {
            RemoveNode(h[key]);
            AddNodeToHead(h[key]);
            h[key]->value_ = value;
        } else {
            if(size_ == cap_) { // LRU容量不够，删除链表尾元素
                h.erase(tail->prev->key_);
                RemoveNode(tail->prev);
                size_--;
            }
            h[key] = new Node(key, value);
            AddNodeToHead(h[key]);
            size_++;
        }
    }

    // 从双向链表中删除某个结点
    void RemoveNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 将node插入到头结点之后
    void AddNodeToHead(Node *node) {
        node->prev = head;
        node->next = head->next;

        head->next->prev = node;
        head->next = node;
    }
};