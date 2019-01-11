# Lists

[List module](https://reasonml.github.io/api/List.html)

- homogeneous
- immutable
- fast at prepending items

Immutable data structure for sequences of elements that all have the same type. 
They are processed via pattern matching

## Reading Type signatures

`let map: ('a => 'b, list('a)) => list('b);`

Function map gets as first argument a function getting type a and returning type b. As a second argument it gets a type `list` of any type and returns list of any type

List is self-recursive parameterized variant.
`
type mylist('a) =
  | Nil;
  | Cons('a, mylist('a))
`

`let abc = Cons("a", Cons("b", Cons("c", Nil)));`
`let abc: mylist(string) = Cons("a", Cons("b", Cons("c", Nil)));`

In memory list is represented like this:

|"a"|  | -> |"b"|  | -> |"c"|  |

#  Syntax for list

- `[]` - empty list
- `[head, ...tail]` - Cons pair

# Spread

let someList = [0, ...myList];

# Pattern Matching on lists
```
let test = 
  switch (someList) {
   | [] => "Empty"
   | [first, ...last] => "Head of the list is " ++ string_of_int(first)
  };
  
```

## Compute list length 

```
let rec len = (myList) =>
  switch myList {
  | [] => 0
  | [_, ...tail] => 1 + len(tail)
  };
  
```
 # Acess nth
 `List.nth(someList, 2);`

# Sorting lists

```
List.rev(
  List.sort(
    compare, 
      [8,6,4,3,3,2,6,8,4]
  )
);

[8,6,4,3,3,2,6,8,4] |> List.sort(compare) |> List.rev;
```
> list a syntax sugar. `[1, 2, 3]` is conceptually equivalent to `Head(1, Head(2, Head(3, Empty)))`

## Printing list

`Js.log(Array.of_list(myList));`

## Remove elements from list

```
let rec removeAll = (~value: 'a, l: list('a)) =>
  switch l {
  | [] => []
  | [head, ...tail] when head == value => removeAll(~value, tail)
  | [head, ...tail] => [head, ...removeAll(~value, tail)]
  };
```


### Stdlib functions

- map
- for_all
- flatten
[[2,4],[2,5],[4,6]] |> List.flatten
- fold_left
`[1,2,3] |> List.fold_left((a,b) => a + b, 0);`

# Array
[Array](https://reasonml.github.io/api/Array.html), [ArrayLabel](https://reasonml.github.io/api/ArrayLabels.html)
For JS compilation ([Js.Array](https://bucklescript.github.io/bucklescript/api/Js.Array.html))

- mutable 
- fast at random access & updates
- fix-sized on native (flexible on JS)

Difference between lists and arrays:


|            | Lists                | Arrays             |
| ---------- | -------------------- | ------------------ |
| size       | small-medium         | small-large        |
| resizable  | flexible             | fixed              |
| mutability | immutable            | mutable            |
| elem types | same                 | same               |
| access via | destructuring        | index              |
| fastest    | prepend/remove first | read / write elems |

- Arrays provide fast indexed access. Lists are processed via recursion and pattern matching.

## Creating arrays

`let myArray = [| "a", "b", "c" |]`

`ArrayLabels.make(3, "x");`

`ArrayLabels.init(~f=i=>i, 3);`

`ArrayLabels.length([| "a", "b", "c" |]);`



## Pattern matching on arrays should have the same length as data


## Conversion of Arrays

ArrayLabels `to_list` and `of_list`


# Processing

- map
- fold_left
```
let maxOfArray = (arr) =>
  ArrayLabels.fold_left(~f=max, ~init=min_int, arr);
```
# Filtering arrays

Array functions will return arrays 

```

let filterArray = (filter, arr) =>
  arr
  |> Array.to_list
  |> List.filter(filter)
  |> Array.of_list;
  
```

# Using Ocaml stdlib with Lists

[sdlib](https://reasonml.github.io/api/index)

an Excercise

Determine if a sentence is a [Pangram](https://en.wikipedia.org/wiki/Pangram). 

- `Array.map`
- `Array.to_list`
- `List.for_all`
```
let alphabet =
  Array.make(26, 0)
  |> Array.mapi((i, _) => Char.chr(i + 65))
  |> Array.to_list;

let isPangram: string => bool =
  s => alphabet |> List.for_all(String.uppercase(s) |> String.contains);
```