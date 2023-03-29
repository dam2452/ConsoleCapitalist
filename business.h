//
// Created by zodia on 28.03.2023.
//

#ifndef CC2_BUSINESS_H
#define CC2_BUSINESS_H


#include <string>

class business {
public:
    business(std::string name = {}, double price = 1.0, double profit = 1.0, unsigned int count= 0);

    ~business() = default;

    void businessBuy();

    std::string  businessGetName()const;

    long double businessGetPrice() const;

    long double businessGetTotalProfit() const;

    long double businessGetProfit() const;

    unsigned int businessGetCount() const;

  //  void businessSetProfit(long double profit);

  //  void businessSetPrice(long double price);
    void businessSetName(std::string name);

    void businessSetCount(unsigned int count);





private:
    std::string name;
    long double price;
    long double profit;
    unsigned int count;


};


#endif //CC2_BUSINESS_H
