#ifndef POINT_H //header guard
#define POINT_H

#include <vector>


class Point {
    public:
        //constructors
        Point(int n);
        Point(std::vector<int> v);

        //setter
        void set_coordinate(int coord,int x_val);

        //getters
        int get_dimensions();
        int get_coordinate(int coord);

        //other methods
        double distance(Point p);
        void translate(int dist);

    private:
        std::vector<int> p;
};

#endif // end header guard