#include "HighScoreScene.h"
#include "ui/CocosGUI.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* HighScoreScene::createScene()
{
	return HighScoreScene::create();
}

static void problemLoading(const char* filename) {
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HighScoreScene::init() {
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//auto background = Sprite::create("background.png");
	//background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	//background->setScale(0.8f);
	//this->addChild(background);

	//auto scrollView = ui::ScrollView::create();
	//scrollView->setPosition(Vec2(150,100));
	//scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	//scrollView->setBounceEnabled(true);
	//addChild(scrollView);

	//auto bgHighScore = Sprite::create("BG.png");
	//bgHighScore->setPosition(Vec2(bgHighScore->getBoundingBox().size/2));
	//scrollView->addChild(bgHighScore);
	//scrollView->setInnerContainerSize(bgHighScore->getBoundingBox().size); // content
	//scrollView->setContentSize(bgHighScore->getContentSize()); // view
	//scrollView->setScrollBarEnabled(false);

	//auto label = Label::createWithTTF("High Score Scene", "fonts/Marker Felt.ttf", 36);
	//label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height *0.8));
	//this->addChild(label);


	//auto buttonQuit = ui::Button::create("QuitGreen.png", "QuitRed.png");
	//buttonQuit->addTouchEventListener(
	//	[&](Ref* sender, ui::Widget::TouchEventType type) {
	//		switch (type)
	//		{
	//		case ui::Widget::TouchEventType::BEGAN:
	//			break;
	//		case ui::Widget::TouchEventType::ENDED:
	//			Director::getInstance()->replaceScene(TransitionFade::create(2, MainMenuScene::createScene()));
	//			break;
	//		case ui::Widget::TouchEventType::CANCELED:
	//			break;
	//		default:
	//			break;
	//		}});
	//buttonQuit->setPosition(Vec2(visibleSize.width * 0.1, visibleSize.height * 0.9));
	//this->addChild(buttonQuit);
	return true;
}