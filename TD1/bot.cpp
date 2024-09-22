#include "bot.h"

std::string formatName(const std::string &name)
{
    std::string formattedName = name;
    formattedName[0] = toupper(formattedName[0]);
    for (int i = 1; i < formattedName.size(); i++)
    {
        formattedName[i] = tolower(formattedName[i]);
    }
    return formattedName;
}

std::string formatSurname(const std::string &surname)
{
    std::string formattedSurname = surname;
    for (int i = 0; i < formattedSurname.size(); i++)
    {
        formattedSurname[i] = toupper(formattedSurname[i]);
    }
    return formattedSurname;
}

int generateRandomNumber()
{
    srand(time(0));
    return rand() % 1001;
}

bool compareNumbers(int userGuess, int randomNumber)
{
    if (userGuess > randomNumber)
    {
        std::cout << "Your guess is higher than the generated number!" << std::endl;
        return false;
    }
    else if (userGuess < randomNumber)
    {
        std::cout << "Your guess is lower than the generated number!" << std::endl;
        return false;
    }
    else
    {
        std::cout << "Congratulations! You guessed the correct number!" << std::endl;
        return true;
    }
}

int main()
{
    std::cout << "Welcome to the terminal !\nWhat's your name & surname ?" << std::endl;
    std::string name;
    std::string surname;
    std::cin >> name >> surname;

    name = formatName(name);
    surname = formatSurname(surname);

    std::cout << "Hello " << name << " " << surname << " !" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    int randomNumber = generateRandomNumber();
    std::cout << "A random number between 0 and 1000 has been generated." << std::endl;

    int userGuess;
    int attempts = 0;
    bool correctGuess = false;

    while (!correctGuess)
    {
        std::cout << "Please enter a number between 0 and 1000: ";
        std::cin >> userGuess;
        attempts++;
        correctGuess = compareNumbers(userGuess, randomNumber);
    }

    std::cout << "--------------------------------" << std::endl;
    std::cout << "You guessed the correct number in " << attempts << " attempts!" << std::endl;

    return 0;
}
