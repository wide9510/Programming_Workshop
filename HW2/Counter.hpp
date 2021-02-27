#ifndef COUNTER_HPP
#define COUNTER_HPP
#include <map>
#include <set>
#include <iterator>
#include <iostream>
#include <stdexcept>

struct compare { 
    template <typename T> 
  
    // Comparator function 
    bool operator()(const T& l, 
                    const T& r) const
    { 
        if (l.second != r.second) { 
            return l.second < r.second; 
        } 
        return l.first < r.first; 
    } 
};

template <class T>
class Counter {
    public:

        Counter(){
            counter_ = std::map<T, int>();
        }
        /** initialize a Counter<T> appropriately from a vector or array that contains type T
         * 
         * @param vals vector of values you want to make a counter on
         * 
        */
        Counter(std::vector<T> vals){
            for (int i = 0; i < vals.size();i++) {
                counter_[vals[i]]++;
            }
        }

        //return the total of all counts in the Counter
        int Count(){
            int total = 0;
            for (std::pair<T, int> pair : counter_ ) {
                total += pair.second;
            }
            return total;
        }
        /** return the count for the key
         * 
         * @param key key you want count for
         * @return the keys value
        */
        int Count(T key){
            for (std::pair<T, int> pair : counter_) {
                if(pair.first == key){
                    return pair.second; //change back
                }
            }
            return 0;
        }
        /** access the total of all counts for objects T given a certain range (an inclusive minimum T and an exclusive maximum T element)
         * 
         * @param min beginning of range(inclusive)
         * @param max end of range(exclusive)
         * @return total of counts in range
        */
        int Count(T min, T max){
            // check that position of min is less than position of max
            //check that min and max exist
            bool sum = false;
            int total = 0;
            for (std::pair<T, int> pair : counter_ ) {
                if(pair.first == min){
                    sum = true;
                }
                if(pair.first == max){
                    sum = false;
                }
                if(sum == true){
                    total += pair.second;
                }
            }
            return total;
        }
        //remove key from Counter
        void Remove(T key){
            counter_.erase(counter_.find(key));
        }
        //increment key by 1
        void Increment(T key){
            counter_[key]++;
        }
        /** increment key by n
         * 
         * @param key key to be incremented
         * @param n amount to be added
        */
        void Increment(T key, int n){
            counter_[key] += n;
        }
        // decrement key by 1
        void Decrement(T key){
            if(counter_[key] >= 1){
                counter_[key]--;
            }
        }
        /** decrement key by n
         * 
         * @param key key to be decremented
         * @param n amount to be subtracted
        */
        void Decrement(T key, int n){
            int newVal = counter_[key] - n;
            if(newVal >= 0){
                counter_[key] -= n;
            }
            else{
                counter_[key] = 0;
            }
        }

        // return the key of the pair with the largest count
        T MostCommon(){
            if(counter_.empty()){
                throw std::domain_error ("Counter is empty");
            }
            std::pair<T,int> mostCommon;
            int max = 0;
            for (std::pair<T, int> pair : counter_) {
                if(pair.second > max){
                    mostCommon = pair;
                    max = pair.second;
                }
            }
            return mostCommon.first;

        }
        /** return the top n keys
         * 
         * @param n number of keys you want
         * @return vector of most common keys
        */
        std::vector<T> MostCommon(int n){
            int counter = 0;
            std::vector<T> common;
            std::set<std::pair<T,int>, compare> set(counter_.begin(), counter_.end());
            //typename std::set<T>::iterator it = set.begin();
            typename std::set<std::pair<T,int>, compare>::reverse_iterator revIt = set.rbegin();
            while (revIt != set.rend()){
                // std::cout << revIt->first << std::endl;
                if(counter < n){
                    common.push_back(revIt->first);
                }
                counter++;
                revIt++;
            }   
            return common;
        } 
        //return the least common key
        T LeastCommon(){
            if(counter_.empty()){
                throw std::domain_error ("Counter is empty");
            }
            std::pair<T,int> mostCommon;
            int max = INT16_MAX;
            for (std::pair<T, int> pair : counter_) {
                if(pair.second < max){
                    mostCommon = pair;
                    max = pair.second;
                }
            }
            return mostCommon.first;
        }
        /** return the least common n keys
         * 
         * @param n number of keys you want
         * @return vector of least common keys
        */
        std::vector<T> LeastCommon(int n){
            int counter = 0;
            std::vector<T> common;
            std::set<std::pair<T,int>, compare> set(counter_.begin(), counter_.end());
            typename std::set<std::pair<T,int>, compare>::iterator it = set.begin();
            while (it != set.end()){
                // std::cout << revIt->first << std::endl;
                if(counter < n){
                    common.push_back(it->first);
                }
                counter++;
                it++;
            }   
            return common;
        }

        //returns the set of keys from the counter
        std::set<T> Keys(){
            std::set<T> keys;
            for (std::pair<T, int> pair : counter_) {
                keys.insert(pair.first);
            }
            return keys;
        }
        //return the set of values from the counter
        std::vector<int> Values(){
            std::vector<int> values;
            for (std::pair<T, int> pair : counter_) {
                values.push_back(pair.second);
            }
            return values;
        }
        // return a map with the count as percentage of total
        std::map<T,double> Normalized(){
            double total = Count();
            std::map<T, double> normalized;
            for (std::pair<T, int> pair : counter_) {
                normalized.insert(std::pair<T, double>(pair.first,pair.second/total));
            }
            return normalized;
        }
        //override that good ol' output
        friend std::ostream& operator<< (std::ostream& os, const Counter<T> &b){
            int counter = 0;
            os << "{";
            for (std::pair<T, int> pair : b.counter_) {
                os << pair.first << ":" << pair.second << ",";
                // if(counter != (b.counter_.size()-1)){
                //     os << ", ";
                // }
                counter++;
            }
            os << "}" << std::endl;
            return os;
            
        }

    private:
        std::map<T,int> counter_;

};

#endif