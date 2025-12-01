class LRUCache {
public:
    class Node{
    public:
        Node* prev;
        Node* next;
        int val,key;

        Node(int k,int v){
            val=v;
            key=k;
            prev=next=NULL;
        }    
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> m;
    int limit;

    void addnode(Node* newnode){
        Node* oldnext=head->next;

        head->next=newnode;
        oldnext->prev=newnode;

        newnode->next=oldnext;
        newnode->prev=head;
    }
    void delnode(Node* oldnode){
        Node* oldprev=oldnode->prev;
        Node* oldnext=oldnode->next;

        oldprev->next=oldnext;
        oldnext->prev=oldprev;
    }

    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* ansnode=m[key];
        int ans=ansnode->val;

        m.erase(key);
        delnode(ansnode);

        addnode(ansnode);
        m[key]=ansnode;

        return ans;
    }
    
    void put(int key, int val) {
        if(m.find(key)!=m.end()){
            Node* oldnode=m[key];
            delnode(oldnode);
            m.erase(key);
        }
        if(m.size()==limit){
            m.erase(tail->prev->key);
            delnode(tail->prev);
            
        }
        Node* newnode=new Node(key,val);
        addnode(newnode);
        m[key]=newnode;
    }
};
