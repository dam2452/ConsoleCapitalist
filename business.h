#ifndef CC2_BUSINESS_H
#define CC2_BUSINESS_H


#include <string>

class business {
public:
    business(const std::string& name = {}, double price = 1.0, double profit = 1.0, unsigned int count = 0);

    ~business() = default;

    void businessBuy();

    //Getters
    [[nodiscard]] std::string businessGetName() const;

    [[nodiscard]] long double businessGetPrice() const;

    [[nodiscard]] long double businessGetTotalProfit() const;

    [[nodiscard]] long double businessGetProfit() const;

    [[nodiscard]] unsigned int businessGetCount() const;

    //Setters
    void businessSetName(std::string nameToSet);

    void businessSetCount(unsigned int countToSet);


private:
    std::string name;
    long double price;
    long double profit;
    unsigned int count;
};


#endif //CC2_BUSINESS_H
