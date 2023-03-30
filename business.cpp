#include <stdexcept>
#include <utility>
#include "business.h"

business::business(const std::string& name, double price, double profit, unsigned int count) : name(name),
                                                                                        price(price), profit(profit),
                                                                                        count(count) {
    if (name.empty()) throw std::invalid_argument("Name is empty");
    if (price <= 0) throw std::invalid_argument("Price is invalid");
    if (profit <= 0) throw std::invalid_argument("Profit is invalid");
}

void business::businessBuy() {
    this->count++;
}

unsigned int business::businessGetCount() const {
    return count;
}

long double business::businessGetTotalProfit() const {
    return static_cast<long double>(profit * count);
}

long double business::businessGetPrice() const {
    return price;
}

std::string business::businessGetName() const {
    return name;
}

long double business::businessGetProfit() const {
    return static_cast<long double>(profit);
}

void business::businessSetCount(unsigned int countToSet) {
    this->count = countToSet;
}

void business::businessSetName(std::string nameToSet) {
    this->name = std::move(nameToSet);
}

