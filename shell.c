// ACADEMIC INTEGRITY PLEDGE
//
// - I have not used source code obtained from another student nor
//   any other unauthorized source, either modified or unmodified.
//
// - All source code and documentation used in my program is either
//   my original work or was derived by me from the source code
//   published in the textbook for this course or presented in
//   class.
//
// - I have not discussed coding details about this project with
//   anyone other than my instructor. I understand that I may discuss
//   the concepts of this program with other students and that another
//   student may help me debug my program so long as neither of us
//   writes anything during the discussion or modifies any computer
//   file during the discussion.
//
// - I have violated neither the spirit nor letter of these restrictions.
//
//
//
// Signed:_David_Reese__________________________ Date:_2024:02:26__

// 3460:426 Lab 1 - Basic C shell rev. 9/10/2020

/* Basic shell */

/*
 * This is a very minimal shell. It finds an executable in the
 * PATH, then loads it and executes it (using execv). Since
 * it uses "." (dot) as a separator, it cannot handle file
 * names like "minishell.h"
 *
 * The focus on this exercise is to use fork, PATH variables,
 * and execv. 
 */

// included in starter file
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// for running the starter file code
#include <stdbool.h>
#include <sys/wait.h>

// not included in starter file
#include<stdlib.h>      // stdlib.h library: https://www.ibm.com/docs/en/zos/3.1.0?topic=files-stdlibh-standard-library-functions 

#define MAX_ARGS		64
#define MAX_ARG_LEN		16
#define MAX_LINE_LEN	80
#define WHITESPACE		" ,\t\n"

struct command_t {
   char *name;
   int argc;
   char *argv[MAX_ARGS];
};

/* Function prototypes */
int parseCommand(char *, struct command_t *);
void printPrompt();
void readCommand(char *);

int main(int argc, char *argv[]) {
    int status;
    char cmdLine[MAX_LINE_LEN];
    struct command_t command;

    while (true) {
        printPrompt();
        /* Read the command line and parse it */
        readCommand(cmdLine);
        parseCommand(cmdLine, &command);
        command.argv[command.argc] = NULL;

        // =========== GENERAL COMMANDS =========== 
        if(strcmp(command.name, "Q") == 0) {
            exit(0);
        } else if (strcmp(command.name, "W") == 0) {
            int pid = fork();
            if (pid == 0) {
                printf("Execute clear");
                execvp("clear", NULL);
                perror("W exec failure"); // shouldn't fire
                exit(1);
            } else if (pid < 0) {
                perror("W fork failure");
            } else {
                wait(NULL); // waits for clear to finish
            }
        } else if (strcmp(command.name, "S") == 0) {
            // Doesn't wait for the process to end. 
            system("firefox &");  
        } else if (strcmp(command.name, "L") == 0) {
            printf("\n");
            system("pwd");
            printf("\n");
            system("ls -l");
            continue;
        } else if (strcmp(command.name, "E") == 0) {
            if (command.argc > 1) {
                for (int i = 1; i < command.argc; i++) {
                    printf("%s", command.argv[i]);
                    if (i < command.argc - 1) {
                        printf(" ");
                    }
                }
            } printf("\n");
        } else if (strcmp(command.name, "X") == 0) {
            for (int i = 1; i < command.argc; i++) {
                command.argv[i] = command.argv[i+1];
            }
            command.argc -= 1;
            // execute program
            int pid;
            if ((pid = fork()) == 0) {
                execvp(command.name, &command.argv[1]);
            }

        } 
        // =========== FILE MANAGEMENT COMMANDS ===========
        /*
        else if (strcmp(command.name, "C") == 0) {
            if (command.argc >= 3) {
                pid_t pid2 = fork();
                if (pid2 == 0) {
                    // begat child
                    char *args[] = {"cp", command.argv[1], command.argv[2], NULL};
                    execvp("cp", args);
                    // fails if reaches this line
                    fprintf(stderr, "copy failed\n");
                    exit(EXIT_FAILURE);
                } else if (pid2 > 0) {
                    wait(NULL);
                } else {
                    fprintf(stderr, "error in copy fork.\n");
                }
            } else {
                fprintf(stderr, "Usage: C [file1] [file2]\n");
            }
        }*/ 
        else if (strcmp(command.name, "D") == 0) {
            if (command.argc >= 2) {
                char posixCommand[128];
                snprintf(posixCommand, sizeof(posixCommand), "rm %s", command.argv[1], command.argv[2]);
                system(posixCommand);
            }
        }
        else if (strcmp(command.name, "M") == 0) {
            if (command.argc >= 2) {
                char posixCommand[128];
                snprintf(posixCommand, sizeof(posixCommand), "nano %s", command.argv[1], command.argv[2]);
                system(posixCommand);
            }
        }
        else if (strcmp(command.name, "P") == 0) {
            if (command.argc >= 2) {
                char posixCommand[128];
                snprintf(posixCommand, sizeof(posixCommand), "more %s", command.argv[1], command.argv[2]);
                system(posixCommand);
            }
        }
        // simple manual print statements
        else if (strcmp(command.name, "H") == 0) {
            // printf("======================================================================\n");
            printf("\nA Simple Linux Shellp:\n");
            printf("======================\n");
            printf(">C [file1] [file2]\t- Copy [file1] + Paste to [file2].\n");
            printf(">D [file]\t\t- Delete [file].\n");
            printf(">E [comment]\t\t- Print [comment] (echo).\n");
            printf(">H\t\t\t- Help me!\n");
            printf(">L\t\t\t- List current directory contents, no arguments.\n");
            printf(">M [file]\t\t- Create [file] w/ nano, which is a choice...\n");
            printf(">P [file]\t\t- Display the contents of [file].\n");
            printf(">Q\t\t\t- Quit.\n");
            printf(">S\t\t\t- Launches firefox.\n");
            printf(">W\t\t\t- Clears the console.\n");
            printf(">X [program]\t\t- Execute [program].\n");
            printf("======================================================================\n");
            printf("\n3 BASIC RULES:\n");
            printf("==============\n");
            printf("1.) Internal commands are case sensitive.\n");
            printf("2.) Provide ONLY the necessary arguments, or use an external command.\n");
            printf("3.) Unlisted/Unrecognized commands ARE external commands.\n");
            printf("======================================================================\n");
        } else {
            /* Create a child process to execute the command */
            int pid;
            if ((pid = fork()) == 0) {
                execvp(command.name, command.argv);
            /* TODO: what happens if you enter an incorrect command? */
            }
        }
        /* Wait for the child to terminate */
        wait(&status);
    }

    /* Shell termination */
    printf("\n\n shell: Terminating successfully\n");
    return 0;
}

