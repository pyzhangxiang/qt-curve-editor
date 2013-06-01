#ifndef __SMGRAPHICSSCENE_H__
#define __SMGRAPHICSSCENE_H__

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMenu>

//////////////////////////////////////////////////////////////////////////


class smGraphicsScene : public QGraphicsScene
{
	Q_OBJECT
	
private:
//	QMenu *m_pMenuContext;
	QPointF m_pointMenu;
	
	bool m_bRectSelecting;
	QGraphicsRectItem *m_itemSelectRect;
	QPointF m_pointStart;
	
//	smFakeScene *m_sceneFake;
	
//	static const qreal mc_fExtent;

	//  [2/11/2011 fabiozhang]
	//////////////////////////////////////////////////////////////////////////
	
	
public:
	smGraphicsScene(/*QMenu *itemMenu = 0, */QObject *parent = 0);
	~smGraphicsScene(void);
	
public:
	void insertNode(void);
	
protected slots:
	//void checkBounding(QGraphicsItem *item);
	void adjustRect(void);
	//void onSceneRectChanged(const QRectF &rect);
	
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
	
 //   virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
};

#endif // __SMGRAPHICSSCENE_H__

