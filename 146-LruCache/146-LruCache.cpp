// Last updated: 11/25/2026, 3:48:40 PM
class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    void addNode(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* keyNode = mp[key];
            deleteNode(keyNode);
            addNode(keyNode);
            return keyNode->val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* keyNode = mp[key];
            keyNode->val = value;
            deleteNode(keyNode);
            mp.erase(key);
        } else if (mp.size() == capacity) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */