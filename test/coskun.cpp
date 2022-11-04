
#include <bits/stdc++.h>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

//////////////////////////////
//////////////////////////////
//////////////////////////////
class Solution
{
private:
    string possible[81]
    {
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
    };
    /*****************************************/
    void find_swordfish(void)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t index;
        size_t indexA;
        size_t indexB;
        size_t count;
        vector<size_t> adr_list;
        vector<size_t> candidate_listA;
        vector<size_t> candidate_listB;
        vector<size_t> candidate_listC;
        vector<char> pairs;
        vector<char> triples;
        for(char fish = '1'; fish <= '9'; fish++)
        {
            candidate_listA.clear();
            candidate_listB.clear();
            candidate_listC.clear();
            for(size_t colum = 0; colum < 9; colum++)
            {
                count = 0;
                adr_list.clear();
                for(size_t row = 0; row < 9; row++)
                {
                    index = (colum * 9) + row;
                    if(possible[index].find(fish) != string::npos)
                    {
                        adr_list.push_back(index);
                        count++;
                    }
                }
                if(count == 2 || count == 3)
                {
                    if(candidate_listA.size() == 0)
                    {
                        candidate_listA = adr_list;
                    }
                    else if(candidate_listB.size() == 0)
                    {
                        count = 0;
                        for(size_t x : candidate_listA)
                        {
                            for(size_t y : adr_list)
                            {
                                if(x + ((adr_list[0] / 9) - (candidate_listA[0] / 9)) * 9 == y)
                                {
                                    count++;
                                }
                            }
                        }
                        if(candidate_listA.size() == 3)
                        {
                            if((adr_list.size() == 3 && count == 3) || (adr_list.size() == 2 && count))
                            {
                                candidate_listB = adr_list;
                            }
                        }
                        else
                        {
                            if((adr_list.size() == 3 && count == 2) || (adr_list.size() == 2 && count))
                            {
                                candidate_listB = adr_list;
                            }
                        }
                    }
                    else if(candidate_listC.size() == 0)
                    {
                        count = 0;
                        for(size_t x : candidate_listB)
                        {
                            for(size_t y : adr_list)
                            {
                                if(x + ((adr_list[0] / 9) - (candidate_listB[0] / 9)) * 9 == y)
                                {
                                    count++;
                                }
                            }
                        }
                        if(candidate_listB.size() == 3)
                        {
                            if((adr_list.size() == 3 && count == 3) || (adr_list.size() == 2 && count))
                            {
                                candidate_listC = adr_list;
                                break;
                            }
                        }
                        else
                        {
                            if((adr_list.size() == 3 && count == 2) || (adr_list.size() == 2 && count))
                            {
                                candidate_listC = adr_list;
                                break;
                            }
                        }
                    }
                }
            }
            if(candidate_listC.size())
            {
                // erase code..
                cout << "Applies swordfish.(" << fish << ")\n";
                adr_list.clear();
                for(size_t x : candidate_listA)
                {
                    adr_list.push_back(x);
                }
                for(size_t x : candidate_listB)
                {
                    adr_list.push_back(x);
                }
                for(size_t x : candidate_listC)
                {
                    adr_list.push_back(x);
                }
                for(size_t x : adr_list)
                {
                    for(size_t i = x % 9; i < 81; i += 9)
                    {
                        count = 0;
                        for(size_t check : candidate_listA)
                        {
                            if(i == check)
                            {
                                count++;
                            }
                        }
                        for(size_t check : candidate_listB)
                        {
                            if(i == check)
                            {
                                count++;
                            }
                        }
                        for(size_t check : candidate_listC)
                        {
                            if(i == check)
                            {
                                count++;
                            }
                        }
                        if(count == 0)
                        {
                            possible[i].erase(remove(possible[i].begin(), possible[i].end(), fish), possible[i].end());
                        }
                    }
                }
            }
        }
    }
    /*****************************************/
    void find_pointing_triples(void)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t index;
        size_t indexA;
        vector<char> pairs;
        vector<size_t> count{0, 0, 0, 0, 0, 0, 0, 0, 0};
        // test
        // possible[0].erase();
        // possible[1].erase();
        // possible[1] = "1234";
        // possible[2].erase();
        // possible[9].erase();
        // possible[10].erase();
        // possible[10] = "1567";
        // possible[11].erase();
        // possible[18].erase();
        // possible[19].erase();
        // possible[19] = "189";
        // possible[20].erase();
        // test
        for(size_t i = 0; i < 9; i++)
        {
            for(size_t &c : count)
            {
                c = 0;
            }
            pairs.clear();
            colum = (i / 3) * 3;
            row = (i * 3) % 9;
            for(size_t i = 0; i < 9; i++)// count use numb.
            {
                cube_row = ((row / 3) * 3) + (i % 3);
                cube_colum = ((colum / 3) * 3) + (i / 3);
                index = (cube_colum * 9) + cube_row;
                for(char c : possible[index])
                {
                    count[c - '1']++;
                }
            }
            for(size_t i = 0; i < count.size(); i++) // find pairs.
            {
                if(count[i] == 3)
                {
                    pairs.push_back(i + '1');
                }
            }
            for(char pair : pairs)
            {
                for(size_t i = 0; i < 9; i += 3)
                {
                    cube_row = ((row / 3) * 3) + (i % 3);
                    cube_colum = ((colum / 3) * 3) + (i / 3);
                    index = (cube_colum * 9) + cube_row;
                    if(possible[index].find(pair) != string::npos &&
                            possible[index + 1].find(pair) != string::npos &&
                            possible[index + 2].find(pair) != string::npos)
                    {
                        for(size_t i = 0; i < 9; i++)
                        {
                            size_t j = cube_colum * 9 + i;
                            if(j != index && j != (index + 1) && j != (index + 2))
                            {
                                possible[j].erase(remove(possible[j].begin(), possible[j].end(), pair), possible[j].end());
                            }
                        }
                        cout << "Applies pointing triples.\n";
                        break;
                    }
                }
                for(size_t i = 0; i < 3; i++)
                {
                    cube_row = ((row / 3) * 3) + (i % 3);
                    cube_colum = ((colum / 3) * 3) + (i / 3);
                    index = (cube_colum * 9) + cube_row;
                    if(possible[index].find(pair) != string::npos &&
                            possible[index + 9].find(pair) != string::npos &&
                            possible[index + 18].find(pair) != string::npos)
                    {
                        for(size_t i = 0; i < 9; i++)
                        {
                            size_t j = i * 9 + cube_row;
                            if(j != index && j != (index + 9) && j != (index + 18))
                            {
                                possible[j].erase(remove(possible[j].begin(), possible[j].end(), pair), possible[j].end());
                            }
                        }
                        cout << "Applies pointing triples.\n";
                        break;
                    }
                }
            }
        }
    }
    /*****************************************/
    void find_pointing_pairs(void)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t index;
        size_t indexA;
        vector<char> pairs;
        vector<size_t> count{0, 0, 0, 0, 0, 0, 0, 0, 0};
        // test
        // possible[0].erase();
        // possible[0] = "1234";
        // possible[1].erase();
        // possible[2].erase();
        // possible[9].erase();
        // possible[9] = "2567";
        // possible[10].erase();
        // possible[11].erase();
        // possible[18].erase();
        // possible[19].erase();
        // possible[19] = "89";
        // possible[20].erase();
        // possible[20] = "89";
        // test
        for(size_t i = 0; i < 9; i++)
        {
            for(size_t &c : count)
            {
                c = 0;
            }
            pairs.clear();
            colum = (i / 3) * 3;
            row = (i * 3) % 9;
            for(size_t i = 0; i < 9; i++)// count use numb.
            {
                cube_row = ((row / 3) * 3) + (i % 3);
                cube_colum = ((colum / 3) * 3) + (i / 3);
                index = (cube_colum * 9) + cube_row;
                for(char c : possible[index])
                {
                    count[c - '1']++;
                }
            }
            for(size_t i = 0; i < count.size(); i++) // find pairs.
            {
                if(count[i] == 2)
                {
                    pairs.push_back(i + '1');
                }
            }
            for(char pairA : pairs)
            {
                for(size_t i = 0; i < 9; i++)
                {
                    cube_row = ((row / 3) * 3) + (i % 3);
                    cube_colum = ((colum / 3) * 3) + (i / 3);
                    index = (cube_colum * 9) + cube_row;
                    if(possible[index].find(pairA) != string::npos)
                    {
                        indexA = index;
                        for(size_t i = 0; i < 9; i++)
                        {
                            cube_row = ((row / 3) * 3) + (i % 3);
                            cube_colum = ((colum / 3) * 3) + (i / 3);
                            index = (cube_colum * 9) + cube_row;
                            if(index != indexA)
                            {
                                if(possible[index].find(pairA) != string::npos)
                                {
                                    if((index - indexA) <= 3)
                                    {
                                        for(size_t i = 0; i < 9; i++)
                                        {
                                            size_t j = cube_colum * 9 + i;
                                            if(j != index && j != indexA)
                                            {
                                                possible[j].erase(remove(possible[j].begin(), possible[j].end(), pairA), possible[j].end());
                                            }
                                        }
                                        cout << "Applies pointing pairs.\n";
                                    }
                                    else if(((index - indexA) % 9) == 0)
                                    {
                                        for(size_t i = 0; i < 9; i++)
                                        {
                                            size_t j = i * 9 + cube_row;
                                            if(j != index && j != indexA)
                                            {
                                                possible[j].erase(remove(possible[j].begin(), possible[j].end(), pairA), possible[j].end());
                                            }
                                        }
                                        cout << "Applies pointing pairs.\n";
                                    }
                                    pairA = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    /*****************************************/
    void find_hidded_triples(void)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t index;
        size_t indexA;
        size_t indexB;
        vector<char> pairs;
        vector<char> triples;
        vector<size_t> count{0, 0, 0, 0, 0, 0, 0, 0, 0};
        char tripleA, pair;
        // test
        // possible[0].erase();
        // possible[0] = "34";
        // possible[1].erase();
        // possible[2].erase();
        // possible[2] = "348";
        // possible[9].erase();
        // possible[9] = "368";
        // possible[10].erase();
        // possible[10] = "1357";
        // possible[11].erase();
        // possible[11] = "348";
        // possible[18].erase();
        // possible[18] = "1578";
        // possible[19].erase();
        // possible[20].erase();
        // possible[20] = "167";
        // test
        for(size_t i = 0; i < 9; i++)
        {
            for(size_t &c : count)
            {
                c = 0;
            }
            pairs.clear();
            colum = (i / 3) * 3;
            row = (i * 3) % 9;
            for(size_t i = 0; i < 9; i++)// count use numb.
            {
                cube_row = ((row / 3) * 3) + (i % 3);
                cube_colum = ((colum / 3) * 3) + (i / 3);
                index = (cube_colum * 9) + cube_row;
                for(char c : possible[index])
                {
                    count[c - '1']++;
                }
            }
            for(size_t i = 0; i < count.size(); i++) // find pairs.
            {
                if(count[i] == 2)
                {
                    pairs.push_back(i + '1');
                }
                if(count[i] == 3)
                {
                    triples.push_back(i + '1');
                }
            }
            while(triples.size() >= 2)
            {
                tripleA = triples.back();
                triples.pop_back();
                for(char tripleB : triples)
                {
                    for(size_t i = 0; i < 9; i++)
                    {
                        cube_row = ((row / 3) * 3) + (i % 3);
                        cube_colum = ((colum / 3) * 3) + (i / 3);
                        index = (cube_colum * 9) + cube_row;
                        if(possible[index].find(tripleA) != string::npos && possible[index].find(tripleB) != string::npos)
                        {
                            indexA = index;
                            for(size_t i = 0; i < 9; i++)
                            {
                                cube_row = ((row / 3) * 3) + (i % 3);
                                cube_colum = ((colum / 3) * 3) + (i / 3);
                                index = (cube_colum * 9) + cube_row;
                                if(index != indexA)
                                {
                                    if(possible[index].find(tripleA) != string::npos && possible[index].find(tripleB) != string::npos)
                                    {
                                        indexB = index;
                                        for(size_t i = 0; i < 9; i++)
                                        {
                                            cube_row = ((row / 3) * 3) + (i % 3);
                                            cube_colum = ((colum / 3) * 3) + (i / 3);
                                            index = (cube_colum * 9) + cube_row;
                                            if(index != indexA && index != indexB)
                                            {
                                                if(possible[index].find(tripleA) != string::npos && possible[index].find(tripleB) != string::npos)
                                                {
                                                    for(char pair : pairs)
                                                    {
                                                        if(possible[index].find(pair) != string::npos)
                                                        {
                                                            if(possible[indexA].find(pair) != string::npos)
                                                            {
                                                                possible[index].erase();
                                                                possible[indexA].erase();
                                                                possible[indexB].erase();
                                                                possible[index].push_back(tripleA);
                                                                possible[indexA].push_back(tripleA);
                                                                possible[indexB].push_back(tripleA);
                                                                possible[index].push_back(tripleB);
                                                                possible[indexA].push_back(tripleB);
                                                                possible[indexB].push_back(tripleB);
                                                                possible[index].push_back(pair);
                                                                possible[indexA].push_back(pair);
                                                                cout << "Applies hidden triples.\n";
                                                                break;
                                                            }
                                                            else if(possible[indexB].find(pair) != string::npos)
                                                            {
                                                                possible[index].erase();
                                                                possible[indexA].erase();
                                                                possible[indexB].erase();
                                                                possible[index].push_back(tripleA);
                                                                possible[indexA].push_back(tripleA);
                                                                possible[indexB].push_back(tripleA);
                                                                possible[index].push_back(tripleB);
                                                                possible[indexA].push_back(tripleB);
                                                                possible[indexB].push_back(tripleB);
                                                                possible[index].push_back(pair);
                                                                possible[indexB].push_back(pair);
                                                                cout << "Applies hidden triples.\n";
                                                                break;
                                                            }
                                                        }
                                                        else if(possible[indexA].find(pair) != string::npos)
                                                        {
                                                            if(possible[indexB].find(pair) != string::npos)
                                                            {
                                                                possible[index].erase();
                                                                possible[indexA].erase();
                                                                possible[indexB].erase();
                                                                possible[index].push_back(tripleA);
                                                                possible[indexA].push_back(tripleA);
                                                                possible[indexB].push_back(tripleA);
                                                                possible[index].push_back(tripleB);
                                                                possible[indexA].push_back(tripleB);
                                                                possible[indexB].push_back(tripleB);
                                                                possible[indexA].push_back(pair);
                                                                possible[indexB].push_back(pair);
                                                                cout << "Applies hidden triples.\n";
                                                                break;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    /*****************************************/
    void find_hidded_pairs(void)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t index;
        size_t indexA;
        vector<char> pairs;
        vector<size_t> count{0, 0, 0, 0, 0, 0, 0, 0, 0};
        char pairA;
        // test
        // possible[0].erase();
        // possible[0] = "1234";
        // possible[1].erase();
        // possible[1] = "2378";
        // possible[2].erase();
        // possible[9].erase();
        // possible[10].erase();
        // possible[11].erase();
        // possible[18].erase();
        // possible[19].erase();
        // possible[19] = "579";
        // possible[20].erase();
        // possible[20] = "159";
        // test
        for(size_t i = 0; i < 9; i++)
        {
            for(size_t &c : count)
            {
                c = 0;
            }
            pairs.clear();
            colum = (i / 3) * 3;
            row = (i * 3) % 9;
            for(size_t i = 0; i < 9; i++)// count use numb.
            {
                cube_row = ((row / 3) * 3) + (i % 3);
                cube_colum = ((colum / 3) * 3) + (i / 3);
                index = (cube_colum * 9) + cube_row;
                for(char c : possible[index])
                {
                    count[c - '1']++;
                }
            }
            for(size_t i = 0; i < count.size(); i++) // find pairs.
            {
                if(count[i] == 2)
                {
                    pairs.push_back(i + '1');
                }
            }
            while(pairs.size() >= 2)
            {
                pairA = pairs.back();
                for(size_t i = 0; i < 9; i++)
                {
                    cube_row = ((row / 3) * 3) + (i % 3);
                    cube_colum = ((colum / 3) * 3) + (i / 3);
                    index = (cube_colum * 9) + cube_row;
                    if(possible[index].find(pairA) != string::npos)
                    {
                        indexA = index;
                        for(size_t i = 0; i < 9; i++)
                        {
                            cube_row = ((row / 3) * 3) + (i % 3);
                            cube_colum = ((colum / 3) * 3) + (i / 3);
                            index = (cube_colum * 9) + cube_row;
                            if(index != indexA)
                            {
                                if(possible[index].find(pairA) != string::npos)
                                {
                                    for(size_t i = 0; i < pairs.size(); i++)
                                    {
                                        if(pairs[i] != pairA)
                                        {
                                            if(possible[index].find(pairs[i]) != string::npos)
                                            {
                                                if(possible[indexA].find(pairs[i]) != string::npos)
                                                {
                                                    if(possible[indexA].size() > 2 || possible[index].size() > 2)
                                                    {
                                                        possible[indexA].erase();
                                                        possible[indexA].push_back(pairA);
                                                        possible[indexA].push_back(pairs[i]);
                                                        pairs.erase(remove(pairs.begin(), pairs.end(), pairA), pairs.end());// already remove
                                                        possible[index].erase();
                                                        possible[index].push_back(pairA);
                                                        possible[index].push_back(pairs[i]);
                                                        pairs.erase(remove(pairs.begin(), pairs.end(), pairs[i]), pairs.end());
                                                        pairA = 0;
                                                        cout << "Applies hidden pairs.\n";
                                                    }
                                                    break;

                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        pairs.erase(remove(pairs.begin(), pairs.end(), pairA), pairs.end());
                    }
                }
            }
        }
    }
    /*****************************************/
    void find_obvious_triples(void)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t index;
        size_t triples_index[3];
        char tripA, tripB, tripC;
        for(size_t i = 0; i < 9; i++)
        {
            colum = (i / 3) * 3;
            row = (i * 3) % 9;
            tripA = 0;
            tripB = 0;
            tripC = 0;
            for(size_t i = 0; i < 9; i++)
            {
                cube_row = ((row / 3) * 3) + (i % 3);
                cube_colum = ((colum / 3) * 3) + (i / 3);
                index = (cube_colum * 9) + cube_row;
                if(tripA == 0)
                {
                    if(possible[index].size() == 2)
                    {
                        tripA = possible[index][0]; // 1 -> 1
                        tripB = possible[index][1]; // 8 -> 8
                        triples_index[0] = index;
                    }
                }
                else if(tripC == 0)
                {
                    if(possible[index].size() == 2)
                    {
                        size_t p = possible[index].find(tripA);
                        if(p != string::npos)
                        {
                            p++;
                            tripC = possible[index][p % 2];
                        }
                        else
                        {
                            p = possible[index].find(tripB);
                            if(p != string::npos)
                            {
                                p++;
                                tripC = tripB;
                                tripB = tripA;
                                tripA = tripC;
                                tripC = possible[index][p % 2];
                                triples_index[1] = index;
                            }
                            else
                            {
                                tripA = possible[index][0];
                                tripB = possible[index][1];
                                triples_index[0] = index;
                            }
                        }
                    }
                }
                else if(possible[index].size() == 2)
                {
                    size_t p = possible[index].find(tripC);
                    if(p != string::npos)
                    {
                        p++;
                        if(possible[index][p % 2] == tripB)
                        {
                            triples_index[2] = index;
                            // finded triples.
                            for(size_t i = 0; i < 9; i++)
                            {
                                cube_row = ((row / 3) * 3) + (i % 3);
                                cube_colum = ((colum / 3) * 3) + (i / 3);
                                index = (cube_colum * 9) + cube_row;
                                if(index != triples_index[0] && index != triples_index[1] && index != triples_index[2])
                                {
                                    possible[index].erase(remove(possible[index].begin(), possible[index].end(), tripA), possible[index].end());
                                    possible[index].erase(remove(possible[index].begin(), possible[index].end(), tripB), possible[index].end());
                                    possible[index].erase(remove(possible[index].begin(), possible[index].end(), tripC), possible[index].end());
                                }
                            }
                            cout << "Applies obvious triples.\n";
                            return;
                        }
                    }
                }
            }
        }
    }
    /*****************************************/
    void find_obvious_pairs(void)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t index;
        size_t subindex;
        size_t lastindex;
        char pairA, pairB;
        for(size_t i = 0; i < 9; i++)
        {
            colum = (i / 3) * 3;
            row = (i * 3) % 9;
            for(size_t i = 0; i < 9; i++)
            {
                cube_row = ((row / 3) * 3) + (i % 3);
                cube_colum = ((colum / 3) * 3) + (i / 3);
                index = (cube_colum * 9) + cube_row;
                if(possible[index].size() == 2)
                {
                    for(size_t i = 0; i < 9; i++)
                    {
                        cube_row = ((row / 3) * 3) + (i % 3);
                        cube_colum = ((colum / 3) * 3) + (i / 3);
                        subindex = (cube_colum * 9) + cube_row;
                        if(subindex != index && possible[subindex].size() == 2)
                        {
                            if(possible[subindex] == possible[index])
                            {
                                pairA = possible[subindex][0];
                                pairB = possible[subindex][1];
                                for(size_t i = 0; i < 9; i++)
                                {
                                    cube_row = ((row / 3) * 3) + (i % 3);
                                    cube_colum = ((colum / 3) * 3) + (i / 3);
                                    lastindex = (cube_colum * 9) + cube_row;
                                    if(lastindex != index && lastindex != subindex)
                                    {
                                        possible[lastindex].erase(remove(possible[lastindex].begin(), possible[lastindex].end(), pairA), possible[lastindex].end());
                                        possible[lastindex].erase(remove(possible[lastindex].begin(), possible[lastindex].end(), pairB), possible[lastindex].end());
                                    }
                                }
                                cout << "Applies obvious paris.\n";
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    /*****************************************/
    void releated_extract_number(void)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t index;
        size_t subindex;
        size_t i;

        for(colum = 0; colum < 9; colum++)
        {
            for(row = 0; row < 9; row++)
            {
                index = (colum * 9) + row;
                for(char c : possible[index])
                {
                    if(c)
                    {
                        for(i = 0; i < 9; i++)
                        {
                            subindex = (colum * 9) + i;
                            if(index != subindex)
                            {
                                if(possible[subindex].find(c) != string::npos)
                                {
                                    break;
                                }
                            }
                        }
                        if(i == 9)
                        {
                            possible[index].erase();
                            possible[index].push_back(c);
                        }
                        for(i = 0; i < 9; i++)
                        {
                            subindex = (i * 9) + row;
                            if(index != subindex)
                            {
                                if(possible[subindex].find(c) != string::npos)
                                {
                                    break;
                                }
                            }
                        }
                        if(i == 9)
                        {
                            possible[index].erase();
                            possible[index].push_back(c);
                        }
                        for(i = 0; i < 9; i++)
                        {
                            cube_row = ((row / 3) * 3) + (i % 3);
                            cube_colum = ((colum / 3) * 3) + (i / 3);
                            subindex = (cube_colum * 9) + cube_row;
                            if(index != subindex)
                            {
                                if(possible[subindex].find(c) != string::npos)
                                {
                                    break;
                                }
                            }
                        }
                        if(i == 9)
                        {
                            possible[index].erase();
                            possible[index].push_back(c);
                        }
                    }
                }
            }
        }
    }
    /*****************************************/
    void direct_extract_number(size_t colum, size_t row, char c)
    {
        size_t cube_row;
        size_t cube_colum;
        size_t index = (colum * 9) + row;
        size_t i;
        possible[index].erase();
        for(i = 0; i < 9; i++)
        {
            index = (colum * 9) + i;
            possible[index].erase(remove(possible[index].begin(), possible[index].end(), c), possible[index].end());
            index = (i * 9) + row;
            possible[index].erase(remove(possible[index].begin(), possible[index].end(), c), possible[index].end());
            cube_row = ((row / 3) * 3) + (i % 3);
            cube_colum = ((colum / 3) * 3) + (i / 3);
            index = (cube_colum * 9) + cube_row;
            possible[index].erase(remove(possible[index].begin(), possible[index].end(), c), possible[index].end());
        }
    }
    /*****************************************/
    bool find_number(vector<vector<char>> &board)
    {
        size_t row;
        size_t colum;
        char c;
        bool solve = false;
        for(colum = 0; colum < 9; colum++)
        {
            for(row = 0; row < 9; row++)
            {
                if(possible[(colum * 9) + row].size() == 1)
                {
                    c = possible[(colum * 9) + row][0];
                    direct_extract_number(colum, row, c);
                    board[colum][row] = c;
                    solve = true;
                }
            }
        }
        return solve;
    }
    /*****************************************/
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        size_t row;
        size_t colum;
        char c;
        for(colum = 0; colum < 9; colum++)
        {
            for(row = 0; row < 9; row++)
            {
                c = board[colum][row];
                if(c != '.')
                {
                    direct_extract_number(colum, row, c);
                }
            }
        }
        do
        {
            releated_extract_number();
            find_obvious_pairs();
            find_obvious_triples();
            find_hidded_pairs();
            find_pointing_pairs();
            find_pointing_triples();
            find_hidded_triples();
            find_swordfish();
        }
        while(find_number(board));
    }
};
//////////////////////////////
//////////////////////////////
//////////////////////////////
int main()
{
    Solution x;

    vector<vector<char>> board{{'.', '.', '9', '7', '4', '8', '.', '.', '.'}, {'7', '.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '2', '.', '1', '.', '9', '.', '.', '.'}, {'.', '.', '7', '.', '.', '.', '2', '4', '.'}, {'.', '6', '4', '.', '1', '.', '5', '9', '.'}, {'.', '9', '8', '.', '.', '.', '3', '.', '.'}, {'.', '.', '.', '8', '.', '3', '.', '2', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '6'}, {'.', '.', '.', '2', '7', '5', '9', '.', '.'}};
    //vector<vector<char>> board{{'5', '1', '9', '7', '4', '8', '6', '3', '2'}, {'7', '8', '3', '6', '5', '2', '4', '1', '9'}, {'4', '2', '6', '1', '3', '9', '8', '7', '5'}, {'3', '5', '7', '9', '8', '6', '2', '4', '1'}, {'2', '6', '4', '3', '1', '7', '5', '9', '8'}, {'1', '9', '8', '5', '2', '4', '3', '6', '7'}, {'9', '7', '5', '8', '6', '3', '1', '2', '4'}, {'8', '3', '2', '4', '9', '1', '7', '5', '6'}, {'6', '4', '1', '2', '7', '5', '9', '8', '3'}};
    vector<vector<char>> solve{{'5', '1', '9', '7', '4', '8', '6', '3', '2'}, {'7', '8', '3', '6', '5', '2', '4', '1', '9'}, {'4', '2', '6', '1', '3', '9', '8', '7', '5'}, {'3', '5', '7', '9', '8', '6', '2', '4', '1'}, {'2', '6', '4', '3', '1', '7', '5', '9', '8'}, {'1', '9', '8', '5', '2', '4', '3', '6', '7'}, {'9', '7', '5', '8', '6', '3', '1', '2', '4'}, {'8', '3', '2', '4', '9', '1', '7', '5', '6'}, {'6', '4', '1', '2', '7', '5', '9', '8', '3'}};

    cout << "----------begin--------\n";
    x.solveSudoku(board);
    int left = 0;
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[i].size(); ++j)
        {
            if(board[i][j] != '.' && solve[i][j] != board[i][j])
            {
                cout << "[x" << board[i][j] << ']';
            }
            else
            {
                cout << '[' << board[i][j] << ']';
            }
            if(board[i][j] == '.')
            {
                left++;
            }
        }
        cout << '\n';
    }
    cout << "Left:" << left << '\n';

    cout << "-----------end---------";
}
//////////////////////////////
//////////////////////////////
//////////////////////////////
