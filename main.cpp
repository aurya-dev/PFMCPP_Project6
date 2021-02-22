/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const std::string c) : value(v), name(c) {}   //1
    int value;
    std::string name; 
};

struct Struct1                                //4
{
    T* compare( T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &a;
        return &a;   // Added to remove the compiler warnings "control may reach end of non-void function [-Wreturn-type]"
    }
};

struct U
{
    float name1 { 30 }, name2 { 20 };
    float memberFunction(const float& updatedValue)      //12
    {

        std::cout << "U's name1 value: " << name1 << std::endl;
        name1 = updatedValue;
        std::cout << "U's name1 updated value: " << name1 << std::endl;
        while( std::abs(name2 - name1) > 0.001f )
        {
            name1 -= .5f;
            name2 -= 1.0f;
        }
        std::cout << "U's name2 updated value: " << name2 << std::endl;
        return name2 * name1;   
    }
};

struct Struct2
{
    static float staticFunctionA(U& that, const float& updatedValue )        //10
    {
        std::cout << "U's name1 value: " << that.name1 << std::endl;
        that.name1 = updatedValue;
        std::cout << "U's name1 updated value: " << that.name1 << std::endl;
        while( std::abs(that.name2 - that.name1) > 0.001f )
        {
            that.name1 -= .5f;
            that.name2 -= 1.0f;
        }
        std::cout << "U's name2 updated value: " << that.name2 << std::endl;
        return that.name2 * that.name1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(10 , "a");                                             //6
    T t2(20 , "b");                                             //6
    
    Struct1 f;                                            //7
    auto* smaller = f.compare(t1, t2); 
    std::cout << "the smaller one is << " << smaller->name << std::endl; //9 
    
    U u3;
    float updatedValue = 5.f;
    std::cout << "[static func] u3's multiplied values: " << Struct2::staticFunctionA(u3 , updatedValue) << std::endl;                  //11
    
    U u4;
    std::cout << "[member func] u4's multiplied values: " << u4.memberFunction( updatedValue ) << std::endl;

    std::cout << "- complete -" << std::endl;
    
}

        
        
        
        
        
        
        
