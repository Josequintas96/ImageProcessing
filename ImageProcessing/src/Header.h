//
// Created by Jose Manuel Quintas on 2019-03-23.
//

#ifndef PROJECT2_HEADER_H
#define PROJECT2_HEADER_H

class Header {
public:
    void setidLength(const char &t)
        {idLength = t;};
    void setcolorMapType(const char &t)
        {colorMapType = t;};
    void setdataTypeCode(const char &t)
        {dataTypeCode =t;};
    void setcolorMapOrigin(const short &t)
        { colorMapOrigin = t;};
    void setcolorMapLength(const short &t)
        { colorMapLength = t;};
    void setcolorMapDepth(const char &t)
        { colorMapDepth = t;};
    void setxOrigin(const short &t)
        { xOrigin = t;};
    void setyOrigin(const short &t)
        { yOrigin = t;};
    void setwidth(const short &t)
        {width = t;};
    void setheight(const short &t)
        {height = t;};
    void setbitsperPixel(const char &t)
        {bitsperPixel = t;};
    void setimageDescription(const char &t)
        {imageDescription = t;};



    char getidLength()
        {return idLength;};
    char* getidLengthF()
        {return &idLength;};

    char getcolorMapType()
        {return colorMapType;};
    char* getcolorMapTypeF()
        {return &colorMapType;};

    char getdataTypeCode()
        {return dataTypeCode;};
    char* getdataTypeCodeF()
        {return &dataTypeCode;};

    short getcolorMapOrigin()
        {return colorMapOrigin;};
    short* getcolorMapOriginF()
        {return &colorMapOrigin;};

    short getcolorMapLength()
        {return colorMapLength;};
    short* getcolorMapLengthF()
        {return &colorMapLength;};

    char getcolorMapDepth()
        {return colorMapDepth;};
    char* getcolorMapDepthF()
        {return &colorMapDepth;};

    short getxOrigin()
        {return xOrigin;};
    short* getxOriginF()
        {return &xOrigin;};

    short getyOrigin()
        {return yOrigin;};
    short* getyOriginF()
        {return &yOrigin;};

    short getwigth()
        {return width;};
    short* getwigthF()
        {return &width;};

    short getheight()
        {return height;};
    short* getheightF()
        {return &height;};

    char getbitsperPixel()
        {return bitsperPixel;};
    char* getbitsperPixelF()
        {return &bitsperPixel;};

    char getimageDescription()
        {return imageDescription;};
    char* getimageDescriptionF()
        {return &imageDescription;};


private:
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsperPixel;
    char imageDescription;
};


#endif //PROJECT2_HEADER_H
