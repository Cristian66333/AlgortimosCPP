//
// Created by cristian suancha on 23/11/2020.
//

#include "Detail.h"

Detail::Detail(short numDetail, short amount, Product *product) : numDetail(numDetail), amount(amount),
                                                                  product(product) {}

Detail::Detail() {}

short Detail::getNumDetail() const {
    return numDetail;
}

void Detail::setNumDetail(short numDetail) {
    Detail::numDetail = numDetail;
}

short Detail::getAmount() const {
    return amount;
}

void Detail::setAmount(short amount) {
    Detail::amount = amount;
}

Product *Detail::getProduct() const {
    return product;
}

void Detail::setProduct(Product *product) {
    Detail::product = product;
}

double Detail::calcSubtotal() {
    double subTotal=product->getValue()*amount;
    return subTotal;
}


Detail::~Detail() {

}
