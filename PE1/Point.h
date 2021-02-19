#ifndef POINT_H //header guard
#define POINT_H


class Point {
    public:
        //constructors
        Point();
        Point(int x_val, int y_val);

        //setters
        void set_x(int x_val);
        void set_y(int y_val);

        //getters
        int get_x();
        int get_y();

        //other methods
        double distance(Point p);
        void translate(int dist);

    private:

        int x_;
        int y_;
};

#endif // end header guard