let array = [|1, 2, 3|];

let otherArray = Array.make(3, "a");
let logicArray = ArrayLabels.init(~f=i => i + 1, 3);

let maxOfArray = arr => arr |> ArrayLabels.fold_left(~f=max, ~init=min_int);

let filterArray = (filter, array) =>
  array |> Array.to_list |> List.filter(filter) |> Array.of_list;

let alphabet =
  Array.make(26, 0)
  |> Array.mapi((i, _) => Char.chr(i + 65))
  |> Array.to_list;

let isPangram = str =>
  alphabet |> List.for_all(String.uppercase(str) |> String.contains);