class MyHashMap {
public:
    vector<pair<int, int>> v;
    
    MyHashMap() {
        v;
    }
    
    void put(int key, int value) {
        bool isExist = false;
        for(int i=0; i<v.size(); i++) {
            if(v[i].first == key) {
                isExist = true;
                v[i].second = value;
                break;
            }
        }
        if(!isExist) {
            v.push_back({key, value});
        }
    }
    
    int get(int key) {
        for(int i=0; i<v.size(); i++) {
            if(v[i].first == key) {
                return v[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i=0; i<v.size(); i++) {
            if(v[i].first == key) {
                v.erase(v.begin() + i);
                break;
            }
        }
    }
};

