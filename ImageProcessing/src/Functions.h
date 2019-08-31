//
// Created by Jose Manuel Quintas on 2019-03-24.
//

#ifndef PROJECT2_FUNCTIONS_H
#define PROJECT2_FUNCTIONS_H

#include "Header.h"
#include "Pixel.h"


struct Image
{
    Header begin;
    std::vector<Pixel> rainbow;
};

void filling(std::string name, Image &Image);
void provingcontent(Image &Image);
void pretest(Image &a, Image &b, int &score);
bool test(Image &a, Image &b);
void creation(std::string name, Image &picture);
void Duplication(Image &newImage, Image &picture);
void DuplicationHeader(Image &newImage, Image &picture);
Pixel createpix(Image &copying, int location);

Image substract(Image &top, Image &bottom);
Image Multiply(Image &top, Image &bottom);
Image Screen(Image &top, Image &bottom);
Image Overlay(Image &top, Image &bottom);
unsigned char substractclamp(unsigned char orin, unsigned char minus);
unsigned char addclamp(unsigned char orin, unsigned char plus);
unsigned char normalize2color(unsigned char orin, unsigned char multi);
unsigned char normalizebyscale(unsigned char orin, int multi);
unsigned char screen2color(unsigned char orin, unsigned char multi);
unsigned char Overlay2color(unsigned char fore, unsigned char back);



Pixel createpix(Image &copying, int location)
{
    /* =====================================================*/
    
    //Create a pixel with info of the image
    
    /* =====================================================*/
    Pixel pixC;
    unsigned char newblue = copying.rainbow.at(location).getblueC();
    pixC.setblue(newblue);
    unsigned char newgreen = copying.rainbow.at(location).getgreenC();
    pixC.setgreen(newgreen);
    unsigned char newred = copying.rainbow.at(location).getredC();
    pixC.setred(newred);

    return pixC;
};

void filling(std::string name, Image &Image)
{
    /* =====================================================*/

    //Create image by taking info from the file directly

    /* =====================================================*/
    std::ifstream fileT; //problem with the header, only ythe lenght and the height are actula number, the rest are hollow spaces or blanks


    Pixel pix;
    fileT.open(name, std::ios_base::in|std::ios_base::binary);
    //fileT.open(name);
    char t;
    short q;

    if(fileT.is_open()) {
        fileT.read(&t, 1);
        Image.begin.setidLength(t);

        fileT.read(&t, 1);
        Image.begin.setcolorMapType(t);

        fileT.read(&t, sizeof(t));
        Image.begin.setdataTypeCode(t);

        fileT.read((char *) &q, 2);
        Image.begin.setcolorMapOrigin(q);

        fileT.read((char *) &q, 2);
        Image.begin.setcolorMapLength(q);

        fileT.read(&t, 1);
        Image.begin.setcolorMapDepth(t);

        fileT.read((char *) &q, 2);
        Image.begin.setxOrigin(q);

        fileT.read((char *) &q, 2);
        Image.begin.setyOrigin(q);

        fileT.read((char *) &q, 2);
        Image.begin.setwidth(q);

        fileT.read((char *) &q, 2);
        Image.begin.setheight(q);

        fileT.read(&t, 1);
        Image.begin.setbitsperPixel(t);

        fileT.read(&t, 1);
        Image.begin.setimageDescription(t);

        double pixelsize = Image.begin.getheight() * Image.begin.getwigth();
        //cout << "Pixel size: " << pixelsize <<endl;
        for(double i=0; i< pixelsize; i++)
        {
            unsigned char pixC;
            fileT.read((char*)&pixC, sizeof(pixC));
            pix.setblue(pixC);
            fileT.read((char*)&pixC, sizeof(pixC));
            pix.setgreen(pixC);
            fileT.read((char*)&pixC, sizeof(pixC));
            pix.setred(pixC);
            Image.rainbow.push_back(pix);
        };
        if(Image.rainbow.size() == pixelsize)
        {
            //cout << "the count is complete" <<endl;
        }

        fileT.close();
        //std::cout << "Succed on creating file" << std::endl;
    }
    else
    {
        std::cout << "Failed in creating file" <<std::endl;
    }
};

