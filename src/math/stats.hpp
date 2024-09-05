#pragma once

#include <algorithm>
#include <cmath>
#include <cfloat>

class StatsAccumulator {
private:
    float sum;
    float sum_of_squares;
    float max_value;
    float min_value;
    int count;

public:
    StatsAccumulator() : sum(0.0f), sum_of_squares(0.0f), max_value(-INFINITY), min_value(INFINITY), count(0) {
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
