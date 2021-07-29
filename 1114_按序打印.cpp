class Foo {
public:
    int num_;
    std::mutex m_;
    std::condition_variable cv_;
    Foo() {
        this->num_ = 0;
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(m_);
        cv_.wait(lock, [this]{return this->num_ == 0;});
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        this->num_++;
        cv_.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(m_);
        cv_.wait(lock, [this]{return this->num_ == 1;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        this->num_++;
        cv_.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(m_);
        cv_.wait(lock, [this]{return this->num_ == 2;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};