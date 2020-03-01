open Url;

open GenerateId;

type t = string;

let nanoid = (~size=21, ~alphabet=urlChars, ()) => {
  switch (alphabet) {
  | "-_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" =>
    generateId(~size, ~alphabet)
  | _ => generateIdWithCustom(~size, ~alphabet)
  };
};
