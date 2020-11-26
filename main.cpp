#include <iostream>
#include "ServiceSales.h"

using namespace std;

/**
 * Función que se encarga de probar la funcionalidad de buscar productos
 */
void findProduct() {
    ServiceSales* sales = new ServiceSales();
    cout<<"----------------------Buscar Productos----------------"<<endl;

    //Probar Producto Inexistente;
    if( !sales->findProduct("Prd001") ){
        cout<<"Hecho.."<<endl;
    }else{
        cout<<"Fallo en el método de Buscar Producto"<<endl;
    }

    delete( sales );
}

/**
 * Función para probar la funcionalidad de Agregar productos
 */
void addProducts() {
    ServiceSales* sales = new ServiceSales();
    cout<<"----------------------Agregar Productos---------------"<<endl;

    //Probar un Producto nuevo
    if( sales->addProduct("Prd001","Memoria USB 8GB",15000,67 ) ){
        cout<<"Hecho.. Insertado Prd001"<<endl;
    }else{
        cout<<"Fallo.. no se Insertar Prd001"<<endl;
    }

    //Probar Producto existente
    if( !sales->addProduct("Prd001","Aceleradora de Viodeo",320000,12 ) ){
        cout<<"Hecho.. Ya Existe Prd001"<<endl;
    }else{
        cout<<"Fallo.. Prd001 ya Existe"<<endl;
    }

    //Agregar dos productos;
    sales->addProduct("Prd010","Aceleradora de Video",320000,12 );
    sales->addProduct("Prd050","Mouse Inalambrico",23000,32 );

    //Probar que se han agregado tres productos
    if( 3 == sales->getProducts().size()){
        cout<<"Hecho.. Se han Agregado Tres Productos"<<endl;
    }else{
        cout<<"Fallo.. Se esperaba 3"<<endl;
    }

    delete(sales);
}

/**
 * Función para probar funcionalidad de Buscar Facturas
 */
void findBill() {
    ServiceSales* sales = new ServiceSales();
    cout<<"----------------------Buscar Facturas---------------"<<endl;

    if( !sales->findBill( "3453") ){
        cout<<"Hecho.. La Factura No Existe"<<endl;
    }else{
        cout<<"Fallo.. en el Método Buscar Factura"<<endl;
    }

    delete(sales);
}

/**
 * Función para la Pruebas de la Funcionalidad de Agregar Facturas
 */

void addBills() {
    ServiceSales* sales = new ServiceSales();
    cout<<"----------------------Agregar Facturas---------------"<<endl;

    if( sales->addBill( "2369","2019-10-23")){
        cout<<"Hecho... Se Inserta la Factura 2369"<<endl;
    }else{
        cout<<"Fallo... No se Insertó la Factura 2369"<<endl;
    }

    if( !sales->addBill( "2369","2020-11-21")){
        cout<<"Hecho... La Factura 2369 ya Existe"<<endl;
    }else{
        cout<<"Fallo... La Factura 2369 ya Existe"<<endl;
    }

    sales->addBill( "83474","2020-11-21");
    sales->addBill( "63644","2020-11-21");

    if( 3 == sales->getBills().size() ){
        cout<<"Hecho.. Existen tres Facturas"<<endl;
    }else{
        cout<<"Fallo... Se Esperaban tres Facturas"<<endl;
    }

    delete(sales);
}

/**
 * Función que verifica que se agreguen detalles a las Facturas, validando existencias..
 */
