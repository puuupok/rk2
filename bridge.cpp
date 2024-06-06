/*************************************************************************
> File Name: bridge.cpp
> Author: CarlSun
> Mail:sunxiuyang04@gmail.com 
> Created Time: Sat Aug 13 23:54:43 2016
 ************************************************************************/

#include<iostream>
using namespace std;
#include<bridge.h>
int main(){
	HandsetBrand* iphone = new Iphone();
	iphone->setHandsetsoft(new HandsetGame());
	iphone->run();
	HandsetBrand* android = new Android();
	android->setHandsetsoft(new HandsetAddressList());
	android->run();
}
