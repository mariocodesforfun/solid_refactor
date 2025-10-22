#include <iostream>

// defines what any calculators must be able to do
class DiscountCalculator {
public:
    virtual double calculate(double amount) = 0;
};

// only calculates loyal customer discounts (5% off)
class LoyalCustomerDiscountCalculator : public DiscountCalculator {
public:
    double calculate(double amount) {
        return amount * 0.95;
    }
};

// only calculates VIP customer discounts (10% off)
class VIPCustomerDiscountCalculator : public DiscountCalculator {
public:
    double calculate(double amount) {
        return amount * 0.90;
    }
};

// Handles regular customers without any discount
class OtherCustomerDiscountCalculator : public DiscountCalculator {
public:
    double calculate(double amount) {
        return amount;
    }
};

// usage of the discount calculator
class PriceCalculator {
private:
    DiscountCalculator& calculator;
public:
    PriceCalculator(DiscountCalculator& calc) : calculator(calc) {}
    
    double calculateFinalPrice(double price) {
        return calculator.calculate(price);
    }
};

int main() {
    double price = 1000;

    VIPCustomerDiscountCalculator vip;
    LoyalCustomerDiscountCalculator loyal;
    OtherCustomerDiscountCalculator other;

    std::cout << "VIP Customer Price: " << PriceCalculator(vip).calculateFinalPrice(price) << "\n";
    std::cout << "Loyal Customer Price: " << PriceCalculator(loyal).calculateFinalPrice(price) << "\n";
    std::cout << "Other Customer Price: " << PriceCalculator(other).calculateFinalPrice(price) << "\n";
}
