
#include <iostream>
#include <tinyxml2.h>
#include <sstream>
#include "svg_to_png.hpp"
#include "elements.hpp"

using namespace tinyxml2;

namespace svg {
    // Color parsing
    const std::map<std::string, color> COLORS = {
            {"black",  {0,   0,   0}},
            {"white",  {255, 255, 255}},
            {"red",    {255, 0,   0}},
            {"green",  {0,   255, 0}},
            {"blue",   {0,   0,   255}},
            {"yellow", {255, 255, 0}}
    };

    color parse_color(const std::string &str) {
        color c;
        char first_ch = str.at(0);
        if (first_ch == '#') {
            int v;
            std::stringstream ss(str.substr(1));
            ss >> std::hex >> v;
            c.red = (v >> 16);
            c.green = (v >> 8) & 0xFF;
            c.blue = v & 0xFF;
        } else {
            c = COLORS.at(str);
        }
        return c;
    }

    // Transformation parsing

    void parse_transform(shape *s, XMLElement *elem) {
        const char *p_t_attr = elem->Attribute("transform");
        if (p_t_attr == NULL)
            return; // Not defined
        point origin{0, 0};
        const char *p_t_o_attr = elem->Attribute("transform-origin");
        if (p_t_o_attr != NULL) {
            std::string str = p_t_o_attr;
            std::stringstream ss(str);
            ss >> origin.x >> origin.y;
        }
        std::string attr(p_t_attr);
        for (char &c: attr) {
            if (c == '(' || c == ')' || c == ',') {
                c = ' ';
            }
        }
        std::stringstream ss(attr);
        std::string type;
        ss >> type;
        if (type == "translate") {
            int x, y;
            ss >> x >> y;
            s->translate({x, y});
        } else if (type == "scale") {
            int v;
            ss >> v;
            s->scale(origin, v);
        } else if (type == "rotate") {
            int v;
            ss >> v;
            s->rotate(origin, v);
        } else {
            std::cout << "Unrecognised transform type: " << type << std::endl;
        }
    }

    // Point list parsing
    void
    parse_points(const std::string &s, std::vector<point> &points) {
        std::stringstream ss(s);
        std::string val;
        while (std::getline(ss, val, ' ')) {
            val.at(val.find(',')) = ' ';
            std::stringstream ss2(val);
            int x, y;
            ss2 >> x >> y;
            points.push_back({x, y});
        }
    }

    // Shape parsing
    ellipse *parse_ellipse(XMLElement *elem,std::map<std::string,svg::shape> *IDMAP) {
        int cx = elem->IntAttribute("cx");
        int cy = elem->IntAttribute("cy");
        int rx = elem->IntAttribute("rx");
        int ry = elem->IntAttribute("ry");
        color fill = parse_color(elem->Attribute("fill"));
        ellipse *out=new ellipse(fill, {cx, cy}, {rx, ry});
        std::string id="";
        if(elem->Attribute("id")!=NULL){
            id=elem->Attribute("id");
        }
        IDMAP->insert({id, *out});
        return out;
    }

    ellipse *parse_circle(XMLElement *elem,std::map<std::string,svg::shape> *IDMAP) {
        int cx = elem->IntAttribute("cx");
        int cy = elem->IntAttribute("cy");
        int r = elem->IntAttribute("r");
        color fill = parse_color(elem->Attribute("fill"));
        ellipse *out=new ellipse(fill, {cx, cy}, {r, r});
        std::string id="";
        if(elem->Attribute("id")!=NULL){
            id=elem->Attribute("id");
        }
        IDMAP->insert({id, *out});
        return out;
    }

    // TODO other parsing functions for elements
    polyline *parse_polyline(XMLElement *elem,std::map<std::string,svg::shape> *IDMAP) {
        std::vector<point> points;
        parse_points(elem->Attribute("points"), points);
        color brush = parse_color(elem->Attribute("stroke"));
        std::string id="";
        polyline *out=new polyline(brush, points);
        if(elem->Attribute("id")!=NULL){
            id=elem->Attribute("id");
        }
        IDMAP->insert({id, *out});

        return out;
    }

    polyline *parse_line(XMLElement *elem,std::map<std::string,svg::shape> *IDMAP) {
        int ax = elem->IntAttribute("x1");
        int ay = elem->IntAttribute("y1");
        int bx = elem->IntAttribute("x2");
        int by = elem->IntAttribute("y2");
        point a = {ax, ay};
        point b = {bx, by};
        color brush = parse_color(elem->Attribute("stroke"));
        std::vector<point> points = {a, b};
        std::string id="";
        polyline *out=new polyline(brush, points);
        if(elem->Attribute("id")!=NULL){
            id=elem->Attribute("id");
        }
        IDMAP->insert({id, *out});

        return out;
    }

