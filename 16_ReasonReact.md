# ReasonReact

## Installation

```
npm install -g bs-platform
bsb -init my-react-app -theme react
cd my-react-app && npm install && npm start
# in another tab
npm run webpack
```

## No classes

First create component

```
let component = ReasonReact.statelessComponent("Greeting");
```

Reason React calls make function to create component

```
let make = (~name, _children) => {
  ...component, /* spread the template's other defaults into here  */
  render: _self => <div> {ReasonReact.string(name)} </div>
};
```

## Props are labeled arguments

> The prop name cannot be ref nor key

- Last prop MUST be `children`
- You can pass prop value without wrapping in curly braces

```
<Foo name="Reason" age=myAge />
```
- optional props can be passed further like this:

```
<Foo name="Reason" age=?myAge />
```

## self

ReasonReact render looks like this:
```
render: (self) => ...
```

`self` is a record with `state`, `handle` and `send`


## JSX

ReasonReact children are fully typed ☺️
Read more about internals of JSX [here](https://reasonml.github.io/reason-react/docs/en/jsx)

## render

render needs to return a `ReasonReact.reactElement`. If not you need to pass it to 

- ReasonReact.null
- ReasonReact.string - pass string to dom element
- ReasonReact.array - converts array to reactElement

## Callbacks

```
let component = /* ... */;

let make = (~name, ~onClick, _children) => {
  let click = (event) => onClick(name); /* pass the name string up to the owner */
  {
    ...component,
    render: (self) => <button onClick=click />
  }
};
```

If you want to pass state, or self to callback you need to wrap it with handle

```
let component = /* ... */;

let make = (~name, ~onClick, _children) => {
  let click = (event, self) => {
    onClick(event);
    Js.log(self.state);
  };
  {
    ...component,
    initialState: /* ... */,
    render: (self) => <button onClick={self.handle(click)} />
  }
};
```

## Stateful components

First Declare your state
```
type state = {
  count: int,
  show: bool,
};
```

Then declare your actions
```
type action =
  | Click
  | Toggle;
```

Then declare your component

```
let component = ReasonReact.reducerComponent("Example");

let make = (~greeting, _children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  initialState: () => {count: 0, show: true},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: !state.show})
    },

  render: self => {
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
    <div>
      <button onClick=(_event => self.send(Click))>
        (ReasonReact.string(message))
      </button>
      <button onClick=(_event => self.send(Toggle))>
        (ReasonReact.string("Toggle greeting"))
      </button>
      (
        self.state.show
          ? ReasonReact.string(greeting)
          : ReasonReact.null
      )
    </div>;
  },
};
```

## initialState

*Should be declared before reducerComponent*


## Reducer
pattern matches on action an

- `ReasonReact.NoUpdate` - no update
- `ReasonReact.Update(state)` - update
- `ReasonReact.SideEffects(self => unit)` - triggers side effects without state update
- `ReasonReact.UpdateWithSideEffects(state, self => unit)`


## Lifecycles

- didMount: self => unit

- willReceiveProps: self => state

- shouldUpdate: oldAndNewSelf => bool

- willUpdate: oldAndNewSelf => unit

- didUpdate: oldAndNewSelf => unit

- willUnmount: self => unit

## Getting previous props

```
type retainedProps = {message: string};

let component = ReasonReact.statelessComponentWithRetainedProps("RetainedPropsExample");

let make = (~message, _children) => {
  ...component,
  retainedProps: {message: message},
  didUpdate: ({oldSelf, newSelf}) =>
    if (oldSelf.retainedProps.message !== newSelf.retainedProps.message) {
      /* do whatever sneaky imperative things here */
      Js.log("props `message` changed!")
    },
  render: (_self) => /* ... */
};
```

## Instance variables

must be in state marked with `ref()`
```
type state = {
  someRandomState: option(string),
  intervalId: ref(option(int))
};
```

## Events

`event->ReactEvent.Form.target##value;`

## Cloning elements

```
let clonedElement =
  ReasonReact.cloneElement(
    <div className="foo" />,
    ~props={"payload": 1},
    [||]
  );
```

Read more on ReasonReact [here](https://reasonml.github.io/reason-react/docs):