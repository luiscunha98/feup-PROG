#include "elements.hpp"

namespace svg {
    ellipse::ellipse(const svg::color &fill,
                     const point &center,
                     const point &radius) :
            shape(fill), center(center), radius(radius) {

    }

    void ellipse::draw(png_image &img) const {
        img.draw_ellipse(center, radius, get_color());
    }

    void ellipse::translate(const point &t) {
        center = center.translate(t);
    }

    void ellipse::scale(const point &origin, int v) {
        radius.x *= v;
        radius.y *= v;
        center = center.scale(origin, v);
    }

    void ellipse::rotate(const point &origin, int degrees) {
        center = center.rotate(origin, degrees);
    }

    shape *ellipse::duplicate() const {
        return new ellipse(get_color(), center, radius);
    }

    // elipse
    //
    // circle
    circle::circle(const svg::color &fill,
                   const point &center,
                   const point &radius) :

            ellipse(fill, center, radius) {

    }

    void circle::draw(png_image &img) const {
        img.draw_ellipse(center, radius, get_color());
    }

    void circle::translate(const point &t) {
        center = center.translate(t);
    }

    void circle::scale(const point &origin, int v) {
        radius.x *= v;
        radius.y *= v;
        center = center.scale(origin, v);
    }

    void circle::rotate(const point &origin, int degrees) {
        center = center.rotate(origin, degrees);
    }

    shape *circle::duplicate() const {
        return new circle(get_color(), center, radius);
    }
    // circle
    //
    // polyline

    polyline::polyline(const svg::color &brush,
                       const std::vector<point> &points) :
            shape(brush), points(points) {

    }

    void polyline::draw(png_image &img) const {
        for (int i = 0; i < points.size() - 1; i++) {
            point a = points[i];
            point b = points[i + 1];
            img.draw_line(a, b, get_color());
        }
    }

    void polyline::translate(const point &t) {
        for (int i = 0; i < points.size(); i++) {
            points[i] = points[i].translate(t);
        }
    }

    void polyline::scale(const point &origin, int v) {
        for (int i = 0; i < points.size(); i++) {
            points[i] = points[i].scale(origin, v);
        }

    }

    void polyline::rotate(const point &origin, int degrees) {
        for (int i = 0; i < points.size(); i++) {
            points[i] = points[i].rotate(origin, degrees);
        }
    }

    shape *polyline::duplicate() const {
        return new polyline(get_color(), points);
    }

    // polyline
    //
    // line
    line::line(const svg::color &brush,

               const std::vector<point> &points) :
            polyline(brush, points) {


    }

    void line::draw(png_image &img) const {
        img.draw_line(points[0], points[1], get_color());
    }

    void line::translate(const point &t) {
        points[0].translate(t);
        points[1].translate(t);
    }

    void line::scale(const point &origin, int v) {

        points[0] = points[0].scale(origin, v);
        points[1] = points[1].scale(origin, v);
    }

    void line::rotate(const point &origin, int degrees) {
        points[0] = points[0].rotate(origin, degrees);
        points[1] = points[1].rotate(origin, degrees);


    }

    shape *line::duplicate() const {
        return new line(get_color(), points);
    }
    // line
    //
    // polygon


    polygon::polygon(const svg::color &fill,
                     const std::vector<point> &points) :
            shape(fill), points(points) {

    }

    void polygon::draw(png_image &img) const {
        img.draw_polygon(points, get_color());
    }

    void polygon::translate(const point &t) {
        for (int i = 0; i < points.size(); i++) {
            points[i] = points[i].translate(t);
        }
    }

    void polygon::scale(const point &origin, int v) {
        for (int i = 0; i < points.size(); i++) {
            points[i] = points[i].scale(origin, v);
        }
    }

    void polygon::rotate(const point &origin, int degrees) {
        for (int i = 0; i < points.size(); i++) {
            points[i] = points[i].rotate(origin, degrees);
        }
    }

    shape *polygon::duplicate() const {
        return new polygon(get_color(), points);
    }

    // polygon
    //
    // rect

    rect::rect(const svg::color &fill,
               const std::vector<point> &points) :
            polygon(fill, points) {


    }

    void rect::draw(png_image &img) const {
        img.draw_polygon(points, get_color());
    }

    void rect::translate(const point &t) {
        for (int i = 0; i < points.size(); i++) {
            points[i] = points[i].translate(t);
        }

    }

    void rect::scale(const point &origin, int v) {
        for (int i = 0; i < points.size(); i++) {
            points[i] = points[i].scale(origin, v);
        }
    }

    void rect::rotate(const point &origin, int degrees) {
        for (int i = 0; i < points.size(); i++) {
            points[i] = points[i].rotate(origin, degrees);
        }
    }

    shape *rect::duplicate() const {
        return new rect(get_color(), points);
    }


    // rect
    //
    // group

    group::group(std::vector<shape *> shapes, const color &fill) : shape(fill) {
        this->shapes = shapes;
    }

    void group::draw(png_image &img) const {
        for (auto s: shapes) {
            s->draw(img);
        }
    }

    void group::translate(const point &t) {
        for (auto s: shapes) {
            s->translate(t);
        }
    }

    void group::scale(const point &origin, int v) {
        for (auto s: shapes) {
            s->scale(origin, v);
        }
    }

}




