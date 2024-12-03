#include <iostream>

#include "payment_method.h"
using namespace std;
#include "reservation.h"

int main() {
    Reservation r;
    r.create();
    r.view();
    r.update();
    r.remove();
    return 0;
}