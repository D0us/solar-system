#include "zodiac.h"
#include "config.h"
#include <utility>

Zodiac::Zodiac()
{
}

Zodiac::~Zodiac()
{
}

void Zodiac::render(QPainter &painter) const
{
    double distanceScale = Config::getInstance()->getDistanceScale();
    painter.setPen(Qt::white);
    painter.setBrush(QColor(Qt::white));
    for(auto pair : lines) {
        double x1 = ((pair.first->getPositionX() / distanceScale) * Config::getInstance()->getScale()) + Config::getInstance()->getXOffset();
        double y1 = ((pair.first->getPositionY() / distanceScale) * Config::getInstance()->getScale()) + Config::getInstance()->getYOffset();
        double x2 = ((pair.second->getPositionX() / distanceScale) * Config::getInstance()->getScale()) + Config::getInstance()->getXOffset();
        double y2 = ((pair.second->getPositionY() / distanceScale) * Config::getInstance()->getScale()) + Config::getInstance()->getYOffset();
        painter.drawLine(QLineF(x1, y1, x2, y2));
    }
}

void Zodiac::add(UniverseBody* from, UniverseBody* to)
{
    lines.push_back( std::make_pair(from, to) );
}
