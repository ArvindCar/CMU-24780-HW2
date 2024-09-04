#include<stdio.h>
#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>

int main(void){
    std::vector<std::string> foodchoices = {"Burger from BK", "Pizza from Dominos", "Salad from Root", "Rice Bowl from Chipotle", "Tacos from TexMex", "Noodles from Noodlehead", "Butter chicken from Taste of India"};
    std::vector<std::string> days = {"Sun", "Mon", "Tue", "Wed", "Thr", "Fri", "Sat"};
    int randnum;
    srand(time(NULL));
    for(int i=0; i<7; i++)
    {
        randnum = rand()%(7-i);
        std::cout<< days[i] << " " << foodchoices[randnum]<<"\n";
        foodchoices.erase(foodchoices.begin() + randnum);
    }

}
