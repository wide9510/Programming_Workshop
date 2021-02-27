#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include "catch.hpp"
#include "Counter.hpp"

struct product{
    std::string name;
    double price;

    bool operator==(const product &p) const {
        return (p.name.compare(name) == 0) && (std::abs(price - p.price) < .0000001);
    }

    bool operator<( const product &p)  const {
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


//NOTE: Constructor  is tested by calling methods on it

TEST_CASE("Count Functions Work", "[Count]"){

    std::vector<product> products = createProducts();
    std::vector<std::string> strings{"Hello","World","Hello", "Computer","Computer","Computer"};
    std::vector<int> nums{1,1,2,2,2,3,4,4};


    Counter<product> c1(products);
    Counter<std::string> c2(strings);
    Counter<int> c3(nums);

    SECTION("Count method no parameters"){
        REQUIRE( c1.Count() == 6);
        REQUIRE( c2.Count() == 6);
        REQUIRE( c3.Count() == 8);
    }

    SECTION("Count method 1 parameter"){
        REQUIRE( c1.Count(products[3]) == 3); //products[3] = {Eggs,1.1}
        REQUIRE( c2.Count("Hello") == 2);
        REQUIRE( c3.Count(3) == 1);
    }

    SECTION("Count method 2 parameter"){
        REQUIRE( c1.Count(products[1],products[3]) == 1); //products[1] = (Milk,1.5) products[3] = {Eggs,1.1}
        REQUIRE( c2.Count("Computer","World") == 5);
        REQUIRE( c3.Count(3,5) == 3);
    }

}

TEST_CASE("Removed object from Counter","[Remove]"){
    std::vector<product> products = createProducts();
    std::vector<std::string> strings{"Hello","World","Hello", "Computer","Computer","Computer"};
    std::vector<int> nums{1,1,2,2,2,3,4,4};

    Counter<product> c1(products);
    Counter<std::string> c2(strings);
    Counter<int> c3(nums);
    std::cout << c2;
    std::cout << c1;
    std::cout << c3;
    c1.Remove(products[3]); //products[3] = {Eggs,1.1}
    c2.Remove("Computer");
    c3.Remove(3);

    REQUIRE( c1.Count(products[3]) == 0);
    REQUIRE( c2.Count("Computer") == 0);
    REQUIRE( c3.Count(3) == 0);


}

TEST_CASE("Increment works", "[Increment]"){
    std::vector<product> products = createProducts();
    std::vector<std::string> strings{"Hello","World","Hello", "Computer","Computer","Computer"};
    std::vector<int> nums{1,1,2,2,2,3,4,4};

    Counter<product> c1(products);
    Counter<std::string> c2(strings);
    Counter<int> c3(nums);

    SECTION("Increment by 1"){
        c1.Increment(products[3]);
        c2.Increment("World");
        c3.Increment(3);

        REQUIRE( c1.Count(products[3]) == 4);
        REQUIRE( c2.Count("World") == 2);
        REQUIRE( c3.Count(3) == 2);
    }
    SECTION("Increment by n"){
        c1.Increment(products[3],2);
        c2.Increment("World",5);
        c3.Increment(3,3);

        REQUIRE( c1.Count(products[3]) == 5);
        REQUIRE( c2.Count("World") == 6);
        REQUIRE( c3.Count(3) == 4);
    }


}

TEST_CASE("Decrement works", "[Decrement]"){
    std::vector<product> products = createProducts();
    std::vector<std::string> strings{"Hello","World","Hello", "Computer","Computer","Computer"};
    std::vector<int> nums{1,1,2,2,2,3,4,4};

    Counter<product> c1(products);
    Counter<std::string> c2(strings);
    Counter<int> c3(nums);

    SECTION("Decrement by 1"){
        c1.Decrement(products[3]);
        c2.Decrement("World");
        c3.Decrement(2);

        REQUIRE( c1.Count(products[3]) == 2);
        REQUIRE( c2.Count("World") == 0); //test that it will hit 0
        REQUIRE( c3.Count(2) == 2);
    }
    SECTION("Decrement by n"){
        c1.Decrement(products[3],2);
        c2.Decrement("World",0);
        c3.Decrement(2,3); //test that count wont go lower than 0

        REQUIRE( c1.Count(products[3]) == 1);
        REQUIRE( c2.Count("World") == 1);
        REQUIRE( c3.Count(2) == 0);
    }


}

TEST_CASE("Most and Least Common work", "[Common]"){
    std::vector<product> products = createProducts();
    std::vector<std::string> strings{"Hello","World","Hello", "Computer","Computer","Computer"};
    std::vector<int> nums{1,1,2,2,2,3,4,4};

    Counter<product> c1(products);
    Counter<std::string> c2(strings);
    Counter<int> c3(nums);

    std::vector<product> mostCommon1{products[3],products[0]};
    std::vector<std::string> mostCommon2{"Computer","Hello","World"};
    std::vector<int> mostCommon3{2,4,1};

    std::vector<product> leastCommon1{products[1],products[0]};
    std::vector<std::string> leastCommon2{"World","Hello"};
    std::vector<int> leastCommon3{3,1,4};

    SECTION("Most Common"){
        REQUIRE( c1.MostCommon() == products[3]);
        REQUIRE( c2.MostCommon() == "Computer");
        REQUIRE( c3.MostCommon() == 2);
    }
    SECTION("N Most Common"){
        REQUIRE( c1.MostCommon(2) == mostCommon1);
        REQUIRE( c2.MostCommon(4) == mostCommon2);
        REQUIRE( c3.MostCommon(3) == mostCommon3);
    }
    SECTION("Least Common"){
        REQUIRE( c1.LeastCommon() == products[1]);
        REQUIRE( c2.LeastCommon() == "World");
        REQUIRE( c3.LeastCommon() == 3);
    }
    SECTION("N Least Common"){
        REQUIRE( c1.LeastCommon(2) == leastCommon1);
        REQUIRE( c2.LeastCommon(2) == leastCommon2);
        REQUIRE( c3.LeastCommon(3) == leastCommon3);
    }
}

TEST_CASE("Normalization works", "[Normal]"){
    std::vector<product> products = createProducts();
    std::vector<std::string> strings{"Hello","World","Hello", "Computer","Computer","Computer"};
    std::vector<int> nums{1,1,2,2,2,3,4,4};

    Counter<product> c1(products);
    Counter<std::string> c2(strings);
    Counter<int> c3(nums);

    product p1;
    p1.name = "Apple";
    p1.price = .25;

    product p2;
    p2.name = "Milk";
    p2.price = 1.50;

    product p3;
    p3.name = "Eggs";
    p3.price = 1.1;

    std::map<product,double> normal1 = {{p2, 1/6.0},{ p3, 3/6.0},{p1, 2/6.0}};
    std::map<int,double> normal3 = {{1,0.250},{2,0.375},{3,0.125},{4,0.250}};

    REQUIRE(c3.Normalized() == normal3); //test with int
    std::map<product,double> norm = c1.Normalized();
    for (std::pair<product, double> pair : norm) {

        REQUIRE( pair.second == normal1[pair.first]); //test with user defined
    }
    
}

TEST_CASE("Keys","[Keys]"){
    std::vector<product> products = createProducts();
    std::vector<std::string> strings{"Hello","World","Hello", "Computer","Computer","Computer"};
    std::vector<int> nums{1,1,2,2,2,3,4,4};

    Counter<product> c1(products);
    Counter<std::string> c2(strings);
    Counter<int> c3(nums);

    std::set<product> keys1{products[1],products[0],products[3]};
    std::set<std::string> keys2{"Computer","Hello","World"};
    std::set<int> keys3{1,2,3,4};
    REQUIRE(c1.Keys() == keys1);
    REQUIRE(c2.Keys() == keys2);
    REQUIRE(c3.Keys() == keys3);
}

TEST_CASE("Values","[Values]"){
    std::vector<product> products = createProducts();
    std::vector<std::string> strings{"Hello","World","Hello", "Computer","Computer","Computer"};
    std::vector<int> nums{1,1,2,2,2,3,4,4};

    Counter<product> c1(products);
    Counter<std::string> c2(strings);
    Counter<int> c3(nums);

    std::vector<int> values1{1,3,2};
    std::vector<int> values2{3,2,1};
    std::vector<int> values3{2,3,1,2};

    REQUIRE(c1.Values() == values1);
    REQUIRE(c2.Values() == values2);
    REQUIRE(c3.Values() == values3);
}