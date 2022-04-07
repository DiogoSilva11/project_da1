#include <iostream>
#include "gtest/gtest.h"

#include "Classes/Menu.h"

int main(int argc, char **argv) {
    /*
    std::cout << "Running all tests..." << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    */
    Menu menu;
    menu.run();
}
