#include "calculate.h"
#include <QStack>
#include <QDebug>

bool isoperator(QChar ch){
    return ch == '+'||ch == '-'||ch == '*'||ch == '/';
}

double performeOperator(double num1,double num2,QChar op){
    switch(op.toLatin1()){
    case '+':
        return num1+num2;
    case '-':
        return num1-num2;
    case '*':
        return num1*num2;
    case '/':
        return num1/num2;
    default:
        return 0.0;
    }
}

QString Calculator::calculate(const QString& expression){
    QStack<double> numStack;
    QStack<QChar>  opStack;

    for(int i=0;i<expression.length();++i){
        QChar ch = expression[i];

        if(ch.isSpace()){
            continue;
        }

        if(ch.isDigit()||ch=='.'){
            int j=i;
            while(j<expression.length()&&(expression[j].isDigit()||expression[j]=='.')){
                ++j;
            }
            QString numberstr = expression.mid(i,j-i);
            bool conversionSuccess = false;
            double number = numberstr.toDouble(&conversionSuccess);
            if(conversionSuccess){
                numStack.push(number);
            }else{
                return "Error1";
            }
            i=j-1;
        }else if(isoperator(ch)){
            while(!opStack.isEmpty()&&isoperator(opStack.top())){
                QChar prevOp = opStack.top();
                opStack.pop();

                if(numStack.size()<2){
                    return "Error2";
                }

                double num2 = numStack.top();
                numStack.pop();
                double num1 = numStack.top();
                numStack.pop();
                double result = performeOperator(num1,num2,prevOp);
                numStack.push(result);
            }
            opStack.push(ch);
        }else if(ch=='('){
            opStack.push(ch);
        }else if(ch==')'){
            while(!opStack.empty()&&opStack.top()!='('){
                QChar prevOp = opStack.top();
                opStack.pop();

                if(numStack.size()<2){
                    return "Error3";
                }

                double num2 = numStack.top();
                numStack.pop();
                double num1 = numStack.top();
                numStack.pop();
                double result = performeOperator(num1,num2,prevOp);
                numStack.push(result);
            }
            if(opStack.empty()){
                return "Error4";
            }
            opStack.pop();
        }else {
                return "Error5";
            }
    }


        while(!opStack.empty()){
            QChar prevOp = opStack.top();
            opStack.pop();

            if(numStack.size()<2){
                return "Error6";
            }

            double num2 = numStack.top();
            numStack.pop();
            double num1 = numStack.top();
            numStack.pop();
            double result = performeOperator(num1,num2,prevOp);
            numStack.push(result);
        }
        if(numStack.empty()){
            return "Error7";
        }else {
            double finalresult = numStack.top();
            return QString::number(finalresult);
        }
}

