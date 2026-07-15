# Tests Dcoumentation

## Readme

	- README.md Compilance check
	Does the repository contain a README.md file at its root, and does it include all of the following?
	• The first line is italicized and formatted exactly as: This activity has been created as part of the 42 curriculum
	by <login1>, <login2> (exactly 2 learners required).
	• A "Description" section explaining the activity's purpose and providing a brief overview.
	• An "Instructions" section with relevant details about compilation, installation, and/or execution.
	• A "Resources" section listing references (documentation, tutorials, etc.) and explaining how AI was used,
	specifying for which tasks and which parts of the project.
	• A detailed explanation and justification of the algorithms selected for this activity (Simple O(n²), Medium
	O(n√n), Complex O(n log n), and Adaptive strategies).
	• A clear documentation of each learner's contributions to the project.

### First line of Readme

![alt text](image-2.png)

### Other parts

- [Description](./README.md#description)
- [Instructions](./README.md#instructions)
- [Resources](./README.md#resources)
- [Algorithms](./README.md#algorithm-requirements)
- [Contributors](./README.md#contributors)

## Memory leaks

	- Throughout the defense, pay attention to the amount of memory
	used by push_swap (using the command top for example) in order
	to detect any anomalies and ensure that allocated memory is
	properly freed. If there are significant memory leaks, the final
	grade is 0.
	Note: Minor memory issues may be acceptable depending on the implementation,
	but major leaks or crashes should result in failure.

### Tests

1. memory leak test for simple:<br>
![alt text](image-32.png)
2. memory leak test for medium:<br>
![alt text](image-33.png)
3. memory leak test for complex:<br>
![alt text](image-34.png)
4. memory leak test for adaptive:<br>
![alt text](image-35.png)
5. memory leak test for benchmark:<br>
![alt text](image-36.png)

## Error management

### Eval Requirement

	- Error management
	In this section, we'll evaluate push_swap's error management.
	If most of these tests fail, no points will be awarded for this section.
	Note: At least 3 out of 4 error cases should be handled correctly.
	1. Run push_swap with non numeric parameters. The program must
	display "Error" followed by a ’\n’ on the standard error.
	2. Run push_swap with a duplicate numeric parameter. The program
	must display "Error" followed by a ’\n’ on the standard error.
	3. Run push_swap with only numeric parameters including one greater
	than MAXINT. The program must display "Error" followed by a ’\n’
	on the standard error.
	4. Run push_swap without any parameters. The program must not

### Tests

1. Non-numeric characters:<br>
![non numeric characters](image-3.png)

2. Duplicate numeric parameter:<br>
![alt text](image-4.png)

3. Greater than MAXINT:<br>
![alt text](image-5.png)

4. without any parameters:<br>
![alt text](image-6.png)

## Strategy selection -basic

### Eval requirement

	- Strategy Selection - Basic Tests
	Test the strategy selection flags. If most of these tests fail,
	no points will be awarded for this section.
	1. Run "$>./push_swap --simple 5 4 3 2 1" and verify it produces
	valid output that sorts the numbers.
	2. Run "$>./push_swap --medium 5 4 3 2 1" and verify it produces
	valid output that sorts the numbers.
	3. Run "$>./push_swap --complex 5 4 3 2 1" and verify it produces
	valid output that sorts the numbers.
	4. Run "$>./push_swap --adaptive 5 4 3 2 1" and verify it produces
	valid output that sorts the numbers.
	5. Verify that running without any flag defaults to --adaptive behavior.
	Note: At least 3 out of 5 tests should work for this section to pass.

### Tests

1. with simple:<br>
![alt text](image-7.png)

2. with medium:<br>
![alt text](image-8.png)

3. with comlex:<br>
![alt text](image-9.png)

4. with adaptive:<br>
![alt text](image-10.png)

5. no flags:<br>
![alt text](image-11.png)

## Identity test

### Eval requirement

	- Identity test - Already sorted inputs
	Test push_swap's behavior with already sorted inputs.
	If most tests fail, no points will be awarded for this section.
	1. Run "$>./push_swap 42". The program should display nothing.
	2. Run "$>./push_swap 2 3". The program should display nothing.
	3. Run "$>./push_swap 0 1 2 3". The program should display nothing.
	4. Run "$>./push_swap 0 1 2 3 4 5 6 7 8 9". The program should display nothing.
	All tests should produce no output (0 instructions) since the inputs are already sorted.
	Note: At least 3 out of 4 tests should work correctly.

### Tests

1. ./push_swap 42<br> 
![alt text](image-12.png)

2. ./push_swap 2 3<br> 
![alt text](image-13.png)

3. ./push_swap 0 1 2 3<br> 
![alt text](image-14.png)

4. ./push_swap 0 1 2 3 4 5 6 7 8 9<br> 
![alt text](image-15.png)

## Small inputs

### Eval requirements

	- Small inputs (3 numbers)
	Test with 3 numbers. Use the checker binary provided.
	1. Run "$>ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG".
	Check that the checker displays "OK" and that the number of
	instructions is reasonable (≤5 is acceptable, ≤3 is good).
	2. Test with other 3-number combinations like "0 2 1" or "1 0 2"
	and verify the checker displays "OK" with reasonable instruction count.
	Note: Some variation in instruction count is normal. Focus on correctness first.

### Tests

1. $>ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG<br>
![alt text](image-17.png)

2. $>ARG="1 0 2"; ./push_swap $ARG | ./checker_linux $ARG<br>
![alt text](image-18.png)

3. $>ARG="0 2 1"; ./push_swap $ARG | ./checker_linux $ARG<br>
![alt text](image-19.png)

## Benchmark flag

### Eval requirements

	Test the benchmark mode functionality. This is not a failing requirement
	but should be implemented according to the subject.
	1. Run "$>./push_swap --bench --simple 5 4 3 2 1 2>/dev/null" and
	verify it produces sorting instructions on stdout.
	2. Run "$>./push_swap --bench --simple 5 4 3 2 1 2>bench.txt >/dev/null && cat bench.txt"
	and verify the benchmark output contains most of:
	◦ Disorder percentage (should be present)
	◦ Strategy name and complexity class
	◦ Total operations count
	◦ Individual operation counts for operations
	• Test disorder calculation with known inputs:
	◦ For sorted input "1 2 3 4 5", disorder should be close to 0.00%
	◦ For reverse sorted input "5 4 3 2 1", disorder should be close to 100.00%
	Note: Minor variations in output format are acceptable if the core information is present.

### Tests

1. ./push_swap --bench --simple 5 4 3 2 1 2>/dev/null<br>
![alt text](image-37.png)
2. ./push_swap --bench --simple 5 4 3 2 1 2>bench.txt >/dev/null && cat bench.txt<br>
## Medium inputs

### Eval requirements

	- Medium inputs (5 numbers)
	Test with 5 numbers. Use the checker binary provided#
	1. Run "$>ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG".
	Check that the checker displays "OK" and that the number of
	instructions is reasonable (≤15 is acceptable, ≤12 is good).
	2. Test with 2-3 other combinations of 5 random numbers.
	Check that the checker displays "OK" and instruction count is reasonable.
	Example: try "5 1 4 2 3" or "3 5 1 4 2"
	Note: Different algorithms may produce different instruction counts.
	Correctness is more important than perfect optimization

### Tests

1. $>ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG<br>
![alt text](image-20.png)

2. $>ARG="5 4 3 2 1"; ./push_swap $ARG | ./checker_linux $ARG<br>
![alt text](image-21.png)

3. $>ARG="3 5 1 4 2"; ./push_swap $ARG | ./checker_linux $ARG<br>
![alt text](image-22.png)

## Large Inputs

### Eval requirements

	- Large inputs (100 numbers)
	Test with 100 random numbers. Use the checker binary provided.
	Generate random numbers using: shuf -i 1-500 -n 100
	• Run the test 2-3 times with different random sets.
	• Check that the checker displays "OK" for all tests
	• The program should use less than 2000 operations to pass this test.
	• Less than 1500 is good, less than 700 is excellent performance.
	Note: Some variation between runs is normal. Focus on overall correctness.

### Tests

1. first run:<br>
![alt text](image-23.png)
2. second run:<br>
![alt text](image-24.png)
3. third run:<br>
![alt text](image-25.png)

## Strategy flags

### Eval requirements

	- Strategy flags testing
	Test different strategy flags with the same input:
	• Generate 50 random numbers: shuf -i 1-200 -n 50
	• Test the same input with --simple, --medium, --complex flags
	• Most should produce valid output that sorts correctly
	• Generally, --complex should use fewer instructions than --simple
	• The --adaptive flag (or no flag) should work and choose automatically
	Note: It's acceptable if not all strategies are perfectly optimized.
	The important thing is that they work and show some performance differences

### Tests

simple<br>
![alt text](image-26.png)

medium<br>
![alt text](image-27.png)

complex<br>
![alt text](image-28.png)

adaptive<br>
![alt text](image-29.png)

## Very large inputs

### Eval requirements

	- Test with 500 random numbers. Use the checker binary provided.
	Generate using: shuf -i 1-1000 -n 500
	• Run the test 2 times with different random sets
	• Check that the checker displays "OK" for both tests
	• The program should use less than 12000 operations to pass this test.
	• Less than 8000 is good, less than 5500 is excellent performance.
	Note: This is a challenging test. Some variation in performance is expected.
	Focus on correctness first, then performance

### Tests

1. first run:<br>
![alt text](image-30.png)

2. second run:<br>
![alt text](image-31.png)