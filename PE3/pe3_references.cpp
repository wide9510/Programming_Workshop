#include <iostream>
#include <string.h>

// Name: William Dellinger
//

// Write any functions you need here!
void foo(int *param){
    std::cout << "In foo" << std::endl;
    std::cout << "Value passed in: " << *param << std::endl;  
}

void foo2(int &param){
    std::cout << "In foo2" << std::endl;
    std::cout << "Value passed in: " << param << std::endl; 
}

void foo3(const int &x, int *y){
    *y *= x;
}

class Person{
    public:
    /** Constructor for an object of class Person
    *
    * @param first_name
    * @param last_name
    * @param age
    */
    Person(std::string first_name,std::string last_name,int age): first_name_(first_name),last_name_(last_name),age_(age){}

    //Returns the first name of Person object
    std::string getFirstName(){
        return first_name_;
    }
    //Returns the last name of Person object
    std::string getLastName(){
        return last_name_;
    }
    //Returns the age of Person object
    int getAge(){
        return age_;
    }

    /** Override == operation for comparing Person objects 
     * 
     * @param other reference to another person object that we are comparing to
    */
    bool operator==(const Person &other){
        return ((first_name_ == other.first_name_) && (last_name_ == other.last_name_) && (age_ == other.age_) );
    }
    /** This one was a little creative in order for it to make slight sense
     * Adds two people together to return a 'child' Person that takes the first name of of the object its called on
     * and the last name of the other Person object and finally sets their age to 1
     * @param other reference to the Person object we are adding to object called on
    */  
    Person operator+(const Person &other){
        return (Person(first_name_,other.last_name_,1));
    }

    private:
        std::string first_name_;
        std::string last_name_;
        int age_;
};


int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.
    
    // 1) Declare an int
    int num = 1;

    // 2) Declare a pointer to that int

    int *num_ptr = &num;

    // 3) Increment the int via the pointer
    std::cout << "num_ptr before: " << *num_ptr << std::endl;
    (*num_ptr)++;
    std::cout << "num_ptr after:  " << *num_ptr << std::endl;
    // 4) Declare a reference to your int
    int &num_ref = num;
    // 5) Increment the int via the reference
    std::cout << "num_ref before: " << num_ref << std::endl;
    num_ref++;
    std::cout << "num_ref after: " << num_ref << std::endl;
    // 6) When you increment the int via the variable declared in #1, which
    // variables will be modified to see the changes? (the pointer , reference or both?)
    // Answer: Both variables will be modified

    num++;
    std::cout << "num_ptr before: " << *num_ptr << std::endl;
    std::cout << "num_ptr after:  " << *num_ptr << std::endl;
    std::cout << "num_ref before: " << num_ref << std::endl;
    std::cout << "num_ref after: " << num_ref << std::endl;


    // 7) When you increment the int via the pointer declared in #2, which
    // variables will be modified to see the changes?
    // Answer: All variables will be modified

    (*num_ptr)++;
    std::cout << "num before: " << num << std::endl;
    std::cout << "num after: " << num << std::endl;
    std::cout << "num_ref before: " << num_ref << std::endl;
    std::cout << "num_ref after: " << num_ref << std::endl;

    // 8) When you increment the int via the reference declared in #4, which
    // variables will be modified to see the changes?
    // Answer: All variables will be modified

    num_ref++;
    std::cout << "num before: " << num << std::endl;
    std::cout << "num after:  " << num << std::endl;
    std::cout << "num_ptr before: " << *num_ptr << std::endl;
    std::cout << "num_ptr after:  " << *num_ptr << std::endl;

    // 9) Write a function that takes an int * parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and function call below)

    foo(&num);

    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer: Nope

    //foo(num_ref);


    // 11) Write a function that takes an int & parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and call below)

    foo2(num);

    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer: Nope

    //foo2(num_ptr);

    // 13) Can you pass your reference from #4 to the function from #11?
    // Answer: Yes

    foo2(num_ref);

    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.
    int val = 4;
    int *ptr = &val;
    foo3(3,ptr);
    std::cout << *ptr << std::endl;
    foo3(3,ptr);
    std::cout << *ptr << std::endl;
    foo3(3,ptr);
    std::cout << *ptr << std::endl;

    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer: A return type is specified by the function and return is well defined. 
    //Output parameters are not strictly defined in c++ but we can use a pointer parameter 
    //to update a variable using a void function

    // 16) Create a custom class with at least one private field/class attribute. Overload the == and + operator for this class
    // such that == can be used to compare the objects of the class and + can be used to add
    // 2 objects of the class together. Implement an appropriate constructor for your class.
    // When you overload these operators, the resulting return value should make sense.
    // Instantiate at least 2 objects of this class and perform the == and + operations on them.
    // hint: for operator+, the function signature when implemented as a member function of the Object class is:
    // Object operator+(const Object &other)
    // Answer:

    Person p1("William","Dellinger",21);
    Person p2("Jane","Doe",22);
    Person p3("William","Dellinger",21);

    if(p1 == p3){
        std::cout << "They are indeed the same person" << std::endl;
    }
    else{
        std::cout << "They are different people" << std::endl;
    }
    if(p1 == p2){
        std::cout << "They are indeed the same person" << std::endl;
    }
    else{
        std::cout << "They are different people" << std::endl;
    }
    Person p4 = p1+p2;
    std::cout << "First Name:" << p4.getFirstName() << std::endl;
    std::cout << "Last Name:" << p4.getLastName() << std::endl;
    std::cout << "Age:" << p4.getAge() << std::endl;



    
}
