// ~bytes should be of type Buffer.t, that's why this module is in js/
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
