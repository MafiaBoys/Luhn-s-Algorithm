#include <cs50.h>
#include <stdio.h>

// @MafiaBoy

typedef long long QWORD;

int main(int argc, char const *argv[]) {

    QWORD tmp, cc = get_long_long("Number: ");

    int j, i ,b = 0,sum = 0 ,counts = 0;

    while (cc > 0)
    {
        // begin Luhn’s Algorithm
        tmp = (cc % 100); i = tmp % 10; j = ((tmp - i) / 10) * 2;

        while (j % 10 != j)
        {
            j = ((j - (j % 10)) / 10) + j % 10;
        }
        // end Luhn’s Algorithm

        // begin store card begin numbers
        if (cc % 1000 == cc && cc >= 10)
        {
           if (cc % 100 != cc) b = (cc - (cc % 10)) / 10;
        }
        // end store card begin numbers
        sum += j + i; cc /= 100; counts += 2;
    }

    if (b != 0)
    {
        tmp = b;
    }

    if (sum % 10 == 0 && counts > 10)
    {

        if (tmp == 41 || tmp == 42 || tmp == 40)
        {
            puts("VISA");
            return 0;
        }
        if (tmp == 30)
        {
            puts("Diners Club");
            return 0;
        }
        if (tmp == 60)
        {
            puts("Discover");
            return 0;
        }
        if (tmp == 22 || tmp == 55 || tmp == 51)
        {
            puts("MASTERCARD");
            return 0;
        }
        if (tmp == 35)
        {
            puts("JCP");
            return 0;
        }
        if (tmp == 37)
        {
            puts("AMEX");
            return 0;
        }

        // here if you Want's print ("Card is legit\n");
    }

    puts("INVALID");
    return 0;
}
