cmake_minimum_required(VERSION 3.29)
project(sample)

set(CMAKE_CXX_STANDARD 20)

add_executable(sample main.cpp
        menu/base_menu.h
        menu/admin_menu.h
        base_account.h
        base_register_and_log_in.h
        admin_account.h
        user_account.h
        venue.h
        reservation.h
        payment_method.h
        payment_record.h
        report.h
        menu/user_menu.h
        menu/role_menu.h
)
