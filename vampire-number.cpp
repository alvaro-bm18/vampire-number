#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int fact(int n)
{
    int f = 1;
    for(int i = 1; i < n + 1; i++) f *= i;
    return f;
}

int getCombinations(string number, int len)
{
    string noRepUnits = "";
    int enteriPermutations = fact(len);
    int repitedPermutations = 1;

    for(char n : number)
    {
        bool valid = true;
        for(char u : noRepUnits)
        {
            if(n == u) valid = false;
        }

        if(valid == true) noRepUnits += n;
    }

    for(char u : noRepUnits)
    {
        int rep = 0;
        for(char n : number)
        {
            if(n == u) rep++;
        }
        repitedPermutations *= fact(rep);
    }
    int combinationsTotal = enteriPermutations / repitedPermutations;
    return combinationsTotal;
}

vector <vector <int>> permutateString(int numberItself, int itsLen)
{
    vector<string> permutations;
    string numberString = to_string(numberItself);
    int combinations = getCombinations(numberString, itsLen);
    srand(time(0));


    while(permutations.size() != combinations)
    {
        string combination = "";
        bool valid_combination = true;
        vector <int> indexs;

        while( indexs.size() != itsLen)
        {
            bool valid = true;
            int randomIndex = rand()%itsLen;

            for(int i = 0; i < indexs.size(); i++)
            {
                if(indexs[i] == randomIndex)
                {
                    valid = false;
                    break;
                }
            }

            if(valid == true) indexs.push_back(randomIndex);
        }

        for(int i : indexs) combination += numberString[i];

        for(int j = 0; j < permutations.size(); j++)
        {
            if(permutations[j] == combination)
            {
                valid_combination = false;
                break;
            }
        }

        if(valid_combination == true) permutations.push_back(combination);
    }

    sort(permutations.begin(), permutations.end());
    vector<vector<int>> combinationsAB;
    int middle = itsLen / 2;

    for(string perm : permutations)
    {
        int a = stoi(perm.substr(0, middle));
        int b = stoi(perm.substr(middle, itsLen));
        combinationsAB.push_back({a,b,a*b});
    }

    return combinationsAB;
}


int main()
{
    //number is an integer, ignores all before the dot.
    int number = 12345;
    int digitsLen = to_string(number).length();

    vector <vector<int>> permutations;
    if(number > 9) permutations = permutateString(number, digitsLen);

    if(number < 0)
    {
        cout << "El numero es un numero negativo, no puede ser un vampire number" << endl;
        return 0;
    }

    if(number > 99)
    {
        if(digitsLen % 2 == 0)
        {
            //vampire number
            bool isItaVampireNum = false;
            cout << "Combinations : " << endl;

            for(vector <int> perm : permutations)
            {
                if(perm[2] == number) isItaVampireNum = true;
                cout << perm[0] << " * " << perm[1] << " = " << perm[2] << endl;
            }

            if(isItaVampireNum == true)
                cout << "YES!, " << number << " is a vampire number " << endl;
            else
                cout << "NO!, " << number << " isn't a vampire number " << endl;

        }
        else
        {
            //Pseudovampire
            bool isItaPseudovampireNum = false;
            cout << "Combinations : " << endl;

            for(vector <int> perm : permutations)
            {
                if(perm[2] == number) isItaPseudovampireNum = true;
                cout << perm[0] << " * " << perm[1] << " = " << perm[2] << endl;
            }

            if(isItaPseudovampireNum == true)
                cout << "YES!, " << number << " is a pseudovampire number " << endl;
            else
                cout << "NO!, " << number << " isn't a pseudovampire number " << endl;

        }
    }
    else
    {
        // 0 - 99
        //Normal Number
        cout << number << " cann't be a vampire or pseudovampire number cause < 99"<<endl;
        if( number <= 9 )
        {
            cout << "Combinations are 0";
        }
        else
        {
            cout << "Combinations : " << endl;

            for(vector <int> perm : permutations)
                cout << perm[0] << " * " << perm[1] << " = " << perm[2] << endl;
        }

    }
    return 0;
}
