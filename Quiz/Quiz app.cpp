#include <iostream>
using namespace std;

int main(){
    int score = 0;
    char answer;
    cout << "Enter the letter of the correct answer (a, b, or c): \n";
    cout << "Which one is a loop in c++\n";
    cout << "a) if\nb) cout\nc) for\nd) cin\n";

    cin >> answer;

    if (answer == 'c'){
        cout << "GOOD JOB\n";
        score++;
    } else {
        cout << "wrong\n";
    }

    cout<<"Capital of EGYPT?\n";
    cout<<"a)giza\nb)cairo\nc)roma)\nd)london\n";

    cin>> answer;
    
    if(answer == 'b'){
        cout<<"Excellant\n";
        score++;
    }else{
        cout<<"wrong\n";
    }
    cout<<"Which symbol is using for 'and' in c++\n";
    cout<<"a)&&\nb)||\nc)!=\nd)*\n";

    cin>>answer;

    if(answer == 'a'){
        cout<<"Excellant\n";
         score++;
    }else{
        cout<<"wrong\n";
    }
    cout<<"Which one is using to print in c++\n";
    cout<<"a)for\nb)cin\nc)cout\nd)if\n";

    cin>> answer;

    if(answer == 'c'){
        cout<<"so good\n";
        score++;
    }else{
        cout<<"wrong";
    }

    cout << "Your Score = "<< score<<"/4\n";
    
    if(score == 4) {
    cout << "Congratulations!";
}else{
    cout<<"good try!";
}

    return 0;
}