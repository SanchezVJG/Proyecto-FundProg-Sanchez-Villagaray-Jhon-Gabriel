#include <iostream>
#include <iomanip>
#include "grid.h"
using namespace std;

void display(ostream &os, Complex **grid, size_t fil, size_t col)
{
    os << setw(3) << "num";
    for (size_t i = 0; i < col; i++)
    {
        os << setw(20) << char('A' + i);
    }
    os << "\n";
    for (size_t i = 0; i < fil; i++)
    {
        os << setw(3) << i + 1;
        for (size_t j = 0; j < col; j++)
        {
            os << setw(20) << (grid[i][j]);
        }
        os << "\n";
    }
    os << "\n";
}
size_t find_noParenth(const std::string &str, const string &characters)
{
    size_t inception = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str.at(i) == '(')
            inception++;
        if (str.at(i) == ')')
            inception--;
        if (characters.find(str.at(i)) != std::string::npos && inception == 0)
        {
            return i;
        }
    }
    return std::string::npos;
}

bool correctParenth(const std::string &str)
{
    size_t inception = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str.at(i) == '(')
            inception++;
        if (str.at(i) == ')')
            inception--;
    }
    if (inception == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void deleteSpaces(std::string &str)
{
    size_t i = str.size() - 1;
    while (i > 0)
    {
        i--;
        if (str.at(i) == ' ')
        {
            str.erase(i, 1);
        }
    }
    return;
}

Node *read(const std::string &input, Complex **grid)
{
    size_t found;
    string reduced = input;
    for (;;)
    {
        found = find_noParenth(reduced, "+-");
        if (found != std::string::npos)
        {
            biNode *s=nullptr;
            s= new biNode(nullptr,nullptr,0);
            if (found ==0)
            s->set1(new constNode(Complex{0,0}));
            else
            s->set1(read(reduced.substr(0, found), grid));
            if (found == input.size()-1)
            s->set2(new constNode(Complex{0,0}));
            else 
            s->set2(read(reduced.substr(found + 1, std::string::npos), grid));
            if (reduced.at(found) == '+')
            {
                s->seti(0);
            }
            else
            {
                s->seti(1);
            }
            return s;
        }
        found = find_noParenth(reduced, "*/");
        if (found != std::string::npos)
        {
            biNode *p = nullptr;
            p = new biNode(nullptr,nullptr,0);
            p->set1(read(reduced.substr(0, found), grid));
            p->set2(read(reduced.substr(found + 1, std::string::npos), grid));
            if (reduced.at(found) == '*')
            {
                p->seti(2);
            }
            else
            {
                p->seti(3);
            }
            return p;
        }
        if (reduced.at(0) == '(' && reduced.at(reduced.size() - 1) == ')')
        {
            reduced = reduced.substr(1, reduced.size() - 2);
        }
        else
        {
            Node *n = nullptr;
            n = nullptr;
            if (reduced.substr(0, 3) == "sin")
            {
                n = new unNode(read(reduced.substr(3, string::npos), grid),1);
            }
            if (reduced.substr(0, 3) == "cos")
            {
                n = new unNode(read(reduced.substr(3, string::npos), grid),2);
            }
            if (reduced.substr(0, 3) == "abs")
            {
                n = new unNode(read(reduced.substr(3, string::npos), grid),3);
            }
            if (reduced.substr(0, 2) == "ln")
            {
                n = new unNode(read(reduced.substr(2, string::npos), grid),4);
            }
            if (reduced.substr(0, 2) == "e^")
            {
                n = new unNode(read(reduced.substr(2, string::npos), grid),0);
            }
            if (reduced.size() != 1 && isalpha(reduced.at(0)) != 0)
            {
                n= new constNode(grid[stoi(input.substr(1)) - 1][reduced.at(0) - 'A']);
            }
            else
            {
                if (reduced.at(0) == 'i')
                {
                    n = new constNode(Complex{0,1});
                }
                else
                {
                    n = new constNode(Complex{stof(reduced),0});
                }
            }
            return n;
        }
    }
}

void start()
{
    const size_t fil = 10;
    const size_t col = 9;
    Complex **grid;
    grid = new Complex *[fil];
    for (size_t i = 0; i < 10; i++)
    {
        grid[i] = new Complex[col];
    }
    Node *nodes = nullptr;
    size_t targetC = 0;
    size_t targetN = 0;
    for (;;)
    {
        display(std::cout, grid, fil, col);
        string input;
        getline(cin, input);
        deleteSpaces(input);
        if (correctParenth(input))
        {
            if (input == "end")
            {
                break;
            }
            targetC = input.at(0) - 'A';
            targetN = stoi(input.substr(1, input.find("=") - 1)) - 1;
            nodes = read(input.substr(input.find("=") + 1, std::string::npos), grid);
            grid[targetN][targetC] = nodes->eval();
        }
        else
        {
            cout << "Input error" << endl;
        }
        delete nodes;
    }
    for (size_t i = 0; i < 10; i++)
    {
        delete[] grid[i];
    }
    delete[] grid;
    cout << "Finished" << endl;
    return;
}