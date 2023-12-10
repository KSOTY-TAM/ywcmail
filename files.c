#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include "config.h"

int test_path(char path[])
{
    struct stat st;
    if(stat(path,&st) == 0)
    {
        return 0;
    } else
    {
        return 1;
    }
}

FILE* open_file(char f[])
{
  FILE* fp = fopen(f, "r");
  if (fp == NULL) {
    return NULL;
  }
  return fp;
}

int is_user_in_file(FILE* fp,char user[]) 
{
  char line[1024] = {};
  while (NULL != fgets( line, 1024, fp) )
  {
    if (line[0] != '#')
    {
        if (strncmp( line, user, strlen(user) ) == 0)
        {
          return 0;	
        }
    }
  }
  return 1;
}

// Filename is wmsuername_key 
int wm_is_user_allowed(char wmusername[])
{
  int is_path = 0;
  is_path = test_path(ALLOWED_USERS);
  if (is_path ==0) 
  {
    FILE* fp = open_file(ALLOWED_USERS); // return filehandle or NULL
    if (fp != NULL)
    {
      return is_user_in_file(fp, wmusername);
    }
  }
  return 1;  // path does not exist
}

#ifdef BUILD_FOR_TESTS

int main_read_allow()
{
  if(read_is_user_allowed( "anon" ) == 0)
  {
     // "found"
  }

  return 0;
}

#endif
