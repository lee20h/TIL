class FreqStack {
   public:
       unordered_map <int, int> cnt;
       unordered_map <int, stack<int>>sts;
       int maxFreq = 0;
       FreqStack() {
          maxFreq = 0;
          cnt.clear();
          sts.clear();
       }
       void push(int x) {
          cnt[x]++;
          maxFreq = max(maxFreq, cnt[x]);
          sts[cnt[x]].push(x);
       }
       int pop() {
          int maxKey = maxFreq;
          int x = sts[maxKey].top();
          sts[maxKey].pop();
          if(sts[maxKey].size() == 0){
             sts.erase(maxKey);
             maxFreq--;
          }
          cnt[x]--;
          return x;
       }
};
