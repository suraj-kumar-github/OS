#include  <stdio.h>
#include  <sys/types.h>

void  parse(char *line, char **argv)
{
     while (*line != '\0') {        
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';     
          *argv++ = line;          
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++;             
     }
     *argv = '\0';
}
     
void  execute(char **argv)
{
     pid_t  pid;
     int    status;
     
     if ((pid = fork()) < 0) {  
          fprintf(stderr, "An error occured in forking\n");
     	  abort();
     }
     else if (pid == 0) {   
          if (execvp(*argv, argv) < 0) {     
          		fprintf(stderr, "An error occured in execvp\n");
          		abort();
          }
     }
     else {                                 
          while (wait(&status) != pid);
     }
}


void  main(void)
{
     char  line[1024];             
     char  *argv[64];              
     char shell_name[256]= "/suraj_shell>>>";
     while (1) {                   
         // system("pwd");
          printf("%s", shell_name);
          gets(line);              
          printf("\n");
          parse(line, argv);       
          if (strcmp(argv[0], "exit") == 0)  
               exit(0);            
          execute(argv);           
     }
}               
