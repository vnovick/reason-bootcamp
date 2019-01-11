This is a repo complimentory to the following 4 days [Bootcamp](https://www.youtube.com/playlist?list=PLqrUy7kON1mdq7DLMqQLeTOYRR3hlHaGx)

[Slides](https://slides.com/vladimirnovick/reason-bootcamp)


# Installation

- Install [`reason-cli`](https://github.com/reasonml/reason-cli) cause we will be using `rtop` 
- `yarn global add bs-platform` - Install Bucklescript in order to compile ReasonML to JavaScript
- Init our project with `bsb -init my-new-project -theme basic-reason`
- Add to existing project `yarn add --dev bs-platform`
- Run bucklescript in watch mode `bsb -make-world -w`

[Docs](https://reasonml.github.io/docs/en/installation)


## Try out ReasonML in rtop/playground
- `rtop` (use `#quit;` to quit)
- [Playground](https://reasonml.github.io/en/try)



## Editor integration

We will use VSCode as editor of our choice. 
- Install [reason-vscode](https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode) extension
- Go through settings


[Day1](https://www.youtube.com/watch?v=F2rfxtoZpB0&t=42s&list=PLqrUy7kON1mdq7DLMqQLeTOYRR3hlHaGx&index=2)
- Values
- Bindings and scopes
- tupples
- records
- variants
- pattern matching

[Excercise](./ExcerciseDay1.md)


[Day2](https://www.youtube.com/watch?v=MHDv-0v4WNo&t=373s&list=PLqrUy7kON1mdq7DLMqQLeTOYRR3hlHaGx&index=3)
- loops
- functions
- arrays
- lists
- modules

[Excercise](./ExcerciseDay2.md)

[Day3](https://www.youtube.com/watch?v=6nk64zmEvrg&t=47s&list=PLqrUy7kON1mdq7DLMqQLeTOYRR3hlHaGx&index=4)
- modules
- functors
- JS interop
- Bucklescript

[Day4](https://www.youtube.com/watch?v=gLLoIIAGCmE&index=4&list=PLqrUy7kON1mdq7DLMqQLeTOYRR3hlHaGx)
- Recap
- Continue with Bucklescript 
- Bucklescript build system
- ReasonReact

