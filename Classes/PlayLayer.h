#ifndef __PlayLayer_H__
#define __PlayLayer_H__

#include "cocos2d.h"

USING_NS_CC;

class SushiSprite;

class PlayLayer : public Layer
{
public:
    PlayLayer();
    ~PlayLayer();
    static Scene* createScene();
    CREATE_FUNC(PlayLayer);
    
    virtual bool init() override;
    virtual void update(float dt) override;
	
	// Mới
    virtual bool onTouchBegan(Touch *touch, Event *unused) override;
    virtual void onTouchMoved(Touch *touch, Event *unused) override;
private:
    SpriteBatchNode *spriteSheet;
    SushiSprite **m_matrix;
    int m_width;
    int m_height;

    float m_matrixLeftBottomX;
    float m_matrixLeftBottomY;
	
	// Mới
    bool m_isTouchEnable;
    SushiSprite *m_srcSushi;
    SushiSprite *m_destSushi;
    bool m_isAnimationing;
    bool m_isNeedFillVacancies;
    bool m_movingVertical;
	
    
    void initMatrix();
    void createAndDropSushi(int row, int col);
    Point positionOfItem(int row, int col);
    void checkAndRemoveChain();
    void getColChain(SushiSprite *sushi, std::list<SushiSprite *> &chainList);
    void getRowChain(SushiSprite *sushi, std::list<SushiSprite *> &chainList);
    void removeSushi();	    
    void fillVacancies();
	void explodeSushi(SushiSprite *sushi);
	
	// Mới	
    void actionEndCallback(Node *node);    
    void explodeSpecialH(Point point);
    void explodeSpecialV(Point point);
    SushiSprite *sushiOfPoint(Point *point);
    void swapSushi();
    void markRemove(SushiSprite *sushi);
};

#endif /* defined(__PlayLayer_H__) */
