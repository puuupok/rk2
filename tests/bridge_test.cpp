#include "handset.h"
#include <gtest/gtest.h>

TEST(HandsetTest, IphoneRunsGame) {
  HandsetBrand* iphone = new Iphone();
  iphone->setHandsetsoft(new HandsetGame());
  std::streambuf* oldCout = std::cout.rdbuf();
  std::stringstream ss;
  std::cout.rdbuf(ss.rdbuf());
  iphone->run();
  std::cout.rdbuf(oldCout);
  EXPECT_EQ(ss.str(), "run game\n");
  delete iphone;
}

TEST(HandsetTest, AndroidRunsAddressList) {
  HandsetBrand* android = new Android();
  android->setHandsetsoft(new HandsetAddressList());
  std::streambuf* oldCout = std::cout.rdbuf();
  std::stringstream ss;
  std::cout.rdbuf(ss.rdbuf());
  android->run();
  std::cout.rdbuf(oldCout);
  EXPECT_EQ(ss.str(), "run addressList\n");
  delete android;
}

TEST(HandsetTest, NoSoftwareThrowsError) {
  HandsetBrand* android = new Android();
  EXPECT_DEATH(android->run(), "");
  delete android;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
