#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>

using namespace std;
struct User
   {
      int  user_score = 0;
      string user_name;
    };

void set_High_Score(string name, int score)
{


    vector<User> score_list;
    ifstream Readfile;
    Readfile.open("High_Score.txt");

    if (Readfile.is_open())
    {
        string tempname;
        int tempscore;

        while (Readfile >> tempname >> tempscore)
        {
            User temp_user;
            temp_user.user_score = tempscore;
             temp_user.user_name = tempname;
            score_list.push_back(temp_user);

        }
    }
    Readfile.close();
    User new_user;
    new_user.user_score = score;
    new_user.user_name = name;
    for(int i = 0; i < score_list.size(); i++)
    {
        if(score_list.at(i).user_score < score)
        {
           score_list.insert (score_list.begin() + i, new_user);
            i = score_list.size();
        }
    }
    if(score_list.size() > 10)
    {
        score_list.pop_back();
    }
    ofstream Writefile;
    Writefile.open("High_Score.txt");
    for(int i = 0 ; i < score_list.size();i++)
    {
        Writefile << score_list.at(i).user_name << " " << score_list.at(i).user_score << endl;
    }
    Writefile.close();
}


