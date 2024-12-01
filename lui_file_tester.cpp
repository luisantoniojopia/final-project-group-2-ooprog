#include <iostream>

#include "payment_method.h"
using namespace std;
#include "reservation.h"

int main() {
    PaymentMethod pm;
    pm.create();
    pm.view();
    pm.update();
    pm.remove();
    return 0;
}