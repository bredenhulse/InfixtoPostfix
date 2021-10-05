/*
Name: Breden Hulse
Class: Computer Science 2
Description: It will take an infix equation and will make it postfix
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main(){
    //create stack
    stack<char> conversion;
    string postfix = "(((A-B)+C*D+E)/F))";
    //iterate through string to look at every character
    for(int i = 0; i < postfix.length(); i++){
        if(postfix[i] == '('){
            conversion.push('(');
        }
        else if(postfix[i] == '+'){
            conversion.push('+');
        }
        else if(postfix[i] == '-'){
            conversion.push('-');
        }
        else if(postfix[i] == '*'){
            while(conversion.top() == '+' || conversion.top() == '-'){
                cout << conversion.top();
                conversion.pop();
            }
            conversion.push(postfix[i]);
        }
        else if(postfix[i] == '/'){
            while(conversion.top() == '+' || conversion.top() == '-'){
                cout << conversion.top();
                conversion.pop();
            }
            conversion.push(postfix[i]);
        }
        else if(postfix[i] == ')'){
            while(conversion.top() != '('){
                cout << conversion.top();
                conversion.pop();
            }
        }
        else{
            cout << postfix[i];
        }
        
    }
    //Make sure that every character is printed except open paranthesis
    while(conversion.top() != '('){
        cout << conversion.top();
        conversion.pop();
    } 
}
