//
// Created by PC on 23/11/2020.
//

#ifndef SALESMANAGEMENT_BILL_H
#define SALESMANAGEMENT_BILL_H

#include <string>
#include <vector>

#include "Detail.h"

class Bill {

public:

    Bill(const std::string &numberBill, const std::string &dateBill);

    Bill();

    const std::string &getNumberBill() const;

    void setNumberBill(const std::string &numberBill);

    const std::string &getDateBill() const;

    void setDateBill(const std::string &dateBill);

    bool addDetail(Product *product, int amount);

    double calcTotal();

    const std::vector<Detail *> &getDetails() const;

    virtual ~Bill();


private:

    std::string numberBill;

    std::string dateBill;

    std::vector<Detail*> details;

};


#endif //SALESMANAGEMENT_BILL_H
