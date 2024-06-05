#include <gtest/gtest.h>
#include "bridge.h"

TEST(HandsetSoftTest, HandsetGameRun) {
    HandsetGame game;
    EXPECT_NO_THROW(game.run());
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("run game") != std::string::npos);
}

TEST(HandsetSoftTest, HandsetAddressListRun) {
    HandsetAddressList addressList;
    EXPECT_NO_THROW(addressList.run());
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("run addressList") != std::string::npos);
}

TEST(HandsetBrandTest, IphoneRun) {
    Iphone iphone;
    HandsetGame game;
    iphone.setHandsetsoft(&game);
    EXPECT_NO_THROW(iphone.run());
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("run game") != std::string::npos);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

