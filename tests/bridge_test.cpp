#include <gtest/gtest.h>
#include "bridge.cpp" 

TEST(bridgeTest, GameRunTest) {
    HandsetBrand* iphone = new Iphone();
    iphone->setHandsetsoft(new HandsetGame());
    testing::internal::CaptureStdout();
    iphone->run();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "run game\n");
    delete iphone;
}

TEST(bridgeTest, AddressListRunTest) {
    HandsetBrand* android = new Android();
    android->setHandsetsoft(new HandsetAddressList());
    testing::internal::CaptureStdout();
    android->run();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "run addressList\n");
    delete android;
}

TEST(bridgeTest, NullHandsetSoftTest) {
    HandsetBrand* brand = new Iphone();
    testing::internal::CaptureStdout();
    brand->run();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
    delete brand;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