void provingcontent(Image &Image)
{
    /* =====================================================*/
    //translate and print each byte of the image
    /* =====================================================*/
    std::cout << "idLength: " << Image.begin.getidLength() <<std::endl; //hollow
    std::cout << "colorMapType: " << Image.begin.getcolorMapType() <<std::endl; //hollow
    std::cout << "dataTypeCode: " << Image.begin.getdataTypeCode() <<std::endl;
    std::cout << "colorMapOrigin: " << Image.begin.getcolorMapOrigin() <<std::endl; //0
    std::cout << "colorMapLength: " << Image.begin.getcolorMapLength() <<std::endl; //0
    std::cout << "colorMapDepth: " << Image.begin.getcolorMapDepth() << std::endl; //hollow
    std::cout << "xOrigin: " << Image.begin.getxOrigin() << std::endl; //0
    std::cout << "yOrigin: " << Image.begin.getyOrigin() << std::endl; //0
    std:: cout << "width: " << Image.begin.getwigth() << std::endl; //width: 184
    std::cout << "height: " << Image.begin.getheight() << std::endl; //height: 384
    std::cout << "bitsperPixel: " << Image.begin.getbitsperPixel() << std::endl;
    std::cout << "imageDescription: " << Image.begin.getimageDescription() << std::endl; //hollow
    for(int i=0; i<1; i++)
    {
        std::cout <<"\n" << i+1 << " to " << Image.rainbow.size() << std::endl;
        std::cout << "blue: " << Image.rainbow.at(i).getblue() << std::endl;
        std::cout << "green: " << Image.rainbow.at(i).getgreen() << std::endl;
        std::cout << "red: " << Image.rainbow.at(i).getred() << std::endl;
    }
};

void creation(std::string name, Image &picture)
{
    /* =====================================================*/

    //Create file by taking info from the image directly

    /* =====================================================*/
    std::ofstream fileY(name);
    if(fileY.is_open())
    {
        fileY.write(picture.begin.getidLengthF(),1);
        fileY.write(picture.begin.getcolorMapTypeF(),1);
        fileY.write(picture.begin.getdataTypeCodeF(),1);
        fileY.write((char*)picture.begin.getcolorMapOriginF(), 2);
        fileY.write((char*)picture.begin.getcolorMapLengthF(), 2);
        fileY.write(picture.begin.getcolorMapDepthF(), 1);
        fileY.write((char*)picture.begin.getxOriginF(), 2);
        fileY.write((char*)picture.begin.getyOriginF(), 2);
        fileY.write((char*)picture.begin.getwigthF(), 2);
        fileY.write((char*)picture.begin.getheightF(), 2);
        fileY.write(picture.begin.getbitsperPixelF(), 1);
        fileY.write(picture.begin.getimageDescriptionF(), 1);

        for(int i=0; i < picture.rainbow.size(); i++)
        {
            fileY.write((char*)picture.rainbow.at(i).getblueF(),1);
            fileY.write((char*)picture.rainbow.at(i).getgreenF(),1);
            fileY.write((char*)picture.rainbow.at(i).getredF(),1);

        }
        fileY.close();
        //cout <<"create" <<endl;
    }
    else
    {
        std::cout << "creation failed" <<std::endl;
    }
};

