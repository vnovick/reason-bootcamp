type timeout;
   [@bs.val] external setTimeout: (unit => unit, int) => timeout = "setTimeout";

   [@bs.val] external clearTimeout: timeout = "clearTimeout";

   [@bs.scope "Math"] [@bs.val] external random: int => float = "";

   [@bs.scope ("window", "location", "ancestorOrigins")] [@bs.val]
   external len: int = "length";

   [@bs.module "MyConstant"] external myId: Js.Nullable.t(string) = "myId";

   [@bs.val] external peopleAge: Js.Dict.t(int) = "";

   switch (Js.Dict.get(peopleAge, "Vladimir")) {
   | None => Js.log("Vladimir is not found")
   | Some(age) => Js.log("Vladimir is" ++ string_of_int(age))
   };

   type person = {
     .
     "name": string,
     "lastName": string,
     "age": int,
   };

   [@bs.val] external getPerson: unit => person = "";

   [@bs.deriving abstract]
   type testRecord = {
     [@bs.optional]
     test: string,
     [@bs.optional]
     test3: string,
   };

   [@bs.val] external printTest: testRecord => unit = "printTest";

   let testRec = testRecord(~test="Hey");

   type t;
   [@bs.new] external createDate: unit => t = "Date";

   let date = createDate();

   Js.log(date);

   class type _rect =
     [@bs]
     {
       [@bs.set]
       pub height: int;
       [@bs.set]
       pub width: int;
       pub draw: unit => unit;
     };

   type rect = Js.t(_rect);

   type math;
   [@bs.val] external math: math = "Math";
   [@bs.send] external rnd: (math, int) => float = "random";

   [@bs.module "path"] external dirname: string => string = "";

   Js.log(dirname(""));

/* [@bs.deriving {jsConverter: newType}]
type person = {
  name: string,
  age: int,
  lastName: string,
}; */

/* [@bs.val] external getPerson: unit => abs_person = ""; */

/* let pr = personFromJs(getPerson()); */

/* Js.log(pr.name); */

[@bs.deriving abstract]
type data = {name: string};

[@bs.scope "JSON"] [@bs.val]
external parseIntoMyData : string => data = "parse";

let result = parseIntoMyData("{\"name\": \"Luke\"}");

let n = nameGet(result);