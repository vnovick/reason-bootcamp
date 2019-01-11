type myList('a) =
  | Nil
  | Cons('a, myList('a));

let abc = Cons("s", Cons("b", Cons("c", Nil)));

let regularList = [1, 2, 3];

let rec length =
  fun
  | [] => 0
  | [_, ...tail] => 1 + length(tail);

[7, 2, 4, 5] |> List.sort(compare);

let rec removeAll = (~value, l) =>
  switch (l) {
  | [] => []
  | [head, ...tail] when head == value => removeAll(~value, tail)
  | [head, ...tail] => [head, ...removeAll(~value, tail)]
  };

Js.log([1, 2, 3] |> List.fold_left((a, b) => a + b, 0));

let rec nth = (~index, l) => 
  switch l {
  | [] => None
  | [head, ..._] when index <= 0 => Some(head)
  | [_, ...tail] => nth(~index=index-1, tail)
  };