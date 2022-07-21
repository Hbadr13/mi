#include <unistd.h>
#include <stdio.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
#include <readline/readline.h>
#include "/usr/include/readline/readline.h"
#include<stdlib.h>



int main()
{
    char *p;
    char *str;
    int i;
   printf("PATH : %s\n", getenv("PATH"));
   printf("HOME : %s\n", getenv("HOME"));
   printf("ROOT : %s\n", getenv("ROOT"));
}


// // Ctrl+c - SIGINT
// // Ctrl+\ - SIGQUIT
// // Ctrl+Z - SIGTSTP




    // void handler (int status)
    // {
    //     printf("%d\n",status);
    //    rl_replace_line("",0);
    //    rl_redisplay();

    //   // rl_done = 1;
    // }

// int main (int argc, char** argv)
// {
//     int i = 0;
//    char* entry;
//    while(i <= 35)
//    {
//     signal(i,handler);
//        if(i == 35)
//         i = -1;
//        i++;
//    }
//     entry = readline("--> ");
//    printf("\nEntry was: %s\n", entry);
//    return 0;
// }








// int my_cool_readline_func (int count, int key) {
//    printf ("key pressed: %d\n", key);
//    rl_on_new_line ();
//    return 0;
// }

// int main(void) {
//      rl_command_func_t my_cool_readline_func;
//      rl_bind_key ('\t', my_cool_readline_func);
//      rl_bind_key (27, my_cool_readline_func); /* ascii code for ESC */
//      rl_bind_keyseq ("\\C-a", my_cool_readline_func);
// rl_replace_line();
//      while (1) {
//          char *line = readline ("rl> ");
//      }
// }