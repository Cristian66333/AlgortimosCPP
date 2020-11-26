//
// Created by cristian suancha on 23/11/2020.
//

#include "Product.h"

Product::Product(const std::string &idProduct, const std::string &description, double value, short stock) : idProduct(
        idProduct), description(description), value(value), stock(stock) {}

Product::Product() {}

const std::string &Product::getIdProduct() const {
    //esto es un comentario
    return idProduct;
}

void Product::setIdProduct(const std::string &idProduct) {
    //esto es otro comentario
    Product::idProduct = idProduct;
    //esto es otro comentario
    //esto es otro comentario
    //esto es otro comentario
    //esto es otro comentario
    //esto es otro comentario
}

const std::string &Product::getDescription() const {
    return description;
}

void Product::setDescription(const std::string &description) {
    Product::description = description;
}

double Product::getValue() const {
    return value;
}

void Product::setValue(double value) {
    Product::value = value;
}

short Product::getStock() const {
    return stock;
}

void Product::setStock(short stock) {
    Product::stock = stock;
}

std::ostream &operator<<(std::ostream &os, const Product &product) {
    os << "idProduct: " << product.idProduct << " description: " << product.description << " value: " << product.value
       << " stock: " << product.stock;
    return os;
}

Product::~Product() {

}
