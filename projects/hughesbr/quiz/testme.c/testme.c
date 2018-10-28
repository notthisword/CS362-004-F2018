#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


char inputChar(int state)
{
	//declare variables
	int randNum = 0;
	int min = 0;
	int max = 0;
	char c;
	
	if (state == 0 || state == 8)
	{
		min = 91;
		max = 126;
	}
	else if (state == 1 || state == 3 || state == 7)
	{
		min = 32;
		max = 64;
	}
	else if (state == 2 || state == 6)
	{
		min = 97;
		max = 126;
	}
	else if (state == 4 || state == 5)
	{
		min = 65;
		max = 126;
	}
	else if (state == 9)
	{
		min = 97;
		max = 122;
	}
	else
	{
		min = 32;
		max = 126;		
	}
	
	//note:   rand() % (max - min + 1) + min
	randNum = rand() % (max - min + 1) + min;
	c = randNum;
    return c;
}

char *inputString(char* str)
{
    /*****************
	 * Per the testing algorithm, the string 'reset\0' ends
	 * the testing with the error code 200; therefore, the 
	 * max string count was set to 6 in order to minimize
	 * run times. This could be changed to higher values to 
	 * better increase the randomization of the function calls.
	 ****************/
	
	//declare variables
	int count = 0;
	char c;
	int randNum = 0;
	int min = 97;
	int max = 122;
	
	//first let's fill up the string with random lowercase letters!
	//We're only going up to string size - 1 because we are
	//going to affix the null character to the end of the string.
	for (count = 0; count < 5; count++)
	{
		//note:   rand() % (max - min + 1) + min
		randNum = rand() % (max - min + 1) + min;
		c = randNum;
		str[count] = c;
	}
	
	//affix the null character to the end of the string
	//we're using stringSize - 1 because of 0 numbering
	//technically, we could use 5, but this way, if the
	//size is changed, the number won't have to be changed.
	str[5] = '\0';
	
    return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  char str[6];
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar(state);
    s = inputString(str);
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' ' && state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
