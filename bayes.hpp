#ifndef BAYES_HPP
#define BAYES_HPP

#include <iostream>
#include <vector>
#include <string>

#include <map>
#include <random>
#include <algorithm>
#include <boost/dynamic_bitset.hpp>
#include "pandas.hpp"

namespace pandas{
    class NaiveBayes{
        public:
            NaiveBayes();
            void train(const std::vector<std::vector<int>> &features, const std::vector<int> &labels);
            int predict(const std::vector<int> &feature);

        private:
            std::map<int, int> class_counts;
            std::map<int, std::map<int, int>> feature_counts;

            int total_count;
            int num_features;
    };
}
#endif