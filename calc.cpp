
#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include "dstack.h"

//cerr error message that prints to standard error
void error_message ();

int main () { 
  double number = 0.0;
  char input;
  Dstack stack;
  //while loop that runs until end of file or ctrl-d
  while (std::cin.peek () != EOF) {
      int peek = std::cin.peek ();
      
      //if the character peeked is a ' ' it gets deleted
      if (isspace (peek)) { 
        std::cin.ignore ();
      } 
      //if the character peeked is a . or number it gets inputed
      //onto the stack
      else if (std::isdigit (peek) || peek == '.') {
        std::cin >> number;
        stack.push (number);
        
        //peeking at the next character if it is . then error 
        //prevents 1.2.3, .1., 2.3. etc etc 
        if (std::cin.peek () == '.') { 
          error_message ();
          return 1;
        } 
      } 
      //checks to see if the next character is a letter if it is then
      //it is inputed via string then the string is examined and a value
      //is passed to a switch statement that evaluates the expression
      //after this evalutaion it pushes it onto the stack. 
      else if (isalpha (std::cin.peek ())) { 
        std::string special_case;
        std::cin >> special_case;
        int extra = 0;
        double extra_answer = 0.0;
        double pop_number = 0.0;
                
        if (special_case[0] == 's' && special_case[1] == 'q') 
          extra = 1;
        
        if (special_case[0] == 'a') 
          extra = 2;
        
        switch (extra) { 
          case 1:
            stack.pop (pop_number);
            extra_answer = sqrt (pop_number);
            break;
          case 2:
            int counter = stack.size ();
            int total_numbers = counter;
            while (counter > 0) { 
            stack.pop (pop_number);
            extra_answer = extra_answer + pop_number;  
            counter--;
            } 
            extra_answer = extra_answer / total_numbers;
            break;
        }
        stack.push (extra_answer);
      } else {
          //check to make sure the stack has at least 2 values for the
          //operator to evaluate
          if (stack.size () < 2) {
            error_message ();
            return 1;
          }
        double pop1, pop2 = 0.0;
        stack.pop_two (pop1, pop2);
   
        /*since nothing but an operator can be left the program  
          takes in the  operator and evaluates the expression
          accordingly. Afterwards the result (answer) gets pushed
          onto the stack.  */  
        std::cin >> input;
        double answer = 0.0;
          switch (input) { 
            case '+':
              answer = pop2 + pop1;
              break;
            case '-':
              answer = pop2 - pop1;
              break;
            case '/':
              if (pop1 == 0) { 
                error_message ();
                return 1;
              } 
              answer = pop2 / pop1;
              break;
            case '*':
              answer = pop2 * pop1;
              break;
            case '^':
              answer = pow(pop2, pop1);
              break;
            default:
              error_message ();
              return 1;
           } 
        stack.push (answer);
      }     
  }
  //prints out the what should be the only value on the stack
  //if there is more than one value cerr message is given
  if (stack.size () == 1) {
    double result = 0.0;
    stack.pop (result);
    std::cout << result << std::endl;
  } else { 
    error_message ();
    return 1;
  } 
  
  return 0;
}

void error_message () {
  std::cerr << "Error: Invalid expression." << std::endl;
}   
