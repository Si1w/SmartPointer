#ifndef UNIQUE_PTR
#define UNIQUE_PTR

#include <memory>

template <typename T>

class UniquePtr {
    public:
        UniquePtr(T* ptr) : _p(ptr) {};

        UniquePtr(std::unique_ptr<T> up) : _p(up.release()) {};
    

        UniquePtr() : _p(nullptr) {};

        ~UniquePtr() { delete _p; _p = nullptr; };

        T* get() const { return _p; };

        T& operator*() const { return *_p; };

        T* operator->() const { return _p; };

        void reset() {
            delete _p;
            _p = nullptr;
        };
        
        void reset(T* ptr) {
            if (ptr != _p) {
                delete _p;
                _p = ptr;
            }
        };

        T* release() { T* p = _p; _p = nullptr; return p; };

        operator bool() const { return _p != nullptr; };

    private:
        T* _p;
};

#endif //UNIQUE_PTR