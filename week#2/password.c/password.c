// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool checklower = false;
    bool checkupper = false;
    bool checknumber = false;
    bool checksymbol = false;
    for (int i = 0; i < strlen (password); i++)
    {
        if (islower(password[i])){
            checklower = true;
        }
        if (isupper(password[i])){
            checkupper = true;
        }
        if (isdigit (password[i])){
            checknumber = true;
        }
        if(!isalnum(password[i])){
            checksymbol = true;
        }
    }
    if (checklower == true && checkupper == true && checknumber == true && checksymbol == true)
    {
        return true;
    }
    return false;
}
