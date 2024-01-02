UNITY_ROOT = framework/Unity
C_COMPILER = gcc

# Create directory if these doesn't exist
DIR_GUARD = mkdir -p

# Compiler flags
CFLAGS = -std=gnu99
CFLAGS += -Wall
CFLAGS += -D UNITY_INCLUDE_DOUBLE


# Executable that will be created
TARGET_BASE_1 = version
TARGET_1 = $(TARGET_BASE_1)$(TARGET_EXTENSION)
TARGET_BASE_2 = sum
TARGET_2 = $(TARGET_BASE_2)$(TARGET_EXTENSION)

# Useful paths
RUNNERS_DIR = testRunners/
TESTS_DIR = tests/

# List of files to compile
SRC_FILES_1 = $(UNITY_ROOT)/src/unity.c ../src/*.c $(TESTS_DIR)test_version.c $(RUNNERS_DIR)test_version_runner.c
SRC_FILES_2 = $(UNITY_ROOT)/src/unity.c ../src/*.c $(TESTS_DIR)test_sum.c $(RUNNERS_DIR)test_sum_runner.c

# Included directory
INC_DIRS = -I../src -I$(UNITY_ROOT)/src

all: check test 

check:
	@echo '=== Run cppcheck ==='
	cppcheck --language=c --enable=warning --error-exitcode=1 ../src

test:
	@echo '=== Create runner file with Ruby ==='
	$(DIR_GUARD) $(RUNNERS_DIR)
# Create the test_runner.c file based on test.c using Ruby.
# The runner file contains the main function that will call each tests functions declared in test.c
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb $(TESTS_DIR)test_version.c $(RUNNERS_DIR)test_version_runner.c
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb $(TESTS_DIR)test_sum.c $(RUNNERS_DIR)test_sum_runner.c

	@echo '=== Compile tests with gcc ==='
# Build all the sources/tests files and compile it into an executable
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SRC_FILES_1) -o $(TARGET_1)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SRC_FILES_2) -o $(TARGET_2)

	@echo '=== Run tests ==='
# Run the executable
	./$(TARGET_1)
	./$(TARGET_2)

clean:
	@echo '=== Clean all ==='
	rm -rf $(RUNNERS_DIR)*
	rm -rf $(TARGET_1)
	rm -rf $(TARGET_2)