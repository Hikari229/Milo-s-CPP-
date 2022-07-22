/*Passwords are extremely imporant and are used on a daily basis.
Unfortunatley 80 Percent of Passwords around the world arent very secure.
Wouldnt it be wonderful if we all could have secure passwords.
This C++ Program can not only check if your password is secure,
but also has the option to generate an "uncrackable" passcode...

-Version 1.0
-Author: Milo Becker - Pos
-Language: C++

-If you have any suggestions on what i can improve please let me know!

*/


#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <stdlib.h>
#include <ctime>


class Password
{
public:
    std::string UserPass;
    int menuchoice;
    bool PassLength = false, LowerCase = false, UpperCase = false, Digit = false, SpecialChar = false;

    std::vector<char> SpecialChars = {'!', '@', '#', '$', '%', '^', '&', '8', '(', ')', '-', '+', '='};

    void CheckPass()
    {
        std::cout << "Please Enter your current password to check if it's secure : \n";
        std::cin.ignore();
        getline(std::cin, UserPass);

        if (UserPass.length() >= 10)
        {
            PassLength = true;

            for (int i=0; i<UserPass.length(); i++)
            {
                if (islower(UserPass[i]))
                {
                    LowerCase = true;
                }
                if (isupper(UserPass[i]))
                {
                    UpperCase = true;
                }
                if (!isalpha(UserPass[i]))
                {
                    Digit = true;
                }

                // Checking if the password contains any special characters
                for (int a=0; a<SpecialChars.size(); a++)
                {
                    for (int b=0; b<UserPass.length(); b++)
                    {
                        if (UserPass[b] == SpecialChars[a])
                        {
                            SpecialChar = true;
                            break;
                        }
                    }
                }
            }


            // Checking if pass is secure
            if (PassLength == true && LowerCase == true && UpperCase == true && Digit == true && SpecialChar == true)
            {
                std::cout << "Secure Password!" << std::endl;
            }

            // Telling user why the pass isnt secure
            if (LowerCase == false || UpperCase == false || Digit == false || SpecialChar == false)
            {
                std::cout << "Your password is not secure because - " << std::endl;

                if (LowerCase == false)
                {
                    std::cout << "You Have No Lower Case Letters! ";
                }
                if (UpperCase == false)
                {
                    std::cout << "You Have No Upper Case Letters! ";
                }
                if (Digit == false)
                {
                    std::cout << "You Have No Numbers! ";
                }
                if (SpecialChar == false)
                {
                    std::cout << "You Have No Special Characters! Ex(!, $, @, $) ";
                }
            }
        }
        else
        {
            std::cout << "Password is less than 10 characters long \n";
            Menu();
            CheckPass();
        }


    }

    void GeneratePass()
    {
        std::string GenPass; // Stores Generated password
        int PL; // PL == PasswordLength
        std::string AllChars = "qwertyuiopasdfghjklzxcvbnm"
                               "QWERTYUIOPASDFGHJKLZXCVBNM"
                               "1234567890"
                               "~`!@#$%^&*()-=_+[] ";

        std::cout << "How many digits would you like your password to be? : \n";
        std::cin >> PL;

        // Seeding the rand num
        srand(time(0));

        if (PL >= 7)
        {
            for (int i=1; i<=PL; i++)
            {
                GenPass = GenPass + AllChars[rand() % 93];
            }

            std::cout << "Generated Password : " << GenPass << std::endl;
        }
        else
        {
            std::cout << "Password is too short! Make sure you're generating a password that has more than 7 characters!" << std::endl;

        }
    }

     void Menu()
    {
        std::cout << "---Menu--- \n"
                  << "Options : Enter one or two : \n"
                  << "1. Check the security of my current password : \n"
                  << "2. Generate me a random password : \n"
                  << std::endl;
        std::cin >> menuchoice;

        if (menuchoice == 1)
        {
            system("CLS");
            CheckPass();
        }
        else if (menuchoice == 2)
        {
            system("CLS");
            GeneratePass();
        }
        else
        {
            std::cout << "INVALID OPTION " << std::endl;
        }
    }
};


int main()
{
    Password CallObj;

    // Calling Functions

    CallObj.Menu();



}

