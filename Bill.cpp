//
// Created by PC on 23/11/2020.
//

#include "Bill.h"

Bill::Bill(const std::string &numberBill, const std::string &dateBill) : numberBill(numberBill), dateBill(dateBill) {}

Bill::Bill() {}

const std::string &Bill::getNumberBill() const {
    return numberBill;
}

void Bill::setNumberBill(const std::string &numberBill) {
    Bill::numberBill = numberBill;
}

const std::string &Bill::getDateBill() const {
    return dateBill;
}

void Bill::setDateBill(const std::string &dateBill) {
    Bill::dateBill = dateBill;
}

const std::vector<Detail *> &Bill::getDetails() const {
    return details;
}
bool Bill::addDetail(Product *product, int amount) {
    if (product->getStock()-amount>=Product::MIN_STOCK){
        Detail *detail= new Detail(details.size()+1, amount, product);
        details.push_back(detail);
        product->setStock(product->getStock()-amount);
        return true;
    }
    return false;
}

double Bill::calcTotal() {
    double totalSale;

    for (Detail* detail: details) {
        totalSale+=detail->calcSubtotal();
    }
    return totalSale;
}

Bill::~Bill() {

}


