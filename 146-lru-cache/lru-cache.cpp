class LRUCache {
public:
unordered_map<int,int>keyvalue;
map<int,int>timekey;
unordered_map<int,int>keytime;
int size=0;
int count=0;
    LRUCache(int capacity) {
        size=capacity;
        keyvalue.clear();
        keytime.clear();
        timekey.clear();
        count=0;
    }
    
    int get(int key) {
        if(keyvalue.find(key) != keyvalue.end()) {
            int time=keytime[key];
            timekey.erase(time);
            timekey[count]=key;
            keytime[key]=count;
            count++;
            return keyvalue[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyvalue.find(key) != keyvalue.end()) {
            keyvalue[key]=value;
            int time=keytime[key];
            keytime[key]=count;
            timekey.erase(time);
            timekey[count]=key;
            count++;
        }else {
            if(keytime.size()<size) {
                keyvalue[key]=value;
                keytime[key]=count;
                timekey[count]=key;
                count++;
            }else {
                int oldtime=timekey.begin()->first;
                int oldkey =timekey.begin()->second;
                timekey.erase(oldtime);
                keyvalue.erase(oldkey);
                keytime.erase(oldkey);
                keyvalue[key]=value;
                keytime[key]=count;
                timekey[count]=key;
                count++;
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