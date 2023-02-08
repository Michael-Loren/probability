#include "bayes.hpp"
using namespace std;
namespace pandas{
    void NaiveBayes::train(const std::vector<std::vector<int>> &features, const std::vector<int> &labels)
    {
        total_count = labels.size();
        num_features = features[0].size();
        
        for (int i = 0; i < features.size(); i++)
        {
            int label = labels[i];
            class_counts[label]++;

            for (int j = 0; j < features[i].size(); j++)
            {
                int feature = features[i][j];
                feature_counts[label][feature]++;
            }
        }
    }

    int NaiveBayes::predict(const std::vector<int> &features)
    {
        int best_label = -1;
        double best_prob = -1.0;

        for (auto &[label, count] : class_counts)
        {
            double prob = std::log(count / total_count);

            for (int feature : features)
            {
                prob += std::log((feature_counts[label][feature] + 1.0) / (count + num_features));
            }

            if (prob > best_prob)
            {
                best_prob = prob;
                best_label = label;
            }
        }

        return best_label;
    }
};