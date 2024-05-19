
#include "catch.hpp"

#include "bridge.cpp" // Включаем наш исходный код

TEST_CASE("HandsetGame") {
    HandsetBrand* iphone = new Iphone();
    iphone->setHandsetsoft(new HandsetGame());

    SECTION("Run HandsetGame") {
        iphone->run();
        // Проверяем, что вывод соответствует ожидаемому
        // Здесь можно использовать мок-объект или перенаправить вывод в поток
    }
}

TEST_CASE("HandsetAddressList") {
    HandsetBrand* android = new Android();
    android->setHandsetsoft(new HandsetAddressList());

    SECTION("Run HandsetAddressList") {
        android->run();
        // Проверяем, что вывод соответствует ожидаемому
    }
}

TEST_CASE("SetHandsetsoft") {
    HandsetBrand* brand = new Iphone();

    SECTION("Set HandsetGame") {
        brand->setHandsetsoft(new HandsetGame());
        brand->run();
        // Проверяем, что вывод соответствует ожидаемому
    }

    SECTION("Set HandsetAddressList") {
        brand->setHandsetsoft(new HandsetAddressList());
        brand->run();
        // Проверяем, что вывод соответствует ожидаемому
    }
}

