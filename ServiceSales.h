//
// Created by PC on 23/11/2020.
//

#ifndef SALESMANAGEMENT_SERVICESALES_H
#define SALESMANAGEMENT_SERVICESALES_H

#include "Product.h"
#include "Bill.h"

class ServiceSales {

public:

    ServiceSales();

    Product* findProduct(std::string id);

    bool addProduct(std::string idProduct, std::string description, double value, int stock);

    Bill* findBill(std::string numberBill);

    bool addBill(std::string numberBill, std::string dateBill);

    bool addDetail(Bill* bill, Product* product, short int amount);

    const std::vector<Product *> getProducts() const;

    const std::vector<Bill *> getBills() const;

    double getTotalSales();

    virtual ~ServiceSales();


private:

    std::vector<Product*> products;

    std::vector<Bill*> bills;


};


#endif //SALESMANAGEMENT_SERVICESALES_H
