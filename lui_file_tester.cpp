#include <iostream>

#include "payment_method.h"
using namespace std;
#include "reservation.h"

int main() {
    Reservation h;
    h.create();
    h.view();
    h.update();
    h.remove();
    return 0;
}