//
// Created by PC on 23/11/2020.
//

#ifndef SALESMANAGEMENT_PRODUCT_H
#define SALESMANAGEMENT_PRODUCT_H


#include <string>
#include <ostream>


class Product {
public:

    Product(const std::string &idProduct, const std::string &description, double value, short stock);

    Product();

    const std::string &getIdProduct() const;

    void setIdProduct(const std::string &idProduct);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    double getValue() const;

    void setValue(double value);

    short getStock() const;

    void setStock(short stock);

    friend std::ostream &operator<<(std::ostream &os, const Product &product);

    virtual ~Product();

    const static int MIN_STOCK = 5;

private:
    std::string idProduct;
    std::string description;
    double value;
    short int stock;

};


#endif //SALESMANAGEMENT_PRODUCT_H
