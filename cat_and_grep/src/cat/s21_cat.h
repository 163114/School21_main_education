#ifndef SRC_S21_CAT_H_
#define SRC_S21_CAT_H_

#include <stdio.h>
#include <string.h>

#define TOTAL_NUMBER_OF_FLAGS 11
#define MAX_LENGTH_OF_FLAG 18
#define NMAX 20

enum true_of_false{
    FALSE,
    TRUE
};

static const char possible_flags[TOTAL_NUMBER_OF_FLAGS][MAX_LENGTH_OF_FLAG] = {
    "-b", "--number-nonblank", "-e", "-E",
    "-n", "--number", "-s", "--squeeze-blank", "-t", "-T", "NULL"
};

typedef struct Flags {
    int b;
    int s;
    int n;
    int e;
    int E;
    int T;
    int t;
} Flags;

typedef struct Data {
    // Create an array for all the flags - valid and invalid to sort them out later
    char all_flags_array[NMAX][NMAX];
    // And an array for text-file names - valid and invalid to sort later
    char all_text_files_array[NMAX][NMAX];
    int ordinal_b;
    int character_index;
} Data;

int check_start_conditions(int argc, char *argv[], Data* data);
void initialize_flags(Flags* flags);
void initialize_data(Data* data);
int parse_flags_and_text_files(int argc, char *argv[], Data* data);
int check_if_flags_are_valid(int counter_for_flags, Data* data);
int check_if_files_exist(int number_of_files, Data* data);
void pass_flags_to_structure(Flags* flags, Data* data);
void print_result(Flags* flags, Data* data);
int handle_b(char first_character, char second_character, Data* data);

// void handle_s(FILE* file);

#endif  // SRC_S21_CAT_H_