open Url;
open Random;

type t = string;

let rec generateId = (~size, ~currId: string, ~bytes: array('a)) => {
  switch (size) {
  | 0 => currId
  | _ =>
    generateId(
      ~size=size - 1,
      ~currId=currId ++ String.make(1, urlChars.[bytes[size - 1] land 63]),
      ~bytes,
    )
  };
};

let nanoid = (~size=21, ()) => {
  let bytes = random(~bytes=size);
  generateId(~size, ~currId="", ~bytes);
};
