/**
 * @brief LRU Cache implementation using doubly linked list and hash map
 * @intuition Doubly linked list for O(1) removal/insertion, hash map for O(1) lookup
 * @approach Most recently used at head, least recently used at tail
 * @complexity Time: O(1) for get and put, Space: O(capacity)
 */

#include <unordered_map>

using std::unordered_map;

class LRUCache final {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    int size_;
    int capacity_;
    Node* head_;
    Node* tail_;
    unordered_map<int, Node*> cache_;
    
    auto removeNode(Node* node) -> void {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    auto addToHead(Node* node) -> void {
        node->next = head_->next;
        node->prev = head_;
        head_->next->prev = node;
        head_->next = node;
    }
    
public:
    explicit LRUCache(int capacity) : size_(0), capacity_(capacity) {
        head_ = new Node(0, 0);
        tail_ = new Node(0, 0);
        head_->next = tail_;
        tail_->prev = head_;
    }
    
    [[nodiscard]] auto get(int key) -> int {
        if (!cache_.contains(key)) {
            return -1;
        }
        Node* node = cache_[key];
        removeNode(node);
        addToHead(node);
        return node->val;
    }
    
    auto put(int key, int value) -> void {
        if (cache_.contains(key)) {
            Node* node = cache_[key];
            removeNode(node);
            node->val = value;
            addToHead(node);
        } else {
            auto* node = new Node(key, value);
            cache_[key] = node;
            addToHead(node);
            if (++size_ > capacity_) {
                Node* lru = tail_->prev;
                cache_.erase(lru->key);
                removeNode(lru);
                delete lru;
                --size_;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
