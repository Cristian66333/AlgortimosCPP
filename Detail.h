//
// Created by PC on 23/11/2020.
//

#ifndef SALESMANAGEMENT_DETAIL_H
#define SALESMANAGEMENT_DETAIL_H

#include "Product.h"


class Detail {

public:

    Detail(short numDetail, short amount, Product *product);

    Detail();

    short getNumDetail() const;

    void setNumDetail(short numDetail);

    short getAmount() const;

    void setAmount(short amount);

    Product *getProduct() const;

    void setProduct(Product *product);

    double calcSubtotal();

    virtual ~Detail();

private:
    short int numDetail;

    short int amount;

    Product *product;

};


#endif //SALESMANAGEMENT_DETAIL_H
