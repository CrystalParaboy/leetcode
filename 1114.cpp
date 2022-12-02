class Foo {
    std::mutex _mutex;
    int _count = 1;
    std::condition_variable _cv;

public:
    Foo() { }

    void first(function<void()> printFirst) {
        std::lock_guard<std::mutex> lock(_mutex);
        _count = 2;        
        
        printFirst();        
        
        _cv.notify_all();        
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(_mutex);
        _cv.wait(lk, [this] { return _count == 2; });
        _count = 3;
                
        printSecond();        
        
        lk.unlock();
        _cv.notify_one();        
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(_mutex);
        _cv.wait(lk, [this] { return _count == 3; });        
        
        printThird();
        
        lk.unlock();        
    }
};
