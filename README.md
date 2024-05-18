# Graph Class Implementation and Testing

This repository contains the implementation of a `Graph` class in C++ along with unit tests for various operator overloads. The `Graph` class supports operations such as addition, subtraction, multiplication, increment, and comparison between graphs.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Graph Class](#graph-class)
- [Operator Overloads](#operator-overloads)
- [Unit Tests](#unit-tests)
- [License](#license)

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/TubiSmadar/System_Programming_EX2.git
    cd System_Programming_EX2
    ```

2. Ensure you have a C++ compiler installed (e.g., `clang++`) and the doctest testing framework.

## Usage

### Building the Project

To compile the project, use the following command:
```sh
make
```

This will compile the source files and create the `demo` and `test` executables.

### Running the Tests

To run the unit tests, execute the following command:
```sh
make test
./test
```

### Memory Check with Valgrind

To check for memory leaks using Valgrind, use the following command:
```sh
make valgrind
```

### Cleaning the Build

To clean the build directory, use the following command:
```sh
make clean
```

## Graph Class

The `Graph` class represents a graph using an adjacency matrix. Here is a brief overview of its features:

- Load a graph from a 2D vector.
- Overloaded operators for graph manipulation and comparison.
- Output operator to display the graph's adjacency matrix.

### Example

```cpp
#include "Graph.hpp"

int main() {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graph);
    std::cout << g;
    return 0;
}
```

## Operator Overloads

The `Graph` class supports the following operator overloads:

- Unary operators: `+` (copy), `-` (negate).
- Binary operators: `+` (addition), `-` (subtraction), `*` (multiplication).
- Compound assignment operators: `+=`, `-=`.
- Increment and decrement operators: `++` (prefix and postfix), `--` (prefix and postfix).
- Comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`.
- Output operator: `<<` to print the adjacency matrix.

## Unit Tests

Unit tests are written using the Catch2 framework. The tests cover:

- Comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`.
- Increment and decrement operators: `++`, `--`.
- Multiplication operators: `*`.
- Output operator: `<<`.

### Example Test

```cpp
TEST_CASE("Test >,<,>=,<=,==,!= operators")
{
    ariel::Graph g1, g2, g3;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    g3.loadGraph(graph3);

    CHECK((g1 < g2) == true);  
    CHECK((g1 > g2) == false);
    CHECK((g1 <= g2) == true);
    CHECK((g1 >= g2) == false);
    CHECK((g1 == g3) == true);  
    CHECK((g1 != g2) == true);  
}
```



## License

This project is licensed under the MIT License.




# מטלה 2 - גרפים והעמסת אופרטורים

במטלה הקודמת מימשתם את המחלקה `Graph.cpp` המאפשרת ייצוג של גרפים בעזרת מטריצת שכנויות. במטלה הזאת, אתם תרחיבו את המחלקה ותוסיפו תמיכה באופרטורים חשבוניים על גרפים.
כאמור, הגרפים מיוצגים בעזרת מטריצת שכנויות, לכן כל האופרטורים צריכים להיות חוקיים עבור מטריצות (כמו שלמדתם בקורס אלגברה לינארית).

אתם תצטרכו להוסיף את האופרטורים הבאים:

- שישה אופרטורים חשבוניים: חיבור (+) הוספה (+=) פלוס אונרי (+), ושלושת האופרטורים המקבילים לחיסור (-). כאמור, חיבור/חיסור של שתי מטריצות מוגדר רק על מטריצות מאותו סדר גודל nXn. ניסיון לחבר/לחסר שתי מטריצות שלא מקיימות תנאי זה יגרום לזריקת שגיאה.
- שישה אופרטורי השוואה: גדול, גדול-או-שווה, קטן, קטן-או-שווה, שווה, לא-שווה. לשם מטלה זו כללי השוואת גרפים הם כדלקמן:

  1. גרפים G1 ו-G2 ייקראו שווים אם הם מאותו סדר גודל ומכילים את אותן הצלעות (והמשקלים של הצלעות זהים) או אם G1 לא גדול מ-G2 וגם G2 לא גדול מ-G1.
  2. גרף G2 גדול מגרף G1 אם הגרף G1 מוכל ממש בגרף G2. אם אף גרף לא מוכל ממש בשני והגרפים לא שווים, אז גרף G2 גדול מגרף G1 אם מספר הצלעות ב-G2 גדול ממספר הצלעות ב-G1. אם בכל זאת מספר הצלעות זהה, אז הגרף G2 גדול מהגרף G1 אם המטריצה המייצגת של G2 בעלת סדר גודל גבוה יותר משל G1.

- הגדלה ב-1 (++) והקטנה ב-1 (--) לפני ואחרי המספר. פעולה זו תגדיל או תקטין ב-1 את כל המשקלים של הצלעות בגרף.
- הכפלה בסקלר שלם (`int`) - מכפיל את המשקל של כל הצלעות.
- הכפלת גרפים - אנחנו מגדירים את פעולת הכפל בין גרף G1 לגרף G2 על ידי מכפלה של המטריצות המייצגות של שני הגרפים. התוצאה צריכה להיות מטריצה המייצגת גרף. ניסיון לבצע כפל בין גרפים בגדלים שונים צריך לזרוק שגיאה.
- אופרטור פלט - הדפסה הגיונית של הגרף (צורת ההפדסה היא לשיקולכם).


כמו כן, עליכם לכלול גם את הקובץ `Algorithms.cpp` מהמטלה הקודמת ולראות כיצד הפונקציות שהגדרתם בפעם הקודמת משתנות עכשיו. בנוסף לקבצים של המטלה אתם נדרשים להגיש גם קובץ README המתאר את אופן המימוש ואת החלוקה שביצעתם בקוד (סוג של מדריך משתמש).
עליכם לכתוב בתחילת כל קובץ את מספר תעודת הזהות שלכם ואת המייל. אי עמידה בהנחיות תגרור הפחתה בציון.
בהצלחה!

