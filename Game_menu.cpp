#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    //hangman Var
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
    int n;
    int length_counter;
    int max_word;
    string ran_word;
    string sub_word;
    string input_recorder;
    string user_input;
    const int defualt_score = 6;
    bool isCorrect;
    int input_counter = 1;
    bool isDuplicate;
    int correction_counter = 0;
    int incorrect_counter = 0;
    int score;

    // common var
    string replay;
    string start;
    bool isReplay;
    bool isStart;
    string enter_menu;

    //Garden Var
    string rocks = "\U0001FAA8";
    string the_boy = "\U0001F468";
    string the_bug = "\U0001F41B";
    string border[] ={R"(/------------------\)",R"(\------------------/)"};
    const string seed[4]={"\U0001F345","\U0001F344","\U0001F353","\U0001F96C"};
    string plant[4]; 
    string order[4]={"2nd","3rd","4th","5th"};
    int amount[4];
    bool isPlant;

    do{
        cout<<"========= Welcome to Team 2 Play Station ========="<<endl<<endl;
        cout<<"GAME MENU :"<<endl;
        cout<<"[ a ] : Hang man"<<endl
            <<"[ b ] : Garden"<<endl
            <<"[ x ] : Exit"<<endl<<endl;
        cout<<"Choose a Menu : ";
        cin>>enter_menu; 
        isStart = true;
        isReplay = true;
        if(enter_menu == "a"){
            cout << "------------Welcome to Hangman!------------" << endl<<endl;
            do{
            cout<<"Are you ready to play the game? [yes/no] : ";
            cin>>start;
            if(start=="yes"){
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
                        if(user_input.length()==1){
                            isDuplicate = false;
                            for(int i=0;i<input_counter;i++){
                                if(user_input[0] == input_recorder[i]){
                                    isDuplicate = true;
                                }
                            }
                            if(isDuplicate == false){
                                input_counter++;
                                input_recorder[input_counter-2] = user_input[0];
                                isCorrect = false;
                                for(int i=0;i<length_counter;i++){
                                    if(user_input[0] == ran_word[i]){
                                        isCorrect = true;
                                        correction_counter++;
                                    }
                                }
                                if(isCorrect == false){
                                    incorrect_counter++;
                                }
                                score = defualt_score - incorrect_counter;
                                if(isCorrect == true){
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
                                        <<endl<<"=============================="<<endl;
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
                        isReplay = false;
                        cout<<endl <<"Back to Menu..."<<endl<<endl;
                    }
                }while(replay == "yes");
            }
            else if(start =="no"){
                isStart = false;
                cout<<endl;
                cout<<"Back to Menu..."<<endl<<endl;
            }else if (start !="yes" && start != "no"){
                cout<<endl;
                cout<<"Invalid input..." <<endl;
            }
            }while(start !="yes" && start !="no");
            //Garden
        }else if(enter_menu == "b"){
            cout<<"========= Welcome to Garden Game ========="<<endl<<endl;
            cout<<"Are you ready to plant? [yes/no] : ";
            cin>>start;
            cout<<endl;
            do{
                if(start =="yes"){
                    for(int i=0;i<4;i++){
                        cout<<the_bug <<": "
                            <<"What are you going to plant in the " <<order[i] <<" row?"<<endl;
                        cout<<the_boy<<": ";
                        cin>>plant[i];
                        isPlant = false;
                        if(plant[i] == seed[i]){
                            isPlant = true;
                        }
                        if(isPlant == true){
                        cout<<the_bug <<": "
                            <<"How many do you want to plant?"<<endl;
                        cout<<the_boy <<": ";
                        cin>>amount[i];
                        cout<<endl;
                        if(amount[i]>9){
                            amount[i] = 9;
                        }else{
                            if(i==1 && amount[1] % 2 ==0){
                                amount[1]+=1;
                            }else if(i==2 && amount[2]%3 !=0){
                                for(int i=amount[2];i<10;i++){
                                    if(i % 3 == 0){
                                        amount[2]=i;
                                        break;
                                    }
                                }
                            }
                        }
                        }else{
                            cout<<endl;
                            plant[i] = "\U0001FAA8 ";
                            amount[i] = 9;
                        }
                    }
                    cout<<endl;
                    cout<<border[0]<<endl;
                    for(int i=0;i<4;i++){
                        cout<<"|";
                        if(amount[3]<9&&i==3){
                            amount[3]+=1; 
                        }
                        for(int j=0;j<amount[i];j++){
                            if(amount[3]<9&&i==3&&j==amount[3]-1){
                                plant[i] = the_bug; 
                            }
                            cout<<plant[i];
                        }
                        for(int k=0;k<18-(amount[i]*2);k++){
                            cout<<" ";
                        }
                        cout<<"|";
                        cout<<endl;
                    }
                    cout<<border[1]<<endl<<endl;
                    do{
                        cout<<"Do you want to plant again? [yes/no] : ";
                        cin>>replay;
                        cout<<endl;
                        if(replay == "no"){
                            isReplay = false;
                            cout<<"Back to Menu..."<<endl<<endl;
                        }else if (replay !="yes" && replay!="no"){
                            cout<<"Invalid Input..."<<endl;
                        }
                    }while(replay !="yes" && replay!="no");
                }else if (start !="yes" && start!="no"){
                    cout<<"Invalid Input..."<<endl;
                }else if(start =="no"){
                    isStart = false;
                    cout<<"Back to Menu..."<<endl<<endl;
                }
            }while(start !="yes" && start!="no" || replay =="yes");
        }else if(enter_menu == "x"){
                cout<<endl
                    <<"Exit..."<<endl;
        }else{
                cout<<"Invalid menu..." <<endl<<endl;
        }
    }while(enter_menu != "a" && enter_menu != "b" && enter_menu != "x" || isReplay == false || isStart == false);
    return 0;
}