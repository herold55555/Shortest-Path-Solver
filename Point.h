//
// Created by herold55 on 1/14/19.
//

#ifndef PROJ2_POINT_H
#define PROJ2_POINT_H
class Point {
    double x;
    double y;
public:
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    Point() = default;
    Point(const Point &point) {
        this->x = point.getX();
        this->y = point.getY();
    }
    double getX() const{
        return this->x;
    }
    double getY() const{
        return this->y;
    }
    void setX(double x) {
        this->x = x;
    }
    void setY(double y) {
        this->y = y;
    }
    bool operator==(Point point) {
        return (this->x == point.x && this->y == point.y);
    }
};
#endif //PROJ2_POINT_H
