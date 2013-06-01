#include "smGraphicsScene.h"
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>
#include <limits>

smGraphicsScene::smGraphicsScene(/*QMenu *itemMenu = 0 , */QObject *parent/* = 0 */)
: QGraphicsScene(parent),
m_pointMenu(0, 0), m_bRectSelecting(false),
m_itemSelectRect(0)
//////////////////////////////////////////////////////////////////////////

{
//	QGraphicsLineItem *line = new QGraphicsLineItem(0, 0, 100, 100);
 //   this->addItem(line);
	adjustRect();
}

smGraphicsScene::~smGraphicsScene(void){
}

void smGraphicsScene::insertNode(void){
}

//void smGraphicsScene::onSceneRectChanged(const QRectF &rect){
//	m_sceneFake->setRect(rect);
//}

void smGraphicsScene::adjustRect(void){

}

void smGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{	
    QGraphicsScene::mousePressEvent(mouseEvent);
	
}

void smGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void smGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

//void smGraphicsScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){
//	clearSelection();
//	m_pointMenu = event->scenePos();
//	if(m_pMenuContext){
//		m_pMenuContext->exec(event->screenPos());
//	}
//}