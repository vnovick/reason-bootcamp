# Types

- Types can be inferred
- Types coverage is always 100%
- If it compiles it works. no null bugs

# Comments
```
/*
foo(); /* foo */
bar(); /* bar */
*/

```

# Booleans

```
true  || false;
true && false;
```

# Numbers

## Integers
`2 + 1;`

[Int3d](https://reasonml.github.io/api/Int32.html)

## Floats
`2.0 +. 1.0;`
`1000.`;

[Check JS.Float](https://bucklescript.github.io/bucklescript/api/Js.Float.html)

# Strings

## String concatination
`"abc" ++ "defg"`

## String concatination with int conversion
`"Get Ready, Player" ++ " " + string_of_int(1);

More string manipulations here: [https://reasonml.github.io/api/String.html](https://reasonml.github.io/api/String.html)

## Multiline string
```
{|
 hey there.
 This is a multiline string
|};
```

> Bucklescript string interpolation (won't work in rtop);
```
let greetings = "Greetings";
let helloWorld = {j|${greetings}, Vladimir|j};
```

# Chars

`'y'`

`String.get("abc", 1);`

# Unit type

`()`

`print_string;`

# Equalities

`==` structural equality

`===` referential equality

# Values and Basic  types walkthrough

- `1 + 6 * 7 - 5`?
As most programming languages, OCaml follows the usual priority rules in arithmetic expressions. This expression is read as: `1 + 6 * 7 - 5`.

usual priority rules;

- `10 / 3 * 3`

The `/` and `*`  operators are *left associative*. It means that this expression is read as: `(10 / 3) * 3`.
The `/` operator is the integer division.

- `42 + 73 mod 5 * 2`
The mod operator computes the rest of the integer division. It is one of the rare infix operators composed only of alpha-numerical characters. It has a higher priority than other arithmetic operators, and this expression is read as: 42 + ((73 mod 5) * 2).

- `11 / 4 * 4 + 11 mod 4`

This expression is read as: ((11 / 4) * 4) + (11 mod 4), which is equal to (2 * 4) + 3

- `1 < 2 && 2 != 3`

- `true = 1`

While the comparison operators are polymorphic, you cannot compare two values of different types. Hence, the expressions true = 1 is rejected by the typechecker.

- `1 < 2 < 7`

The comparison operators are left associative. It means that this expression is syntactically valid, and is read as: (1 < 2) < 3.This is not a ternary comparison, which OCaml does not have. Although this pattern can make sense in some cases, it is here the result of a (common) beginner error.
Fortunately, the typechecker rejects this expression, because the polymorphic comparison cannot compare two values of different types, namely 1 < 2 of type bool and 3 of type int.

- `1.5 *. 1e3`
The *. operator is a floating-point multiplication. Floating-point constants must contain a dot (e.g. 1.5), an exponential part (e.g. 1e3), or both: 1.5e3.
The OCaml toplevel always prints floating-point values with the dot notation.

- `2.7 *. 1000`
The expression 1000, without a final dot, is an integer constant ; it cannot be used as argument for a floating-point multiplication, as there is no implicit type conversion in OCaml.

- `"12" + "34"`
The string-concatenation operator is ++ The + operator is only the integer addition.

- "34" ++ string_of_int(4) ++ "64"
The string_of_int function pretty-prints an integer into a string. The evaluation of string_of_int(4) is then the string "4"


- "She texted me: "hi :-)"!!!"
As usual, special characters in string needs to be escaped, e.g. in this particular string the " character.
A correct string constant could be "She texted me: \"hi :-)\"!!!"

- String.get("asd", 1);

Quoting the [OCaml manual](https://caml.inria.fr/pub/docs/manual-ocaml/libref/String.html): "String.get s n returns the character at index n in string s".
As usual, character indexes in strings starts at 0.
Character literals are written between single quotes: for instance 'a', 'A' or ' '.

- What replacement for the function f renders the expression `f("3") + 1415` correct

Answer: `let f = int_of_string;`

type_of_type conversion function can be used to convert a type

- `"abcd" == ("ab" ^ "cd");`

Polymorphic comparison operators are able to compare strings.

- "dfs" < "sdf"

- 
```
 [1,2,3] == [1,2,3]
```

`==` is the preferred equality operator (unless you really want to compare references).

# If and statements

if (predicate) {
 "Hey"
} else {
  "Hello"
};

## ternary

`let message = isMorning ? "Good morning!" : "Hello!";`



