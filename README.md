# Parallel & Cloud Computing Laboratory — B.Sc. (Hons.) Computer Application, Semester V

**Course Code:** CABSXO-5P01
**Credits:** 02
**Periods per Week:** 03
**Department:** Computer Science, Aligarh Muslim University
**Session:** 2025–2026

---

## About the Course

This lab course covers Parallel and Cloud Computing. It starts with core C programming and array handling, moves into shared-memory parallelism using OpenMP, then distributed-memory communication using MPI, and ends with cloud computing topics — security, data analytics, and simulation using CloudSim.

Students progress from sequential C programs to multi-threaded and multi-process parallel programs, and finally to cloud-based simulation tools.

## Course Objectives

- Build a foundation in C programming, control flow, and arrays
- Implement shared-memory parallelism using OpenMP
- Implement distributed-memory communication using MPI
- Apply parallel techniques to numerical methods and sorting
- Understand basic cloud security, data analytics, and simulation using CloudSim

## Course Outcomes

By the end of this course, students should be able to:

- Write and debug C programs involving numbers, characters, and arrays
- Parallelize problems using OpenMP directives and synchronization
- Write message-passing programs using MPI, including collective communication
- Apply parallel sorting and numerical methods
- Evaluate basic cloud security practices and simulate cloud environments with CloudSim

---

## Assessment Scheme

Total: 100 marks

- **Continuous Assessment — 60 marks**
  - Sessional I (30): Lab report (20), lab question (5), viva (5)
  - Sessional II (30): Lab report (20), lab question (5), viva (5)
- **Final Lab Examination — 40 marks**

At least 10 timely, completed, and signed weekly assignments are required to sit the final lab exam.

---

## Weekly Lab Index

### Week 1 — Basic C Programming and Array Operations *(this folder)*

Basic C programming skills — control flow, functions, and arrays.

| # | Problem | File |
|---|---|---|
| 1 | Check if a number is a palindrome | `1_palindrome.c` |
| 2 | Find the roots of a quadratic equation | `2_quadratic_roots.c` |
| 3 | Check if a year is a leap year | `3_leap_year.c` |
| 4 | Calculate simple and compound interest | `4_simple_compound_interest.c` |
| 5 | Check if a character is a vowel or consonant | `5_vowel_consonant.c` |
| 6 | Print primes in a range | `6_primes_in_range.c` |
| 7 | Find the LCM and HCF of two numbers | `7_lcm_hcf.c` |
| 8 | Find the largest and smallest value in an array | `8_largest_smallest_array.c` |
| 9 | Insert a value at a given position in an array | `9_insert_in_array.c` |
| 10 | Search for a value in an array | `10_search_in_array.c` |

**Tools:** GCC

**Compile & run:**

```bash
cd "Week 1"

# single program (use -lm for programs 2 and 4, which use math.h)
gcc 1_palindrome.c -o palindrome
./palindrome

gcc 2_quadratic_roots.c -o quadratic -lm
./quadratic

# or compile everything at once
for f in *.c; do gcc "$f" -o "${f%.c}.out" -lm; done
```

Note: Programs 8, 9, and 10 are interactive — they ask for array size `N`, then each element. Program 9 uses `N + 1` slots to allow inserting a new value. All programs were tested with `gcc -Wall` with no errors or warnings.

---

### Later Weeks

| Week | Topic |
|---|---|
| 2 | Basic OpenMP programming and number checks |
| 3 | OpenMP task distribution and mathematical computation |
| 4 | Introduction to the OpenMP environment and tools |
| 5 | Parallelizing with threads — basic problems |
| 6 | Data environment and synchronization |
| 7 | Advanced work-sharing and reduction |
| 8 | Introduction to MPI — basic communication |
| 9 | Collective MPI operations (broadcast, scatter, gather, reduce) |
| 10 | Parallel numerical methods and sorting (OpenMP) |
| 11 | Advanced parallel sorting (OpenMP & MPI) |
| 12 | Cloud security fundamentals and basic web services |
| 13 | Cloud data analytics and advanced security |
| 14 | Cloud simulation with CloudSim |

---

## Tech Stack

- **C / GCC** — core sequential programming (Week 1)
- **OpenMP** — shared-memory parallel programming (Weeks 2–7, 10–11)
- **MPI** — distributed-memory message passing (Weeks 8–11)
- **CloudSim** — cloud simulation (Week 14)

---

## Deliverables per Exercise (teacher-signed)

- Source code with sample input/output
- Screenshot of compilation and execution *(from Week 2 onward)*

---

## Lab File Format

```
Week No. | Problems with Description | Page No. | Teacher Signature & Date
1        | 1#, 2#, ... 10#            |          |
2        | 1#, 2#, 3#                 |          |
...      | ...                        |          |
```

Header: Page number
Footer: Roll number & name

---

## Department Info

- **Department:** Computer Science, Aligarh Muslim University, Aligarh (U.P.), India
- **Lab Manual Edition:** Revised — January 2026
- **Convener:** Prof. Aasim Zafar
- **Committee Members:** Prof. Mohammad Ubaidullah Bokhari, Dr. Arman Rasool Faridi, Dr. Faisal Anwer
- **Design & Compilation:** Dr. Faraz Masood