bool test(Image &a, Image &b)
{
    /* =====================================================*/
    //Compare two different images, if one element is not the same, then it is
    //false
    /* =====================================================*/

    bool hello = true;
    if(a.begin.getidLength() != b.begin.getidLength())
    {
        std::cout << "the id is wrong" <<std::endl;
        return false;
    }

    if(a.begin.getcolorMapType() != b.begin.getcolorMapType())
    {
        std::cout <<"color map type is wrong" <<std::endl;
        return false;
    }

    if(a.begin.getdataTypeCode() != b.begin.getdataTypeCode())
    {
        std::cout <<"data type code is wrong" <<std::endl;
        return false;
    }

    if(a.begin.getcolorMapOrigin() != b.begin.getcolorMapOrigin())
    {
        std::cout <<"color map origin is wrong" <<std::endl;
        return false;
    }
    if(a.begin.getcolorMapLength() != b.begin.getcolorMapLength())
    {
        std::cout <<"color map lenght is wrong" <<std::endl;
        return false;
    }
    if(a.begin.getcolorMapDepth() != b.begin.getcolorMapDepth())
    {
        std::cout <<"color map depth is wrong" <<std::endl;
        return false;
    }
    if(a.begin.getxOrigin() != b.begin.getxOrigin())
    {
        std::cout <<"xorigin  is wrong" <<std::endl;
        return false;
    }
    if(a.begin.getyOrigin() != b.begin.getyOrigin())
    {
        std::cout <<"yorigin  is wrong" <<std::endl;
        return false;
    }
    if(a.begin.getwigth() != b.begin.getwigth())
    {
        std::cout <<"width  is wrong" <<std::endl;
        return false;
    }
    if(a.begin.getheight() != b.begin.getheight())
    {
        std::cout <<"height  is wrong" <<std::endl;
        return false;
    }
    if(a.begin.getbitsperPixel() != b.begin.getbitsperPixel())
    {
        std::cout <<"bitssperPixel  is wrong" <<std::endl;
        return false;
    }
    if(a.begin.getimageDescription() != b.begin.getimageDescription())
    {
        std::cout << "image description is wrong" <<std::endl;
        return false;
    }

    if(a.rainbow.size() == b.rainbow.size())
    {
        for (int i = 0; i < a.rainbow.size(); i++)
        {
            if(a.rainbow.at(i).getblue() != b.rainbow.at(i).getblue())
            {
                std::cout << "the blue is wrong" <<std::endl;
                return false;
            }

            if(a.rainbow.at(i).getgreen() != b.rainbow.at(i).getgreen())
            {
                std::cout << "the green is worng" <<std::endl;
                return false;
            }

            if(a.rainbow.at(i).getred() != b.rainbow.at(i).getred())
            {
                std::cout << "the red is wrong" <<std::endl;
                return false;
            }
        }
    }
    else
    {
        return false;
    }

    return hello;
};

void pretest(Image &a, Image &b, int &score)
{
    if(test(a, b))
    {
        std::cout << "the image are the same" <<std::endl;
        score+=11;
    }
    else
    {
        std::cout <<"You are screwed" <<std::endl;
    }

};

void Duplication(Image &newImage, Image &picture)
{
    /* =====================================================*/

    //Create Image by taking info from the image directly

    /* =====================================================*/

    //cout << "Proving content new Image:" <<endl;
    //provingcontent(newImage);
    //cout <<endl;
    //cout << "Proving content  picture:" <<endl;
    //provingcontent(picture);

    DuplicationHeader(newImage, picture);


    int pixelsize = newImage.begin.getheight() * newImage.begin.getwigth();
    //cout << "Pixel size: " << pixelsize <<endl;
    for(int i=0; i< pixelsize; i++)
    {
        Pixel pix;

        pix = createpix(picture, i);
        //cout << i <<endl;

        newImage.rainbow.push_back(pix);
    };
    //cout << "Duplication succed" <<endl;
};

