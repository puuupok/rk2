#include <gtest/gtest.h>
#include "bridge.h"

TEST(HandsetSoftTest, HandsetGameRun) {
    HandsetGame game;
    EXPECT_NO_THROW(game.run());
    EXPECT_TRUE(testing::internal::CaptureStdout().find("run game") != std::string::npos);
}

TEST(HandsetSoftTest, HandsetAddressListRun) {
    HandsetAddressList addressList;
    EXPECT_NO_THROW(addressList.run());
    EXPECT_TRUE(testing::internal::CaptureStdout().find("run addressList") != std::string::npos);
}

TEST(HandsetBrandTest, IphoneRun) {
    Iphone iphone;
    HandsetGame game;
    iphone.setHandsetsoft(&game);
    EXPECT_NO_THROW(iphone.run());
    EXPECT_TRUE(testing::internal::CaptureStdout().find("run game") != std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
