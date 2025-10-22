#include <iostream>

// Abstract base class for all birds
// This defines what any bird must be able to do
class Bird {
public:
    virtual void lay_egg() = 0;
};

// Interface for birds that can fly
class CanFly {
public:
    virtual void fly() = 0;
};

// Ostrich is a bird, but cannot fly, so it only implements the Bird interface
class Ostrich : public Bird {
public:
    void lay_egg() {
        std::cout << "Ostrich laid an egg\n";
    }
};

// Eagle is a bird AND can fly, so it implements both interfaces
class Eagle : public Bird, public CanFly {
public:
    void lay_egg() {
        std::cout << "Eagle laid an egg\n";
    }
    
    void fly() {
        std::cout << "Eagle is flying\n";
    }
};

// For demonstration
int main() {
    Eagle eagle;
    Ostrich ostrich;
    
    // Both can lay eggs
    eagle.lay_egg();
    ostrich.lay_egg();
    
    // Only eagle can fly
    eagle.fly();
      
    return 0;
}
