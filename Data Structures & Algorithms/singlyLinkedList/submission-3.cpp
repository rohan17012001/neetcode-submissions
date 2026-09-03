class LinkedList {
    vector<int> v;
    int n=0;
public:
    LinkedList() {
    }

    int get(int index) {
        if(index>=n || index<0) return -1;
        return v[index];
    }

    void insertHead(int val) {
        // if(v.empty()){
        //     v.push_back(val);
        //     return;
        // }
        // v.push_back(0);
        // n++;
        // for(int i=n-1; i>0; i++){
        //     v[i]=v[i-1];
        // }
        // v[0]=val;
        v.insert(v.begin(), val);
        n++;
    }
    
    void insertTail(int val) {
        v.push_back(val);
        n++;
    }

    bool remove(int index) {
        // v.pop_back();
        // n--;
        if(index>=n || index<0) return false;
        // for(int i=index; i<n-1; i++) v[i]=v[i+1];
        // v.pop_back();
        // n--;
        // return true;
        v.erase(v.begin()+index); n--; return true;
    }

    vector<int> getValues() {
        return v;
    }
};
