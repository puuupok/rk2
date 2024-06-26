#include <gtest/gtest.h>
#include "bridge.h"

TEST(IphoneTest, RunGame) {
    HandsetBrand* iphone = new Iphone();
    iphone->setHandsetsoft(new HandsetGame());
    testing::internal::CaptureStdout();
    iphone->run();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "run game\n");
    delete iphone;
}

TEST(AndroidTest, RunAddressList) {
    HandsetBrand* android = new Android();
    android->setHandsetsoft(new HandsetAddressList());
    testing::internal::CaptureStdout();
    android->run();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "run addressList\n");
    delete android;
}

TEST(HandsetBrandTest, CleanupTest) {
    HandsetBrand* iphone = new Iphone();
    iphone->setHandsetsoft(new HandsetGame());
    delete iphone;
    ASSERT_EQ(static_cast<Handsetsoft*>(nullptr), iphone->soft);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
