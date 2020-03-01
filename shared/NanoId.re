open Url;

open Random;
open GenerateId;

type t = string;

let nanoid = (~size=21, ~alphabet=urlChars, ()) => {
  let bytes = random(~bytes=size);
  generateId(~size, ~alphabet, ~currId="", ~bytes);
};
