#include "tennis.h"

int main()
{
    int player1Points, player2Points;

    std::cout << "Enter the number of rallies won by player 1: ";
    std::cin >> player1Points;
    std::cout << "Enter the number of rallies won by player 2: ";
    std::cin >> player2Points;

    std::cout << "Current score: " << calculateGameScore(player1Points, player2Points) << std::endl;

    return 0;
}

std::string convertPointsToScore(int points)
{
    switch (points)
    {
    case 0:
        return "0";
    case 1:
        return "15";
    case 2:
        return "30";
    case 3:
        return "40";
    default:
        return "";
    }
}

std::string calculateGameScore(int player1Points, int player2Points)
{
    if (player1Points >= 4 && player1Points >= player2Points + 2)
    {
        return "Player 1 wins the game";
    }
    if (player2Points >= 4 && player2Points >= player1Points + 2)
    {
        return "Player 2 wins the game";
    }

    if (player1Points >= 3 && player2Points >= 3)
    {
        if (player1Points == player2Points)
        {
            return "Deuce";
        }
        else if (player1Points == player2Points + 1)
        {
            return "Advantage Player 1";
        }
        else if (player2Points == player1Points + 1)
        {
            return "Advantage Player 2";
        }
    }

    std::string scorePlayer1 = convertPointsToScore(player1Points);
    std::string scorePlayer2 = convertPointsToScore(player2Points);

    return scorePlayer1 + " - " + scorePlayer2;
}