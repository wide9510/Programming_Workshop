#include <iostream>
#include <vector>
#include "Counter.hpp"
#include <iterator>
#include <set>
#include <map>

struct product{
    std::string name;
    double price;

    bool operator==(const product &p) const {
        return (p.name.compare(name) == 0) && price == p.price;
    }

    bool operator<(const product &p)  const {
        return (p.name.compare(name) < 0) || ( (p.name.compare(name) == 0) && (price < p.price));
    } 

    friend std::ostream& operator<< (std::ostream& os, const product &p){
        os << "(" << p.name << "," << p.price << ")";
        return os;
        
    }
};

std::vector<product> createProducts(){
    std::vector<product> products;
    
    product p1;
    p1.name = "Apple";
    p1.price = .25;

    product p2;
    p2.name = "Milk";
    p2.price = 1.50;

    product p3;
    p3.name = "Apple";
    p3.price = .25;

    product p4;
    p4.name = "Eggs";
    p4.price = 1.1;

    product p5;
    p5.name = "Eggs";
    p5.price = 1.1;

    product p6;
    p6.name = "Eggs";
    p6.price = 1.1;

    products.push_back(p1);
    products.push_back(p2);
    products.push_back(p3);
    products.push_back(p4);
    products.push_back(p5);
    products.push_back(p6);

    return products;
}

int main(){
    std::vector<int> nums{1,1,1,1,1,1,2,2,2,3,3,3,4,4};
    // std::vector<int> mostCommon;
    // std::map<int,double> norm;
    // Counter<int> c(nums);
    // // std::cout << c.Count() << std::endl;
    // // // std::cout << "Hello" << std::endl;
    // // mostCommon = c.MostCommon(2);
    // // for(int i= 0; i < mostCommon.size();i++){
    // //     std::cout << mostCommon[i] << std::endl;
    // // }
    // // norm = c.Normalized();
    // // for (std::pair<int, double> pair : norm){
    // //     std::cout << pair.first << " , " << pair.second << std::endl;
    // // }
    // // std::set<int> keys = c.Keys();
    // // std::vector<int> values = c.Values();
    // // for(int i = 0; i < values.size();i++){
    // //     std::cout << values[i] << std::endl;
    // // }
    // // for (auto& it : keys) { 
    // //     std::cout << it << std::endl;
    // // }
    // std::cout << c; 

    Counter<int> c(nums);
    // std::cout << c;
    // c.Remove(products[3]);
    // std::cout << c; 

    // std::map<product,double> norm;
    // norm = c.Normalized();
    // for (std::pair<product, double> pair : norm){
    //     std::cout << pair.first << " , " << pair.second << std::endl;
    // }
    std::cout << c;
    c.Decrement(1,8);
    c.Decrement(3,3);
    std::cout << c;

}