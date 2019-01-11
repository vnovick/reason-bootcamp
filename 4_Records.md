# Declaring a Record

```
type person = {
  age: int,
  name: string
}
```
Value (this will be inferred to be of type person):
> Records need explicit definition

## Spread operator

```
let person = {
  age: 34,
  name: "Vladimir Novick"
};

let person = { ...person, age: person.age + 1 };

```
## Mutability

```
type rocket = {
  rocketType: string,
  mutable destination: string,
  fuelType: string
};

let rocketToMars = {
  rocketType: "SpaceX rocket",
  destination: "Moon",
  fuelType: "RP-1"
}

rocketToMars.destination = "Mars";
```

# Punning 
```
let coordinates = ("RA: 21h 10m 44s", "Dec +52° 53′ 11″");
type rocketDistination = {
  destinationName: string,
  constellation: string,
  coordinates: (string, string)
};

let marsDestination = {
  destinationName: "Mars",
  constellation: "Pisces",
  coordinates
};

```

Record, since its fields are fixed, is compiled to an array with array index accesses instead of JS object (try it in the playground!). On native, it compiles to basically a region of memory where a field access is just one field lookup + one actual access, aka 2 assembly instructions. The good old days where folks measured in nanoseconds...

> Records use "nominal typing"

## Record destructuring

`let { destinationName } = marsDestination; `

### Nested destructuring

`let { coordinates: (x, y) } = marsDestination;`

# Recursive record types

```
type rocketDistination = {
  destinationName: string,
  constellation: string,
  coordinates: celestialCoordinates
} and celestialCoordinates = {
  rA: (string, string, string),
  dEc: (string, string, string)
};
```
# Parameterized record types


```
type rocketDistination('a) = {
  destinationName: string,
  constellation: string,
  coordinates: celestialCoordinates('a)
} and celestialCoordinates('a) = {
  rA: ('a, 'a, 'a),
  dEc: ('a, 'a, 'a)
};

let rocket = {
  destinationName: "Mars",
  constellation: "Pisces",
  coordinates: {
    rA: ("20m", "14s", "00"),
    dEc: ("51deg", "34m", "12"),
  },
};
```


