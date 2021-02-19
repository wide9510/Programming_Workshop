template <class T>
class Counter {
    public:

        Counter(){ counter_};

        Counter(std::vector<T> vals){
            
        }

        int Count(){

        }

        int Count(T key);
        int Count(T min, T max);

        void Remove(T key);

        void Increment(T key);
        void Increment(T key, int n);

        void Decrement(T key);
        void Decrement(T key, int n); 

        T MostCommon();
        std::vector<T> MostCommon(int n); 

        T LeastCommon();
        std::vector<T> LeastCommon(int n);

        std::map<T, double> Normalized(); 

        std::set<T> Keys(); 
        std::vector<int> Values();

        std::ostream& operator<<(std::ostream& os, const Counter<U> &b);
    
    private:
        Counter<T> counter_;
        std::map<std::string, double> words_to_numbers;
};