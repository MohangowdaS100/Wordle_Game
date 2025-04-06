#include "Wordle.h"
/**
 * @brief String comparision
 * 
 * @param str1 
 * @param str2 
 * @return true 
 * @return false 
 */
bool strcmp_m(char *str1, char *str2)
{
    int s, i;
    s = 0;
    for (i = 0; i < 5; i++)
    {
        if (str1[i] == str2[i])
            s++;
    }
    return (s < 5) ? false : true;
}
/**
 * @brief Function used to validate the user input
 * 
 * @param word 
 * @return ValResult 
 */
ValResult validator(char *word)
{
    int n, i;
    bool ret;
    n = strlen(word);
    if (n != 5)
    {
        return ValBadInput;
    }

    for (i = 0; i < MAX; i++)
    {
        if ((strcmp_m(words[i], word)))
        {
            ret = true;
            break;
        }
    }
    if (ret)
        return Valok;
    else
        return ValNosuchword;
}
/**
 * @brief Function is used to generate the seed value
 * 
 */
void seed(void)
{
    int x;
    x = getpid();
    srand(x);
    return;
}
/**
 * @brief Function is used to select a random 5 letters word from the pool of words available
 * 
 * @param max 
 * @return char* 
 */
char *randomword(int max)
{
    int x;
    static char ret[8];
    x = rand() % max;

    ret[0] = words[x][0];
    ret[1] = words[x][1];
    ret[2] = words[x][2];
    ret[3] = words[x][3];
    ret[4] = words[x][4];
    ret[5] = 0;
    return ret;
}
/**
 * @brief Function is used to analyze the given file and store the results in an array 
 * @param filename 
 * @return int 
 */
int readfile(char *filename)
{
    char buf[8];
    int i = 0, size;
    FILE *fd;
    fd = fopen(filename, "r");
    if (!fd)
    {
        perror("fopen()");
        return -1;
    }

    size = MAX * 5;

    (void)memset(buf, 0, 8);

    while (fgets(buf, 7, fd))
    {
        size = strlen(buf);
        if (size < 1)
        {
            memset(buf, 0, 8);
            continue;
        }
        size--;
        if (size != 5)
        {
            memset(buf, 0, 8);
            continue;
        }

        words[i][0] = buf[0];
        words[i][1] = buf[1];
        words[i][2] = buf[2];
        words[i][3] = buf[3];
        words[i][4] = buf[4];

        memset(buf, 0, 8);
        i++;

        if (i >= MAX)
        {
            break;
        }
    }
    fclose(fd);
    return i;
}
/**
 * @brief Function is used to check how many letters are predicted correctly
 * 
 * @param correctword 
 */
void prompt(char *correctword)
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        switch (corrects[i])
        {
        case false:
        {
            printf("-");
            break;
        }
        case true:
        {
            printf("%c", correctword[i]);
            break;
        }
        }
    }
    printf("\n\n%d> ", (5 - rounds));
    fflush(stdout);
    return;
}
/**
 * @brief Function is used to print the results
 * 
 * @param res 
 * @param guess 
 * @param correct 
 */
void print_results(char *res, char *guess, char *correct)
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        switch (res[i])
        {
        case ResultGreen:
            printf("%s%c%s", ClrGreen, guess[i], ClrStop);
            break;
        case ResultYellow:
            printf("%s%c%s", ClrYellow, guess[i], ClrStop);
            break;
        case ResultRed:
            printf("%s%c%s", ClrRed, guess[i], ClrStop);
            break;
        default:
            printf("Unknown\n");
            break;
        }
    }
    printf("\n");
    return;
}
/**
 * @brief Function is used to check if the character is present inside the word or not
 * 
 * @param c 
 * @param str 
 * @return true 
 * @return false 
 */
bool isin(char c, char *str)
{
    bool ret;
    ret = false;
    int i = 0;
    int size;
    size = strlen(str);

    for (i = 0; i < size; i++)
    {
        if (c == str[i])
        {
            ret = true;
            return ret;
        }
    }

    return ret;
}
/**
 * @brief Function is used to check if the predicted characters are present in the correct word or not.
 * 
 * @param guess 
 * @param idx 
 * @param word 
 * @return Result 
 */
Result cc(char guess, int idx, char *word)
{
    char correct = word[idx];
    if (guess == correct)
    {
        corrects[idx] = true;
        return ResultGreen;
    }
    else if (isin(guess, word))
        return ResultYellow;
    else
        return ResultRed;
}
/**
 * @brief Function is used to check if Guess word is the word we are predicting 
 * 
 * @param Guess 
 * @param word 
 * @return Result* 
 */
Result *cw(char *Guess, char *word)
{
    static Result res[5];
    int i = 0;

    for (i = 0; i < 5; i++)
        res[i] = cc(Guess[i], i, word);

    return res;
}
/**
 * @brief Function is used for handling the user input
 * 
 * @return char* 
 */
char *readline()
{
    static char buf[8];
    int size;
    memset(buf, 0, 8);
    fgets(buf, 7, stdin);
    size = strlen(buf);
    assert(size > 0);
    size--;
    buf[size] = 0;
    return buf;
}
/**
 * @brief This function is the main body of the game
 * 
 * @param correct 
 */
void gameloop(char *correct)
{
    char *input;
    Result *res;
    ValResult valres;
    int i, c;
    prompt(correct);
    input = readline();
    valres = validator(input);
    switch (valres)
    {
    case ValBadInput:
    {
        printf("Bad input\n");
        return;
    }
    case ValNosuchword:
    {
        printf("No such word in english\n"); // this change is required for working
        rounds++;
        return;
    }
    default:
        break;
    }
    res = cw(input, correct);
    for (i = c = 0; i < 5; i++)
    {
        if (corrects[i])
            c++;
    }
    print_results(res, input, correct);
    if (c == 5)
    {
        win = true;
        continuation = false;
        return;
    }
    rounds++;
    if (rounds > 5)
    {
        win = false;
        continuation = false;
        return;
    }
}
/**
 * @brief Main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    corrects[0] = false;
    corrects[1] = false;
    corrects[2] = false;
    corrects[3] = false;
    corrects[4] = false;

    rounds = 0;
    win = false;
    char *p;
    seed();
    int n = readfile("wordl.txt");
    assert(!(n < 0));
    p = randomword(n);
    printf("Welcome to Wordle. Please enter a proper\n");
    printf("5 letter english word, Good Luck!\n\n");
    continuation = true;
    while (continuation)
    {
        gameloop(p);
    }
    printf("The correct word was: '%s' \n", p);
    if (win)
        printf("congratulatiosn, you own the game\n");
    else
        printf("You Lost, Game Over\n");
    return 0;
}