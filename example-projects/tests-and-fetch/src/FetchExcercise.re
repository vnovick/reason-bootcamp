type post = {
  userId: int,
  title: string,
  body: string,
};


module Decode = {
  let post = post =>
    Json.Decode.{
      userId: field("userId", int, post),
      title: field("title", string, post),
      body: field("body", string, post),
    };
};

let url = "https://jsonplaceholder.typicode.com/posts/";

let fetchPosts = postId =>
  Js.Promise.(
    Fetch.fetch(url ++ string_of_int(postId))
    |> then_(Fetch.Response.json)
    |> then_(json => json |> Decode.post |> (post => Some(post) |> resolve))
    |> catch(_err => resolve(None))
  );

Js.Promise.(
  fetchPosts(2)
  |> then_(result =>
        switch (result) {
        | Some(post) => resolve(Js.log(post))
        | None => resolve(Js.log("no result"))
        }
      )
  |> ignore
)