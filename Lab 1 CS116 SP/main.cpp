//
//  main.cpp
//  Lab 1 CS116 SP
//
//  Created by Danny Mairena Jarquin on 2/4/21.
//  Copyright © 2021 Danny Mairena. All rights reserved.
//

/*
 Program Name: Lab1 Array and Strings
 Author: Danny Mairena Jarquin
 Due date: 2/4/2020
 Description: To output student ID, grade, and test answers.
 */

#include<iostream>
#include<string>
#include<fstream>
#define MAX 50
using namespace std;

int main()

{
    ifstream test_solution;
    ifstream student_answers; //To read the input files
   
    string location;
    string s_id[MAX];
    string grade[MAX];
    string answers[MAX];
    string solutions;
    string str;
    
    int score[MAX]={};      //initialises array with all elements 0
    
    char c;
    
    cout << "Enter the solution file (test-solution.txt): ";
    
    cin >> location;
    
    if (location.empty()){
       
        location = "test-solutions.txt";    // setting test-solutions.txt as default in case there is no input
    }
    
    test_solution.open (location);       // Opening the test solutions file
    
    location=" ";
    
    cout << "Enter the students' answer file (student_answer.txt): ";
    
    cin >> location;
    
    if(location.empty()){
       
        location = "students-answers.txt";
    }

    student_answers.open(location);
    int i =0;
    
    while(getline(student_answers,str)){
        
        answers[i]=str;
        
        i+=1  ;
    
    }
    
    int n=i;
    
    while(test_solution>>noskipws>>c){
       
        solutions+=c;
    }

    int temp=0;
                        

    
    for (int i =0; i<n;i++){
       
        for(int j=0; j<answers[i].size();j++){
          
            if (answers[i][j]==' '){
               
                temp=j;
                
                break;
                }
            }
         s_id[i]= answers[i].substr(0,temp);
         
        answers[i]=answers[i].substr(temp+1,answers[i].size()-temp);
        
    }

    for(int i =0;i<n;i++){
        
        for (int j=0;j<solutions.size();j++){
          
            if(answers[i][j]==' '){
                score[i]=score[i]+0;
                }
            else if ( answers[i][j]==solutions[j]){
                score[i]+=1;
                }
            else if (answers[i][j]!=solutions[j]){
                score[i]-=1;
            }
        }
    }

    float percent[MAX]={-1};
    
    for(int i=0; i<n; i++){
       
        percent[i]=(score[i]/solutions.size())*100;
        
        if(percent[i]>=90 && percent[i]<=100)
        
            grade[i]='A';
        else if(percent[i]>=80 && percent[i]<=89)
            grade[i]='B';
        else if(percent[i]>=70 && percent[i]<=79)
            grade[i]='C';
        else if(percent[i]>=60 && percent[i]<=59)
            grade[i]='D';
        else if(percent[i]<=59)
            grade[i]='F';
    }
    for(int i=0; i<n; i++){
        
        cout <<"Student Id: "<<s_id[i]<<endl;
        
        cout <<"Your Answers: "<<answers[i]<<endl;
        
        cout <<"Score(out of "<<solutions.size( )<<"): "<<score[i]<<endl;
        
        cout <<"Test Grade: "<<grade[i]<<endl<<endl<<endl;
    }
    return 0;
}
