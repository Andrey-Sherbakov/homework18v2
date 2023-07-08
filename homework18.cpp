// homework18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class PlayerInfo
{
public:
    int GetPlayerScore()
    {
        return score;
    }

    void SetPlayerScore(int newScore)
    {
        score = newScore;
    }

    string GetPlayerName()
    {
        return playerName;
    }

    void SetPlayerName(string newName)
    {
        playerName = newName;
    }

private:
    int score;
    string playerName;
};


int main()
{
    int n;
    
    //Создание массива.
    cout << "Number of players:";
    cin >> n;
    PlayerInfo* playerInfo = new PlayerInfo[n];

    //Наполнение массива.
    string tempPlayerName;
    int tempScore;
    for (int i = 0; i < n; i++) {
        cout << "Enter player " << i + 1 << " name: ";
        cin >> tempPlayerName;
        playerInfo[i].SetPlayerName(tempPlayerName);
        cout << "Enter player " << i + 1 << " score: ";
        cin >> tempScore;
        playerInfo[i].SetPlayerScore(tempScore);
    }
    cout << endl;

    //Вывод массива.
    for (int i = 0; i < n; i++) {
        cout << playerInfo[i].GetPlayerName() << " ";
        cout << playerInfo[i].GetPlayerScore();
        cout << endl;
    }
    cout << endl;

    //Сортировка массива.
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (playerInfo[j].GetPlayerScore() > playerInfo[j+1].GetPlayerScore()) {
                auto temp = playerInfo[j];
                playerInfo[j] = playerInfo[j + 1];
                playerInfo[j + 1] = temp;
            }
        }
    }

    //Вывод сортированного массива.
    for (int i = 0; i < n; i++) {
        cout << playerInfo[i].GetPlayerName() << " ";
        cout << playerInfo[i].GetPlayerScore();
        cout << endl;
    }

    delete[] playerInfo;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
