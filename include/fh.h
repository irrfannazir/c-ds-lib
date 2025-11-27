#ifndef FH_H
#define FH_H
#include <stdio.h>
#include <string.h>



#define FUNCTION_TERMINATOR(FH, ERROR_PROGRAM) if(!FH){ \
    ERROR_PROGRAM;\
    return 1;\
    }
;


static inline int write_content_to_file(const char *filename, const char *content){
    FILE *file = fopen(filename, "w");
    unsigned int size = 0;
    FUNCTION_TERMINATOR( file, printf("Error while writing data to file named %s", filename) );
    fputs(content, file);
    fclose(file);
    return 0;
}

static inline int append_content_to_file(const char *filename, const char *content){
    FILE *file = fopen(filename, "a");
    FUNCTION_TERMINATOR( file, printf("Error while appending the content to file named %s", filename) );
    fputs(content, file);
    fclose(file);
    return 0;
}

static inline int read_content_from_file(const char *filename, char *str, int size){
    FILE *file = fopen(filename, "r");
    char temp[1024];
    FUNCTION_TERMINATOR( file, printf("Error while reading file named %s", filename));
    while(fgets(temp, size, file)) strcat(str, temp);
    fclose(file);
    return 0;
}

#undef IS_FILE_SAFE
#endif