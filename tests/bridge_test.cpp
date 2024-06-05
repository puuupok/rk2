#include <gtest/gtest.h>
#include <iostream>
#include <thread>
#include <vector>

// Подключение основного файла bridge.h
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

TEST(BridgeTest, SingleInstanceWithoutThreads) {
    Handsetsoft* game = new HandsetGame();
    Handsetsoft* addressList = new HandsetAddressList();

    HandsetBrand* iphone = new Iphone();
    iphone->setHandsetsoft(game);
    iphone->run(); // Output: run game

    HandsetBrand* android = new Android();
    android->setHandsetsoft(addressList);
    android->run(); // Output: run addressList

    delete iphone;
    delete android;
    delete game;
    delete addressList;
}

TEST(BridgeTest, ThreadSafety) {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([]() {
            HandsetBrand* iphone = new Iphone();
            iphone->setHandsetsoft(new HandsetGame());
            iphone->run();
            delete iphone;
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

TEST(BridgeTest, MultipleInstancesWithoutThreadSafety) {
    std::vector<Handsetsoft*> games;
    std::vector<Handsetsoft*> addressLists;
    std::vector<HandsetBrand*> iphones;
    std::vector<HandsetBrand*> androids;

    for (int i = 0; i < 10; ++i) {
        games.push_back(new HandsetGame());
        addressLists.push_back(new HandsetAddressList());
        iphones.push_back(new Iphone());
        androids.push_back(new Android());
    }

    for (int i = 0; i < 10; ++i) {
        iphones[i]->setHandsetsoft(games[i]);
        androids[i]->setHandsetsoft(addressLists[i]);
    }

    for (int i = 0; i < 10; ++i) {
        delete iphones[i];
        delete androids[i];
        delete games[i];
        delete addressLists[i];
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
