/**************************************************************************/
/*  stats.hpp                                                             */
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

#ifndef STATS_HPP
#define STATS_HPP

#include <algorithm>
#include <cfloat>
#include <cmath>

class StatsAccumulator {
private:
    float sum;
    float sum_of_squares;
    float max_value;
    float min_value;
    int count;

public:
    StatsAccumulator()
        : sum(0.0f), sum_of_squares(0.0f), max_value(-INFINITY), min_value(INFINITY), count(0) {
    }

    void add_sample(float sample) {
        sum += sample;
        sum_of_squares += sample * sample;
        max_value = std::max(max_value, sample);
        min_value = std::min(min_value, sample);
        count++;
    }

    float get_mean() const {
        return sum / count;
    }

    float get_max() const {
        return max_value;
    }

    float get_min() const {
        return min_value;
    }

    float get_standard_deviation() const {
        float mean = get_mean();
        return sqrt(sum_of_squares / count - mean * mean);
    }

    void reset() {
        sum = 0.0f;
        sum_of_squares = 0.0f;
        max_value = -INFINITY;
        min_value = INFINITY;
        count = 0;
    }
};

#endif // STATS_HPP
