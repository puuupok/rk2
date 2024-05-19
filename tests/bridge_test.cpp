#include "gtest/gtest.h"

class Handsetsoft {
public:
  Handsetsoft() {}
  virtual ~Handsetsoft() {}
  virtual void run() = 0;
};

class HandsetGame : public Handsetsoft {
public:
  HandsetGame() : Handsetsoft() {}
  virtual ~HandsetGame() {}
  virtual void run() {
    cout << "run game" << endl;
  }
};

class HandsetAddressList : public Handsetsoft {
public:
  HandsetAddressList() : Handsetsoft() {}
  virtual ~HandsetAddressList() {}
  virtual void run() {
    cout << "run addressList" << endl;
  }
};

class HandsetBrand {
public:
  HandsetBrand() {}
  virtual ~HandsetBrand() { delete soft; }
  virtual void setHandsetsoft(Handsetsoft* soft) {
    this->soft = soft;
  }
  virtual void run() {}

protected:
  Handsetsoft* soft;
};

class Iphone : public HandsetBrand {
public:
  Iphone() : HandsetBrand() {}
  virtual ~Iphone() {}
  virtual void run() {
    soft->run();
  }
};

class Android : public HandsetBrand {
public:
  Android() : HandsetBrand() {}
  virtual ~Android() {}
  virtual void run() {
    soft->run();
  }
};

TEST(BridgePattern, IphoneGame) {
  // Arrange
  HandsetBrand* iphone = new Iphone();
  iphone->setHandsetsoft(new HandsetGame());

  // Act
  iphone->run();

  // Assert
  ASSERT_EQ(cout.str(), "run gamen");
}

TEST(BridgePattern, AndroidAddressList) {
  // Arrange
  HandsetBrand* android = new Android();
  android->setHandsetsoft(new HandsetAddressList());

  // Act
  android->run();

  // Assert
  ASSERT_EQ(cout.str(), "run addressListn");
}

TEST(BridgePattern, IphoneSetHandsetsoft) {
  // Arrange
  HandsetBrand* iphone = new Iphone();

  // Act
  iphone->setHandsetsoft(new HandsetAddressList());

  // Assert
  ASSERT_EQ(iphone->soft, new HandsetAddressList());
}
