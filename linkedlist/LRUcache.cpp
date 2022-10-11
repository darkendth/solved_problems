
struct Node{
    int key,value;
    struct Node *prev,*next;
};
typedef struct Node DNode;

class LRUCache {
    unordered_map<int,DNode *> hmap;
    DNode *head,*tail;
    int cap;
    
    void insert(DNode *temp){
        if (head==NULL)
            tail=temp;
        else
            head->prev=temp;
        temp->next=head;
        head=temp;
    }
    
    void remove_end(){
        DNode *temp=tail;
        if (tail==NULL)
            return ;
        if (head==tail){
            head=NULL;
            tail=NULL;
        }
        else{
            tail=tail->prev;    
        }
        hmap.erase(temp->key);
        delete temp;
        temp=NULL;
    }
    
    void put_at_head(DNode *temp){
        temp->prev->next=temp->next;
        if (temp==tail)
            tail=tail->prev;
        else
            temp->next->prev=temp->prev;
        temp->prev=NULL;
        temp->next=NULL;
        insert(temp);
    }
    
public:
    LRUCache(int capacity) {
        cap=capacity;    
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if (hmap.find(key)==hmap.end())
            return -1;
        int val = hmap[key]->value;
        if (hmap[key]!=head){
            put_at_head(hmap[key]); 
        }
        return val;
    }
    
    void put(int key, int value) {
        if (hmap.find(key)!=hmap.end()){
            hmap[key]->value=value;
            if (hmap[key]!=head){
                put_at_head(hmap[key]);
            }
        }
        else{
            if (hmap.size()==cap)
                remove_end();
            DNode *temp = new DNode;
            temp->next=NULL;
            temp->prev=NULL;
            temp->value=value;
            temp->key=key;
            insert(temp);
            hmap[key]=temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */