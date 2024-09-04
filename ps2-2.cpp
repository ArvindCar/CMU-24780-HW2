#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <random>  

void SwapInt(int &a,int &b)
{
    int c;
    c=b;
    b=a;
    a=c;
}

void shuffleArray(int* arr, int size) 
{
    int j;
    for (int i = size - 1; i > 0; --i) 
    {
        j = rand()%size;
        SwapInt(arr[i], arr[j]);
    }
}

int main() 
{
    const int num1 = 12;
    const int num2 = 12;
    const int totalCards = num1*num2;
    int flashcards[totalCards];
    int numcards, randnum1, randnum2, numspaces, combinnum, ans, userans, numcorrect;
    numcorrect = 0;

    int index = 0;
    for (int i = 1; i <= 12; ++i) 
    {
        for (int j = 1; j <= 12; ++j) 
        {
            flashcards[index++] = i * 100 + j;
        }
    }
    srand(time(NULL));
    shuffleArray(flashcards, totalCards);

    std::cout << "Enter number of cards to practise: ";
    std::cin >> numcards;
    while (numcards < 1 || numcards > totalCards) 
    {
        std::cout << "Number of cards must be between 1 and " << totalCards << ". \nEnter again.\nEnter number of cards to practise: ";
        std::cin >> numcards;
    }

    std::time_t startTime = std::time(nullptr);

    for (int i = 0; i < numcards; i++) 
    {
        combinnum = flashcards[i];
        randnum1 = combinnum / 100;
        randnum2 = combinnum % 100;
        ans = randnum1 * randnum2;

        numspaces = 2 - (randnum1/10 + randnum2/10);
        std::cout << "+-----+\n";
        std::cout << "|     |\n";
        std::cout << "|";
        for (int j = 0; j < numspaces; j++) 
        {
            std::cout << " ";
        }
        std::cout << randnum1 << "X" << randnum2 << "|\n";
        std::cout << "|     |\n";
        std::cout << "+-----+\n";
        std::cout << "Enter your answer: ";
        std::cin >> userans;

        if (userans == ans) 
        {
            std::cout << "Correct!\n";
            numcorrect++;
        } 
        else 
        {
            std::cout << "Wrong. Correct Answer is " << ans << "\n";
        }
    }

    std::cout << "You answered " << numcards << " problems in " << std::difftime(std::time(nullptr), startTime) << " seconds\n";
    std::cout << "You answered " << numcorrect << " problems correctly (" << double(numcorrect * 100) / numcards << "%)\n";

    return 0;
}
