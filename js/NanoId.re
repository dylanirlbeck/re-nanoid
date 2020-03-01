open Url;
open Random;

type t = string;

let rec generateId = (~size, ~alphabet, ~currId: string, ~bytes: array('a)) => {
  switch (size) {
  | 0 => currId
  | _ =>
    generateId(
      ~size=size - 1,
      ~alphabet,
      ~currId=currId ++ String.make(1, alphabet.[bytes[size - 1] land 63]),
      ~bytes,
    )
  };
};

let nanoid = (~size=21, ~alphabet=urlChars, ()) => {
  let bytes = random(~bytes=size);
  generateId(~size, ~alphabet, ~currId="", ~bytes);
};
