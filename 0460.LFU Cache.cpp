/**
 * @brief LFU Cache with O(1) get and put operations
 * @intuition Track frequency and recency using doubly linked lists per frequency
 * @approach Hash map for key->node, frequency->list mapping, track min frequency
 * @complexity Time: O(1) for get/put Space: O(capacity)
 */
#include <unordered_map>

class Node final {
public:
    int key;
    int value;
    int freq;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), value(v), freq(1), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList final {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    auto addFirst(Node* node) -> void {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    auto remove(Node* node) -> Node* {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = nullptr;
        node->prev = nullptr;
        return node;
    }

    [[nodiscard]] auto removeLast() -> Node* {
        return remove(tail->prev);
    }

    [[nodiscard]] auto isEmpty() const -> bool {
        return head->next == tail;
    }
};

class LFUCache final {
public:
    explicit LFUCache(int capacity) : capacity_(capacity), minFreq_(0) {}

    [[nodiscard]] auto get(int key) -> int {
        if (capacity_ == 0 || map_.find(key) == map_.end()) {
            return -1;
        }

        Node* node = map_[key];
        incrFreq(node);
        return node->value;
    }

    auto put(int key, int value) -> void {
        if (capacity_ == 0) {
            return;
        }

        if (map_.find(key) != map_.end()) {
            Node* node = map_[key];
            node->value = value;
            incrFreq(node);
            return;
        }

        if (static_cast<int>(map_.size()) == capacity_) {
            DoublyLinkedList* list = freqMap_[minFreq_];
            Node* node = list->removeLast();
            map_.erase(node->key);
        }

        auto* node = new Node(key, value);
        addNode(node);
        map_[key] = node;
        minFreq_ = 1;
    }

private:
    int capacity_;
    int minFreq_;
    std::unordered_map<int, Node*> map_;
    std::unordered_map<int, DoublyLinkedList*> freqMap_;

    auto incrFreq(Node* node) -> void {
        const int freq = node->freq;
        DoublyLinkedList* list = freqMap_[freq];
        list->remove(node);

        if (list->isEmpty()) {
            freqMap_.erase(freq);
            if (freq == minFreq_) {
                ++minFreq_;
            }
        }

        ++node->freq;
        addNode(node);
    }

    auto addNode(Node* node) -> void {
        const int freq = node->freq;
        if (freqMap_.find(freq) == freqMap_.end()) {
            freqMap_[freq] = new DoublyLinkedList();
        }
        freqMap_[freq]->addFirst(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
