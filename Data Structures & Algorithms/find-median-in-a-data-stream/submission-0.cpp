class MedianFinder {
public:
    double median;
        priority_queue<int> first;
        priority_queue<int, vector<int>, greater<int>> second; 
        // int flen=0;
        // int slen=0;
    MedianFinder() {
        // public:
        // return new MedianFinder;
    };
    
    void addNum(int num) {
        // if(!first.empty() && first.top()>num){
        //     int temp=first.top();
        //     first.pop();
        //     first.push(num);
        //     second.push(temp);
        //     slen++;
        // }
        // else{
        //     first.push(num);
        //     flen++;
        // }
        // if(flen>slen+1){
        //         second.push(first.top());
        //         slen++;
        //         first.pop();
        //         flen--;
            
        // }
        // if(slen>flen+1){
        //         first.push(second.top());
        //         flen++;
        //         second.pop();
        //         slen--;
        // }
        first.push(num);
        second.push(first.top());
        first.pop();
        if(second.size()>first.size()){
            first.push(second.top());
            second.pop();
        }
    }
    
    double findMedian() {
        if(first.size()==second.size()){
            // if(flen==0) return 0;
            return (first.top()+second.top())/2.0;
        }
        return first.top();
    }
};
