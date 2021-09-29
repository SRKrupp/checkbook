#include <iostream>

using namespace std;
struct check{
    int checknum;
    string checkmemo;
    float checkamount;
};

class checkbook{
public:
    checkbook():balance(0),numofchecks(0){}
    checkbook(float bal):balance(bal),numofchecks(0){}
    void deposit(float addbal);
    void displaychecks();
    struct check checkarray[5];
    bool writecheck(float amount);
private:
    float balance,lastdeposit;
    int numofchecks, checklimit = 5;
};
int main()
{
    checkbook checkbook1(500);
    checkbook1.writecheck(250);
    checkbook1.writecheck(250);

    checkbook1.displaychecks();

    return 0;
}

void checkbook::displaychecks(){
    for (int i=0;i<numofchecks;i++){
        cout << "check number: " << checkarray[i].checknum << endl;
        cout << "check memo: " << checkarray[i].checkmemo << endl;
        cout << "check amount: " << checkarray[i].checkamount << endl;
    }
}

void checkbook::deposit(float addbal){
    balance +=addbal;
}

bool checkbook::writecheck(float amount){
    if (amount > balance){
        return 0;
    }else {
        balance -=amount;
        cout << "What is the memo of this check?" << endl;
        cin >> checkarray[numofchecks].checkmemo;
        checkarray[numofchecks].checknum = numofchecks;
        checkarray[numofchecks].checkamount = amount;
        lastdeposit = amount;
        numofchecks++;
        return 1;
    }
}

