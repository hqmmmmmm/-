class Solution {
public: // 分八个不重叠的部分就可以，上下左右（圆与直线），左上角右上角左下角右下角（圆与点），其它情况就是重叠的
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(xCenter + radius < x1 || xCenter - radius > x2 || yCenter + radius < y1 || yCenter - radius > y2)
            return false;
        
        if(xCenter < x1 && yCenter > y2 && dist(xCenter, yCenter, x1, y2) > radius * radius)
            return false;
        if(xCenter > x2 && yCenter > y2 && dist(xCenter, yCenter, x2, y2) > radius * radius)
            return false;
        if(xCenter > x2 && yCenter < y1 && dist(xCenter, yCenter, x2, y1) > radius * radius)
            return false;
        if(xCenter < x1 && yCenter < y1 && dist(xCenter, yCenter, x1, y1) > radius * radius)
            return false;

        return true;
    }


    double dist(int x1, int y1, int x2, int y2)
    {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
};