Image substract(Image &top, Image &bottom)
{
    Image result;
    Duplication(result, bottom);
    //cout << "Proving content top" << endl;
    //provingcontent(top);

    for(int j=0; j<result.rainbow.size(); j++)
    {
        unsigned char newblue = substractclamp(result.rainbow.at(j).getblueC(), top.rainbow.at(j).getblueC());
        result.rainbow.at(j).setblue(newblue);
        unsigned char newgreen = substractclamp(result.rainbow.at(j).getgreenC(), top.rainbow.at(j).getgreenC());
        result.rainbow.at(j).setgreen(newgreen);
        unsigned char newred = substractclamp(result.rainbow.at(j).getredC(), top.rainbow.at(j).getredC());
        result.rainbow.at(j).setred(newred);
    }
    //cout << "Substract succeed" <<endl;
    return result;
};

unsigned char substractclamp(unsigned char orin, unsigned char minus)
{
    /* =====================================================*/
    //reduce the color of the image with another image
    //be careful, avoid underflow; unsigned char doesn't go below 0
    /* =====================================================*/
    int original = (int)orin;
    int minusS = (int)minus;
    int resultblue = original - minusS;
    unsigned char final;
    if(resultblue<0)
    {
        //cout <<"clamp happen" <<endl;
        final =0;
    }
    else
    {
        //cout << resultblue <<endl;
        final = (unsigned char)resultblue;
    }
    return final;
};

unsigned char addclamp(unsigned char orin, unsigned char plus)
{
    /* =====================================================*/
    //reduce the color of the image with another image
    //be careful, avoid overflow; unsigned char doesn't go above 255
    /* =====================================================*/
    int original = (int)orin;
    int plusS = (int)plus;
    int resultblue = original + plusS;
    unsigned char final;
    if(resultblue>255)
    {
        final =255;
    }
    else
    {
        final = (unsigned char)resultblue;
    }
    return final;
};

Image Multiply(Image &top, Image &bottom)
{
    /* =====================================================*/
    //reduce the color of the image with another image
    //be careful, consider standardize values; you must avoid overflow, because
    // unsigned char doesn't go above 255, but multiplying 2 number aboive 72 always cross the limit
    /* =====================================================*/
    Image result;
    Duplication(result, top);

    for(int k=0; k< result.rainbow.size(); k++)
    {
        unsigned char newblue = normalize2color(result.rainbow.at(k).getblueC(), bottom.rainbow.at(k).getblueC());
        result.rainbow.at(k).setblue(newblue);
        unsigned char newgreen = normalize2color(result.rainbow.at(k).getgreenC(), bottom.rainbow.at(k).getgreenC());
        result.rainbow.at(k).setgreen(newgreen);
        unsigned char newred = normalize2color(result.rainbow.at(k).getredC(), bottom.rainbow.at(k).getredC());
        result.rainbow.at(k).setred(newred);
    }
    return result;
};

unsigned char normalize2color(unsigned char orin, unsigned char multi)
{
    /* =====================================================*/
    //normalize process for multiply to colors
    /* =====================================================*/
    float oper1 = (float)orin;
    oper1 = oper1/255;
    float oper2 = (float)multi;
    oper2 = oper2/255;
    float product = oper1*oper2;
    product = product*255;

    product+=0.5f;
    if(product >255)
    {
        product = 255;
    }
    unsigned char finalproduct = (unsigned char)product;
    return finalproduct;
};

unsigned char normalizebyscale(unsigned char orin, int multi)
{
    /* =====================================================*/
    //now you are multiplying color by a scale, not two color, so you must not worry about
    //normalize the two values, but be careful of not going beyond limit
    /* =====================================================*/
    float oper1 = (float)orin;
    float oper2 = (float)multi;
    float product = oper1*oper2;

    product+=0.5f;
    if(product >255)
    {
        product = 255;
    }
    unsigned char finalproduct = (unsigned char)product;
    return finalproduct;
};

