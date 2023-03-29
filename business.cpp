//
// Created by zodia on 28.03.2023.
//

#include <stdexcept>
#include "business.h"

business::business(std::string name, double price,  double profit, unsigned int count): name(name),
    price(price), profit(profit), count(count){
    if(name.empty()) throw std::invalid_argument("Name is empty");
    if(price <= 0) throw std::invalid_argument("Price is invalid");
    if(profit <= 0) throw std::invalid_argument("Profit is invalid");
    if(count < 0) throw std::invalid_argument("Count is 0");
}

unsigned int business::businessGetCount() const{
    return count;
}

long double business::businessGetTotalProfit() const {
    return static_cast<long double>(profit*count);
}

long double business::businessGetPrice() const {
    return price;
}

std::string business::businessGetName()const{
    return name;
}

void business::businessBuy() {
    this->count++;
}

long double business::businessGetProfit() const {
    return static_cast<long double>(profit);
}

void business::businessSetCount(unsigned int count) {
    this->count = count;
}

void business::businessSetName(std::string name) {
    this->name = name;
}

