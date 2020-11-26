//
// Created by PC on 23/11/2020.
//

#include "ServiceSales.h"

ServiceSales::ServiceSales() {}

Product *ServiceSales::findProduct(std::string id) {
    for (Product *product: products){
        if (product->getIdProduct().compare(id)==0){
            return product;
        }
    }
    return NULL;
}

bool ServiceSales::addProduct(std::string idProduct, std::string description, double value, int stock) {
    if (findProduct(idProduct)==NULL){
        Product *product=new Product(idProduct,description,value,stock);
        products.push_back(product);
        return true;
    }

    return false;
}

Bill *ServiceSales::findBill(std::string numberBill) {
    for(Bill *bill: bills){
        if (bill->getNumberBill().compare(numberBill)==0){
            return bill;
        }
    }
    return NULL;

}

bool ServiceSales::addBill(std::string numberBill, std::string dateBill) {
   if (findBill(numberBill)==NULL){
       Bill *billTwo=new Bill(numberBill, dateBill);
       bills.push_back(billTwo);
       return true;
   }
    return false;
}

bool ServiceSales::addDetail(Bill *bill, Product *product, short amount) {
    Bill *billOne=findBill(bill->getNumberBill());
    if (billOne!=NULL&&findProduct(product->getIdProduct())!=NULL){
        if(billOne->addDetail(product, amount)){
            return true;
        }else{
            return false;
        }

    }

    return false;
}

double ServiceSales::getTotalSales() {
    double totalSales;
    for(Bill *bill: bills){
        totalSales+=bill->calcTotal();
    }

    return totalSales;
}


const std::vector<Product *> ServiceSales::getProducts() const {
    return products;
}

const std::vector<Bill *> ServiceSales::getBills() const {
    return bills;
}

ServiceSales::~ServiceSales() {

}

//fin de mi parcial