void addSales() {
    ServiceSales* sales = new ServiceSales();
    cout<<"----------------------Agregar Ventas---------------"<<endl;

    //Se agregan los Productos
    sales->addProduct("prd010","Memoria USB 8 GB",15000,45);
    sales->addProduct("prd020","Disco Duro Externo 1 TB",230000,13);
    sales->addProduct("prd030","Aceleradora de Video",350000,8);
    sales->addProduct("prd040","Teclado USB",27000,19);
    sales->addProduct("prd050","Mouse Inalambrico",20000,28);

    if( sales->getProducts().size() == 5 ){
        cout<<"Hecho.. Se han insertado 5 Productos"<<endl;
    }else{
        cout<<"Fallo No se Insertaron los Productos"<<endl;
    }

    //Insertar las Facturas
    sales->addBill("6972","2019-06-25");
    sales->addBill("4335","2020-11-21");
    sales->addBill("9384","2020-11-21");

    if( sales->getBills().size() == 3 ){
        cout<<"Hecho.. Se han insertado 3 Facturas"<<endl;
    }else{
        cout<<"Fallo No se Insertaron las Facturas"<<endl;
    }

    //Probar Agregar detalle de Ventas a las Facturas
    //No se agrega por Existencias
    if( !sales->addDetail( sales->findBill("6972"),  sales->findProduct("prd020"), 10 )  ){
        cout<<"Hecho... El Producto no Tiene suficiente Existencias"<<endl;
    }else{
        cout<<"Fallo.. Se Esperaba Verdadero"<<endl;
    }

    //Agregar Detalles a la Factura 6972
    sales->addDetail( sales->findBill("6972"),  sales->findProduct("prd020"), 1 );
    sales->addDetail( sales->findBill("6972"),  sales->findProduct("prd050"), 2 );

    //Probar el Total de la Factura 6972 --> 270000
    if( 270000 == sales->findBill("6972")->calcTotal()){
        cout<<"Hecho.. El Total de la Factura 6972 es 270000"<<endl;
    }else{
        cout<<"Fallo... Se esperaba 270000"<<endl;
    }

    //Agregar Detalles a la Factura 4335
    sales->addDetail( sales->findBill("4335"),  sales->findProduct("prd030"), 1 );
    sales->addDetail( sales->findBill("4335"),  sales->findProduct("prd010"), 5 );
    sales->addDetail( sales->findBill("4335"),  sales->findProduct("prd040"), 2 );

    //Probar el Total de la Factura 4335 --> 479000
    if( 479000 == sales->findBill("4335")->calcTotal()){
        cout<<"Hecho.. El Total de la Factura 4335 es 479000"<<endl;
    }else{
        cout<<"Fallo... Se esperaba 479000"<<endl;
    }

    //Agregar Detalles a la Factura 9384
    sales->addDetail( sales->findBill("9384"),  sales->findProduct("prd010"), 10 );
    sales->addDetail( sales->findBill("9384"),  sales->findProduct("prd020"), 1 );
    sales->addDetail( sales->findBill("9384"),  sales->findProduct("prd030"), 1 );
    sales->addDetail( sales->findBill("9384"),  sales->findProduct("prd040"), 5 );


    //Probar el Total de la Factura 9384 --> 865000
    if( 865000 == sales->findBill("9384")->calcTotal()){
        cout<<"Hecho.. El Total de la Factura 4335 es 865000"<<endl;
    }else{
        cout<<"Fallo... Se esperaba 865000"<<endl;
    }

    //Probar si se actualizaron las existencias de los Productos
    if( 30 == sales->findProduct("prd010")->getStock()){
        cout<<"Hecho.. Se actualizaron las Existencias"<<endl;
    }else{
        cout<<"Fallo.. Las Existencias no Coinciden -->"<<sales->findProduct("prd010")->getStock()<<endl;
    }

    if( 6 == sales->findProduct("prd030")->getStock()){
        cout<<"Hecho.. Se actualizaron las Existencias"<<endl;
    }else{
        cout<<"Fallo.. Las Existencias no Coinciden -->"<<sales->findProduct("prd030")->getStock()<<endl;
    }

    //Probar el Total de la Facturación de la Empresa-->1614000
    if(1614000 == sales->getTotalSales()){
        cout<<"Hecho.. La Facturación Total es OK"<<endl;
    }else{
        cout<<"Fallo.., Se eseperaba "<<sales->getTotalSales()<<" de Facturacion Total"<<endl;
    }

    delete(sales);
}

int main() {

    findProduct();
    addProducts();
    findBill();
    addBills();
    addSales();

    return 0;
}