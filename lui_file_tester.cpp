#include <iostream>

#include "admin_account.h"
#include "payment_method.h"
using namespace std;
#include "reservation.h"

int main() {
    AdminAccount r;
    r.create();
    r.view();
    r.update();
    r.remove();
    return 0;
}