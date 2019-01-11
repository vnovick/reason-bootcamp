# Arrays and Lists
- Using [List](https://reasonml.github.io/api/List.html) sorting functions  sort the following list to be unique, reverse it and convert each element to string
[8,5,3,5,2,6,2,5,8,3,6,7]

- Then convert previous list to an array and then convert array to list by using [ArrayLabels]
- (https://reasonml.github.io/api/ArrayLabels.html) fold_right function
- Recreate `List.nth` function

```
let rec nth = (~index, l)) =>
  switch l {
  | [] => None
  | [head, ..._] when index <= 0 => Some(head)
  | [head, ...tail] => nth(~index=index-1, tail)
  };
```

# Functions
- write a function that determines if a word is an [isogram](https://en.wikipedia.org/wiki/Isogram)
  
```
let is_isogram = inputString => {
  let lowercaseString = inputString |> String.lowercase;

  inputString
  |> Js.String.split("")
  |> Array.to_list
  |> List.sort_uniq(compare)
  |> List.length == String.length(lowercaseString);
};  
```
- Write a recursive function to convert from normal numbers to Roman Numerals.
```
let ones =
  fun
  | '0' => ""
  | '1' => "I"
  | '2' => "II"
  | '3' => "III"
  | '4' => "IV"
  | '5' => "V"
  | '6' => "VI"
  | '7' => "VII"
  | '8' => "VIII"
  | '9' => "IX"
  | _ => raise(OutOfRange("Expected char between '0' and '9'."));

let tens =
  fun
  | '0' => ""
  | '1' => "X"
  | '2' => "XX"
  | '3' => "XXX"
  | '4' => "XL"
  | '5' => "L"
  | '6' => "LX"
  | '7' => "LXX"
  | '8' => "LXXX"
  | '9' => "XC"
  | _ => raise(OutOfRange("Epected char between '0' and '9'."));

let hundreds =
  fun
  | '0' => ""
  | '1' => "C"
  | '2' => "CC"
  | '3' => "CCC"
  | '4' => "CD"
  | '5' => "D"
  | '6' => "DC"
  | '7' => "DCC"
  | '8' => "DCCC"
  | '9' => "CM"
  | _ => raise(OutOfRange("Expected char between '0' and '9'."));

let thousands =
  fun
  | '1' => "M"
  | '2' => "MM"
  | '3' => "MMM"
  | _ => raise(OutOfRange("Expected char between '1' and '3'."));

let toRoman = i => {
  let str = string_of_int(i);
  switch (String.length(str)) {
  | 1 => ones(str.[0])
  | 2 => tens(str.[0]) ++ ones(str.[1])
  | 3 => hundreds(str.[0]) ++ tens(str.[1]) ++ ones(str.[2])
  | 4 =>
    thousands(str.[0])
    ++ hundreds(str.[1])
    ++ tens(str.[2])
    ++ ones(str.[3])
  | _ => raise(OutOfRange("Expected int with 1 to 4 digits."))
  };
};
```

- Write a [merge sort](https://en.wikipedia.org/wiki/Merge_sort) algorythm in ReasonML (use your own infix operator for compare function)


# Modules
- Experiment with Js module (won't run in rtop. will run only in environment with Bucklescript
- create [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree) Module for creating data structure as well as with insert and remove functions

```
type binarySearchTree('a) =
  | Empty
  | Node(node('a))
and node('a) = {
  value: 'a,
  left: binarySearchTree('a),
  right: binarySearchTree('a),
};

let empty = Empty;
let bst = Node({value: 1, left: Empty, right: Empty});

let rec insert = (tree, compare, v) =>
  switch (tree) {
  | Empty => Node({value: v, left: Empty, right: Empty})
  | Node({value, left, right}) =>
    if (compare(v, value) == (-1)) {
      Node({value, left: insert(left, compare, v), right});
    } else if (compare(v, value) == 1) {
      Node({value, left, right: insert(right, compare, v)});
    } else {
      tree;
    }
  };
  
  let rec remove = (tree, compare, v) =>
  switch (tree) {
  | Empty => Empty
  | Node({value, left: Empty, right: Empty}) =>
    compare(v, value) == 0 ? Empty : tree
  | Node({value, left: Node(_) as left, right: Empty as right}) =>
    compare(v, value) == 0 ?
      left : Node({value, left: remove(left, compare, v), right})
  | Node({value, left: Empty as left, right: Node(_) as right}) =>
    compare(v, value) == 0 ?
      right : Node({value, left, right: remove(right, compare, v)})
  | Node({value, left: Node(_) as left, right: Node(_) as right}) =>
    if (compare(v, value) == (-1)) {
      Node({value, left: remove(left, compare, v), right});
    } else if (compare(v, value) == 1) {
      Node({value, left, right: remove(right, compare, v)});
    } else {
      switch (min(right)) {
      | Empty => tree
      | Node(a) =>
        Node({value: a.value, left, right: remove(right, compare, a.value)})
      };
    }
  };

```
- Create [PriorityQueue module](https://en.wikipedia.org/wiki/Priority_queue)


