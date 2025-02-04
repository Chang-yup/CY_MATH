#pragma once

#include <iterator>
#include <vector>
#include <cstddef>

template<typename T, typename containerT>
class Container {
public:
    using iterator = typename containerT::iterator;
    using const_iterator = typename containerT::const_iterator;
    using reverse_iterator = typename containerT::reverse_iterator;
    using const_reverse_iterator = typename containerT::const_reverse_iterator;

    virtual ~Container() = default;

    virtual iterator begin() = 0;
    virtual iterator end() = 0;
    virtual reverse_iterator rbegin() = 0;
    virtual reverse_iterator rend() = 0;
    virtual size_t size() const = 0;
    virtual size_t max_size() const = 0;
    virtual void resize(size_t n, const T& val = T()) = 0;
    virtual size_t capacity() const = 0;
    virtual bool empty() const = 0;
    virtual void reserve(size_t n) = 0;
    virtual void shrink_to_fit() = 0;
    virtual void assign(size_t n, const T& val) = 0;
    virtual void assign(iterator first, iterator last) = 0;
    virtual void push_back(const T& val) = 0;
    virtual void push_back(T&& val) = 0;
    virtual void pop_back() = 0;
    virtual iterator insert(iterator pos, const T& val) = 0;
    virtual iterator insert(iterator pos, size_t n, const T& val) = 0;
    virtual iterator erase(iterator pos) = 0;
    virtual iterator erase(iterator first, iterator last) = 0;
    virtual void swap(containerT& x) = 0;
    virtual void clear() = 0;
    virtual T* data() = 0;
    virtual T& operator[](size_t pos) = 0;
};

template<typename T>
class VecWrap : public Container<T, std::vector<T>> {
private:
    std::vector<T> mData;
public:
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;
    using reverse_iterator = typename std::vector<T>::reverse_iterator;
    using const_reverse_iterator = typename std::vector<T>::const_reverse_iterator;

    VecWrap() {}
    VecWrap(std::vector<T> data) : mData(data) {}
    ~VecWrap() {}

    iterator begin() override { return mData.begin(); }
    iterator end() override { return mData.end(); }
    reverse_iterator rbegin() override { return mData.rbegin(); }
    reverse_iterator rend() override { return mData.rend(); }
    size_t size() const override { return mData.size(); }
    size_t max_size() const override { return mData.max_size(); }
    void resize(size_t n, const T& val = T()) override { mData.resize(n, val); }
    size_t capacity() const override { return mData.capacity(); }
    bool empty() const override { return mData.empty(); }
    void reserve(size_t n) override { mData.reserve(n); }
    void shrink_to_fit() override { mData.shrink_to_fit(); }
    void assign(size_t n, const T& val) override { mData.assign(n, val); }
    void assign(iterator first, iterator last) override { mData.assign(first, last); }
    void push_back(const T& val) override { mData.push_back(val); }
    void push_back(T&& val) override { mData.push_back(std::move(val)); }
    void pop_back() override { mData.pop_back(); }
    iterator insert(iterator pos, const T& val) override { return mData.insert(pos, val); }
    iterator insert(iterator pos, size_t n, const T& val) override { return mData.insert(pos, n, val); }
    iterator erase(iterator pos) override { return mData.erase(pos); }
    iterator erase(iterator first, iterator last) override { return mData.erase(first, last); }
    void swap(std::vector<T>& x) override { mData.swap(x); }
    void clear() override { mData.clear(); }
    T* data() { return &mData[0]; }

    T& operator[](size_t pos) override { return mData[pos]; }
};