Image Screen(Image &top, Image &bottom)
{
    /* =====================================================*/
    //similiar to multiplying colors, it require its specific operation;
    /* =====================================================*/
    Image result;
    Duplication(result, top);

    for(int k=0; k< result.rainbow.size(); k++)
    {
        unsigned char newblue = screen2color(result.rainbow.at(k).getblueC(), bottom.rainbow.at(k).getblueC());
        result.rainbow.at(k).setblue(newblue);
        unsigned char newgreen = screen2color(result.rainbow.at(k).getgreenC(), bottom.rainbow.at(k).getgreenC());
        result.rainbow.at(k).setgreen(newgreen);
        unsigned char newred = screen2color(result.rainbow.at(k).getredC(), bottom.rainbow.at(k).getredC());
        result.rainbow.at(k).setred(newred);
    }
    return result;
};

unsigned char screen2color(unsigned char orin, unsigned char multi)
{
    /* =====================================================*/
    //make a screen between two color;one image wil be the background(multi) of the other(orin);
    //make sure to follow equation
    // C = 1-(1-A)*(1-B)
    /* =====================================================*/
    float oper1 = (float)orin;
    oper1 = oper1/255;
    float oper2 = (float)multi;
    oper2 = oper2/255;

    float oper1B = 1-oper1;
    float oper2B = 1-oper2;

    float product = 1 - oper1B*oper2B;
    product = product*255;
    product+=0.5f;
    unsigned char final = (unsigned char)product;

    return final;
};

Image Overlay(Image &top, Image &bottom)
{
    /* =====================================================*/
    //similiar to multiplying colors, it require its specific operation to combine two images
    /* =====================================================*/
    Image result;
    Duplication(result, top);

    for(int k=0; k< result.rainbow.size(); k++)
    {
        unsigned char newblue = Overlay2color(result.rainbow.at(k).getblueC(), bottom.rainbow.at(k).getblueC());
        result.rainbow.at(k).setblue(newblue);
        unsigned char newgreen = Overlay2color(result.rainbow.at(k).getgreenC(), bottom.rainbow.at(k).getgreenC());
        result.rainbow.at(k).setgreen(newgreen);
        unsigned char newred = Overlay2color(result.rainbow.at(k).getredC(), bottom.rainbow.at(k).getredC());
        result.rainbow.at(k).setred(newred);
    }
    return result;
};

unsigned char Overlay2color(unsigned char fore, unsigned char back)
{
    /* =====================================================*/
    //make a overlay between two color;overlay is a combination of multiply and screen
    //be careful which one is which one
    // if back <=0.5f; C = 2*A*B
    // if back >0.5f;  C = 1-2*(1-A)*(1-B)
    /* =====================================================*/
    float oper1 = (float)fore;
    oper1 = oper1/255;
    float oper2 = (float)back;
    oper2 = oper2/255;

    float product;
    unsigned char final;
    if(oper2 <= 0.5)
    {
        product = 2*oper1*oper2;
    }
    else
    {
        oper1 = 1-oper1;
        oper2 = 1-oper2;
        product = 1-2*oper1*oper2;
    }

    product = product*255;
    product += 0.5f;
    final = (unsigned char)product;

    return final;

};


void DuplicationHeader(Image &newImage, Image &picture)
{
    /* =====================================================*/

    //Create header by taking info from the image directly

    /* =====================================================*/
    newImage.begin.setidLength(picture.begin.getidLength());
    newImage.begin.setcolorMapType(picture.begin.getcolorMapType());
    newImage.begin.setdataTypeCode(picture.begin.getdataTypeCode());
    newImage.begin.setcolorMapOrigin(picture.begin.getcolorMapOrigin());
    newImage.begin.setcolorMapLength(picture.begin.getcolorMapLength());
    newImage.begin.setcolorMapDepth(picture.begin.getcolorMapDepth());
    newImage.begin.setxOrigin(picture.begin.getxOrigin());
    newImage.begin.setyOrigin(picture.begin.getyOrigin());
    newImage.begin.setwidth(picture.begin.getwigth());
    newImage.begin.setheight(picture.begin.getheight());
    newImage.begin.setbitsperPixel(picture.begin.getbitsperPixel());
    newImage.begin.setimageDescription(picture.begin.getimageDescription());

}


#endif //PROJECT2_FUNCTIONS_H
