#include "GameScene.h"
#include "MainMenuScene.h"
#include "SettingLayer.h"
#include "ui/CocosGUI.h"
#include "DefineBitmask.h"
#include "Chess/ChessSpawn.h"
#include "Chess/EnemySpawn.h"

USING_NS_CC;

bool GameScene::init() {
	if (!Scene::initWithPhysics())
	{
		return false;
	}
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	layer = Layer::create();
	auto background = Sprite::create("Background/1st_Backgound.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height *0.6));
	background->setScale(visibleSize.height / background->getContentSize().height);
	this->addChild(background);
	this->addChild(layer,100);

	auto yourBase = Sprite::create("Barrack/Lvl1_ori.png");
	yourBase->setPosition(Vec2(visibleSize.width *0.1, visibleSize.height * 0.42));
	yourBase->setScale(visibleSize.height / yourBase->getContentSize().height*0.2);
	this->addChild(yourBase,10);

	//auto enemyBase = Sprite::create("Barrack/Lvl1_ori.png");
	//enemyBase->setFlippedX(-1);
	//enemyBase->setPosition(Vec2(visibleSize.width *0.9, visibleSize.height * 0.42));
	//enemyBase->setScale(visibleSize.height / enemyBase->getContentSize().height*0.2);
	//this->addChild(enemyBase,10);

	auto bgLayerDown = Sprite::create("Background/Btn_orange_active.png");
	layer->addChild(bgLayerDown);
	bgLayerDown->setAnchorPoint(Vec2(0.5, 0));
	bgLayerDown->setScaleY(visibleSize.height / bgLayerDown->getContentSize().height*0.2);
	bgLayerDown->setScaleX(visibleSize.width / bgLayerDown->getContentSize().width );
	bgLayerDown->setPosition(Vec2(visibleSize.width  / 2, visibleSize.height*0));

	// character spawn
	characterSpawn = new ChessSpawn();
	characterSpawn->init(this);

	auto buttonChessSoldier = ui::Button::create("Icon/Soldier1.png", "Icon/Soldier1.png");
	buttonChessSoldier->addTouchEventListener(
		[=](Ref* sender, ui::Widget::TouchEventType type) {
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
			{
				characterSpawn->spawnSoldier1();
				break;
			}
			case ui::Widget::TouchEventType::CANCELED:
				break;
			default:
				break;
			}});
	buttonChessSoldier->setPosition(Vec2(visibleSize.width * 0.05, visibleSize.height * 0.1));
	buttonChessSoldier->setScale(visibleSize.height / buttonChessSoldier->getContentSize().height * 0.15);
	layer->addChild(buttonChessSoldier);

	auto buttonChessArcher = ui::Button::create("Icon/Archer1.png", "Icon/Archer1.png");
	buttonChessArcher->addTouchEventListener(
		[=](Ref* sender, ui::Widget::TouchEventType type) {
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
			{
				characterSpawn->spawnArcher1();
				break;
			}
			case ui::Widget::TouchEventType::CANCELED:
				break;
			default:
				break;
			}});
	buttonChessArcher->setPosition(Vec2(visibleSize.width * 0.15, visibleSize.height * 0.1));
	buttonChessArcher->setScale(visibleSize.height / buttonChessArcher->getContentSize().height * 0.15);
	layer->addChild(buttonChessArcher);

	auto buttonChessAssassin = ui::Button::create("Icon/Assassin1.png", "Icon/Assassin1.png");
	buttonChessAssassin->addTouchEventListener(
		[=](Ref* sender, ui::Widget::TouchEventType type) {
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
			{
				characterSpawn->spawnAssassin1();
				break;
			}
			case ui::Widget::TouchEventType::CANCELED:
				break;
			default:
				break;
			}});
	buttonChessAssassin->setPosition(Vec2(visibleSize.width * 0.25, visibleSize.height * 0.1));
	buttonChessAssassin->setScale(visibleSize.height / buttonChessAssassin->getContentSize().height * 0.15);
	layer->addChild(buttonChessAssassin);

	auto buttonChessCombatant = ui::Button::create("Icon/Combatant1.png", "Icon/Combatant1.png");
	buttonChessCombatant->addTouchEventListener(
		[=](Ref* sender, ui::Widget::TouchEventType type) {
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
			{
				characterSpawn->spawnCombatant1();
				break;
			}
			case ui::Widget::TouchEventType::CANCELED:
				break;
			default:
				break;
			}});
	buttonChessCombatant->setPosition(Vec2(visibleSize.width * 0.35, visibleSize.height * 0.1));
	buttonChessCombatant->setScale(visibleSize.height / buttonChessCombatant->getContentSize().height * 0.15);
	layer->addChild(buttonChessCombatant);

	auto buttonSetting = ui::Button::create("Button/Option_icon.png");
	buttonSetting->addTouchEventListener(
		[=](Ref* sender, ui::Widget::TouchEventType type) {
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED: {
				Director::getInstance()->pause();
				auto layer1 = SettingLayer::create();
				this->addChild(layer1,101);
				break; }
			case ui::Widget::TouchEventType::CANCELED:
				break;
			default:
				break;
			}});
	buttonSetting->setPosition(Vec2(visibleSize.width * 0.95, visibleSize.height * 0.9));
	buttonSetting->setScale(visibleSize.height / buttonSetting->getContentSize().height * 0.1);
	layer->addChild(buttonSetting, 99);

	// enemy spawn
	enemy = new EnemySpawn();
	enemy->init(this);
	enemy->startSpawn(2.0f, 10);
	
	this->schedule(CC_SCHEDULE_SELECTOR(GameScene::updateSpawn), 3.0f);
	this->scheduleUpdate();
	return true;
}

bool GameScene::OnTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	return false;
}

void GameScene::update(float dt) {	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	layer->setPosition(this->getDefaultCamera()->getPosition()+ visibleSize / -2);
}

void GameScene::updateSpawn(float dt)
{
	enemy->spawnSoldier1();
	enemy->spawnSoldier1();
	enemy->spawnArcher1();
	enemy->spawnAssassin1();
	enemy->spawnCombatant1();
}

