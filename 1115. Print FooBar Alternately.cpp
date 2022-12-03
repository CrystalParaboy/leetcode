class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    int bar_count;
    int foo_count;

public:
    FooBar(int n) {
        this->n = n;
        bar_count=0;
        foo_count=0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(m);
            cv.wait(lk,[this,i]{return bar_count==i;});
            lk.unlock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            foo_count++;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(m);
            cv.wait(lk,[this,i]{return foo_count==i+1;});
            lk.unlock();
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            bar_count++;
            cv.notify_all();
        }
    }
};
