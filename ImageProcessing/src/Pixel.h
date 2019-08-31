//
// Created by Jose Manuel Quintas on 2019-03-23.
//

#ifndef PROJECT2_PIXEL_H
#define PROJECT2_PIXEL_H


class Pixel {
public:
    Pixel()
    {blue=0;
    green=0;
    red =0;};

    void setblue(unsigned char &t)
        {blue = t;};
    void setgreen(unsigned char &t)
        {green = t;};
    void setred(unsigned char &t)
        {red = t;};

    //return pixels as int
    int getblue()
        {return (int)blue;};
    int getgreen()
        {return (int)green;};
    int getred()
        {return (int)red;};

    //return pixels to build files, the address
    unsigned char* getblueF()
    {return &blue;};
    unsigned char* getgreenF()
    {return &green;};
    unsigned char* getredF()
    {return &red;};

    //retrun pixels in the basic form -> as unsigned char itself
    unsigned char getblueC()
    {return blue;};
    unsigned char getgreenC()
    {return green;};
    unsigned char getredC()
    {return red;};

private:
    unsigned char blue;
    unsigned char green;
    unsigned char red;


};


#endif //PROJECT2_PIXEL_H
