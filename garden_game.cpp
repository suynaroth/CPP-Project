#include <iostream>
using namespace std;

int main() {

    string rocks = "\U0001FAA8";
    string the_boy = "\U0001F468";
    string the_bug = "\U0001F41B";
    string border[] ={R"(/------------------\)",R"(\------------------/)"};
    string seed[6]={"\U0001F345","\U0001F344","\U0001F353","\U0001F96C"};
    string start;
    string replay;
    string plant[4]; 
    string order[4]={"2nd","3rd","4th","5th"};
    int amount[4];
    bool isPlant;
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
                    cout<<"Game Exit.."<<endl;
                }else if (replay !="yes" && replay!="no"){
                    cout<<"Invalid Input..."<<endl;
                }
            }while(replay !="yes" && replay!="no");
        }else if (start !="yes" && start!="no"){
            cout<<"Invalid Input..."<<endl;
        }else if(start =="no"){
            cout<<"Game Exit.."<<endl;
        }
    }while(start !="yes" && start!="no" || replay =="yes");
    return 0;
}