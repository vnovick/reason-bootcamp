# Functor

- A function whose parameters are modules and whose result is a module.
- A module (the result) that is parameterized (configured) via modules (the parameters).

```
module «F» = («ParamM1»: «ParamI1», ···): «ResultI» => {
  «body of functor»
};


module Count: Functor.Count = {
  let count = 3;
};


module Repeat = Functor.Make(Count);


let () = print_string(Repeat.repeat("abc\n"));

```