#include "SettingLayer.h"
#include "Scenes/GameScene.h"
#include "Scenes/MainMenuScene.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
//
//Scene* SettingLayer::createScene()
//{
//	return SettingLayer::create();
//}

bool SettingLayer::init() {
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("Options_box.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	background->setScale(visibleSize.height / background->getContentSize().height*0.8);
	this->addChild(background);

	/*auto gameover = Sprite::create("gameover.png");
	gameover->setScale(2.0f);
	gameover->setPosition(Vec2(visibleSize.width / 2, visibleSize.height *0.7));
	this->addChild(gameover);*/

	//auto buttonNewGame = ui::Button::create("NewGameGreen.png", "NewGameRed.png");
	//buttonNewGame->addTouchEventListener(
	//	[&](Ref* sender, ui::Widget::TouchEventType type) {
	//		switch (type)
	//		{
	//		case ui::Widget::TouchEventType::BEGAN:
	//			break;
	//		case ui::Widget::TouchEventType::ENDED:
	//			Director::getInstance()->replaceScene(GameScene::create());
	//			break;
	//		case ui::Widget::TouchEventType::CANCELED:
	//			break;
	//		default:
	//			break;
	//		}});
	//buttonNewGame->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.3));
	//this->addChild(buttonNewGame);
	//Director::getInstance()->getActionManager()->pauseAllRunningActions();
	
	std::string buttonOrange = "Button/Orange_btn.png";
	std::string buttonGreen2 = "Button/Green_Btn2.png";
	auto buttonResume = ui::Button::create(buttonGreen2, buttonOrange);
	buttonResume->addTouchEventListener(
		[&](Ref* sender, ui::Widget::TouchEventType type) {
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				Director::getInstance()->resume();
				this->removeFromParentAndCleanup(true);
				break;
			case ui::Widget::TouchEventType::CANCELED:
				break;
			default:
				break;
			}});
	buttonResume->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.65));
	buttonResume->setScale(visibleSize.height / buttonResume->getContentSize().height * 0.15);
	this->addChild(buttonResume, 5);
	auto labelResume = Label::createWithTTF("Resume", "fonts/Marker Felt.ttf", 36);
	labelResume->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.65));
	labelResume->setScale(visibleSize.height / labelResume->getContentSize().height * 0.05);
	this->addChild(labelResume, 6);

	auto buttonRestart = ui::Button::create(buttonGreen2, buttonOrange);
	buttonRestart->addTouchEventListener(
		[&](Ref* sender, ui::Widget::TouchEventType type) {
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				Director::getInstance()->resume();
				Director::getInstance()->replaceScene( GameScene::create());
				break;
			case ui::Widget::TouchEventType::CANCELED:
				break;
			default:
				break;
			}});
	buttonRestart->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.45));
	buttonRestart->setScale(visibleSize.height / buttonRestart->getContentSize().height * 0.15);
	this->addChild(buttonRestart, 5);
	auto labelRestart = Label::createWithTTF("Restart", "fonts/Marker Felt.ttf", 36);
	labelRestart->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.45));
	labelRestart->setScale(visibleSize.height / labelRestart->getContentSize().height * 0.05);
	this->addChild(labelRestart, 6);

	auto buttonQuit = ui::Button::create(buttonGreen2, buttonOrange);
	buttonQuit->addTouchEventListener(
		[&](Ref* sender, ui::Widget::TouchEventType type) {
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				Director::getInstance()->resume();
				this->removeFromParentAndCleanup(true);
				Director::getInstance()->replaceScene(MainMenuScene::createScene());
				break;
			case ui::Widget::TouchEventType::CANCELED:
				break;
			default:
				break;
			}});
	buttonQuit->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.25));
	buttonQuit->setScale(visibleSize.height / buttonQuit->getContentSize().height * 0.15);
	this->addChild(buttonQuit, 5);
	auto labelQuit = Label::createWithTTF("Quit", "fonts/Marker Felt.ttf", 36);
	labelQuit->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.25));
	labelQuit->setScale(visibleSize.height / labelQuit->getContentSize().height * 0.05);
	this->addChild(labelQuit, 6);

	//Director::getInstance()->getActionManager()->pauseAllRunningActions();
	return true;
}

