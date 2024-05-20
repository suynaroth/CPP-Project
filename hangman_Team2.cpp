//  hangman.cpp
//  Created by Tannhuot Khouv on 23/4/24.
//  Group 2

#include <iostream>
#include <cstdlib>
using namespace std;
    
int main() {
    string word_list[] = {"community", "computer", "elephant", "chocolate", "sunshine", "butterfly",
        "watermelon", "christmas", "kangaroo", "mountain", "celebrate", "telescope",
        "discovery", "baseball", "umbrella", "adventure", "halloween", "unbelievable","car", "coffee",
        "table","truck"};
    string win_champ = R"(
                         ___________
                        '._==_==_=_.'
                        .-\:      /-.
                       | (|:.     |) |
                        '-|:.     |-'
                          \::.    /
                           '::. .'
                             ) (
                           _.' '._
                        )";

    string stages[] = {R"(
         +---+
         |   |
         O   |
        /|\  |
        / \  |
             |
        =========)", R"(
         +---+
         |   |
         O   |
        /|\  |
        /    |
             |
        =========)", R"(
         +---+
         |   |
         O   |    
        /|\  |
             |
             |
        =========
        )" , R"(
         +---+
         |   |
         O   |
        /|   |
             |
             |
        =========)", R"(
        +---+
        |   |
        O   |
        |   |
            |
            |
        =========
        )", R"(
        +---+
        |   |
        O   |
            |
            |
            |
        =========
        )", R"(
        +---+
        |   |
            |
            |
            |
            |
        =========
        )"};
    string answer;
    int n;
    int length_counter;
    int max_word;
    string ran_word;
    string sub_word;
    string input_recorder;
    string user_input;
    const int defualt_score = 6;
    bool statment;
    int input_counter = 1;
    bool isDuplicate;
    int correction_counter = 0;
    int incorrect_counter = 0;
    int score;
    bool isValid;
    string valid_input="abcdefghijklmnopqrstuvwxyz";
    string replay;
    
    cout << "------------Welcome to Hangman!------------" << endl<<endl;
    do{
        cout<<"Are you ready to play the game? [yes/no] : ";
        cin>>answer;
        if(answer=="yes"){
            do{
                max_word = sizeof(word_list)/sizeof(word_list[0]);
                srand(time(0));
                n=rand() % max_word;
                ran_word = word_list[n];
                sub_word = word_list[n];
                length_counter = word_list[n].length();
                cout<<"Guess the word below : "<<endl
                    <<"Your score : "<<defualt_score <<endl <<endl;
                for(int i=0;i<length_counter;i++){
                    sub_word[i]='-';
                }
                cout<<sub_word;
                score = defualt_score;
                do{
                    cout<<endl;
                    cout<<"Enter your guessing charactor : ";
                    cin>>user_input;
                    isValid = false;
                    for(int i=0;i<26;i++){
                        if(user_input[0] == valid_input[i]){
                            isValid = true;
                            break;
                        }
                    }
                    if(user_input.length()==1 && isValid == true){
                        isDuplicate = false;
                        for(int i=0;i<input_counter;i++){
                            if(user_input[0] == input_recorder[i]){
                                isDuplicate = true;
                            }
                        }
                        if(isDuplicate == false){
                            input_counter++;
                            input_recorder[input_counter-2] = user_input[0];
                            statment = false;
                            for(int i=0;i<length_counter;i++){
                                if(user_input[0] == ran_word[i]){
                                    statment = true;
                                    correction_counter++;
                                }
                            }
                            if(statment == false){
                                incorrect_counter++;
                            }
                            score = defualt_score - incorrect_counter;
                            if(statment == true){
                                cout<<"You're correct!"<<endl
                                    <<"Your score: " <<score <<endl
                                    <<stages[score] <<endl;  
                                for(int i=0;i<length_counter;i++){
                                    if(user_input[0] == ran_word[i]){
                                        sub_word[i]=user_input[0];
                                    }
                                }
                                cout<<sub_word <<endl;
                            }else{
                                cout<<"You're wrong! Try again..."<<endl    
                                    <<"Your score: "<<score<<endl;
                                cout<<stages[score] <<endl;
                                cout<<sub_word <<endl;
                            }
                            if(correction_counter == length_counter && score >0){
                                cout<<"You win!"<<endl;
                                cout<<win_champ <<endl;
                            }else if(score == 0){
                                cout<<"Game over"<<endl;
                                cout<<"The word is " <<"\"" <<ran_word <<"\""
                                    <<endl<<"--------------------------"<<endl;
                            }        
                        }else{
                            cout<<"You have already used this charactor..."<<endl;
                        }
                    }else{
                        cout<<"Invalid input..." <<endl;
                    }
                }while(correction_counter != length_counter && score >0 || user_input.length()>1 || isDuplicate == true);
                for(int i=0;i<input_counter-1;i++){
                    input_recorder[i]=0;
                }
                correction_counter = 0;
                incorrect_counter = 0;
                input_counter = 1;
                do{
                    cout<<endl;
                    cout<<"Do you want to play again? [yes/no]: ";
                    cin>>replay;
                    if(replay != "yes" && replay !="no"){
                        cout<<"Invalid input..." <<endl;
                    }
                }while(replay != "yes" && replay !="no");
                if(replay == "no"){
                    cout<<endl <<"Exit Game...";
                }
            }while(replay == "yes");
        }
        else if(answer =="no"){
            cout<<endl;
            cout<<"Exit Game...";
        }else if (answer !="yes" && answer != "no"){
            cout<<endl;
            cout<<"Invalid input..." <<endl;
        }
    }while(answer !="yes" && answer!="no");
    return 0;
}
