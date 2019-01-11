# Loops

```
for (myBinding in startValue to endValue) {
  /* use myBinding here */
};
```

## Oposite direction

```
for (myBinding in startValue downto endValue) {
  statements
};
```

## While 

```
while (testCondition) {
  statements
};
```

```
Random.self_init();

let break = ref(false);

while (! break^) {
  if (Random.int(10) === 3) {
    break := true
  } else {
    print_endline("hello")
  }
};
```

[Source](https://reasonml.github.io/docs/en/imperative-loops)