/* End basic shell */

/* Parse Command function */

/* Determine command name and construct the parameter list.
 * This function will build argv[] and set the argc value.
 * argc is the number of "tokens" or words on the command line
 * argv[] is an array of strings (pointers to char *). The last
 * element in argv[] must be NULL. As we scan the command line
 * from the left, the first token goes in argv[0], the second in
 * argv[1], and so on. Each time we add a token to argv[],
 * we increment argc.
 */
int parseCommand(char *cLine, struct command_t *cmd) {
   int argc;
   char **clPtr;
   /* Initialization */
   clPtr = &cLine;	/* cLine is the command line */
   argc = 0;
   cmd->argv[argc] = (char *) malloc(MAX_ARG_LEN);
   /* Fill argv[] */
   while ((cmd->argv[argc] = strsep(clPtr, WHITESPACE)) != NULL) {
      cmd->argv[++argc] = (char *) malloc(MAX_ARG_LEN);
   }

   /* Set the command name and argc */
   cmd->argc = argc-1;
   cmd->name = (char *) malloc(sizeof(cmd->argv[0]));
   strcpy(cmd->name, cmd->argv[0]);
   return 1;
}

/* End parseCommand function */

/* Print prompt and read command functions - Nutt pp. 79-80 */

void printPrompt() {
    /* Build the prompt string to have the machine name,
    * current directory, or other desired information
    */
    char *user = "dcr54";
    char prompt[MAX_LINE_LEN];
    // Construct & Print promptString
    int len = snprintf(prompt, sizeof(prompt), "linux(%s)|>", user);   
    printf("%s ", prompt);
}

void readCommand(char *buffer) {
   /* This code uses any set of I/O functions, such as those in
    * the stdio library to read the entire command line into
    * the buffer. This implementation is greatly simplified,
    * but it does the job.
    */
   fgets(buffer, 80, stdin);
}

/* End printPrompt and readCommand */