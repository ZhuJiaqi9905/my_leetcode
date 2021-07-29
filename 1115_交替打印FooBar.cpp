class FooBar {
private:
    int n;
    bool first_;
    std::mutex mutex_;
    std::condition_variable cv_;
public:
    FooBar(int n) {
        this->n = n;
        this->first_ = true;
    }

    void foo(function<void()> printFoo) {
        unique_lock<std::mutex> lock(mutex_);
        for (int i = 0; i < n; i++) {
            cv_.wait(lock, [this]{return (this->first_);});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            first_ = false;
            cv_.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<std::mutex> lock(mutex_);
        for (int i = 0; i < n; i++) {
            cv_.wait(lock, [this]{return !(this->first_);});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            first_ = true;
            cv_.notify_all();
        }
    }
};