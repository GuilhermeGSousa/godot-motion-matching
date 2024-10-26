/**************************************************************************/
/*  circular_buffer.h                                                     */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <cstddef>
#include <deque>
#include <vector>

template <typename T>
class CircularBuffer {

private:
    std::deque<T> buffer;
    size_t max_size;

public:
    explicit CircularBuffer(size_t size)
        : max_size(size) {
    }

    void clear() {
        buffer.clear();
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

    bool is_empty() const {
        return buffer.empty();
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
#endif // CIRCULAR_BUFFER_H
