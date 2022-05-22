CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -c
CFLAGS=-std=c11 -c
CFLAGS_GCOV=-fprofile-arcs -ftest-coverage
LIBS=-lcheck -lgcov

SOURCE_DIRECTORIES=s21_common/s21_is_found s21_common/s21_memcpy_forward_backward s21_common/s21_filter_from_beginning s21_memchr s21_memcmp s21_memcpy s21_memmove s21_memset s21_strcat s21_strchr s21_strcmp s21_strcspn s21_strerror s21_strlen s21_strncat s21_strncmp s21_strncpy s21_strpbrk s21_strrchr s21_strspn s21_strstr s21_strtok


OBJECT_DIRECTORIES_TO_CLEAN=$(subst ../,,$(filter ../%, $(SOURCE_DIRECTORIES)))


BUILD_DIRECTORY=build
DEPENDENCY_DIRECTORY=$(BUILD_DIRECTORY)/dependencies


ALL_TESTS_IN_ONE_FILE=$(BUILD_DIRECTORY)/s21_string_test.check
ALL_TESTS_IN_ONE_FILE_GENERATED=$(BUILD_DIRECTORY)/s21_string_test.c
#SOURCE_FILES_TESTS=$(foreach directory_as_variable, $(SOURCE_DIRECTORIES),$(wildcard $(directory_as_variable)/*.check))
TEST_FILES=$(foreach directory_as_variable, $(SOURCE_DIRECTORIES),$(wildcard $(directory_as_variable)/*.check))


TEST_FILE=$(ALL_TESTS_IN_ONE_FILE)
TEST_FILE_GENERATED=$(patsubst %.check,%.c,$(TEST_FILE))
OBJECT_TEST_FILE_GENERATED=$(BUILD_DIRECTORY)/$(notdir $(patsubst %.c,%.o,$(TEST_FILE_GENERATED)))
TARGET_TEST=$(BUILD_DIRECTORY)/$(notdir $(patsubst %.o,%.out,$(OBJECT_TEST_FILE_GENERATED)))

SOURCE_FILES_ALL=$(wildcard *.c)
SOURCE_FILES_ALL+=$(foreach directory_as_variable, $(SOURCE_DIRECTORIES),$(wildcard $(directory_as_variable)/*.c))
SOURCE_FILES=$(filter-out %_test.c, $(SOURCE_FILES_ALL))

OBJECT_FILES_IN_SOURCE_DIRECTORIES=$(patsubst %.c,%.o,$(SOURCE_FILES))
OBJECT_FILES_IN_BUILD_DIRECTORIES=$(addprefix $(BUILD_DIRECTORY)/,$(OBJECT_FILES_IN_SOURCE_DIRECTORIES))
# OBJECT_FILES_IN_BUILD_DIRECTORIES+=$(OBJECT_TEST_FILE_GENERATED)

DEPENDENCY_FILES_ALL_IN_SOURCE_DIRECTORIES=$(patsubst %.c,%.d,$(SOURCE_FILES))
DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES=$(addprefix $(DEPENDENCY_DIRECTORY)/,$(DEPENDENCY_FILES_ALL_IN_SOURCE_DIRECTORIES))

TEST_FILE_GENERATED_DEPENDENCY=$(DEPENDENCY_DIRECTORY)/$(subst .c,.d,$(notdir $(TEST_FILE_GENERATED)))
DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES+=$(TEST_FILE_GENERATED_DEPENDENCY)
DEPENDENCY_DIRECTORIES=$(dir $(DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES))

DEPFLAGS=-MT $@ -MMD -MP -MF $(DEPENDENCY_DIRECTORY)/$*.d

run_test: test
		-$(TARGET_TEST)

test: $(TARGET_TEST)

rerun_test: clean run_test


generate_all_tests: $(ALL_TESTS_IN_ONE_FILE_GENERATED)


$(ALL_TESTS_IN_ONE_FILE): $(TEST_FILES)
		mkdir -p $(dir $@)
		touch $(notdir $@)
		cat $^ >> $@
		echo "" >> $@


gcov_report: run_test
		$(foreach directory,$(SOURCE_DIRECTORIES),gcovr $(subst ../,,$(directory)) -r $(directory) --html-details -o coverage_report.html ;)
		gcovr . --html --html-details -o coverage_report.html

leaks: run_test
		leaks -atExit -- $(TARGET_TEST)

leaks_short: run_test
		leaks -atExit -- $(TARGET_TEST) | grep LEAK

$(TEST_FILE_GENERATED): $(TEST_FILE)
		checkmk $< > $@


$(TARGET_TEST): $(OBJECT_FILES_IN_BUILD_DIRECTORIES) $(OBJECT_TEST_FILE_GENERATED)
		$(CC) -o $@ $^ $(LIBS) $(CFLAGS_GCOV)


$(OBJECT_TEST_FILE_GENERATED): $(TEST_FILE_GENERATED) $(DEPENDENCY_FILE_TEST_FILE_GENERATED_IN_DEPENDENCY_DIRECTORY) | $(DEPENDENCY_DIRECTORY)
		mkdir -p $(dir $@)
		mkdir -p $(DEPENDENCY_DIRECTORY)/$(dir $*)
		$(CC) $(CFLAGS) $< -o $@ $(DEPFLAGS)


$(OBJECT_FILES_IN_BUILD_DIRECTORIES): $(BUILD_DIRECTORY)/%.o: %.c $(DEPENDENCY_DIRECTORY)/%.d | $(DEPENDENCY_DIRECTORY)
		mkdir -p $(dir $@)
		mkdir -p $(DEPENDENCY_DIRECTORY)/$(dir $*)
		$(CC) $(CFLAGS) $(CFLAGS_GCOV) $< -o $@ $(DEPFLAGS)


$(DEPENDENCY_DIRECTORY):
		mkdir -p $(DEPENDENCY_DIRECTORY)


$(DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES):


clean: 
		rm -rf $(BUILD_DIRECTORY) $(DEPENDENCY_DIRECTORY) $(OBJECT_DIRECTORIES_TO_CLEAN) $(TEST_FILE_GENERATED) *.gcov *.html *.css


print:
		echo $(TEST_FILES)
		

include $(wildcard $(DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES))