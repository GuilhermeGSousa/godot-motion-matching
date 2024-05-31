#pragma once

#include <deque>
#include <vector>

template <typename T>
class CircularBuffer {

private:
    std::deque<T> buffer;
    size_t max_size;

public:
    explicit CircularBuffer(size_t size) : max_size(size) {
    }

    void push(T item) {
        if (buffer.size() == max_size) {
            buffer.pop_front();
        }
        buffer.push_back(item);
    }

    T pop() {
        T val = buffer.front();
        buffer.pop_front();
        return val;
    }

    bool empty() const {
        return buffer.empty();
    }

    bool is_full() const {
        return buffer.size() == max_size;
    }

    size_t capacity() const {
        return max_size;
    }

    size_t size() const {
        return buffer.size();
    }

    void resize(size_t size) {
        max_size = size;
        while (buffer.size() > max_size) {
            buffer.pop_front();
        }
    }

    T& operator[](size_t index) {
        return buffer[index];
    }

    const T& operator[](size_t index) const {
        return buffer[index];
    }

    std::vector<T> to_vector() const {
        return std::vector<T>(buffer.begin(), buffer.end());
    }
};