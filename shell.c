#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "parse.h"   //include declarations for parse-related structs

enum
BUILTIN_COMMANDS { NO_SUCH_BUILTIN=0, EXIT,JOBS};
 
char *
buildPrompt()
{
  return  "%";
}
 
int
isBuiltInCommand(char * cmd){
  
  if ( strncmp(cmd, "exit", strlen("exit")) == 0){
    return EXIT;
  }
  return NO_SUCH_BUILTIN;
}


int 
main (int argc, char **argv)
{

  
  char * cmdLine;
  parseInfo *info; //info stores all the information returned by parser.
  struct commandType *com; //com stores command name and Arg list for one command.

#ifdef UNIX
  
    fprintf(stdout, "This is the UNIX version\n");
#endif

#ifdef WINDOWS
    fprintf(stdout, "This is the WINDOWS version\n");
#endif

  while(1){
    //insert your code to print prompt here.

#ifdef UNIX
    cmdLine = readline(buildPrompt());
    if (cmdLine == NULL) {
      fprintf(stderr, "Unable to read command\n");
      continue;
    }
#endif

    //insert your code about history and !x !-x here

    //calls the parser
    info = parse(cmdLine);
    if (info == NULL) continue;
    //prints the info struct
    print_info(info);

    //com contains the info. of the command before the first "|"
    com=&info->CommArray[0];

    //com->command tells the command name of com
    if (isBuiltInCommand(com->command) == EXIT){
      exit(1);
    }
  
    //insert your code here.

    free_info(info);
    free(cmdLine);
  }/* while(1) */
}
  





