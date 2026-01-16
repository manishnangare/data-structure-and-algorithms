struct Node {
    int val;
    int key;
    Node* prev;
    Node* next;

    Node(int v,int k) : val(v), key(k), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    Node* head;
    Node* tail;
    Node* temp;
    int c;
    int nc;
    map<int,Node*> m;
    map<int,int> k;

    void removeNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToHead( Node* node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    LRUCache(int capacity) {
        nc = 0;
        c = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if( k[key] == 0)
        {
            return -1;
        }
        else
        {

            removeNode(m[key]);
            addNodeToHead(m[key]);

            return m[key]->val;
        }
    }
    
    void put(int key, int value) {
        
        if(k[key] == 0)
        {
            nc++;
            temp = new Node(value,key);
            addNodeToHead(temp);
            k[key] = 1;
            m[key] = temp;

            if(nc > c)
            {
                k[tail->prev->key] = 0;
                removeNode(tail->prev);
                nc--;
            }
        }
        else
        {
            removeNode(m[key]);
            addNodeToHead(m[key]);
            m[key]->val = value;
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */