#include <iostream>
using namespace std;
int main(){
    int linea=0;
    bool sl = true;
    while(sl){
        linea++;
        if(linea==1){
            for(int pl = 1; pl <= 3; pl++)
            {cout<<"|";}
        }else if(linea==2){
            for(int esl = 1; esl <= 4;esl++){ 
                if(esl==1||esl==3){ 
                    cout<<" ";
                }else{
                    cout<<"|";
                }
            }
        }else if(linea==3){ 
            for(int etl = 1; etl <= 5;etl++){
                if(etl<=2||etl==4){
                    cout<<" ";
                }else{cout<<"|"; 
                } 
            }
            }else if(linea==4){
                for(int ecl = 1; ecl <= 6;ecl++){
                    if(ecl<=3||ecl==5){
                        cout<<" ";
                    }else{
                        cout<<"|";
                    }
                }
                }else if(linea==5){
                    for(int eql = 1; eql<=15;eql++){
                        if(eql<=2){cout<<" "; 
                        }else{
                            cout<<"|";
                        }
                    }
                    }else if(linea==6){
                        for(int exl = 1; exl<=16;exl++){
                            if(exl<=1){ 
                                cout<<" ";
                            }else{
                                cout<<"|";
                            }
                        }
                        }else if(linea==7){
                            for(int epl = 1; epl<=17;epl++){
                                if(epl<=2){
                                     cout<<"|";
                                     }else if(epl>=16){
                                        cout<<"|";
                                        }else{
                                            cout<<" ";
                                        }
                                    }
                            }else if(linea==8){
                                for(int eol = 1; eol<=17;eol++){
                                    if(eol<=2){
                                        cout<<"|";
                                    }else if(eol>=16){
                                        cout<<"|";
                                        }else{
                                            cout<<" ";
                                        }
                                    }
                                }else if(linea==9){
                                    for(int enl = 1; enl<=17;enl++){
                                        if(enl<=2){
                                            cout<<"|";
                                        }else if(enl>=16){
                                            cout<<"|";
                                            }else{
                                                cout<<" ";
                                            }
                                        }
                                    }else if(linea==10){
                                        for(int edl = 1; edl<=16;edl++){
                                            if(edl<=1 || edl >= 4 && edl <= 14){
                                                cout<<" ";
                                            }else{
                                                cout<<"|";
                                            }
                                        }
                                    }else if(linea==11){
                                        for(int encl = 1; encl<=15;encl++){
                                            if(encl<=2){
                                                cout<<" ";
                                            }else{
                                                cout<<"|";
                                            }
                                        }
                                    }else{
                                        sl=false;
                                    }
                                    cout<<endl;
    }
    return 0;
}