    polygon *parse_polygon(XMLElement *elem,std::map<std::string,svg::shape> *IDMAP) {
        std::vector<point> points;
        parse_points(elem->Attribute("points"), points);
        color fill = parse_color(elem->Attribute("fill"));
        polygon *out=new polygon(fill, points);
        std::string id="";
        if(elem->Attribute("id")!=NULL){
            id=elem->Attribute("id");
        }
        IDMAP->insert({id, *out});
        return out;
    }

    polygon *parse_rect(XMLElement *elem,std::map<std::string,svg::shape> *IDMAP) {
        point UpLeftCorn;
        const int x = elem->IntAttribute("x");
        const int y = elem->IntAttribute("y");
        const int w = elem->IntAttribute("width");
        const int h = elem->IntAttribute("height");
        UpLeftCorn = {x, y};
        std::vector<point> points;
        point c2, c3, c4;

        c2.x = UpLeftCorn.x + w - 1;
        c2.y = UpLeftCorn.y;

        c3.x = UpLeftCorn.x;
        c3.y = UpLeftCorn.y + h - 1;

        c4.x = UpLeftCorn.x + w - 1;
        c4.y = UpLeftCorn.y + h - 1;

        points = {UpLeftCorn, c2, c4, c3};
        color fill = parse_color(elem->Attribute("fill"));
        polygon *out=new polygon(fill, points);
        std::string id="";
        if(elem->Attribute("id")!=NULL){
            id=elem->Attribute("id");
        }
        IDMAP->insert({id, *out});
        return out;
    }

    /*
    rect *parse_rect(XMLElement *elem) {
        point UpLeftCorn;
        const int x=elem->IntAttribute("x");
        const int y=elem->IntAttribute("y");
        const int w=elem->IntAttribute("width");
        const int h=elem->IntAttribute("height");
        UpLeftCorn={x,y};
        std::vector<point> points;
        point c2,c3,c4;

        c2.x= UpLeftCorn.x+w-1;
        c2.y= UpLeftCorn.y;

        c3.x= UpLeftCorn.x;
        c3.y= UpLeftCorn.y+h-1;

        c4.x=UpLeftCorn.x+w-1;
        c4.y=UpLeftCorn.y+h-1;

        points={UpLeftCorn,c3,c4,c2};
        color fill = parse_color(elem->Attribute("fill"));
        return new rect(fill, points);

    }
     */
    void *parse_use(XMLElement *elem,std::map<std::string,svg::shape> *IDMAP) {
        std::string temp=elem->Attribute("href");
        temp.erase(0);
        if(IDMAP->find(temp)!=IDMAP->end()){

            auto s=IDMAP->at(temp);
            parse_transform(&s, (XMLElement *) elem->Attribute("transform"));
        }
    }
    void parse_shapes(XMLElement *elem, std::vector<shape *> &shapes);
    group *parse_group(XMLElement *elem) {
        std::vector<shape*> shapes;
        parse_shapes(elem,shapes);
        return new group(shapes, parse_color("red"));
    }

    // Loop for parsing shapes
    void parse_shapes(XMLElement *elem, std::vector<shape *> &shapes) {
        std::map<std::string,svg::shape> IDMAP;
        for (auto child_elem = elem->FirstChildElement();
             child_elem != NULL;
             child_elem = child_elem->NextSiblingElement()) {
            std::string type(child_elem->Name());
            shape *s;
            // TODO complete
            if (type == "ellipse") {
                s = parse_ellipse(child_elem,&IDMAP);
            } else if (type == "circle") {
                s = parse_circle(child_elem, &IDMAP);
            } else if (type == "polyline") {
                s = parse_polyline(child_elem,&IDMAP);
            } else if (type == "line") {
                s = parse_line(child_elem,&IDMAP);
            } else if (type == "polygon") {
                s = parse_polygon(child_elem,&IDMAP);
            } else if (type == "rect") {
                s = parse_rect(child_elem,&IDMAP);
            } else if (type == "g") {
                s = parse_group(child_elem);
            } else if (type == "use") {
                parse_use(child_elem, &IDMAP);
            } else{
                std::cout << "Unrecognized shape type: " << type << std::endl;
                continue;
            }
            parse_transform(s, child_elem);
            shapes.push_back(s);
        }
    }

    // Main conversion function.
    // TODO adapt if necessary
    void svg_to_png(const std::string &svg_file, const std::string &png_file) {
        XMLDocument doc;
        XMLError r = doc.LoadFile(svg_file.c_str());
        if (r != XML_SUCCESS) {
            return;
        }
        XMLElement *elem = doc.RootElement();
        std::vector<shape *> shapes;
        parse_shapes(elem, shapes);
        int width = elem->IntAttribute("width");
        int height = elem->IntAttribute("height");
        png_image img(width, height);
        for (auto s: shapes) {
            s->draw(img);
        }
        img.save(png_file);
        for (auto s: shapes) {
            delete s;
        }
    }
}