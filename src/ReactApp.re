module App = {
  // This sample forces an import of Belt.*, so that CI builds can ensure that
  // Melange has been installed correctly for JS bundlers to be able to find it.
  [@react.component]
  let make = () =>
    ["Hello " ++ World.name ++ "!", "This is React via Melange with Relude!"]
    |> List.map(greeting => <h1> {greeting |> React.string} </h1>)
    |> List.toArray
    |> React.array;
};

ReactDOM.querySelector("#root")
|> (
  fun
  | Some(root) => ReactDOM.render(<App />, root)
  | None =>
    Js.Console.error("Failed to start React: couldn't find the #root element")
);
// Alternative way of doing this:
// ReactDOM.querySelector("#root")
// |> Option.foldLazy(
//      () =>
//        Js.Console.error(
//          "Failed to start React: couldn't find the #root element",
//        ),
//      root => ReactDOM.render(<App />, root),
//    );
