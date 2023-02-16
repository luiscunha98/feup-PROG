#include <rgb/image.hpp>
namespace rgb {

    /*image::image(int wi, int he) {
    iwidth=wi;
    iheight=he;
    for(int i=0;i<wi;i++){
        for(int j=0;j<he;j++){
            pixels[i][j].red()=0;
            pixels[i][j].blue()=0;
            pixels[i][j].green()=0;

            }
        }
    }

    */

    image::image(int wi, int he, const color& fill) {
        iwidth=wi;
        iheight=he;
        pixels = new color*[wi];
        for(int i=0;i<wi;i++) {
               pixels[i] = new color[he];
        }



        for(int i=0;i<wi;i++){
            for(int j=0;j<he;j++){
                pixels[i][j]=fill;
                /*
                pixels[i][j].red()=fill.red();
                pixels[i][j].blue()=fill.blue();
                pixels[i][j].green()=fill.green();
                */
            }
        }
        /*
        rgb_value temp=255;
        pixels[wi][0]=color(temp,temp,temp);
        pixels[0][he]=color(temp,temp,temp);
        */
    }


    int image::width() const {
        /*
        int out=0;
        for(int i=0;this->at(i,0)!= color(256,256,256);++i) {
            ++out;
        }
        return out;
         */
        return iwidth;
    }
    int image::height() const {
        /*
        int out=0;
        for(int i=0;this->at(0,i)!= color(256,256,256);++i) {
            ++out;
        }
        return out;
         */
        return iheight;
    }
    image::~image() {
        for(int i=0;i<width();i++){
            delete[] pixels[i];
        }
        delete[] pixels;
    }
    color& image::at(int x, int y) {
        return pixels[x][y];
    }
    const color& image::at(int x, int y) const {
        return pixels[x][y];
    }
    void image::invert() {
        for(int i=0;i<width();i++){
            for(int j=0;j<height();j++) {
                pixels[i][j].invert();
            }
        }
    }
    void image::to_gray_scale() {
        for(int i=0;i<width();i++){
            for(int j=0;j<height();j++) {
                pixels[i][j].to_gray_scale();
            }
        }
    }
    void image::fill(int x, int y, int w, int h, const color& c) {
        for(int i=x;i<x+w;i++){
            for(int j=y;j<y+h;j++) {
                pixels[i][j]=c;
            }
        }
    }
    void image::replace(const color& a, const color& b) {
        for(int i=0;i<width();i++){
            for(int j=0;j<height();j++) {
                if(pixels[i][j]==a){
                    pixels[i][j]=b;
                }
            }
        }
    }
    void image::add(const image& img, const color& neutral, int x, int y){
        for(int i=0; i<img.width();++i){
            for(int j=0;j<img.height();++j){
                if(neutral!=img.at(i,j)){
                    pixels[i+x][j+y]=img.at(i,j);
                }

            }
        }
    }
    void image::crop(int x, int y, int w, int h) {
        color** temp = new color*[w];
        for(int i=0;i<w;i++) {
            temp[i] = new color[h];
        }
        for(int i=x;i<x+w;++i){
            for(int j=y;j<y+h;++j){
                temp[i-x][j-y]=pixels[i][j];
            }
        }
        for(int i=0;i<width();i++){
            delete[] pixels[i];
        }
        delete[] pixels;
        iwidth=w;
        iheight=h;
        pixels = new color*[w];
        for(int i=0;i<w;i++) {
            pixels[i] = new color[h];
        }
        for(int i=0;i<w;++i){
            for(int j=0;j<h;j++){
                pixels[i][j]=temp[i][j];
            }
        }

        for(int i=0;i<w;i++){
            delete [] temp[i];
        }
        delete [] temp;
    }

    void image::rotate_left() {
        int w=width();
        int h=height();
        color **temp = new color *[height()];
        for (int i = 0; i < height(); i++) {
            temp[i] = new color[width()];
        }
        for (int i = 0; i < width(); i++) {
            for (int j = 0; j < height(); j++) {
                temp[j][width() - 1 - i] = pixels[i][j];
            }
        }
            for(int i=0;i<width();i++){
                delete[] pixels[i];
            }
            delete[] pixels;
            iwidth=h;
            iheight=w;
            pixels = new color*[h];
            for(int i=0;i<h;i++) {
                pixels[i] = new color[w];
            }
            for(int i=0;i<h;++i){
                for(int j=0;j<w;++j){
                    pixels[i][j]=temp[i][j];
                }
            }
        for(int i=0;i<h;i++){
            delete [] temp[i];
        }
        delete [] temp;
    }
    void image::rotate_right() {
        int w=width();
        int h=height();
        color **temp = new color *[height()];
        for (int i = 0; i < height(); i++) {
            temp[i] = new color[width()];
        }
        for (int i = 0; i < width(); i++) {
            for (int j = 0; j < height(); j++) {
                temp[height() - j - 1][i] = pixels[i][j];
            }
        }
        for (int i = 0; i < width(); i++) {
            delete[] pixels[i];
        }
        delete[] pixels;
        iwidth=h;
        iheight=w;
        pixels = new color*[h];
        for(int i=0;i<h;i++) {
            pixels[i] = new color[w];
        }
        for(int i=0;i<h;++i){
            for(int j=0;j<w;++j){
                pixels[i][j]=temp[i][j];
            }
        }
        for(int i=0;i<h;i++){
            delete [] temp[i];
        }
        delete [] temp;
    }



    void image::mix(const image& img, int factor) {
        for(int i=0;i<width();i++){
            for(int j=0;j<height();j++) {
                pixels[i][j].mix(img.at(i,j),factor);
            }
        }
    }
}
