module Count: Functor.Count = {
  let count = 3;
};

module Repeat = Functor.Make(Count);

let () = print_string(Repeat.repeat("abc\n"));