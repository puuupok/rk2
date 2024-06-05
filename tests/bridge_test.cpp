#include <gtest/gtest.h>
#include "bridge.h"

TEST(HandsetSoftTest, HandsetGameRun) {
    HandsetGame game;
    ASSERT_NO_THROW(game.run());
    // Проверьте, что метод run() выполняет необходимые действия
}

TEST(HandsetSoftTest, HandsetAddressListRun) {
    HandsetAddressList addressList;
    ASSERT_NO_THROW(addressList.run());
    // Проверьте, что метод run() выполняет необходимые действия
}

TEST(HandsetBrandTest, IphoneRun) {
    Iphone iphone;
    HandsetGame game;
    iphone.setHandsetsoft(&game);
    ASSERT_NO_THROW(iphone.run());
    // Проверьте, что метод run() выполняет необходимые действия
}

int main(int argc, char** argv) {
    try {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception occurred" << std::endl;
        return 1;
    }
}
