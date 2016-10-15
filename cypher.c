#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void cypher(char* method, int key, char* message);

int main(int argc, char* argv[])
{
  if(!argv[1] || !argv[2] || !argv[3])
  {
    printf("%s\n", "Help: ./cypher [-e (encrypt) / -d (decrypt)] [10 (positive integer key)] ['Hello, world!' (string message in single quotes)]");
  }
  else if(strcmp(argv[1], "-e") != 0 && strcmp(argv[1], "-d") != 0)
  {
    printf("%s\n", "Help: [-e (encrypt) / -d (decrypt)]");
  }
  else if(*argv[2] != 0 && !isdigit(*argv[2]))
  {
    printf("%s\n", "Help: [10 (positive integer key)]");
  }
  else
  {
    cypher(argv[1], atoi(argv[2]), argv[3]);
  }
  return 0;
}

void cypher(char* method, int key, char* message)
{
  if(strcmp(method, "-e") == 0)
  {
    printf("Encrypted message: ");
  }
  else if(strcmp(method, "-d") == 0)
  {
    printf("Decrypted message: ");
  }
  for (int i = 0, j = strlen(message); i < j; i++)
  {
    if(isalpha(message[i]) != 0)
    {
      if(islower(message[i]) != 0)
      {
        if(strcmp(method, "-e") == 0)
        {
          message[i] = (message[i] - 97 + key) % 26 + 97;
        }
        else if(strcmp(method, "-d") == 0)
        {
          message[i] = (message[i] - 97 - key) % 26 + 97;
        }
      }
      else if(isupper(message[i]) != 0)
      {
        if(strcmp(method, "-e") == 0)
        {
          message[i] = (message[i] - 65 + key) % 26 + 65;
        }
        else if(strcmp(method, "-d") == 0)
        {
          message[i] = (message[i] - 65 - key) % 26 + 65;
        }
      }
    }
    printf("%c", message[i]);
  }
  printf("\n");
}
