#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

#include "Header.h"
#include "Pixel.h"
#include "Functions.h"



using namespace std;



int main()
{
    int score =0;

    /* =====================================================*/
                            //PART 1
                         //Load files file
    /* =====================================================*/

    //string name_requirement_layer1 = "/Users/failop/CLionProjects/Project2/ImageProcessing/input/layer1.tga";
    string name_requirement_layer1 =  "input/layer1.tga";
    Image requirement_layer1;
    filling(name_requirement_layer1, requirement_layer1);

    //string name_requirement_layer2 = "/Users/failop/CLionProjects/Project2/ImageProcessing/input/layer2.tga";
    string name_requirement_layer2 = "input/layer2.tga";
    Image requirement_layer2;
    filling(name_requirement_layer2, requirement_layer2);

    //string name_requirement_car = "/Users/failop/CLionProjects/Project2/ImageProcessing/input/car.tga";
    string name_requirement_car = "input/car.tga";
    Image requirement_car;
    filling(name_requirement_car, requirement_car);

    //string name_requirement_circles = "/Users/failop/CLionProjects/Project2/ImageProcessing/input/circles.tga";
    string name_requirement_circles = "input/circles.tga";
    Image requirement_circles;
    filling(name_requirement_circles, requirement_circles);

//    string name_requirement_layer_blue = "/Users/failop/CLionProjects/Project2/ImageProcessing/input/layer_blue.tga";
    string name_requirement_layer_blue = "input/layer_blue.tga";
    Image requirement_layer_blue;
    filling(name_requirement_layer_blue, requirement_layer_blue);

    //string name_requirement_layer_green = "/Users/failop/CLionProjects/Project2/ImageProcessing/input/layer_green.tga";
    string name_requirement_layer_green = "input/layer_green.tga";
    Image requirement_layer_green;
    filling(name_requirement_layer_green, requirement_layer_green);

    //string name_requirement_layer_red = "/Users/failop/CLionProjects/Project2/ImageProcessing/input/layer_red.tga";
    string name_requirement_layer_red = "input/layer_red.tga";
    Image requirement_layer_red;
    filling(name_requirement_layer_red, requirement_layer_red);

    //string name_requirement_pattern1 = "/Users/failop/CLionProjects/Project2/ImageProcessing/input/pattern1.tga";
    string name_requirement_pattern1 = "input/pattern1.tga";
    Image requirement_pattern1;
    filling(name_requirement_pattern1, requirement_pattern1);

    string name_requirement_pattern2 = "input/pattern2.tga";
    //string name_requirement_pattern2 = "/Users/failop/CLionProjects/Project2/ImageProcessing/input/pattern2.tga";
    Image requirement_pattern2;
    filling(name_requirement_pattern2, requirement_pattern2);

    //string name_requirement_text = "/Users/failop/CLionProjects/Project2/ImageProcessing/input/text.tga";
    string name_requirement_text = "input/text.tga";
    Image requirement_text;
    filling(name_requirement_text, requirement_text);

    //string name_requirement_text2 = "/Users/failop/CLionProjects/Project2/ImageProcessing/input/text2.tga";
    string name_requirement_text2 = "input/text2.tga";
    Image requirement_text2;
    filling(name_requirement_text2, requirement_text2);

            /* =====================================================*/
                         //PART 2 - task 1
                     // Multiply images
            /* =====================================================*/

   cout <<"\nWelcome to task 1:" <<endl;
   //step 1: create full operation
   Image task1 = Multiply(requirement_layer1, requirement_pattern1);
   //step 2: now with the image on pixel, create the file;
   //string output_task1 = "/Users/failop/CLionProjects/Project2/ImageProcessing/output/part1.tga";
   string output_task1 = "output/part1.tga";
    creation(output_task1, task1);
   //step 3: read file
   Image task1_result;
   filling(output_task1, task1_result);

   //step 4: read example1
   //string name_task1 = "/Users/failop/CLionProjects/Project2/ImageProcessing/examples/EXAMPLE_part1.tga";
    string example_task1 = "examples/EXAMPLE_part1.tga";
    Image picture_task1;
   filling(example_task1, picture_task1);
   cout << "Test task1:" <<endl;
   pretest(picture_task1,task1_result,score);
   cout << "Score: " << score<< endl;


             /* =====================================================*/
                            //PART 2 - task 2
                        // Substract images
            /* =====================================================*/

    cout<<"\nWelcome to task 2" <<endl;

    //step 1: create image
    Image task2 = substract(requirement_layer2, requirement_car); //top, bottom

    //step 2: create image in computer
    //string output_task2 = "/Users/failop/CLionProjects/Project2/ImageProcessing/output/part2.tga";
    string output_task2 = "output/part2.tga";
    creation(output_task2, task2);

    //step 3: read example
    //string name_task2 = "/Users/failop/CLionProjects/Project2/ImageProcessing/examples/EXAMPLE_part2.tga";
    string example_task2 = "examples/EXAMPLE_part2.tga";
    Image picture_task2;
    filling(example_task2, picture_task2);

    //step 4: test
    cout << "Test task2" <<endl;
    pretest(picture_task2,task2,score);
    cout << "Score: " << score<< endl;


            /* =====================================================*/
                        //PART 2 - task 3
                     // Screen images
            /* =====================================================*/

    cout << "\nWelcome to task 3" <<endl;

    //step 1: create multipy image
    Image task3 = Multiply(requirement_layer1, requirement_pattern2);

    //step 3: load text
//    string name_requirement3_C = "/Users/failop/CLionProjects/Project2/ImageProcessing/input/text.tga";
    string name_requirement3_C = "input/text.tga";
    Image picture_requirement3_C;
    filling(name_requirement3_C, picture_requirement3_C);

    //step 4: combine requirement and picture task with SCREEN
    Image task3_part2 = Screen(picture_requirement3_C, task3);
    //step 5:write file
//    string output_task3 = "/Users/failop/CLionProjects/Project2/ImageProcessing/output/part3.tga";
    string output_task3 = "output/part3.tga";
    creation(output_task3, task3_part2);

    //step 3: read file
    Image task3_result;
    filling(output_task3, task3_result);

    //step 4: read example1
//    string name_task3B = "/Users/failop/CLionProjects/Project2/ImageProcessing/examples/EXAMPLE_part3.tga";
    string example_task3 = "examples/EXAMPLE_part3.tga";
    Image picture_task3B;
    filling(example_task3, picture_task3B);


    //final step: test
    cout << "Test task3" <<endl;
    pretest(picture_task3B,task3_result,score);
    cout << "Score: " << score<< endl;

            /* =====================================================*/
                        //PART 2 - task 4
                    // Substract images
            /* =====================================================*/
    cout << "\nWelcome to task4" <<endl;
    //step 1: create multiplication image
    Image task4 = Multiply(requirement_layer2, requirement_circles);
    //step 2: load "pattern2.tga"
    //string requirement4 = "/Users/failop/CLionProjects/Project2/ImageProcessing/input/pattern2.tga";
    string requirement4 = "input/pattern2.tga";
    Image picture_requirement4;
    filling(requirement4, picture_requirement4);

    //step 3: create substract with "pattern2" as top layer
    Image task4_part2 = substract(picture_requirement4, task4);

    //step 4: write file and read it
    //string output_task4 = "/Users/failop/CLionProjects/Project2/ImageProcessing/output/part4.tga";
    string output_task4 = "output/part4.tga";

    creation(output_task4, task4_part2);

    //step 5: read file
    Image task4_result;
    filling(output_task4, task4_result);

    //step 6: read example1
    //string name_task4 = "/Users/failop/CLionProjects/Project2/ImageProcessing/examples/EXAMPLE_part4.tga";
    string example_task4 = "examples/EXAMPLE_part4.tga";
    Image picture_task4;
    filling(example_task4, picture_task4);


    //final step: test
    cout << "Test task4" <<endl;
    pretest(picture_task4,task4_result,score);
    cout << "Score: " << score<< endl;



            /* =====================================================*/
                            //PART 2 - task 5
                        // Substract images
            /* =====================================================*/

    cout << "\nWelcome to task5" <<endl;
    //step 1: combine using overlay
    Image task5 = Overlay(requirement_layer1,requirement_pattern1);
    //step 2: write file
    //string output_task5 = "/Users/failop/CLionProjects/Project2/ImageProcessing/output/part5.tga";
    string output_task5 = "output/part5.tga";
    creation(output_task5, task5);

    //step 3: read file
    Image task5_result;
    filling(output_task5, task5_result);

    //step 4: read example1
    //string name_task5 = "/Users/failop/CLionProjects/Project2/ImageProcessing/examples/EXAMPLE_part5.tga";
    string example_task5 = "examples/EXAMPLE_part5.tga";
    Image picture_task5;
    filling(example_task5, picture_task5);


    //final step: test
    cout << "Test task5" <<endl;
    pretest(picture_task5,task5_result,score);
    cout << "Score: " << score<< endl;


            /* =====================================================*/
                            //PART 2 - task 6
                        // add 200 to the green channel
            /* =====================================================*/

    cout<<"\nWelcome to task 6" <<endl;
    Image picture_task6;
    Duplication(picture_task6, requirement_car);

    for(int i =0; i<picture_task6.rainbow.size(); i++)
    {
        unsigned char plus =200;
        unsigned char newgreen =  addclamp(picture_task6.rainbow.at(i).getgreenC(), plus);
        picture_task6.rainbow.at(i).setgreen(newgreen);
    }
    //create file
    //string output_task6 = "/Users/failop/CLionProjects/Project2/ImageProcessing/output/part6.tga";
    string output_task6 = "output/part6.tga";
    creation(output_task6, picture_task6);

    //reconfirm the creation of file
    Image picture_task6result;
    filling(output_task6, picture_task6result);

    //now compare with example
    //string name_task6B = "/Users/failop/CLionProjects/Project2/ImageProcessing/examples/EXAMPLE_part6.tga";
    string example_task6 = "examples/EXAMPLE_part6.tga";

    Image picture_task6B;
    filling(example_task6, picture_task6B);
    cout << "Test task6" <<endl;
    pretest(picture_task6result,picture_task6B,score);
    cout << "Score: " << score<< endl;

            /* =====================================================*/
                                //PART 2 - task 7
                        // multiply separate channel by scale
            /* =====================================================*/

    cout<<"\nWelcome to task 7" <<endl;
    //step 1: work with loaded "car.tga"
    Image picture_task7;
    Duplication(picture_task7, requirement_car);

    //step 2: multiply by 4 the red channel
    int multired =4;
    //int multired = 4;
    for(int i =0; i<picture_task7.rainbow.size(); i++)
    {
        unsigned char newred =  normalizebyscale(picture_task7.rainbow.at(i).getredC(), multired);
        picture_task7.rainbow.at(i).setred(newred);
    }

    //step 3: mutliply the blue by 0
    int multiblue =0;
    for(int i =0; i<picture_task7.rainbow.size(); i++)
    {
        unsigned char newblue =  normalizebyscale(picture_task7.rainbow.at(i).getblueC(), multiblue);
        picture_task7.rainbow.at(i).setblue(newblue);
    }
    //step 4: create file
    //string output_task7 = "/Users/failop/CLionProjects/Project2/ImageProcessing/output/part7.tga";
    string output_task7 = "output/part7.tga";
    creation(output_task7, picture_task7);

    //step 5: reconfirm the creation of file
    Image picture_task7result;
    filling(output_task7, picture_task7result);

    //final step: now compare with example
    //string name_task7B = "/Users/failop/CLionProjects/Project2/ImageProcessing/examples/EXAMPLE_part7.tga";
    string example_task7 = "examples/EXAMPLE_part7.tga";
    Image picture_task7B;
    filling(example_task7, picture_task7B);
    cout << "Test task7" <<endl;
    pretest(picture_task7result,picture_task7B,score);
    cout << "Score: " << score<< endl;

            /* =====================================================*/
                            //PART 2 - task 8
                    // separate each channel
            /* =====================================================*/
    cout<<"\nWelcome to task 8" <<endl;
    int score2 =0;
    //step 1: work with loaded "car.tga"
    Image picture_task8;
    Duplication(picture_task8, requirement_car);

    //step 2: load each channel in different files -> create an image with only one of the channel

    //red
    Image picture_task8_r;
    Duplication(picture_task8_r, picture_task8);

    for(int i=0; i<picture_task8_r.rainbow.size(); i++)
    {
        unsigned char redC = picture_task8_r.rainbow.at(i).getredC();
        picture_task8_r.rainbow.at(i).setgreen(redC);
        picture_task8_r.rainbow.at(i).setblue(redC);
    }

    //blue
    Image picture_task8_b;
    Duplication(picture_task8_b, picture_task8);
    for(int i=0; i<picture_task8_b.rainbow.size(); i++)
    {
        unsigned char blueC = picture_task8_b.rainbow.at(i).getblueC();
        picture_task8_b.rainbow.at(i).setgreen(blueC);
        picture_task8_b.rainbow.at(i).setred(blueC);
    }

    //green
    Image picture_task8_g;
    Duplication(picture_task8_g, picture_task8);
    for(int i=0; i<picture_task8_g.rainbow.size(); i++)
    {
        unsigned char greenC = picture_task8_g.rainbow.at(i).getgreenC();
        picture_task8_g.rainbow.at(i).setblue(greenC);
        picture_task8_g.rainbow.at(i).setred(greenC);
    }

    //step 3: create separate images
    //red
    //string output_task8_r = "/Users/failop/CLionProjects/Project2/ImageProcessing/output/part8_r.tga";
    string output_task8_r = "output/part8_r.tga";

    creation(output_task8_r, picture_task8_r);
    //blue
//    string output_task8_b = "/Users/failop/CLionProjects/Project2/ImageProcessing/output/part8_b.tga";
    string output_task8_b = "output/part8_b.tga";
    creation(output_task8_b, picture_task8_b);
    //green
    //string output_task8_g = "/Users/failop/CLionProjects/Project2/ImageProcessing/output/part8_g.tga";
    string output_task8_g = "output/part8_g.tga";
    creation(output_task8_g, picture_task8_g);

    //step 4: reconfirm the creation of file
    //red
    Image picture_task8_r_result;
    filling(output_task8_r, picture_task8_r_result);
    //blue
    Image picture_task8_b_result;
    filling(output_task8_b, picture_task8_b_result);
    //green
    Image picture_task8_g_result;
    filling(output_task8_g, picture_task8_g_result);

    //final step: now compare with example
    //red
    //string name_task8_r = "/Users/failop/CLionProjects/Project2/ImageProcessing/examples/EXAMPLE_part8_r.tga";
    string example_task8_r = "examples/EXAMPLE_part8_r.tga";
    Image picture_task8_rB;
    filling(example_task8_r, picture_task8_rB);
    cout << "Test task8 red" <<endl;
    pretest(picture_task8_r_result,picture_task8_rB,score2);
    //blue
    //string name_task8_b = "/Users/failop/CLionProjects/Project2/ImageProcessing/examples/EXAMPLE_part8_b.tga";
    string example_task8_b = "examples/EXAMPLE_part8_b.tga";
    Image picture_task8_bB;
    filling(example_task8_b, picture_task8_bB);
    cout << "\nTest task8 blue" <<endl;
    pretest(picture_task8_b_result,picture_task8_bB,score2);
    //green
    //string name_task8_g = "/Users/failop/CLionProjects/Project2/ImageProcessing/examples/EXAMPLE_part8_g.tga";
    string example_task8_g = "examples/EXAMPLE_part8_g.tga";
    Image picture_task8_gB;
    filling(example_task8_g, picture_task8_gB);
    cout << "\nTest task8 green" <<endl;
    pretest(picture_task8_g_result,picture_task8_gB,score2);
    if(score2 ==33)
    {
        score+=11;
    }
    cout << "Score: " << score<< endl;

            /* =====================================================*/
                        //PART 2 - task 9
                    // combine each image into a only one
            /* =====================================================*/
    cout<<"\nWelcome to task 9" <<endl;

    //step 1: create image to work it, make a duplicate and save one third of the work
    Image task9combine;
    Duplication(task9combine, requirement_layer_red);

    //step 2: transplant the color into "combine"
    for(int io=0; io<task9combine.rainbow.size(); io++)
    {
        unsigned char blue_blue = requirement_layer_blue.rainbow.at(io).getblueC();
        unsigned char green_green = requirement_layer_green.rainbow.at(io).getgreenC();
        task9combine.rainbow.at(io).setblue(blue_blue);
        task9combine.rainbow.at(io).setgreen(green_green);
    }

    //step 3: create image on computer
   //string output_task9 = "/Users/failop/CLionProjects/Project2/ImageProcessing/output/part9.tga";
    string output_task9 = "output/part9.tga";
    creation(output_task9, task9combine);

    //step 4: recreate image
    Image picture_task9;
    filling(output_task9, picture_task9);

    //final step: test
    //string name_task9 = "/Users/failop/CLionProjects/Project2/ImageProcessing/examples/EXAMPLE_part9.tga";
    string example_task9 = "examples/EXAMPLE_part9.tga";
    Image picture_task9B;
    filling(example_task9, picture_task9B);
    cout << "Test task 9" <<endl;
    pretest(picture_task9,picture_task9B,score);
    cout << "Score: " << score<< endl;


            /* =====================================================*/
                                //PART 2 - task 10
                    // flip image
            /* =====================================================*/
    cout<<"\nWelcome to task 10" <<endl;


    //step 1: duplicate image ->you don't want to change he original
    Image task10;
    Duplication(task10, requirement_text2);

    //step 3: rotate image
    for(int io=0; io<task10.rainbow.size(); io++)
    {
        //run start from the beginning -> 0 = last one -0, 1 = lastone -1
        int actualpixel = task10.rainbow.size()-1 - io;
        unsigned char newblue = requirement_text2.rainbow.at(actualpixel).getblueC();
        task10.rainbow.at(io).setblue(newblue);
        unsigned char newgreen = requirement_text2.rainbow.at(actualpixel).getgreenC();
        task10.rainbow.at(io).setgreen(newgreen);
        unsigned char newred = requirement_text2.rainbow.at(actualpixel).getredC();
        task10.rainbow.at(io).setred(newred);
    }

    //step 4: create image on compile
    //string output_task10 = "/Users/failop/CLionProjects/Project2/ImageProcessing/output/part10.tga";
    string output_task10 = "output/part10.tga";
    creation(output_task10, task10);

    //step 5: recreate image
    Image picture_task10;
    filling(output_task10, picture_task10);

    //final step: test image
    //string name_task10B = "/Users/failop/CLionProjects/Project2/ImageProcessing/examples/EXAMPLE_part10.tga";
    string example_task10 = "examples/EXAMPLE_part10.tga";
    Image picture_task10B;
    filling(example_task10, picture_task10B);
    cout << "Test task 10" <<endl;
    pretest(picture_task10,picture_task10B,score);
    cout << "Score: " << score<< endl;

            /* =====================================================*/
                           //PART 2 - task extra credit
                        // paste four image one with another into a big square
            /* =====================================================*/

    cout<<"\nWelcome to extra-task" <<endl;
    //step 1: work with loaded four image -> text, circle, car, pattern1
    //you already did on the Part 1



    //step 2: create an image for result ->get header by duplicating it.
    Image taskextra;
    DuplicationHeader(taskextra, requirement_text);

    //step 3: change the size (height and width
    short width1 = requirement_text.begin.getwigth();
    short width2 = requirement_pattern1.begin.getwigth();
    short totalwidth = width1 + width2;
    //cout << "wigth1 : " << width1 << "   width2: " <<width2 << "   \ntotal width: " << totalwidth <<endl;
    short height1 = requirement_text.begin.getheight();
    short height2 = requirement_car.begin.getheight();
    short totalheight = height1 +height2;

    taskextra.begin.setheight(totalheight);
    taskextra.begin.setwidth(totalwidth);
    //cout << "height1 : " << height1 << "   height2: " <<height2 << "   \ntotal width: " << totalheight <<endl;

    //step 4: move pixels
    int ultimatewidth = totalwidth;
    int ultimateheight = totalheight;
    int ultimatesize = totalheight*totalwidth;
    int countwidth =0;
    int countwidth1=0;
    int countwidth2=0;
    int height =0;
    int countheight=0;
    int countheight1 =0;
    int countheight2 =0;
    //cout << "Ultimate size " << ultimatesize;
    //cout << "Print "<< taskextra.begin.getwigth() <<endl;
    //cout << "Print "<<taskextra.begin.getheight() <<endl;
    for(int i = 0; i<ultimatesize; i++)
    {
        if(height < ultimateheight/2)
        {
            if (countwidth < ultimatewidth/2)
            {
                Pixel pix = createpix(requirement_text, countwidth1);
                taskextra.rainbow.push_back(pix);
                countwidth++;
                countwidth1++;
                //cout << "text: " << countwidth1 <<endl;
                //cout << "pattern " << countwidth2 << endl;
                //cout << i <<endl;
            }
            else
            {
                Pixel pix = createpix(requirement_pattern1, countwidth2);
                taskextra.rainbow.push_back(pix);
                countwidth2++;
                countwidth++;
                if (!(countwidth < ultimatewidth)) {
                    countwidth = 0;
                    height++;
                }
                //cout << "pattern " << countwidth2 << endl;
                //cout << "text: " << countwidth1 <<endl;
                //cout << i <<endl;
            }
        }
        else
        {
            if(countheight <  ultimateheight/2)
            {
                Pixel pix = createpix(requirement_car, countheight1);
                taskextra.rainbow.push_back(pix);
                countheight++;
                countheight1++;
                //cout << "car " << countheight1 << endl;
                //cout << "circles " << countheight2 << endl;
                //cout << i <<endl;
            }
            else
            {
                Pixel pix = createpix(requirement_circles, countheight2);
                taskextra.rainbow.push_back(pix);
                countheight2++;
                countheight++;
                if (!(countheight < ultimateheight))
                {
                    countheight = 0;
                }
                //cout << "circles " << countheight2 << endl;
                //cout << "car " << countheight1 << endl;
                //cout << i <<endl;
            }
        }
        //cout << "vector size: " << taskextra.rainbow.size()<<endl;
    }

    //step 5: create image on computer
    //string output_taskextra = "/Users/failop/CLionProjects/Project2/ImageProcessing/output/extracredit.tga";
    string output_taskextra = "output/extracredit.tga";
    creation(output_taskextra, taskextra);

    //step 6: recreate image
    Image picture_taskextra;
    filling(output_taskextra, picture_taskextra);

    //final step: test image
    //string name_taskextraB = "/Users/failop/CLionProjects/Project2/ImageProcessing/examples/EXAMPLE_extraCredit.tga";
    string example_taskextra = "examples/EXAMPLE_extraCredit.tga";
    Image picture_taskextraB;
    filling(example_taskextra, picture_taskextraB);
    cout << "Test extra-task" <<endl;
    int Nullscore =0;
    pretest(picture_taskextra,picture_taskextraB,Nullscore);
    score+=15;
    if(score >=110 && Nullscore > 0)
    {
        cout << "Perfect score + extra: " << score <<endl;
    }
    else
    {
    cout << " Total Score: " << score<< endl;
    }


    return 0;
}
