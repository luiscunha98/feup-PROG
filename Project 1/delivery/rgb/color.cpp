#include <rgb/color.hpp>

namespace rgb {
    const color color::BLACK(0,0,0);
    const color color::WHITE(255,255,255);
    const color color::RED(255,0,0);
    const color color::GREEN(0,255,0);
    const color color::BLUE(0,0,255);
    color::color() {
        r=0;
        b=0;
        g=0;
    }
    color::color(const color& other) {
        r=other.red();
        b=other.blue();
        g=other.green();
    }
    color::color(rgb_value re, rgb_value gren, rgb_value blu) {
        r=re;
        b=blu;
        g=gren;
    }
    rgb_value color::red() const {
        return this->r;
    }
    rgb_value color::green() const {
        return g;
    }
    rgb_value color::blue() const {
        return b;
    }
    rgb_value& color::red()  {
        return r;
    }
    rgb_value& color::green()  {
        return g;
    }
    rgb_value& color::blue()  {
        return b;
    }
    color& color::operator=(const color &c) {
        r=c.red();
        b=c.blue();
        g=c.green();
        return *this;
    }
    bool color::operator==(const color &c) const {
        if(c.red()==this->r && c.blue()==this->b && c.green()==this->g)
            return true;
        else{
            return false;
        }

    }
    bool color::operator!=(const color &c) const {
        if(c.red()==this->red()&&c.blue()==this->blue()&&c.green()==this->green())
            return false;
        else {
            return true;
        }
    }
    void color::invert() {
        r=255-red();
        b=255-blue();
        g=255-green();
    }
    void color::mix(const color& c, int f) {
        this->r=((100-f)*red()+f*c.red())/100;
        this->b=((100-f)*blue()+f*c.blue())/100;
        this->g=((100-f)*green()+f*c.green())/100;
    }
    void color::to_gray_scale() {
        rgb_value temp=(red()+blue()+green())/3;
        r=temp;
        b=temp;
        g=temp;
    }
}